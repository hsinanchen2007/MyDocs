#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;	/* Status是函數的型態,其值是函數結果狀態程式碼，如OK等 */  
typedef int Boolean; /* Boolean是布爾型態,其值是TRUE或FALSE */

typedef char VertexType; /* 頂點型態應由使用者定義 */
typedef int EdgeType; /* 邊上的權值型態應由使用者定義 */

#define MAXSIZE 9 /* 儲存空間起始分配量 */
#define MAXEDGE 15
#define MAXVEX 9

typedef struct
{
	VertexType vexs[MAXVEX]; /* 頂點表 */
	EdgeType arc[MAXVEX][MAXVEX];/* 鄰接矩陣，可看作邊表 */
	int numVertexes, numEdges; /* 圖中目前的頂點數和邊數 */ 
}MGraph;

/* 用到的佇列結構與函數********************************** */

/* 循環佇列的連序儲存結構 */
typedef struct
{
	int data[MAXSIZE];
	int front;    	/* 頭指標 */
	int rear;		/* 尾指標，若佇列不空，指向佇列尾元素的下一個位置 */
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

/* 若佇列未滿，則插入元素e為Q新的佇列尾元素 */
Status EnQueue(Queue *Q,int e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)	/* 佇列滿的判斷 */
		return ERROR;
	Q->data[Q->rear]=e;			/* 將元素e給予值給佇列尾 */
	Q->rear=(Q->rear+1)%MAXSIZE;/* rear指標向後移一位置， */
								/* 若到最後則轉到陣列頁首 */
	return  OK;
}

/* 若佇列不空，則移除Q中列首元素，用e傳回其值 */
Status DeQueue(Queue *Q,int *e)
{
	if (Q->front == Q->rear)			/* 佇列空的判斷 */
		return ERROR;
	*e=Q->data[Q->front];				/* 將列首元素給予值給e */
	Q->front=(Q->front+1)%MAXSIZE;	/* front指標向後移一位置， */
									/* 若到最後則轉到陣列頁首 */
	return  OK;
}
/* ****************************************************** */


void CreateMGraph(MGraph *G)
{
	int i, j;

	G->numEdges=15;
	G->numVertexes=9;

	/* 讀入頂點訊息，建立頂點表 */
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
 
Boolean visited[MAXVEX]; /* 存取標志的陣列 */

/* 鄰接矩陣的深度優先遞歸算法 */
void DFS(MGraph G, int i)
{
	int j;
 	visited[i] = TRUE;
 	printf("%c ", G.vexs[i]);/* 列印頂點，也可以其它動作 */
	for(j = 0; j < G.numVertexes; j++)
		if(G.arc[i][j] == 1 && !visited[j])
 			DFS(G, j);/* 對為存取的鄰接頂點遞歸呼叫 */
}

/* 鄰接矩陣的深度檢查動作 */
void DFSTraverse(MGraph G)
{
	int i;
 	for(i = 0; i < G.numVertexes; i++)
 		visited[i] = FALSE; /* 起始所有頂點狀態都是未存取過狀態 */
	for(i = 0; i < G.numVertexes; i++)
 		if(!visited[i]) /* 對未存取過的頂點呼叫DFS，若是連通圖，只會執行一次 */ 
			DFS(G, i);
}

/* 鄰接矩陣的廣度檢查算法 */
void BFSTraverse(MGraph G)
{
	int i, j;
	Queue Q;
	for(i = 0; i < G.numVertexes; i++)
       	visited[i] = FALSE;
    InitQueue(&Q);		/* 起始化一輔助用的佇列 */
    for(i = 0; i < G.numVertexes; i++)  /* 對每一個頂點做循環 */
    {
		if (!visited[i])	/* 若是未存取過就處理 */
		{
			visited[i]=TRUE;		/* 設定目前頂點存取過 */
			printf("%c ", G.vexs[i]);/* 列印頂點，也可以其它動作 */
			EnQueue(&Q,i);		/* 將此頂點加入佇列列 */
			while(!QueueEmpty(Q))	/* 若目前佇列不為空 */
			{
				DeQueue(&Q,&i);	/* 將佇列首元素出佇列，給予值給i */
				for(j=0;j<G.numVertexes;j++) 
				{ 
					/* 判斷其它頂點若與目前頂點存在邊且未存取過  */
					if(G.arc[i][j] == 1 && !visited[j]) 
					{ 
 						visited[j]=TRUE;			/* 將找到的此頂點標示為已存取 */
						printf("%c ", G.vexs[j]);	/* 列印頂點 */
						EnQueue(&Q,j);				/* 將找到的此頂點加入佇列列  */
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
	printf("\n深度檢查：");
	DFSTraverse(G);
	printf("\n廣度檢查：");
	BFSTraverse(G);
	return 0;
}

