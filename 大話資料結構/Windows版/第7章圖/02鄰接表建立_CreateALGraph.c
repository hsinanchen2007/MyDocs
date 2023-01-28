#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* �����N��,���������� */

typedef int Status;	/* Status������ ��,���������������á��֧R*/
typedef char VertexType; /* ���������������� */
typedef int EdgeType; /* ������� ������������ */

typedef struct EdgeNode /* �����b */
{
	int adjvex;    /* Z����,�����������T�ӡ�/
	EdgeType info;		/* ����������,�N�������롼���� */
	struct EdgeNode *next; /* t��,���������X������/
}EdgeNode;

typedef struct VertexNode /* ��������/
{
	VertexType data; /* ����,����â����/
	EdgeNode *firstedge;/* �������� */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int numNodes,numEdges; /* �����Z���a������/
}GraphAdjList;

/* �����T��������*/
void  CreateALGraph(GraphAdjList *G)
{
	int i,j,k;
	EdgeNode *e;
	printf("��������������n");
	scanf("%d,%d",&G->numNodes,&G->numEdges); /* ��������������/
	for(i = 0;i < G->numNodes;i++) /* ����â���������� */
	{
		scanf(&G->adjList[i].data); 	/* ���������� */
		G->adjList[i].firstedge=NULL; 	/* ������������/
	}
	
	
	for(k = 0;k < G->numEdges;k++)/* ������*/
	{
		printf("������vi,vj)�����N����\n");
		scanf("%d,%d",&i,&j); /* ������vi,vj)�����N����*/
		e=(EdgeNode *)malloc(sizeof(EdgeNode)); /* ���������E���������b*/
		e->adjvex=j;					/* Z������j */                         
		e->next=G->adjList[i].firstedge;	/* �����������Z���K�����С� */
		G->adjList[i].firstedge=e;		/* ����������������e */               
		
		e=(EdgeNode *)malloc(sizeof(EdgeNode)); /* ���������E���������b*/
		e->adjvex=i;					/* Z������i */                         
		e->next=G->adjList[j].firstedge;	/* �����������Z���K�����С� */
		G->adjList[j].firstedge=e;		/* ����������������e */               
	}
}

int main(void)
{    
	GraphAdjList G;    
	CreateALGraph(&G);
	
	return 0;
}

