#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* �̤j���I�ơA���ѨϥΪ̩w�q */
#define GRAPH_INFINITY 65535 /* ��65535�ӥN��� */

typedef int Status;	/* Status�O��ƪ����A,��ȬO��Ƶ��G���A�{���X�A�pOK�� */
typedef char VertexType; /* ���I���A���ѨϥΪ̩w�q  */
typedef int EdgeType; /* ��W���v�ȫ��A���ѨϥΪ̩w�q */
typedef struct
{
	VertexType vexs[MAXVEX]; /* ���I�� */
	EdgeType arc[MAXVEX][MAXVEX];/* �F���x�}�A�i�ݧ@��� */
	int numNodes, numEdges; /* �Ϥ��ثe�����I�ƩM���  */
}MGraph;

/* �إߵL�V���Ϫ��F���x�}��� */
void CreateMGraph(MGraph *G)
{
	int i,j,k,w;
	printf("��J���I�ƩM���:\n");
	scanf("%d,%d",&G->numNodes,&G->numEdges); /* ��J���I�ƩM��� */
	for(i = 0;i <G->numNodes;i++) /* Ū�J���I�T��,�إ߳��I�� */
		scanf(&G->vexs[i]);
	for(i = 0;i <G->numNodes;i++)
		for(j = 0;j <G->numNodes;j++)
			G->arc[i][j]=GRAPH_INFINITY;	/* �F���x�}�_�l�� */
	for(k = 0;k <G->numEdges;k++) /* Ū�JnumEdges����A�إ߾F���x�} */
	{
		printf("��J��(vi,vj)�W������i�A����j�M�vw:\n");
		scanf("%d,%d,%d",&i,&j,&w); /* ��J��(vi,vj)�W���vw */
		G->arc[i][j]=w; 
		G->arc[j][i]= G->arc[i][j]; /* �]���O�L�V�ϡA�x�}��� */
	}
}

int main(void)
{    
	MGraph G;    
	CreateMGraph(&G);
	
	return 0;
}
