#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;	/* Status������ ��,���������������á���OK�R*/  
typedef int Boolean; /* Boolean��������,������TRUE��ALSE */

typedef char VertexType; /* ���������������� */
typedef int EdgeType; /* ������� ������������ */

#define MAXSIZE 9 /* ��������æ�� */
#define MAXEDGE 15
#define MAXVEX 9

typedef struct
{
	VertexType vexs[MAXVEX]; /* ���� */
	EdgeType arc[MAXVEX][MAXVEX];/* Z�������Y������/
	int numVertexes, numEdges; /* �����Z������������/ 
}MGraph;

/* ������������������******************************** */

/* ������������������*/
typedef struct
{
	int data[MAXSIZE];
	int front;    	/* ������ */
	int rear;		/* �]��������P���������֡��t���T�����f�� */
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

/* ���֡�������������e��Q���⡼�t�� */
Status EnQueue(Queue *Q,int e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)	/* �֡������]*/
		return ERROR;
	Q->data[Q->rear]=e;			/* ����e���`����/
	Q->rear=(Q->rear+1)%MAXSIZE;/* rear����������������*/
								/* ���k�������ʡ�����*/
	return  OK;
}

/* ���֡��������������F����a�_���� */
Status DeQueue(Queue *Q,int *e)
{
	if (Q->front == Q->rear)			/* �֡���������*/
		return ERROR;
	*e=Q->data[Q->front];				/* �����F�����`e */
	Q->front=(Q->front+1)%MAXSIZE;	/* front����������������*/
									/* ���k�������ʡ�����*/
	return  OK;
}
/* ****************************************************** */


void CreateMGraph(MGraph *G)
{
	int i, j;

	G->numEdges=15;
	G->numVertexes=9;

	/* ����â������������/
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
 
Boolean visited[MAXVEX]; /* �{������ */

/* Z���������Ρ��������Y*/
void DFS(MGraph G, int i)
{
	int j;
 	visited[i] = TRUE;
 	printf("%c ", G.vexs[i]);/* �����B���롼������/
	for(j = 0; j < G.numVertexes; j++)
		if(G.arc[i][j] == 1 && !visited[j])
 			DFS(G, j);/* �G�����T�����N���ء� */
}

/* Z����������������/
void DFSTraverse(MGraph G)
{
	int i;
 	for(i = 0; i < G.numVertexes; i++)
 		visited[i] = FALSE; /* �������������~���������� */
	for(i = 0; i < G.numVertexes; i++)
 		if(!visited[i]) /* �G�����졼�N�qAFS����l����������������*/ 
			DFS(G, i);
}

/* Z�������⡼�����Y*/
void BFSTraverse(MGraph G)
{
	int i, j;
	Queue Q;
	for(i = 0; i < G.numVertexes; i++)
       	visited[i] = FALSE;
    InitQueue(&Q);		/* �������W���⡼��*/
    for(i = 0; i < G.numVertexes; i++)  /* �֊����N������*/
    {
		if (!visited[i])	/* �����_�{��������/
		{
			visited[i]=TRUE;		/* �����Z����I����/
			printf("%c ", G.vexs[i]);/* �����B���롼������/
			EnQueue(&Q,i);		/* �����N���֡�*/
			while(!QueueEmpty(Q))	/* ���Z��P���� */
			{
				DeQueue(&Q,&i);	/* �������������������� */
				for(j=0;j<G.numVertexes;j++) 
				{ 
					/* ���}�����W���Z���_������������ */
					if(G.arc[i][j] == 1 && !visited[j]) 
					{ 
 						visited[j]=TRUE;			/* ���������N�������{��*/
						printf("%c ", G.vexs[j]);	/* �����b*/
						EnQueue(&Q,j);				/* ���������N���֡� */
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
	printf("\n��������);
	DFSTraverse(G);
	printf("\n�⡼����);
	BFSTraverse(G);
	return 0;
}

