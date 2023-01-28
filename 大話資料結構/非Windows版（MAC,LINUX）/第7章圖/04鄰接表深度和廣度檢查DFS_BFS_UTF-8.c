#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 9 /* 儲存空間起始分配量 */
#define MAXEDGE 15
#define MAXVEX 9

typedef int Status;	/* Status是函數的型態,其值是函數結果狀態程式碼,如OK等 */
typedef int Boolean; /* Boolean是布爾型態,其值是TRUE或FALSE */

typedef char VertexType; /* 頂點型態應由使用者定義 */   
typedef int EdgeType; /* 邊上的權值型態應由使用者定義 */

/* 鄰接矩陣結構 */
typedef struct
{
	VertexType vexs[MAXVEX]; /* 頂點表 */
	EdgeType arc[MAXVEX][MAXVEX];/* 鄰接矩陣,可看作邊表 */
	int numVertexes, numEdges; /* 圖中目前的頂點數和邊數 */ 
}MGraph;

/* 鄰接表結構****************** */
typedef struct EdgeNode /* 邊表節點 */ 
{
	int adjvex;    /* 鄰接點域,儲存該頂點對應的索引 */
	int weight;		/* 用於儲存權值,對於非網圖可以不需要 */
	struct EdgeNode *next; /* 鏈域,指向下一個鄰接點 */ 
}EdgeNode;

typedef struct VertexNode /* 頂點表節點 */ 
{
	int in;	/* 頂點內分支度 */
	char data; /* 頂點域,儲存頂點訊息 */
	EdgeNode *firstedge;/* 邊標頭指標 */   
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int numVertexes,numEdges; /* 圖中目前頂點數和邊數 */
}graphAdjList,*GraphAdjList;
/* **************************** */

/* 用到的佇列結構與函數********************************** */
/* 循環佇列的連序儲存結構 */
typedef struct
{
	int data[MAXSIZE];
	int front;    	/* 頭指標 */
	int rear;		/* 尾指標,若佇列不空,指向佇列尾元素的下一個位置 */
}Queue;

/* 起始化一個空佇列Q */
Status InitQueue(Queue *Q)
{
	Q->front=0;
	Q->rear=0;
	return  OK;
}

/* 若佇列Q為空佇列,則傳回TRUE,否則傳回FALSE */
Status QueueEmpty(Queue Q)
{ 
	if(Q.front==Q.rear) /* 佇列空的標志 */
		return TRUE;
	else
		return FALSE;
}

/* 若佇列未滿,則插入元素e為Q新的佇列尾元素 */
Status EnQueue(Queue *Q,int e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)	/* 佇列滿的判斷 */
		return ERROR;
	Q->data[Q->rear]=e;			/* 將元素e給予值給佇列尾 */
	Q->rear=(Q->rear+1)%MAXSIZE;/* rear指標向後移一位置, */
								/* 若到最後則轉到陣列頁首 */
	return  OK;
}

/* 若佇列不空,則移除Q中列首元素,用e傳回其值 */
Status DeQueue(Queue *Q,int *e)
{
	if (Q->front == Q->rear)			/* 佇列空的判斷 */
		return ERROR;
	*e=Q->data[Q->front];				/* 將列首元素給予值給e */
	Q->front=(Q->front+1)%MAXSIZE;	/* front指標向後移一位置, */
									/* 若到最後則轉到陣列頁首 */
	return  OK;
}
/* ****************************************************** */



void CreateMGraph(MGraph *G)
{
	int i, j;

	G->numEdges=15;
	G->numVertexes=9;

	/* 讀入頂點訊息,建立頂點表 */ 
	G->vexs[0]='A';
	G->vexs[1]='B';
	G->vexs[2]='C';
	G->vexs[3]='D';
	G->vexs[4]='E';
	G->vexs[5]='F';
	G->vexs[6]='G';
	G->vexs[7]='H';
	G->vexs[8]='I';


	for (i = 0; i < G->numVertexes; i++)/* 起始化圖 */
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
 
/* 利用鄰接矩陣建構鄰接表 */
void CreateALGraph(MGraph G,GraphAdjList *GL)
{
	int i,j;
	EdgeNode *e;

	*GL = (GraphAdjList)malloc(sizeof(graphAdjList));

	(*GL)->numVertexes=G.numVertexes;
	(*GL)->numEdges=G.numEdges;
	for(i= 0;i <G.numVertexes;i++) /* 讀入頂點訊息,建立頂點表 */   
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
				e->adjvex=j;					/* 鄰接序號為j */                         
				e->next=(*GL)->adjList[i].firstedge;	/* 將目前頂點上的指向的節點指標給予值給e */
				(*GL)->adjList[i].firstedge=e;		/* 將目前頂點的指標指向e */   
				(*GL)->adjList[j].in++;
				
			}
		}
	}
	
}

Boolean visited[MAXSIZE]; /* 存取標志的陣列 */

/* 鄰接表的深度優先遞歸算法 */
void DFS(GraphAdjList GL, int i)
{
	EdgeNode *p;
 	visited[i] = TRUE;
 	printf("%c ",GL->adjList[i].data);/* 列印頂點,也可以其它動作 */
	p = GL->adjList[i].firstedge;
	while(p)
	{
 		if(!visited[p->adjvex])
 			DFS(GL, p->adjvex);/* 對為存取的鄰接頂點遞歸呼叫 */
		p = p->next;
 	}
}

/* 鄰接表的深度檢查動作 */
void DFSTraverse(GraphAdjList GL)
{
	int i;
 	for(i = 0; i < GL->numVertexes; i++)
 		visited[i] = FALSE; /* 起始所有頂點狀態都是未存取過狀態 */
	for(i = 0; i < GL->numVertexes; i++)
 		if(!visited[i]) /* 對未存取過的頂點呼叫DFS,若是連通圖,只會執行一次 */ 
			DFS(GL, i);
}

/* 鄰接表的廣度檢查算法 */
void BFSTraverse(GraphAdjList GL)
{
	int i;
    EdgeNode *p;
	Queue Q;
	for(i = 0; i < GL->numVertexes; i++)
       	visited[i] = FALSE;
    InitQueue(&Q);
   	for(i = 0; i < GL->numVertexes; i++)
   	{
		if (!visited[i])
		{
			visited[i]=TRUE;
			printf("%c ",GL->adjList[i].data);/* 列印頂點,也可以其它動作 */
			EnQueue(&Q,i);
			while(!QueueEmpty(Q))
			{
				DeQueue(&Q,&i);
				p = GL->adjList[i].firstedge;	/* 找到目前頂點的邊表鏈結串列頭指標 */
				while(p)
				{
					if(!visited[p->adjvex])	/* 若此頂點未被存取 */
 					{
 						visited[p->adjvex]=TRUE;
						printf("%c ",GL->adjList[p->adjvex].data);
						EnQueue(&Q,p->adjvex);	/* 將此頂點加入佇列列 */
					}
					p = p->next;	/* 指標指向下一個鄰接點 */
				}
			}
		}
	}
}

int main(void)
{    
	MGraph G;  
	GraphAdjList GL;    
	CreateMGraph(&G);
	CreateALGraph(G,&GL);

	printf("\n深度檢查:");
	DFSTraverse(GL);
	printf("\n廣度檢查:");
	BFSTraverse(GL);
	return 0;
}

