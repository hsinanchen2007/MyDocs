#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* 最大頂點數,應由使用者定義 */

typedef int Status;	/* Status是函數的型態,其值是函數結果狀態程式碼,如OK等 */
typedef char VertexType; /* 頂點型態應由使用者定義 */
typedef int EdgeType; /* 邊上的權值型態應由使用者定義 */

typedef struct EdgeNode /* 邊表節點  */
{
	int adjvex;    /* 鄰接點域,儲存該頂點對應的索引 */
	EdgeType info;		/* 用於儲存權值,對於非網圖可以不需要 */
	struct EdgeNode *next; /* 鏈域,指向下一個鄰接點 */
}EdgeNode;

typedef struct VertexNode /* 頂點表節點 */
{
	VertexType data; /* 頂點域,儲存頂點訊息 */
	EdgeNode *firstedge;/* 邊標頭指標 */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int numNodes,numEdges; /* 圖中目前頂點數和邊數 */
}GraphAdjList;

/* 建立圖的鄰接表結構 */
void  CreateALGraph(GraphAdjList *G)
{
	int i,j,k;
	EdgeNode *e;
	printf("輸入頂點數和邊數:\n");
	scanf("%d,%d",&G->numNodes,&G->numEdges); /* 輸入頂點數和邊數 */
	for(i = 0;i < G->numNodes;i++) /* 讀入頂點訊息,建立頂點表 */
	{
		scanf(&G->adjList[i].data); 	/* 輸入頂點訊息 */
		G->adjList[i].firstedge=NULL; 	/* 將邊表置為空表 */
	}
	
	
	for(k = 0;k < G->numEdges;k++)/* 建立邊表 */
	{
		printf("輸入邊(vi,vj)上的頂點序號:\n");
		scanf("%d,%d",&i,&j); /* 輸入邊(vi,vj)上的頂點序號 */
		e=(EdgeNode *)malloc(sizeof(EdgeNode)); /* 向記憶體申請空間,產生邊表節點 */
		e->adjvex=j;					/* 鄰接序號為j */                         
		e->next=G->adjList[i].firstedge;	/* 將e的指標指向目前頂點上指向的節點 */
		G->adjList[i].firstedge=e;		/* 將目前頂點的指標指向e */               
		
		e=(EdgeNode *)malloc(sizeof(EdgeNode)); /* 向記憶體申請空間,產生邊表節點 */
		e->adjvex=i;					/* 鄰接序號為i */                         
		e->next=G->adjList[j].firstedge;	/* 將e的指標指向目前頂點上指向的節點 */
		G->adjList[j].firstedge=e;		/* 將目前頂點的指標指向e */               
	}
}

int main(void)
{    
	GraphAdjList G;    
	CreateALGraph(&G);
	
	return 0;
}

