#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;	/* Status�O��ƪ����A,��ȬO��Ƶ��G���A�{���X�A�pOK�� */  
typedef int Boolean; /* Boolean�O�������A,��ȬOTRUE��FALSE */

typedef char VertexType; /* ���I���A���ѨϥΪ̩w�q */
typedef int EdgeType; /* ��W���v�ȫ��A���ѨϥΪ̩w�q */

#define MAXSIZE 9 /* �x�s�Ŷ��_�l���t�q */
#define MAXEDGE 15
#define MAXVEX 9

typedef struct
{
	VertexType vexs[MAXVEX]; /* ���I�� */
	EdgeType arc[MAXVEX][MAXVEX];/* �F���x�}�A�i�ݧ@��� */
	int numVertexes, numEdges; /* �Ϥ��ثe�����I�ƩM��� */ 
}MGraph;

/* �Ψ쪺��C���c�P���********************************** */

/* �`����C���s���x�s���c */
typedef struct
{
	int data[MAXSIZE];
	int front;    	/* �Y���� */
	int rear;		/* �����СA�Y��C���šA���V��C���������U�@�Ӧ�m */
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

/* �Y��C�����A�h���J����e��Q�s����C������ */
Status EnQueue(Queue *Q,int e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)	/* ��C�����P�_ */
		return ERROR;
	Q->data[Q->rear]=e;			/* �N����e�����ȵ���C�� */
	Q->rear=(Q->rear+1)%MAXSIZE;/* rear���ЦV�Ჾ�@��m�A */
								/* �Y��̫�h���}�C���� */
	return  OK;
}

/* �Y��C���šA�h����Q���C�������A��e�Ǧ^��� */
Status DeQueue(Queue *Q,int *e)
{
	if (Q->front == Q->rear)			/* ��C�Ū��P�_ */
		return ERROR;
	*e=Q->data[Q->front];				/* �N�C�����������ȵ�e */
	Q->front=(Q->front+1)%MAXSIZE;	/* front���ЦV�Ჾ�@��m�A */
									/* �Y��̫�h���}�C���� */
	return  OK;
}
/* ****************************************************** */


void CreateMGraph(MGraph *G)
{
	int i, j;

	G->numEdges=15;
	G->numVertexes=9;

	/* Ū�J���I�T���A�إ߳��I�� */
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
 
Boolean visited[MAXVEX]; /* �s���ЧӪ��}�C */

/* �F���x�}���`���u�����k��k */
void DFS(MGraph G, int i)
{
	int j;
 	visited[i] = TRUE;
 	printf("%c ", G.vexs[i]);/* �C�L���I�A�]�i�H�䥦�ʧ@ */
	for(j = 0; j < G.numVertexes; j++)
		if(G.arc[i][j] == 1 && !visited[j])
 			DFS(G, j);/* �אּ�s�����F�����I���k�I�s */
}

/* �F���x�}���`���ˬd�ʧ@ */
void DFSTraverse(MGraph G)
{
	int i;
 	for(i = 0; i < G.numVertexes; i++)
 		visited[i] = FALSE; /* �_�l�Ҧ����I���A���O���s���L���A */
	for(i = 0; i < G.numVertexes; i++)
 		if(!visited[i]) /* �良�s���L�����I�I�sDFS�A�Y�O�s�q�ϡA�u�|����@�� */ 
			DFS(G, i);
}

/* �F���x�}���s���ˬd��k */
void BFSTraverse(MGraph G)
{
	int i, j;
	Queue Q;
	for(i = 0; i < G.numVertexes; i++)
       	visited[i] = FALSE;
    InitQueue(&Q);		/* �_�l�Ƥ@���U�Ϊ���C */
    for(i = 0; i < G.numVertexes; i++)  /* ��C�@�ӳ��I���`�� */
    {
		if (!visited[i])	/* �Y�O���s���L�N�B�z */
		{
			visited[i]=TRUE;		/* �]�w�ثe���I�s���L */
			printf("%c ", G.vexs[i]);/* �C�L���I�A�]�i�H�䥦�ʧ@ */
			EnQueue(&Q,i);		/* �N�����I�[�J��C�C */
			while(!QueueEmpty(Q))	/* �Y�ثe��C������ */
			{
				DeQueue(&Q,&i);	/* �N��C�������X��C�A�����ȵ�i */
				for(j=0;j<G.numVertexes;j++) 
				{ 
					/* �P�_�䥦���I�Y�P�ثe���I�s�b��B���s���L  */
					if(G.arc[i][j] == 1 && !visited[j]) 
					{ 
 						visited[j]=TRUE;			/* �N��쪺�����I�Хܬ��w�s�� */
						printf("%c ", G.vexs[j]);	/* �C�L���I */
						EnQueue(&Q,j);				/* �N��쪺�����I�[�J��C�C  */
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
	printf("\n�`���ˬd�G");
	DFSTraverse(G);
	printf("\n�s���ˬd�G");
	BFSTraverse(G);
	return 0;
}

