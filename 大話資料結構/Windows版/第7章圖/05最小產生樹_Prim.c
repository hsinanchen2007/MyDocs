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

typedef int Status;	/* Status¡¼¡¼¡¼ ¡¼,¡¼¡¼¡¼¡¼¡¼¡¼¡¼¶Ã¡¼¡¼OK§R*/

typedef struct
{
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

void CreateMGraph(MGraph *G)/* ÆPŽÍ */
{
	int i, j;

	/* printf("¡¼¡¼¡¼¡¼¡¼·¥¡¼:"); */
	G->numEdges=15;
	G->numVertexes=9;

	for (i = 0; i < G->numVertexes; i++)/* ¡¼¡¼¡¼ */
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

/* Prim¡¼±ð¡¼¡¼¡¼¡¼¡¼¯£*/
void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];		/* ¡¼Ù]¶¥ÝN¡¼¡¼*/
	int lowcost[MAXVEX];	/* ¡¼Ù]¶¥ÝN¡¼¡¼¡¼ðª */
	lowcost[0] = 0;/* ¡¼¡¼»ò¡¼¡¼¡¼¡¼0¡¼¡¼¡¼¡¼¡¼Òä/
			/* lowcostºÊá¶0¡¼¡¼¡¼Žy¡¼¡¼¡Ó¡¼·¥¡¼›Ô¡¼¡¼¡¼Òä/
	adjvex[0] = 0;			/* ¡¼¡¼»ò¡¼·¥¡¼¡¼¡¼*/
	for(i = 1; i < G.numVertexes; i++)	/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ÝN */
	{
		lowcost[i] = G.arc[0][i];	/* ¡¼0·¥¡¼¡¼¡¼¡¼¡¼ðª¡¼¡¼¡¼ */
		adjvex[i] = 0;					/* ¡¼¡¼â¬¡¼ßT¡Ó¡¼/
	}
	for(i = 1; i < G.numVertexes; i++)
	{
		min = GRAPH_INFINITY;	/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼/
						/* ¡¼¡¼íó¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼32767¡¼5535§R*/
		j = 1;k = 0;
		while(j < G.numVertexes)	/* ¡¼¡¼¡¼·¥¡¼/
		{
			if(lowcost[j]!=0 && lowcost[j] < min)/* ¡¼ï®ðª¡¼¡¼¡¼ðª¡¼¡¼min */
			{	
				min = lowcost[j];	/* ¡¼¡¼ÌZ¡¼¡¼¡¼¡¼¡¼¡¼ */
				k = j;			/* ¡¼¡¼¡¼¡¼¡¼ßT¡Ó¡¼¡¼k */
			}
			j++;
		}
		printf("(%d, %d)\n", adjvex[k], k);/* ¡¼¡¼¡¼·¥¡¼¡¼¡¼¡¼¡¼¡¼ï·¡¼*/
		lowcost[k] = 0;/* ¡¼¡¼·¥¡¼¡¼¡¼¡¼¡¼¡¼0,¡¼žj·¥¡¼›¥¡¼¡¼£\ */
		for(j = 1; j < G.numVertexes; j++)	/* ¡¼¡¼¾R·¥¡¼/
		{
			if(lowcost[j]!=0 && G.arc[k][j] < lowcost[j]) 
			{/* ¡¼ÂH¡Ó¡¼k·¥¡¼¡¼ðª¡¼¡¼¡¼¡¼¡¼·¥¡¼¡¼¡¼¡¼¡¼Æy¡¼ */
				lowcost[j] = G.arc[k][j];/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼wcost¡¼¡¼£f¡¼ */
				adjvex[j] = k;				/* ¡¼¡Ó¡¼kÄâÝN¡¼¡¼jvex */
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