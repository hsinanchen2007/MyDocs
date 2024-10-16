#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;	/* Statusーーー ー,ーーーーーーー驚ーーOK�R*/  
typedef int Boolean; /* Booleanーーーー,ーーーTRUEーALSE */

typedef char VertexType; /* 轡ーーーーーーー */
typedef int EdgeType; /* ーーー險 ーーーーーー */

#define MAXSIZE 9 /* ーーー釦脱ー */
#define MAXEDGE 15
#define MAXVEX 9

typedef struct
{
	VertexType vexs[MAXVEX]; /* 轡ー */
	EdgeType arc[MAXVEX][MAXVEX];/* Zーーー�Yーーー/
	int numVertexes, numEdges; /* ーー�Zー轡ーーーー/ 
}MGraph;

/* ー��ーーーーーーー******************************** */

/* ーーーーーーーー��*/
typedef struct
{
	int data[MAXSIZE];
	int front;    	/* ーーー */
	int rear;		/* �]ーーーーPーーーー蕉ー�tー�Tーー�fー */
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

/* ー蕉ーーーーーーーeーQー亭ー�tー */
Status EnQueue(Queue *Q,int e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)	/* 蕉ーーー�]*/
		return ERROR;
	Q->data[Q->rear]=e;			/* ーーe鮫�`精ー/
	Q->rear=(Q->rear+1)%MAXSIZE;/* rearーーーーーーーー*/
								/* ー�k��ーー省ーーー*/
	return  OK;
}

/* ー蕉ーーーーーー賞�Fーーa�_ーー */
Status DeQueue(Queue *Q,int *e)
{
	if (Q->front == Q->rear)			/* 蕉ーーーーー*/
		return ERROR;
	*e=Q->data[Q->front];				/* ーー�Fー鮫�`e */
	Q->front=(Q->front+1)%MAXSIZE;	/* frontーーーーーーーー*/
									/* ー�k��ーー省ーーー*/
	return  OK;
}
/* ****************************************************** */


void CreateMGraph(MGraph *G)
{
	int i, j;

	G->numEdges=15;
	G->numVertexes=9;

	/* ーー但ーーーー栢ー/
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
 
Boolean visited[MAXVEX]; /* �{ーー糀ー */

/* Zーーーー�痢次次示幻Y*/
void DFS(MGraph G, int i)
{
	int j;
 	visited[i] = TRUE;
 	printf("%c ", G.vexs[i]);/* ーー�Bー�襦次次社�/
	for(j = 0; j < G.numVertexes; j++)
		if(G.arc[i][j] == 1 && !visited[j])
 			DFS(G, j);/* �Gーー�Tーー�Nマ黔ー */
}

/* Zーーーー生桟ー吮/
void DFSTraverse(MGraph G)
{
	int i;
 	for(i = 0; i < G.numVertexes; i++)
 		visited[i] = FALSE; /* ーーー轡ーー�~ーーー齶ー */
	for(i = 0; i < G.numVertexes; i++)
 		if(!visited[i]) /* �Gーー�譟杓N�qAFSーーlーーーーーーーー*/ 
			DFS(G, i);
}

/* Zーーー珥ー桟ー�Y*/
void BFSTraverse(MGraph G)
{
	int i, j;
	Queue Q;
	for(i = 0; i < G.numVertexes; i++)
       	visited[i] = FALSE;
    InitQueue(&Q);		/* ーーー�Wー亭ーー*/
    for(i = 0; i < G.numVertexes; i++)  /* 鑾�獏艚Nーーー*/
    {
		if (!visited[i])	/* ーー�_�{ーーーー/
		{
			visited[i]=TRUE;		/* ーー�Zー茅Iーー/
			printf("%c ", G.vexs[i]);/* ーー�Bー�襦次次社�/
			EnQueue(&Q,i);		/* ーー�Nー蕉ー*/
			while(!QueueEmpty(Q))	/* ー�ZーPーー */
			{
				DeQueue(&Q,&i);	/* ーーーーーーーーー薯 */
				for(j=0;j<G.numVertexes;j++) 
				{ 
					/* ー�}ー轡�Wー�Zー�_ーーーーー�� */
					if(G.arc[i][j] == 1 && !visited[j]) 
					{ 
 						visited[j]=TRUE;			/* ーーーー�Nーーー�{ー*/
						printf("%c ", G.vexs[j]);	/* ーー�b*/
						EnQueue(&Q,j);				/* ーーーー�Nー蕉ー */
					} 
				} 
			}
		}
	}
}


int main(void)
{    
	MGraph G;
	CreateMGraph(&G);
	printf("\nー生桟ー);
	DFSTraverse(G);
	printf("\n珥ー桟ー);
	BFSTraverse(G);
	return 0;
}

