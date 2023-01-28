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

typedef int Status;	/* Status�O��ƪ����A,��ȬO��Ƶ��G���A�{���X�A�pOK�� */

typedef struct
{
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

void CreateMGraph(MGraph *G)/* �ե�� */
{
	int i, j;

	/* printf("�п�J��ƩM���I��:"); */
	G->numEdges=15;
	G->numVertexes=9;

	for (i = 0; i < G->numVertexes; i++)/* �_�l�ƹ� */
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

/* Prim��k���ͳ̤p���;�  */
void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];		/* �x�s���p���I���� */
	int lowcost[MAXVEX];	/* �x�s���p���I���䪺�v�� */
	lowcost[0] = 0;/* �_�l�ƲĤ@���v�Ȭ�0�A�Yv0�[�J���;� */
			/* lowcost���Ȭ�0�A�b�o�̴N�O�����ު����I�w�g�[�J���;� */
	adjvex[0] = 0;			/* �_�l�ƲĤ@�ӳ��I���ެ�0 */
	for(i = 1; i < G.numVertexes; i++)	/* �`�������ެ�0�~���������I */
	{
		lowcost[i] = G.arc[0][i];	/* �Nv0���I�P�����䪺�v�Ȧs�J�}�C */
		adjvex[i] = 0;					/* �_�l�Ƴ���v0������ */
	}
	for(i = 1; i < G.numVertexes; i++)
	{
		min = GRAPH_INFINITY;	/* �_�l�Ƴ̤p�v�Ȭ��ۡA */
						/* �q�`�]�w�����i�઺�j�Ʀr�p32767�B65535�� */
		j = 1;k = 0;
		while(j < G.numVertexes)	/* �`���������I */
		{
			if(lowcost[j]!=0 && lowcost[j] < min)/* �Y�G�v�Ȥ���0�B�v�Ȥp��min */
			{	
				min = lowcost[j];	/* �h���ثe�v�Ȧ����̤p�� */
				k = j;			/* �N�ثe�̤p�Ȫ����ަs�Jk */
			}
			j++;
		}
		printf("(%d, %d)\n", adjvex[k], k);/* �C�L�ثe���I�䤤�v�ȳ̤p���� */
		lowcost[k] = 0;/* �N�ثe���I���v�ȳ]�w��0,��ܦ����I�w�g�����u�@ */
		for(j = 1; j < G.numVertexes; j++)	/* �`���Ҧ����I */
		{
			if(lowcost[j]!=0 && G.arc[k][j] < lowcost[j]) 
			{/* �Y�G���ެ�k���I�U���v�Ȥp�󦹫e�o�ǳ��I���Q�[�J���;��v�� */
				lowcost[j] = G.arc[k][j];/* �N���p���v�Ȧs�Jlowcost������m */
				adjvex[j] = k;				/* �N���ެ�k�����I�s�Jadjvex */
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