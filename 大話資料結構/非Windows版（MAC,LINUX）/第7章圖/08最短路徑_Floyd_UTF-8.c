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
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

typedef int Patharc[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];

/* �ե�� */
void CreateMGraph(MGraph *G)
{
	int i, j;

	/* printf("�п�J��ƩM���I��:"); */
	G->numEdges=16;
	G->numVertexes=9;

	for (i = 0; i < G->numVertexes; i++)/* �_�l�ƹ� */
	{
		G->vexs[i]=i;
	}

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

	G->arc[0][1]=1;
	G->arc[0][2]=5; 
	G->arc[1][2]=3; 
	G->arc[1][3]=7; 
	G->arc[1][4]=5; 

	G->arc[2][4]=1; 
	G->arc[2][5]=7; 
	G->arc[3][4]=2; 
	G->arc[3][6]=3; 
	G->arc[4][5]=3;

	G->arc[4][6]=6;
	G->arc[4][7]=9; 
	G->arc[5][7]=5; 
	G->arc[6][7]=2; 
	G->arc[6][8]=7;

	G->arc[7][8]=4;


	for(i = 0; i < G->numVertexes; i++)
	{
		for(j = i; j < G->numVertexes; j++)
		{
			G->arc[j][i] =G->arc[i][j];
		}
	}

}

/* Floyd��k�A�D����G���U���Iv���E���Iw���̵u���|P[v][w]�αa�v����D[v][w]�C */    
void ShortestPath_Floyd(MGraph G, Patharc *P, ShortPathTable *D)
{    
	int v,w,k;    
	for(v=0; v<G.numVertexes; ++v) /* �_�l��D�PP */  
	{        
		for(w=0; w<G.numVertexes; ++w)  
		{
			(*D)[v][w]=G.arc[v][w];	/* D[v][w]�ȧY�������I�����v�� */
			(*P)[v][w]=w;				/* �_�l��P */
		}
	}
	for(k=0; k<G.numVertexes; ++k)   
	{
		for(v=0; v<G.numVertexes; ++v)  
		{        
			for(w=0; w<G.numVertexes; ++w)    
			{
				if ((*D)[v][w]>(*D)[v][k]+(*D)[k][w])
				{/* �Y�G�g�ѯ��ެ�k���I���|�����I�����|��u */
					(*D)[v][w]=(*D)[v][k]+(*D)[k][w];/* �N�ثe���I���v�ȳ]����p���@�� */
					(*P)[v][w]=(*P)[v][k];/* ���|�]�w���g�ѯ��ެ�k�����I */
				}
			}
		}
	}
}

int main(void)
{    
	int v,w,k;  
	MGraph G;    
	
	Patharc P;    
	ShortPathTable D; /* �D�Y�I���E�U�I���̵u���| */   
	
	CreateMGraph(&G);
	
	ShortestPath_Floyd(G,&P,&D);  

	printf("�U���I���̵u���|�p�U:\n");    
	for(v=0; v<G.numVertexes; ++v)   
	{        
		for(w=v+1; w<G.numVertexes; w++)  
		{
			printf("v%d-v%d weight: %d ",v,w,D[v][w]);
			k=P[v][w];				/* ��o�Ĥ@�Ӹ��|���I���� */
			printf(" path: %d",v);	/* �C�L���I */
			while(k!=w)				/* �Y�G���|���I���ޤ��O���I */
			{
				printf(" -> %d",k);	/* �C�L���|���I */
				k=P[k][w];			/* ��o�U�@�Ӹ��|���I���� */
			}
			printf(" -> %d\n",w);	/* �C�L���I */
		}
		printf("\n");
	}

	printf("�̵u���|D\n");
	for(v=0; v<G.numVertexes; ++v)  
	{        
		for(w=0; w<G.numVertexes; ++w)    
		{
			printf("%d\t",D[v][w]);
		}
		printf("\n");
	}
	printf("�̵u���|P\n");
	for(v=0; v<G.numVertexes; ++v)  
	{        
		for(w=0; w<G.numVertexes; ++w)    
		{
			printf("%d ",P[v][w]);
		}
		printf("\n");
	}

	return 0;
}
