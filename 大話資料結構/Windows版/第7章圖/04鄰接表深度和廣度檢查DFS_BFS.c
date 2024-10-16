#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 9 /* ーーー釦脱ー */
#define MAXEDGE 15
#define MAXVEX 9

typedef int Status;	/* Statusーーー ー,ーーーーーーー驚ー�屶R*/
typedef int Boolean; /* Booleanーーーー,ーーーTRUEーALSE */

typedef char VertexType; /* 轡ーーーーーーー */   
typedef int EdgeType; /* ーーー險 ーーーーーー */

/* Zーーー��*/
typedef struct
{
	VertexType vexs[MAXVEX]; /* 轡ー */
	EdgeType arc[MAXVEX][MAXVEX];/* Zーーーーーーー/
	int numVertexes, numEdges; /* ーー�Zー轡ーーーー/ 
}MGraph;

/* Zーー�k***************** */
typedef struct EdgeNode /* ーー�b*/ 
{
	int adjvex;    /* Zーー,ーー轡ーー�T〉ー/
	int weight;		/* ーーー�勝�,�Nーー改�襦次次� */
	struct EdgeNode *next; /* tー,ーーーー�Xーーー/ 
}EdgeNode;

typedef struct VertexNode /* 轡ーーー/ 
{
	int in;	/* 轡���r*/
	char data; /* 轡ー,ーー但ーー/
	EdgeNode *firstedge;/* ーーーー */   
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int numVertexes,numEdges; /* ーー�Zー�aーーー/
}graphAdjList,*GraphAdjList;
/* **************************** */

/* ー��ーーーーーーー******************************** */
/* ーーーーーーーー��*/
typedef struct
{
	int data[MAXSIZE];
	int front;    	/* ーーー */
	int rear;		/* �]ーー,ー蕉ーー,ーー蕉ー�tー�Tーー�fー */
}Queue;

/* ーーー忸ーーー */
Status InitQueue(Queue *Q)
{
	Q->front=0;
	Q->rear=0;
	return  OK;
}

/* ー蕉ーー��ーーー�_ーRUE,�筺次�ALSE */
Status QueueEmpty(Queue Q)
{ 
	if(Q.front==Q.rear) /* 蕉ーーーー */
		return TRUE;
	else
		return FALSE;
}

/* ー蕉ーー,ーーーーeーQー亭ー�tー */
Status EnQueue(Queue *Q,int e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)	/* 蕉ーーー�]*/
		return ERROR;
	Q->data[Q->rear]=e;			/* ーーe鮫�`精ー/
	Q->rear=(Q->rear+1)%MAXSIZE;/* rearーーーーーーー, */
								/* ー�k��ーー省ーーー*/
	return  OK;
}

/* ー蕉ーー,ーーーー賞�Fー,ーe�_ーー */
Status DeQueue(Queue *Q,int *e)
{
	if (Q->front == Q->rear)			/* 蕉ーーーーー*/
		return ERROR;
	*e=Q->data[Q->front];				/* ーー�Fー鮫�`e */
	Q->front=(Q->front+1)%MAXSIZE;	/* frontーーーーーーー, */
									/* ー�k��ーー省ーーー*/
	return  OK;
}
/* ****************************************************** */



void CreateMGraph(MGraph *G)
{
	int i, j;

	G->numEdges=15;
	G->numVertexes=9;

	/* ーー但ーーー轡ー */ 
	G->vexs[0]='A';
	G->vexs[1]='B';
	G->vexs[2]='C';
	G->vexs[3]='D';
	G->vexs[4]='E';
	G->vexs[5]='F';
	G->vexs[6]='G';
	G->vexs[7]='H';
	G->vexs[8]='I';


	for (i = 0; i < G->numVertexes; i++)/* ーーー */
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
 
/* ;ーZーーーーーーー/
void CreateALGraph(MGraph G,GraphAdjList *GL)
{
	int i,j;
	EdgeNode *e;

	*GL = (GraphAdjList)malloc(sizeof(graphAdjList));

	(*GL)->numVertexes=G.numVertexes;
	(*GL)->numEdges=G.numEdges;
	for(i= 0;i <G.numVertexes;i++) /* ーー但ーーー轡ー */   
	{
		(*GL)->adjList[i].in=0;
		(*GL)->adjList[i].data=G.vexs[i];
		(*GL)->adjList[i].firstedge=NULL; 	/* ーーーー��ー/
	}
	
	for(i=0;i<G.numVertexes;i++) /* ーーー*/
	{ 
		for(j=0;j<G.numVertexes;j++)
		{
			if (G.arc[i][j]==1)
			{
				e=(EdgeNode *)malloc(sizeof(EdgeNode));
				e->adjvex=j;					/* Zーーーj */                         
				e->next=(*GL)->adjList[i].firstedge;	/* ーー轡ー妻求�弌次次嫉��`e */
				(*GL)->adjList[i].firstedge=e;		/* ーー轡ーーーーーe */   
				(*GL)->adjList[j].in++;
				
			}
		}
	}
	
}

Boolean visited[MAXSIZE]; /* �{ーー糀ー */

/* Zーーー�痢次次示幻Y*/
void DFS(GraphAdjList GL, int i)
{
	EdgeNode *p;
 	visited[i] = TRUE;
 	printf("%c ",GL->adjList[i].data);/* ーーばー�襦次次社�/
	p = GL->adjList[i].firstedge;
	while(p)
	{
 		if(!visited[p->adjvex])
 			DFS(GL, p->adjvex);/* �Gーー�Tーー�Nマ黔ー */
		p = p->next;
 	}
}

/* Zーーー生桟ー吮/
void DFSTraverse(GraphAdjList GL)
{
	int i;
 	for(i = 0; i < GL->numVertexes; i++)
 		visited[i] = FALSE; /* ーーー轡ーー�~ーーー齶ー */
	for(i = 0; i < GL->numVertexes; i++)
 		if(!visited[i]) /* �Gーー�譟杓N�qAFS,ーーlーー,ーーーーー*/ 
			DFS(GL, i);
}

/* Zーー珥ー桟ー�Y*/
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
			printf("%c ",GL->adjList[i].data);/* ーーばー�襦次次社�/
			EnQueue(&Q,i);
			while(!QueueEmpty(Q))
			{
				DeQueue(&Q,&i);
				p = GL->adjList[i].firstedge;	/* ー��ー轡ーーーー�nー */
				while(p)
				{
					if(!visited[p->adjvex])	/* ーー�N�_ーIー*/
 					{
 						visited[p->adjvex]=TRUE;
						printf("%c ",GL->adjList[p->adjvex].data);
						EnQueue(&Q,p->adjvex);	/* ーー�Nー蕉ー*/
					}
					p = p->next;	/* ーーーーーー�Xーーー/
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

	printf("\nー生桟:");
	DFSTraverse(GL);
	printf("\n珥ー桟:");
	BFSTraverse(GL);
	return 0;
}

