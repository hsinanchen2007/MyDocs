#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 9 /* �x�s�Ŷ��_�l���t�q */
#define MAXEDGE 15
#define MAXVEX 9

typedef int Status;	/* Status�O��ƪ����A,��ȬO��Ƶ��G���A�{���X,�pOK�� */
typedef int Boolean; /* Boolean�O�������A,��ȬOTRUE��FALSE */

typedef char VertexType; /* ���I���A���ѨϥΪ̩w�q */   
typedef int EdgeType; /* ��W���v�ȫ��A���ѨϥΪ̩w�q */

/* �F���x�}���c */
typedef struct
{
	VertexType vexs[MAXVEX]; /* ���I�� */
	EdgeType arc[MAXVEX][MAXVEX];/* �F���x�},�i�ݧ@��� */
	int numVertexes, numEdges; /* �Ϥ��ثe�����I�ƩM��� */ 
}MGraph;

/* �F�����c****************** */
typedef struct EdgeNode /* ���`�I */ 
{
	int adjvex;    /* �F���I��,�x�s�ӳ��I���������� */
	int weight;		/* �Ω��x�s�v��,���D���ϥi�H���ݭn */
	struct EdgeNode *next; /* ���,���V�U�@�ӾF���I */ 
}EdgeNode;

typedef struct VertexNode /* ���I��`�I */ 
{
	int in;	/* ���I������� */
	char data; /* ���I��,�x�s���I�T�� */
	EdgeNode *firstedge;/* ����Y���� */   
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int numVertexes,numEdges; /* �Ϥ��ثe���I�ƩM��� */
}graphAdjList,*GraphAdjList;
/* **************************** */

/* �Ψ쪺��C���c�P���********************************** */
/* �`����C���s���x�s���c */
typedef struct
{
	int data[MAXSIZE];
	int front;    	/* �Y���� */
	int rear;		/* ������,�Y��C����,���V��C���������U�@�Ӧ�m */
}Queue;

/* �_�l�Ƥ@�ӪŦ�CQ */
Status InitQueue(Queue *Q)
{
	Q->front=0;
	Q->rear=0;
	return  OK;
}

/* �Y��CQ���Ŧ�C,�h�Ǧ^TRUE,�_�h�Ǧ^FALSE */
Status QueueEmpty(Queue Q)
{ 
	if(Q.front==Q.rear) /* ��C�Ū��Ч� */
		return TRUE;
	else
		return FALSE;
}

/* �Y��C����,�h���J����e��Q�s����C������ */
Status EnQueue(Queue *Q,int e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)	/* ��C�����P�_ */
		return ERROR;
	Q->data[Q->rear]=e;			/* �N����e�����ȵ���C�� */
	Q->rear=(Q->rear+1)%MAXSIZE;/* rear���ЦV�Ჾ�@��m, */
								/* �Y��̫�h���}�C���� */
	return  OK;
}

/* �Y��C����,�h����Q���C������,��e�Ǧ^��� */
Status DeQueue(Queue *Q,int *e)
{
	if (Q->front == Q->rear)			/* ��C�Ū��P�_ */
		return ERROR;
	*e=Q->data[Q->front];				/* �N�C�����������ȵ�e */
	Q->front=(Q->front+1)%MAXSIZE;	/* front���ЦV�Ჾ�@��m, */
									/* �Y��̫�h���}�C���� */
	return  OK;
}
/* ****************************************************** */



void CreateMGraph(MGraph *G)
{
	int i, j;

	G->numEdges=15;
	G->numVertexes=9;

	/* Ū�J���I�T��,�إ߳��I�� */ 
	G->vexs[0]='A';
	G->vexs[1]='B';
	G->vexs[2]='C';
	G->vexs[3]='D';
	G->vexs[4]='E';
	G->vexs[5]='F';
	G->vexs[6]='G';
	G->vexs[7]='H';
	G->vexs[8]='I';


	for (i = 0; i < G->numVertexes; i++)/* �_�l�ƹ� */
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
 
/* �Q�ξF���x�}�غc�F���� */
void CreateALGraph(MGraph G,GraphAdjList *GL)
{
	int i,j;
	EdgeNode *e;

	*GL = (GraphAdjList)malloc(sizeof(graphAdjList));

	(*GL)->numVertexes=G.numVertexes;
	(*GL)->numEdges=G.numEdges;
	for(i= 0;i <G.numVertexes;i++) /* Ū�J���I�T��,�إ߳��I�� */   
	{
		(*GL)->adjList[i].in=0;
		(*GL)->adjList[i].data=G.vexs[i];
		(*GL)->adjList[i].firstedge=NULL; 	/* �N���m���Ū� */
	}
	
	for(i=0;i<G.numVertexes;i++) /* �إ���� */
	{ 
		for(j=0;j<G.numVertexes;j++)
		{
			if (G.arc[i][j]==1)
			{
				e=(EdgeNode *)malloc(sizeof(EdgeNode));
				e->adjvex=j;					/* �F���Ǹ���j */                         
				e->next=(*GL)->adjList[i].firstedge;	/* �N�ثe���I�W�����V���`�I���е����ȵ�e */
				(*GL)->adjList[i].firstedge=e;		/* �N�ثe���I�����Ы��Ve */   
				(*GL)->adjList[j].in++;
				
			}
		}
	}
	
}

Boolean visited[MAXSIZE]; /* �s���ЧӪ��}�C */

/* �F�����`���u�����k��k */
void DFS(GraphAdjList GL, int i)
{
	EdgeNode *p;
 	visited[i] = TRUE;
 	printf("%c ",GL->adjList[i].data);/* �C�L���I,�]�i�H�䥦�ʧ@ */
	p = GL->adjList[i].firstedge;
	while(p)
	{
 		if(!visited[p->adjvex])
 			DFS(GL, p->adjvex);/* �אּ�s�����F�����I���k�I�s */
		p = p->next;
 	}
}

/* �F�����`���ˬd�ʧ@ */
void DFSTraverse(GraphAdjList GL)
{
	int i;
 	for(i = 0; i < GL->numVertexes; i++)
 		visited[i] = FALSE; /* �_�l�Ҧ����I���A���O���s���L���A */
	for(i = 0; i < GL->numVertexes; i++)
 		if(!visited[i]) /* �良�s���L�����I�I�sDFS,�Y�O�s�q��,�u�|����@�� */ 
			DFS(GL, i);
}

/* �F�����s���ˬd��k */
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
			printf("%c ",GL->adjList[i].data);/* �C�L���I,�]�i�H�䥦�ʧ@ */
			EnQueue(&Q,i);
			while(!QueueEmpty(Q))
			{
				DeQueue(&Q,&i);
				p = GL->adjList[i].firstedge;	/* ���ثe���I������쵲��C�Y���� */
				while(p)
				{
					if(!visited[p->adjvex])	/* �Y�����I���Q�s�� */
 					{
 						visited[p->adjvex]=TRUE;
						printf("%c ",GL->adjList[p->adjvex].data);
						EnQueue(&Q,p->adjvex);	/* �N�����I�[�J��C�C */
					}
					p = p->next;	/* ���Ы��V�U�@�ӾF���I */
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

	printf("\n�`���ˬd:");
	DFSTraverse(GL);
	printf("\n�s���ˬd:");
	BFSTraverse(GL);
	return 0;
}

