#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;	/* Statusーーー ー,ーーーーーーー驚ーーOK�R*/

#define MAXEDGE 20
#define MAXVEX 20
#define GRAPH_INFINITY 65535

typedef struct
{
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

typedef struct
{
	int begin;
	int end;
	int weight;
}Edge;   /* 瞥ー�后�Edgeー谺ー株/

/* �Pﾍ */
void CreateMGraph(MGraph *G)
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

/* ーーー ーー�譯] */
void Swapn(Edge *edges,int i, int j)
{
	int temp;
	temp = edges[i].begin;
	edges[i].begin = edges[j].begin;
	edges[j].begin = temp;
	temp = edges[i].end;
	edges[i].end = edges[j].end;
	edges[j].end = temp;
	temp = edges[i].weight;
	edges[i].weight = edges[j].weight;
	edges[j].weight = temp;
}

/* 儻險ーーーー/
void sort(Edge edges[],MGraph *G)
{
	int i, j;
	for ( i = 0; i < G->numEdges; i++)
	{
		for ( j = i + 1; j < G->numEdges; j++)
		{
			if (edges[i].weight > edges[j].weight)
			{
				Swapn(edges, i, j);
			}
		}
	}
	printf("ーーーーーーーn");
	for (i = 0; i < G->numEdges; i++)
	{
		printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
	}

}

/* ーーー轡ー�]ー〉ー/
int Find(int *parent, int f)
{
	while ( parent[f] > 0)
	{
		f = parent[f];
	}
	return f;
}

/* ーー罱次社�/
void MiniSpanTree_Kruskal(MGraph G)
{
	int i, j, n, m;
	int k = 0;
	int parent[MAXVEX];/* ー�Α次次�4ー�xーーー悌�^ー弄 */
	
	Edge edges[MAXEDGE];/* ー�Pーー,edge�弌次�begin,end,weight,�sーー */

	/* ー4�Q桿ーーーーー******************* */
	for ( i = 0; i < G.numVertexes-1; i++)
	{
		for (j = i + 1; j < G.numVertexes; j++)
		{
			if (G.arc[i][j]<GRAPH_INFINITY)
			{
				edges[k].begin = i;
				edges[k].end = j;
				edges[k].weight = G.arc[i][j];
				k++;
			}
		}
	}
	sort(edges, &G);
	/* ******************************************* */


	for (i = 0; i < G.numVertexes; i++)
		parent[i] = 0;	/* ーーーーーー0 */

	printf("ーーーーー�D\n");
	for (i = 0; i < G.numEdges; i++)	/* ーー�燹次�*/
	{
		n = Find(parent,edges[i].begin);
		m = Find(parent,edges[i].end);
		if (n != m) /* ー�wーーーーーーーーーー慈ーーーー弄 */
		{
			parent[n] = m;	/* ーーーーー轡ーーーーーЁーarentーー*/
							/* ー�j轡ー��ーーーーーー*/
			printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
		}
	}
}

int main(void)
{
	MGraph G;
	CreateMGraph(&G);
	MiniSpanTree_Kruskal(G);
	return 0;
}