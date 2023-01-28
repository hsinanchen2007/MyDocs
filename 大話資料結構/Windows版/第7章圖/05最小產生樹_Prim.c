#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXEDGE 20
#define MAXVEX 20
#define GRAPH_INFINITY 65535

typedef int Status;	/* Status������ ��,���������������á���OK�R*/

typedef struct
{
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

void CreateMGraph(MGraph *G)/* �P�� */
{
	int i, j;

	/* printf("��������������:"); */
	G->numEdges=15;
	G->numVertexes=9;

	for (i = 0; i < G->numVertexes; i++)/* ������ */
	{
		for ( j = 0; j < G->numVertexes; j++)
		{
			if (i==j)
				G->arc[i][j]=0;
			else
				G->arc[i][j] = G->arc[j][i] = GRAPH_INFINITY;
		}
	}

	G->arc[0][1]=10;
	G->arc[0][5]=11; 
	G->arc[1][2]=18; 
	G->arc[1][8]=12; 
	G->arc[1][6]=16; 
	G->arc[2][8]=8; 
	G->arc[2][3]=22; 
	G->arc[3][8]=21; 
	G->arc[3][6]=24; 
	G->arc[3][7]=16;
	G->arc[3][4]=20;
	G->arc[4][7]=7; 
	G->arc[4][5]=26; 
	G->arc[5][6]=17; 
	G->arc[6][7]=19; 

	for(i = 0; i < G->numVertexes; i++)
	{
		for(j = i; j < G->numVertexes; j++)
		{
			G->arc[j][i] =G->arc[i][j];
		}
	}

}

/* Prim���𡼡���������*/
void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];		/* ���]���N����*/
	int lowcost[MAXVEX];	/* ���]���N������� */
	lowcost[0] = 0;/* �����򡼡�����0������������/
			/* lowcost���0�������y�����ӡ������ԡ�������/
	adjvex[0] = 0;			/* �����򡼷�������*/
	for(i = 1; i < G.numVertexes; i++)	/* �����������������N */
	{
		lowcost[i] = G.arc[0][i];	/* ��0������������𪡼���� */
		adjvex[i] = 0;					/* ����⬡��T�ӡ�/
	}
	for(i = 1; i < G.numVertexes; i++)
	{
		min = GRAPH_INFINITY;	/* ������������������/
						/* �����󡼡�������������32767��5535�R*/
		j = 1;k = 0;
		while(j < G.numVertexes)	/* ����������/
		{
			if(lowcost[j]!=0 && lowcost[j] < min)/* ���𪡼����𪡼��min */
			{	
				min = lowcost[j];	/* �����Z������������ */
				k = j;			/* �����������T�ӡ���k */
			}
			j++;
		}
		printf("(%d, %d)\n", adjvex[k], k);/* ��������������������﷡�*/
		lowcost[k] = 0;/* ������������������0,���j�����������\ */
		for(j = 1; j < G.numVertexes; j++)	/* �����R����/
		{
			if(lowcost[j]!=0 && G.arc[k][j] < lowcost[j]) 
			{/* ���H�ӡ�k������𪡼���������������������y�� */
				lowcost[j] = G.arc[k][j];/* ��������������wcost�����f�� */
				adjvex[j] = k;				/* ���ӡ�k���N����jvex */
			}
		}
	}
}

int main(void)
{
	MGraph G;
	CreateMGraph(&G);
	MiniSpanTree_Prim(G);
  
	return 0;
 
}