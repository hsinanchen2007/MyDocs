#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* �̤j���I��,���ѨϥΪ̩w�q */

typedef int Status;	/* Status�O��ƪ����A,��ȬO��Ƶ��G���A�{���X,�pOK�� */
typedef char VertexType; /* ���I���A���ѨϥΪ̩w�q */
typedef int EdgeType; /* ��W���v�ȫ��A���ѨϥΪ̩w�q */

typedef struct EdgeNode /* ���`�I  */
{
	int adjvex;    /* �F���I��,�x�s�ӳ��I���������� */
	EdgeType info;		/* �Ω��x�s�v��,���D���ϥi�H���ݭn */
	struct EdgeNode *next; /* ���,���V�U�@�ӾF���I */
}EdgeNode;

typedef struct VertexNode /* ���I��`�I */
{
	VertexType data; /* ���I��,�x�s���I�T�� */
	EdgeNode *firstedge;/* ����Y���� */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int numNodes,numEdges; /* �Ϥ��ثe���I�ƩM��� */
}GraphAdjList;

/* �إ߹Ϫ��F�����c */
void  CreateALGraph(GraphAdjList *G)
{
	int i,j,k;
	EdgeNode *e;
	printf("��J���I�ƩM���:\n");
	scanf("%d,%d",&G->numNodes,&G->numEdges); /* ��J���I�ƩM��� */
	for(i = 0;i < G->numNodes;i++) /* Ū�J���I�T��,�إ߳��I�� */
	{
		scanf(&G->adjList[i].data); 	/* ��J���I�T�� */
		G->adjList[i].firstedge=NULL; 	/* �N���m���Ū� */
	}
	
	
	for(k = 0;k < G->numEdges;k++)/* �إ���� */
	{
		printf("��J��(vi,vj)�W�����I�Ǹ�:\n");
		scanf("%d,%d",&i,&j); /* ��J��(vi,vj)�W�����I�Ǹ� */
		e=(EdgeNode *)malloc(sizeof(EdgeNode)); /* �V�O����ӽЪŶ�,�������`�I */
		e->adjvex=j;					/* �F���Ǹ���j */                         
		e->next=G->adjList[i].firstedge;	/* �Ne�����Ы��V�ثe���I�W���V���`�I */
		G->adjList[i].firstedge=e;		/* �N�ثe���I�����Ы��Ve */               
		
		e=(EdgeNode *)malloc(sizeof(EdgeNode)); /* �V�O����ӽЪŶ�,�������`�I */
		e->adjvex=i;					/* �F���Ǹ���i */                         
		e->next=G->adjList[j].firstedge;	/* �Ne�����Ы��V�ثe���I�W���V���`�I */
		G->adjList[j].firstedge=e;		/* �N�ثe���I�����Ы��Ve */               
	}
}

int main(void)
{    
	GraphAdjList G;    
	CreateALGraph(&G);
	
	return 0;
}

