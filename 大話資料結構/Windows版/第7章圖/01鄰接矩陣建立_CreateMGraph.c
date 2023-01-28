#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* ¡¼¡¼ÝN¡¼¡¼é¨¡¼¡¼¡¼ */
#define GRAPH_INFINITY 65535 /* ¡¼655354©]¡¼ */

typedef int Status;	/* Status¡¼¡¼¡¼ ¡¼,¡¼¡¼¡¼¡¼¡¼¡¼¡¼¶Ã¡¼¡¼OK§R*/
typedef char VertexType; /* ·¥¡¼¡¼¡¼¡¼¡¼¡¼¡¼  */
typedef int EdgeType; /* ¡¼¡¼¡¼ðª ¡¼¡¼¡¼¡¼¡¼¡¼ */
typedef struct
{
	VertexType vexs[MAXVEX]; /* ·¥¡¼ */
	EdgeType arc[MAXVEX][MAXVEX];/* Z¡¼¡¼¡¼‡Y¡¼¡¼¡¼/
	int numNodes, numEdges; /* ¡¼¡¼ÌZ¡¼·¥¡¼¡¼¡¼¡¼*/
}MGraph;

/* ¡¼¡¼¡¼¡¼¡¼«T¡¼¡¼¡¼¡¼¡¼ */
void CreateMGraph(MGraph *G)
{
	int i,j,k,w;
	printf("¡¼¡¼·¥¡¼¡¼¡¼¡¼n");
	scanf("%d,%d",&G->numNodes,&G->numEdges); /* ¡¼¡¼·¥¡¼¡¼¡¼¡¼/
	for(i = 0;i <G->numNodes;i++) /* ¡¼¡¼Ã¢¡¼¡¼¡¼·¥¡¼ */
		scanf(&G->vexs[i]);
	for(i = 0;i <G->numNodes;i++)
		for(j = 0;j <G->numNodes;j++)
			G->arc[i][j]=GRAPH_INFINITY;	/* Z¡¼¡¼¡¼¡¼¡¼*/
	for(k = 0;k <G->numEdges;k++) /* ¡¼¡¼mEdges¡¼¡¼¡¼bZ¡¼¡¼¡¼/
	{
		printf("¡¼¡¼¡¼vi,vj)¡¼ßT¡Ó¡¼¡¼¡¼¡¼¸ö\n");
		scanf("%d,%d,%d",&i,&j,&w); /* ¡¼¡¼¡¼vi,vj)¡¼»ûàh*/
		G->arc[i][j]=w; 
		G->arc[j][i]= G->arc[i][j]; /* ¡¼¡¼¡¼£Q¡¼¡¼¡¼¡¼¡¼¡¼*/
	}
}

int main(void)
{    
	MGraph G;    
	CreateMGraph(&G);
	
	return 0;
}
