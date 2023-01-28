#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXEDGE 30
#define MAXVEX 30
#define GRAPH_INFINITY 65535

typedef int Status;	/* Status是函數的型態,其值是函數結果狀態程式碼，如OK等 */  

int *etv,*ltv; /* 事件最早發生時間和最遲發生時間陣列 */
int *stack2;   /* 用於儲存拓撲序列的堆疊 */
int top2;	   /* 用於stack2的指標 */

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
	G->numEdges=13;
	G->numVertexes=10;

	for (i = 0; i < G->numVertexes; i++)/* 起始化圖 */
	{
		G->vexs[i]=i;
	}

	for (i = 0; i < G->numVertexes; i++)/* 起始化圖 */
	{
		for ( j = 0; j < G->numVertexes; j++)
		{
			if (i==j)
				G->arc[i][j]=0;
			else
				G->arc[i][j]=GRAPH_INFINITY;
		}
	}

	G->arc[0][1]=3;
	G->arc[0][2]=4; 
	G->arc[1][3]=5; 
	G->arc[1][4]=6; 
	G->arc[2][3]=8; 
	G->arc[2][5]=7; 
	G->arc[3][4]=3;
	G->arc[4][6]=9; 
	G->arc[4][7]=4;
	G->arc[5][7]=6; 
	G->arc[6][9]=2;
	G->arc[7][8]=5;
	G->arc[8][9]=3;

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
			if (G.arc[i][j]!=0 && G.arc[i][j]<GRAPH_INFINITY)
			{
				e=(EdgeNode *)malloc(sizeof(EdgeNode));
				e->adjvex=j;					/* 鄰接序號為j */   
				e->weight=G.arc[i][j];
				e->next=(*GL)->adjList[i].firstedge;	/* 將目前頂點上的指向的節點指標給予值給e */
				(*GL)->adjList[i].firstedge=e;		/* 將目前頂點的指標指向e  */  
				(*GL)->adjList[j].in++;
				
			}
		}
	}
	
}


/* 拓撲排序 */
Status TopologicalSort(GraphAdjList GL)
{    /* 若GL無回路，則輸出拓撲排序序列並傳回1，若有回路傳回0。 */    
	EdgeNode *e;    
	int i,k,gettop;   
	int top=0;  /* 用於堆疊指標索引  */
	int count=0;/* 用於統計輸出頂點的個數 */   
	int *stack;	/* 建堆疊將內分支度為0的頂點入堆疊  */   
	stack=(int *)malloc(GL->numVertexes * sizeof(int) );    
	for(i = 0; i<GL->numVertexes; i++)                
		if(0 == GL->adjList[i].in) /* 將內分支度為0的頂點入堆疊 */           
			stack[++top]=i;    

	top2=0;    
	etv=(int *)malloc(GL->numVertexes * sizeof(int) ); /* 事件最早發生時間陣列 */    
	for(i=0; i<GL->numVertexes; i++)        
		etv[i]=0;    /* 起始化 */
	stack2=(int *)malloc(GL->numVertexes * sizeof(int) );/* 起始化拓撲序列堆疊 */

	printf("TopologicalSort:\t");
	while(top!=0)    
	{        
		gettop=stack[top--];        
		printf("%d -> ",GL->adjList[gettop].data);        
		count++;        /* 輸出i號頂點，並計數 */ 

		stack2[++top2]=gettop;        /* 將出現的頂點序號存入拓撲序列的堆疊 */

		for(e = GL->adjList[gettop].firstedge; e; e = e->next)        
		{            
			k=e->adjvex;            
			if( !(--GL->adjList[k].in) )        /* 將i號頂點的鄰接點的內分支度減1，若果減1後為0，則入堆疊 */                
				stack[++top]=k; 

			if((etv[gettop] + e->weight)>etv[k])    /* 求各頂點事件的最早發生時間etv值 */                
				etv[k] = etv[gettop] + e->weight;
		}    
	}    
	printf("\n");   
	if(count < GL->numVertexes)        
		return ERROR;    
	else       
		return OK;
}

/* 求關鍵路徑,GL為有向網，輸出G的各項關鍵活動 */
void CriticalPath(GraphAdjList GL) 
{    
	EdgeNode *e;    
	int i,gettop,k,j;    
	int ete,lte;  /* 宣告活動最早發生時間和最遲發生時間變數 */        
	TopologicalSort(GL);   /* 求拓撲序列，計算陣列etv和stack2的值 */ 
	ltv=(int *)malloc(GL->numVertexes*sizeof(int));/* 事件最早發生時間陣列 */   
	for(i=0; i<GL->numVertexes; i++)        
		ltv[i]=etv[GL->numVertexes-1];    /* 起始化 */        
	
	printf("etv:\t");   
	for(i=0; i<GL->numVertexes; i++)        
		printf("%d -> ",etv[i]);    
	printf("\n"); 

	while(top2!=0)    /* 出堆疊是求ltv */    
	{        
		gettop=stack2[top2--];        
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)        /* 求各頂點事件的最遲發生時間ltv值 */        
		{            
			k=e->adjvex;            
			if(ltv[k] - e->weight < ltv[gettop])               
				ltv[gettop] = ltv[k] - e->weight;        
		}   
	}    
	
	printf("ltv:\t");   
	for(i=0; i<GL->numVertexes; i++)        
		printf("%d -> ",ltv[i]);    
	printf("\n"); 

	for(j=0; j<GL->numVertexes; j++)        /* 求ete,lte和關鍵活動 */        
	{            
		for(e = GL->adjList[j].firstedge; e; e = e->next)            
		{                
			k=e->adjvex;                
			ete = etv[j];        /* 活動最早發生時間 */                
			lte = ltv[k] - e->weight; /* 活動最遲發生時間 */               
			if(ete == lte)    /* 兩者相等即在關鍵路徑上 */                    
				printf("<v%d - v%d> length: %d \n",GL->adjList[j].data,GL->adjList[k].data,e->weight);
		}        
	}
}


int main(void)
{    
	MGraph G;    
	GraphAdjList GL;    
	CreateMGraph(&G);
	CreateALGraph(G,&GL);
	CriticalPath(GL);
	return 0;
}
