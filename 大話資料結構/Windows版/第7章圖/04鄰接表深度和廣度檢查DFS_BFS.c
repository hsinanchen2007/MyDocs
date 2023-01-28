#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 9 /* ¡¼¡¼¡¼ËÕÃ¦¡¼ */
#define MAXEDGE 15
#define MAXVEX 9

typedef int Status;	/* Status¡¼¡¼¡¼ ¡¼,¡¼¡¼¡¼¡¼¡¼¡¼¡¼¶Ã¡¼ÏÖ§R*/
typedef int Boolean; /* Boolean¡¼¡¼¡¼¡¼,¡¼¡¼¡¼TRUE¡¼ALSE */

typedef char VertexType; /* ·¥¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */   
typedef int EdgeType; /* ¡¼¡¼¡¼ðª ¡¼¡¼¡¼¡¼¡¼¡¼ */

/* Z¡¼¡¼¡¼ö¿*/
typedef struct
{
	VertexType vexs[MAXVEX]; /* ·¥¡¼ */
	EdgeType arc[MAXVEX][MAXVEX];/* Z¡¼¡¼¡¼¡¼¡¼¡¼¡¼/
	int numVertexes, numEdges; /* ¡¼¡¼ÌZ¡¼·¥¡¼¡¼¡¼¡¼/ 
}MGraph;

/* Z¡¼¡¼øk***************** */
typedef struct EdgeNode /* ¡¼¡¼Ãb*/ 
{
	int adjvex;    /* Z¡¼¡¼,¡¼¡¼·¥¡¼¡¼ßT¡Ó¡¼/
	int weight;		/* ¡¼¡¼¡¼£¾¡¼,ôN¡¼¡¼²þ†ë¡¼¡¼¡¼ */
	struct EdgeNode *next; /* t¡¼,¡¼¡¼¡¼¡¼¶X¡¼¡¼¡¼/ 
}EdgeNode;

typedef struct VertexNode /* ·¥¡¼¡¼¡¼/ 
{
	int in;	/* ·¥¤õÝr*/
	char data; /* ·¥¡¼,¡¼¡¼Ã¢¡¼¡¼/
	EdgeNode *firstedge;/* ¡¼¡¼¡¼¡¼ */   
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int numVertexes,numEdges; /* ¡¼¡¼ÌZ¡¼Ãa¡¼¡¼¡¼/
}graphAdjList,*GraphAdjList;
/* **************************** */

/* ¡¼­£¡¼¡¼¡¼¡¼¡¼¡¼¡¼******************************** */
/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ö¿*/
typedef struct
{
	int data[MAXSIZE];
	int front;    	/* ¡¼¡¼¡¼ */
	int rear;		/* £]¡¼¡¼,¡¼¾Ö¡¼¡¼,¡¼¡¼¾Ö¡¼¢t¡¼ßT¡¼¡¼£f¡¼ */
}Queue;

/* ¡¼¡¼¡¼×Ù¡¼¡¼¡¼ */
Status InitQueue(Queue *Q)
{
	Q->front=0;
	Q->rear=0;
	return  OK;
}

/* ¡¼¾Ö¡¼¡¼‹þ¡¼¡¼¡¼ß_¡¼RUE,õä¡¼¡¼ALSE */
Status QueueEmpty(Queue Q)
{ 
	if(Q.front==Q.rear) /* ¾Ö¡¼¡¼¡¼¡¼ */
		return TRUE;
	else
		return FALSE;
}

/* ¡¼¾Ö¡¼¡¼,¡¼¡¼¡¼¡¼e¡¼Q¡¼Äâ¡¼¢t¡¼ */
Status EnQueue(Queue *Q,int e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)	/* ¾Ö¡¼¡¼¡¼Ù]*/
		return ERROR;
	Q->data[Q->rear]=e;			/* ¡¼¡¼e»­±`Àº¡¼/
	Q->rear=(Q->rear+1)%MAXSIZE;/* rear¡¼¡¼¡¼¡¼¡¼¡¼¡¼, */
								/* ¡¼±k ú¡¼¡¼¾Ê¡¼¡¼¡¼*/
	return  OK;
}

/* ¡¼¾Ö¡¼¡¼,¡¼¡¼¡¼¡¼¾ÞÊF¡¼,¡¼eß_¡¼¡¼ */
Status DeQueue(Queue *Q,int *e)
{
	if (Q->front == Q->rear)			/* ¾Ö¡¼¡¼¡¼¡¼¡¼*/
		return ERROR;
	*e=Q->data[Q->front];				/* ¡¼¡¼ÊF¡¼»­±`e */
	Q->front=(Q->front+1)%MAXSIZE;	/* front¡¼¡¼¡¼¡¼¡¼¡¼¡¼, */
									/* ¡¼±k ú¡¼¡¼¾Ê¡¼¡¼¡¼*/
	return  OK;
}
/* ****************************************************** */



void CreateMGraph(MGraph *G)
{
	int i, j;

	G->numEdges=15;
	G->numVertexes=9;

	/* ¡¼¡¼Ã¢¡¼¡¼¡¼·¥¡¼ */ 
	G->vexs[0]='A';
	G->vexs[1]='B';
	G->vexs[2]='C';
	G->vexs[3]='D';
	G->vexs[4]='E';
	G->vexs[5]='F';
	G->vexs[6]='G';
	G->vexs[7]='H';
	G->vexs[8]='I';


	for (i = 0; i < G->numVertexes; i++)/* ¡¼¡¼¡¼ */
	{
		for ( j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j]=0;
		}
	}

	G->arc[0][1]=1;
	G->arc[0][5]=1;

	G->arc[1][2]=1; 
	G->arc[1][8]=1; 
	G->arc[1][6]=1; 
	
	G->arc[2][3]=1; 
	G->arc[2][8]=1; 
	
	G->arc[3][4]=1;
	G->arc[3][7]=1;
	G->arc[3][6]=1;
	G->arc[3][8]=1;

	G->arc[4][5]=1;
	G->arc[4][7]=1;

	G->arc[5][6]=1; 
	
	G->arc[6][7]=1; 

	
	for(i = 0; i < G->numVertexes; i++)
	{
		for(j = i; j < G->numVertexes; j++)
		{
			G->arc[j][i] =G->arc[i][j];
		}
	}

}
 
/* ;¡¼Z¡¼¡¼¡¼¡¼¡¼¡¼¡¼/
void CreateALGraph(MGraph G,GraphAdjList *GL)
{
	int i,j;
	EdgeNode *e;

	*GL = (GraphAdjList)malloc(sizeof(graphAdjList));

	(*GL)->numVertexes=G.numVertexes;
	(*GL)->numEdges=G.numEdges;
	for(i= 0;i <G.numVertexes;i++) /* ¡¼¡¼Ã¢¡¼¡¼¡¼·¥¡¼ */   
	{
		(*GL)->adjList[i].in=0;
		(*GL)->adjList[i].data=G.vexs[i];
		(*GL)->adjList[i].firstedge=NULL; 	/* ¡¼¡¼¡¼¡¼‹ù¡¼/
	}
	
	for(i=0;i<G.numVertexes;i++) /* ¡¼¡¼¡¼*/
	{ 
		for(j=0;j<G.numVertexes;j++)
		{
			if (G.arc[i][j]==1)
			{
				e=(EdgeNode *)malloc(sizeof(EdgeNode));
				e->adjvex=j;					/* Z¡¼¡¼¡¼j */                         
				e->next=(*GL)->adjList[i].firstedge;	/* ¡¼¡¼·¥¡¼ºÊµá÷Ð¡¼¡¼¡¼»­±`e */
				(*GL)->adjList[i].firstedge=e;		/* ¡¼¡¼·¥¡¼¡¼¡¼¡¼¡¼e */   
				(*GL)->adjList[j].in++;
				
			}
		}
	}
	
}

Boolean visited[MAXSIZE]; /* Ò{¡¼¡¼äñ¡¼ */

/* Z¡¼¡¼¡¼©Î¡¼¡¼¡¼¨¸¸Y*/
void DFS(GraphAdjList GL, int i)
{
	EdgeNode *p;
 	visited[i] = TRUE;
 	printf("%c ",GL->adjList[i].data);/* ¡¼¡¼¤Ð¡¼†ë¡¼¡¼¡¼Òä/
	p = GL->adjList[i].firstedge;
	while(p)
	{
 		if(!visited[p->adjvex])
 			DFS(GL, p->adjvex);/* òG¡¼¡¼«T¡¼¡¼ÝN¥ÞóØ¡¼ */
		p = p->next;
 	}
}

/* Z¡¼¡¼¡¼À¸»·¡¼Òä/
void DFSTraverse(GraphAdjList GL)
{
	int i;
 	for(i = 0; i < GL->numVertexes; i++)
 		visited[i] = FALSE; /* ¡¼¡¼¡¼·¥¡¼¡¼â~¡¼¡¼¡¼óû¡¼ */
	for(i = 0; i < GL->numVertexes; i++)
 		if(!visited[i]) /* òG¡¼¡¼øì¡¼ÝNÅqAFS,¡¼¡¼l¡¼¡¼,¡¼¡¼¡¼¡¼¡¼*/ 
			DFS(GL, i);
}

/* Z¡¼¡¼àâ¡¼»·¡¼¸Y*/
void BFSTraverse(GraphAdjList GL)
{
	int i;
    EdgeNode *p;
	Queue Q;
	for(i = 0; i < GL->numVertexes; i++)
       	visited[i] = FALSE;
    InitQueue(&Q);
   	for(i = 0; i < GL->numVertexes; i++)
   	{
		if (!visited[i])
		{
			visited[i]=TRUE;
			printf("%c ",GL->adjList[i].data);/* ¡¼¡¼¤Ð¡¼†ë¡¼¡¼¡¼Òä/
			EnQueue(&Q,i);
			while(!QueueEmpty(Q))
			{
				DeQueue(&Q,&i);
				p = GL->adjList[i].firstedge;	/* ¡¼­£¡¼·¥¡¼¡¼¡¼¡¼¯n¡¼ */
				while(p)
				{
					if(!visited[p->adjvex])	/* ¡¼¡¼ÝN£_¡¼I¡¼*/
 					{
 						visited[p->adjvex]=TRUE;
						printf("%c ",GL->adjList[p->adjvex].data);
						EnQueue(&Q,p->adjvex);	/* ¡¼¡¼ÝN¡¼¾Ö¡¼*/
					}
					p = p->next;	/* ¡¼¡¼¡¼¡¼¡¼¡¼¶X¡¼¡¼¡¼/
				}
			}
		}
	}
}

int main(void)
{    
	MGraph G;  
	GraphAdjList GL;    
	CreateMGraph(&G);
	CreateALGraph(G,&GL);

	printf("\n¡¼À¸»·:");
	DFSTraverse(GL);
	printf("\nàâ¡¼»·:");
	BFSTraverse(GL);
	return 0;
}

