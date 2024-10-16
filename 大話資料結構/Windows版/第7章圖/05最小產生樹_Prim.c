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

typedef int Status;	/* Statusーーー ー,ーーーーーーー驚ーーOK�R*/

typedef struct
{
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

void CreateMGraph(MGraph *G)/* �Pﾍ */
{
	int i, j;

	/* printf("ーーーーー轡ー:"); */
	G->numEdges=15;
	G->numVertexes=9;

	for (i = 0; i < G->numVertexes; i++)/* ーーー */
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

/* Primー艶ーーーーー��*/
void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];		/* ー�]競�Nーー*/
	int lowcost[MAXVEX];	/* ー�]競�Nーーー險 */
	lowcost[0] = 0;/* ーー賜ーーーー0ーーーーー吮/
			/* lowcost妻甼0ーーー�yーー〉ー轡ー�圈次次社�/
	adjvex[0] = 0;			/* ーー賜ー轡ーーー*/
	for(i = 1; i < G.numVertexes; i++)	/* ーーーーーーーー�N */
	{
		lowcost[i] = G.arc[0][i];	/* ー0轡ーーーーー險ーーー */
		adjvex[i] = 0;					/* ーー皙ー�T〉ー/
	}
	for(i = 1; i < G.numVertexes; i++)
	{
		min = GRAPH_INFINITY;	/* ーーーーーーーーー/
						/* ーー逑ーーーーーーーー32767ー5535�R*/
		j = 1;k = 0;
		while(j < G.numVertexes)	/* ーーー轡ー/
		{
			if(lowcost[j]!=0 && lowcost[j] < min)/* ー鎬險ーーー險ーーmin */
			{	
				min = lowcost[j];	/* ーー�Zーーーーーー */
				k = j;			/* ーーーーー�T〉ーーk */
			}
			j++;
		}
		printf("(%d, %d)\n", adjvex[k], k);/* ーーー轡ーーーーーー鏃ー*/
		lowcost[k] = 0;/* ーー轡ーーーーーー0,ー�j轡ー�ァ次治\ */
		for(j = 1; j < G.numVertexes; j++)	/* ーー�R轡ー/
		{
			if(lowcost[j]!=0 && G.arc[k][j] < lowcost[j]) 
			{/* ー�H〉ーk轡ーー險ーーーーー轡ーーーーー�yー */
				lowcost[j] = G.arc[k][j];/* ーーーーーーーwcostーー�fー */
				adjvex[j] = k;				/* ー〉ーk亭�Nーーjvex */
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