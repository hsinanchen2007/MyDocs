#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXEDGE 20
#define MAXVEX 14

typedef int Status;	/* Status是函數的型態,其值是函數結果狀態程式碼，如OK等 */

/* 鄰接矩陣結構 */
typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

/* 鄰接表結構****************** */
typedef struct EdgeNode /* 邊表節點  */
{
	int adjvex;    /* 鄰接點域，儲存該頂點對應的索引 */
	int weight;		/* 用於儲存權值，對於非網圖可以不需要 */
	struct EdgeNode *next; /* 鏈域，指向下一個鄰接點 */
}EdgeNode;

typedef struct VertexNode /* 頂點表節點 */
{
	int in;	/* 頂點內分支度 */
	int data; /* 頂點域，儲存頂點訊息 */
	EdgeNode *firstedge;/* 邊標頭指標 */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int numVertexes,numEdges; /* 圖中目前頂點數和邊數 */
}graphAdjList,*GraphAdjList;
/* **************************** */


void CreateMGraph(MGraph *G)/* 組件圖 */
{
	int i, j;
	
	/* printf("請輸入邊數和頂點數:"); */
	G->numEdges=MAXEDGE;
	G->numVertexes=MAXVEX;

	for (i = 0; i < G->numVertexes; i++)/* 起始化圖 */
	{
		G->vexs[i]=i;
	}

	for (i = 0; i < G->numVertexes; i++)/* 起始化圖 */
	{
		for ( j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j]=0;
		}
	}

	G->arc[0][4]=1;
	G->arc[0][5]=1; 
	G->arc[0][11]=1; 
	G->arc[1][2]=1; 
	G->arc[1][4]=1; 
	G->arc[1][8]=1; 
	G->arc[2][5]=1; 
	G->arc[2][6]=1;
	G->arc[2][9]=1;
	G->arc[3][2]=1; 
	G->arc[3][13]=1;
	G->arc[4][7]=1;
	G->arc[5][8]=1;
	G->arc[5][12]=1; 
	G->arc[6][5]=1; 
	G->arc[8][7]=1;
	G->arc[9][10]=1;
	G->arc[9][11]=1;
	G->arc[10][13]=1;
	G->arc[12][9]=1;

}

/* 利用鄰接矩陣建構鄰接表 */
void CreateALGraph(MGraph G,GraphAdjList *GL)
{
	int i,j;
	EdgeNode *e;

	*GL = (GraphAdjList)malloc(sizeof(graphAdjList));

	(*GL)->numVertexes=G.numVertexes;
	(*GL)->numEdges=G.numEdges;
	for(i= 0;i <G.numVertexes;i++) /* 讀入頂點訊息，建立頂點表 */
	{
		(*GL)->adjList[i].in=0;
		(*GL)->adjList[i].data=G.vexs[i];
		(*GL)->adjList[i].firstedge=NULL; 	/* 將邊表置為空表 */
	}
	
	for(i=0;i<G.numVertexes;i++) /* 建立邊表 */
	{ 
		for(j=0;j<G.numVertexes;j++)
		{
			if (G.arc[i][j]==1)
			{
				e=(EdgeNode *)malloc(sizeof(EdgeNode));
				e->adjvex=j;					/* 鄰接序號為j  */                        
				e->next=(*GL)->adjList[i].firstedge;	/* 將目前頂點上的指向的節點指標給予值給e */
				(*GL)->adjList[i].firstedge=e;		/* 將目前頂點的指標指向e  */  
				(*GL)->adjList[j].in++;
				
			}
		}
	}
	
}


/* 拓撲排序，若GL無回路，則輸出拓撲排序序列並傳回1，若有回路傳回0。 */
Status TopologicalSort(GraphAdjList GL)
{    
	EdgeNode *e;    
	int i,k,gettop;   
	int top=0;  /* 用於堆疊指標索引  */
	int count=0;/* 用於統計輸出頂點的個數  */    
	int *stack;	/* 建堆疊將內分支度為0的頂點入堆疊  */   
	stack=(int *)malloc(GL->numVertexes * sizeof(int) );    

	for(i = 0; i<GL->numVertexes; i++)                
		if(0 == GL->adjList[i].in) /* 將內分支度為0的頂點入堆疊 */         
			stack[++top]=i;    
	while(top!=0)    
	{        
		gettop=stack[top--];        
		printf("%d -> ",GL->adjList[gettop].data);        
		count++;        /* 輸出i號頂點，並計數 */        
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)        
		{            
			k=e->adjvex;            
			if( !(--GL->adjList[k].in) )  /* 將i號頂點的鄰接點的內分支度減1，若果減1後為0，則入堆疊 */                
				stack[++top]=k;        
		}
	}   
	printf("\n");   
	if(count < GL->numVertexes)        
		return ERROR;    
	else       
		return OK;
}


int main(void)
{    
	MGraph G;  
	GraphAdjList GL; 
	int result;   
	CreateMGraph(&G);
	CreateALGraph(G,&GL);
	result=TopologicalSort(GL);
	printf("result:%d",result);

	return 0;
}