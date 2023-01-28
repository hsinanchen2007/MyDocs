#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 9 /* ��������æ�� */
#define MAXEDGE 15
#define MAXVEX 9

typedef int Status;	/* Status������ ��,���������������á��֧R*/
typedef int Boolean; /* Boolean��������,������TRUE��ALSE */

typedef char VertexType; /* ���������������� */   
typedef int EdgeType; /* ������� ������������ */

/* Z��������*/
typedef struct
{
	VertexType vexs[MAXVEX]; /* ���� */
	EdgeType arc[MAXVEX][MAXVEX];/* Z��������������/
	int numVertexes, numEdges; /* �����Z������������/ 
}MGraph;

/* Z�����k***************** */
typedef struct EdgeNode /* �����b*/ 
{
	int adjvex;    /* Z����,�����������T�ӡ�/
	int weight;		/* ����������,�N�������롼���� */
	struct EdgeNode *next; /* t��,���������X������/ 
}EdgeNode;

typedef struct VertexNode /* ��������/ 
{
	int in;	/* �����r*/
	char data; /* ����,����â����/
	EdgeNode *firstedge;/* �������� */   
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int numVertexes,numEdges; /* �����Z���a������/
}graphAdjList,*GraphAdjList;
/* **************************** */

/* ������������������******************************** */
/* ������������������*/
typedef struct
{
	int data[MAXSIZE];
	int front;    	/* ������ */
	int rear;		/* �]����,���֡���,�����֡��t���T�����f�� */
}Queue;

/* �������١����� */
Status InitQueue(Queue *Q)
{
	Q->front=0;
	Q->rear=0;
	return  OK;
}

/* ���֡������������_��RUE,�䡼��ALSE */
Status QueueEmpty(Queue Q)
{ 
	if(Q.front==Q.rear) /* �֡������� */
		return TRUE;
	else
		return FALSE;
}

/* ���֡���,��������e��Q���⡼�t�� */
Status EnQueue(Queue *Q,int e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)	/* �֡������]*/
		return ERROR;
	Q->data[Q->rear]=e;			/* ����e���`����/
	Q->rear=(Q->rear+1)%MAXSIZE;/* rear��������������, */
								/* ���k�������ʡ�����*/
	return  OK;
}

/* ���֡���,�����������F��,��e�_���� */
Status DeQueue(Queue *Q,int *e)
{
	if (Q->front == Q->rear)			/* �֡���������*/
		return ERROR;
	*e=Q->data[Q->front];				/* �����F�����`e */
	Q->front=(Q->front+1)%MAXSIZE;	/* front��������������, */
									/* ���k�������ʡ�����*/
	return  OK;
}
/* ****************************************************** */



void CreateMGraph(MGraph *G)
{
	int i, j;

	G->numEdges=15;
	G->numVertexes=9;

	/* ����â���������� */ 
	G->vexs[0]='A';
	G->vexs[1]='B';
	G->vexs[2]='C';
	G->vexs[3]='D';
	G->vexs[4]='E';
	G->vexs[5]='F';
	G->vexs[6]='G';
	G->vexs[7]='H';
	G->vexs[8]='I';


	for (i = 0; i < G->numVertexes; i++)/* ������ */
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
 
/* ;��Z��������������/
void CreateALGraph(MGraph G,GraphAdjList *GL)
{
	int i,j;
	EdgeNode *e;

	*GL = (GraphAdjList)malloc(sizeof(graphAdjList));

	(*GL)->numVertexes=G.numVertexes;
	(*GL)->numEdges=G.numEdges;
	for(i= 0;i <G.numVertexes;i++) /* ����â���������� */   
	{
		(*GL)->adjList[i].in=0;
		(*GL)->adjList[i].data=G.vexs[i];
		(*GL)->adjList[i].firstedge=NULL; 	/* ������������/
	}
	
	for(i=0;i<G.numVertexes;i++) /* ������*/
	{ 
		for(j=0;j<G.numVertexes;j++)
		{
			if (G.arc[i][j]==1)
			{
				e=(EdgeNode *)malloc(sizeof(EdgeNode));
				e->adjvex=j;					/* Z������j */                         
				e->next=(*GL)->adjList[i].firstedge;	/* ���������ʵ��С��������`e */
				(*GL)->adjList[i].firstedge=e;		/* ����������������e */   
				(*GL)->adjList[j].in++;
				
			}
		}
	}
	
}

Boolean visited[MAXSIZE]; /* �{������ */

/* Z�������Ρ��������Y*/
void DFS(GraphAdjList GL, int i)
{
	EdgeNode *p;
 	visited[i] = TRUE;
 	printf("%c ",GL->adjList[i].data);/* �����С��롼������/
	p = GL->adjList[i].firstedge;
	while(p)
	{
 		if(!visited[p->adjvex])
 			DFS(GL, p->adjvex);/* �G�����T�����N���ء� */
		p = p->next;
 	}
}

/* Z��������������/
void DFSTraverse(GraphAdjList GL)
{
	int i;
 	for(i = 0; i < GL->numVertexes; i++)
 		visited[i] = FALSE; /* �������������~���������� */
	for(i = 0; i < GL->numVertexes; i++)
 		if(!visited[i]) /* �G�����졼�N�qAFS,����l����,����������*/ 
			DFS(GL, i);
}

/* Z�����⡼�����Y*/
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
			printf("%c ",GL->adjList[i].data);/* �����С��롼������/
			EnQueue(&Q,i);
			while(!QueueEmpty(Q))
			{
				DeQueue(&Q,&i);
				p = GL->adjList[i].firstedge;	/* �����������������n�� */
				while(p)
				{
					if(!visited[p->adjvex])	/* �����N�_��I��*/
 					{
 						visited[p->adjvex]=TRUE;
						printf("%c ",GL->adjList[p->adjvex].data);
						EnQueue(&Q,p->adjvex);	/* �����N���֡�*/
					}
					p = p->next;	/* �������������X������/
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

	printf("\n������:");
	DFSTraverse(GL);
	printf("\n�⡼��:");
	BFSTraverse(GL);
	return 0;
}

