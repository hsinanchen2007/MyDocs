#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* 最大頂點數，應由使用者定義 */
#define GRAPH_INFINITY 65535 /* 用65535來代表∞ */

typedef int Status;	/* Status是函數的型態,其值是函數結果狀態程式碼，如OK等 */
typedef char VertexType; /* 頂點型態應由使用者定義  */
typedef int EdgeType; /* 邊上的權值型態應由使用者定義 */
typedef struct
{
	VertexType vexs[MAXVEX]; /* 頂點表 */
	EdgeType arc[MAXVEX][MAXVEX];/* 鄰接矩陣，可看作邊表 */
	int numNodes, numEdges; /* 圖中目前的頂點數和邊數  */
}MGraph;

/* 建立無向網圖的鄰接矩陣表示 */
void CreateMGraph(MGraph *G)
{
	int i,j,k,w;
	printf("輸入頂點數和邊數:\n");
	scanf("%d,%d",&G->numNodes,&G->numEdges); /* 輸入頂點數和邊數 */
	for(i = 0;i <G->numNodes;i++) /* 讀入頂點訊息,建立頂點表 */
		scanf(&G->vexs[i]);
	for(i = 0;i <G->numNodes;i++)
		for(j = 0;j <G->numNodes;j++)
			G->arc[i][j]=GRAPH_INFINITY;	/* 鄰接矩陣起始化 */
	for(k = 0;k <G->numEdges;k++) /* 讀入numEdges條邊，建立鄰接矩陣 */
	{
		printf("輸入邊(vi,vj)上的索引i，索引j和權w:\n");
		scanf("%d,%d,%d",&i,&j,&w); /* 輸入邊(vi,vj)上的權w */
		G->arc[i][j]=w; 
		G->arc[j][i]= G->arc[i][j]; /* 因為是無向圖，矩陣對稱 */
	}
}

int main(void)
{    
	MGraph G;    
	CreateMGraph(&G);
	
	return 0;
}
