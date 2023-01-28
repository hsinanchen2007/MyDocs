#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* ¡¼¡¼ÝN¡¼,¡¼¡¼¡¼¡¼¡¼ */

typedef int Status;	/* Status¡¼¡¼¡¼ ¡¼,¡¼¡¼¡¼¡¼¡¼¡¼¡¼¶Ã¡¼ÏÖ§R*/
typedef char VertexType; /* ·¥¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */
typedef int EdgeType; /* ¡¼¡¼¡¼ðª ¡¼¡¼¡¼¡¼¡¼¡¼ */

typedef struct EdgeNode /* ¡¼¡¼Ãb */
{
	int adjvex;    /* Z¡¼¡¼,¡¼¡¼·¥¡¼¡¼ßT¡Ó¡¼/
	EdgeType info;		/* ¡¼¡¼¡¼£¾¡¼,ôN¡¼¡¼²þ†ë¡¼¡¼¡¼ */
	struct EdgeNode *next; /* t¡¼,¡¼¡¼¡¼¡¼¶X¡¼¡¼¡¼/
}EdgeNode;

typedef struct VertexNode /* ·¥¡¼¡¼¡¼/
{
	VertexType data; /* ·¥¡¼,¡¼¡¼Ã¢¡¼¡¼/
	EdgeNode *firstedge;/* ¡¼¡¼¡¼¡¼ */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int numNodes,numEdges; /* ¡¼¡¼ÌZ¡¼Ãa¡¼¡¼¡¼/
}GraphAdjList;

/* ¡¼¡¼«T¡¼¡¼¡¼ö¿*/
void  CreateALGraph(GraphAdjList *G)
{
	int i,j,k;
	EdgeNode *e;
	printf("¡¼¡¼·¥¡¼¡¼¡¼¡¼n");
	scanf("%d,%d",&G->numNodes,&G->numEdges); /* ¡¼¡¼·¥¡¼¡¼¡¼¡¼/
	for(i = 0;i < G->numNodes;i++) /* ¡¼¡¼Ã¢¡¼¡¼¡¼·¥¡¼ */
	{
		scanf(&G->adjList[i].data); 	/* ¡¼¡¼·¥¡¼¡¼ */
		G->adjList[i].firstedge=NULL; 	/* ¡¼¡¼¡¼¡¼‹ù¡¼/
	}
	
	
	for(k = 0;k < G->numEdges;k++)/* ¡¼¡¼¡¼*/
	{
		printf("¡¼¡¼¡¼vi,vj)¡¼ÄâÝN¡¼¡¼\n");
		scanf("%d,%d",&i,&j); /* ¡¼¡¼¡¼vi,vj)¡¼ÄâÝN¡¼¡¼*/
		e=(EdgeNode *)malloc(sizeof(EdgeNode)); /* ¡¼¡¼¡¼¡¼ŒE¡¼¡¼¡¼¡¼Ãb*/
		e->adjvex=j;					/* Z¡¼¡¼¡¼j */                         
		e->next=G->adjList[i].firstedge;	/* ¡¼ºÊêú¡¼¡¼ÌZ¡¼éK¡¼µá÷Ð¡¼ */
		G->adjList[i].firstedge=e;		/* ¡¼¡¼·¥¡¼¡¼¡¼¡¼¡¼e */               
		
		e=(EdgeNode *)malloc(sizeof(EdgeNode)); /* ¡¼¡¼¡¼¡¼ŒE¡¼¡¼¡¼¡¼Ãb*/
		e->adjvex=i;					/* Z¡¼¡¼¡¼i */                         
		e->next=G->adjList[j].firstedge;	/* ¡¼ºÊêú¡¼¡¼ÌZ¡¼éK¡¼µá÷Ð¡¼ */
		G->adjList[j].firstedge=e;		/* ¡¼¡¼·¥¡¼¡¼¡¼¡¼¡¼e */               
	}
}

int main(void)
{    
	GraphAdjList G;    
	CreateALGraph(&G);
	
	return 0;
}

