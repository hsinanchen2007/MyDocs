#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* �����N����騡����� */
#define GRAPH_INFINITY 65535 /* ��655354�]�� */

typedef int Status;	/* Status������ ��,���������������á���OK�R*/
typedef char VertexType; /* ����������������  */
typedef int EdgeType; /* ������� ������������ */
typedef struct
{
	VertexType vexs[MAXVEX]; /* ���� */
	EdgeType arc[MAXVEX][MAXVEX];/* Z�������Y������/
	int numNodes, numEdges; /* �����Z������������*/
}MGraph;

/* �����������T���������� */
void CreateMGraph(MGraph *G)
{
	int i,j,k,w;
	printf("��������������n");
	scanf("%d,%d",&G->numNodes,&G->numEdges); /* ��������������/
	for(i = 0;i <G->numNodes;i++) /* ����â���������� */
		scanf(&G->vexs[i]);
	for(i = 0;i <G->numNodes;i++)
		for(j = 0;j <G->numNodes;j++)
			G->arc[i][j]=GRAPH_INFINITY;	/* Z����������*/
	for(k = 0;k <G->numEdges;k++) /* ����mEdges������bZ������/
	{
		printf("������vi,vj)���T�ӡ���������\n");
		scanf("%d,%d,%d",&i,&j,&w); /* ������vi,vj)�����h*/
		G->arc[i][j]=w; 
		G->arc[j][i]= G->arc[i][j]; /* �������Q������������*/
	}
}

int main(void)
{    
	MGraph G;    
	CreateMGraph(&G);
	
	return 0;
}
