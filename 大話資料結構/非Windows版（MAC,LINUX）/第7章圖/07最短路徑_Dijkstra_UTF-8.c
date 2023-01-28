#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXEDGE 20
#define MAXVEX 20
#define GRAPH_INFINITY 65535

typedef int Status;	/* Status是函數的型態,其值是函數結果狀態程式碼，如OK等 */ 


typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

typedef int Patharc[MAXVEX];    /* 用於儲存最短路徑索引的陣列 */
typedef int ShortPathTable[MAXVEX];/* 用於儲存到各點最短路徑的權值和 */

/* 組件圖 */
void CreateMGraph(MGraph *G)
{
	int i, j;

	/* printf("請輸入邊數和頂點數:"); */
	G->numEdges=16;
	G->numVertexes=9;

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
				G->arc[i][j] = G->arc[j][i] = GRAPH_INFINITY;
		}
	}

	G->arc[0][1]=1;
	G->arc[0][2]=5; 
	G->arc[1][2]=3; 
	G->arc[1][3]=7; 
	G->arc[1][4]=5; 

	G->arc[2][4]=1; 
	G->arc[2][5]=7; 
	G->arc[3][4]=2; 
	G->arc[3][6]=3; 
	G->arc[4][5]=3;

	G->arc[4][6]=6;
	G->arc[4][7]=9; 
	G->arc[5][7]=5; 
	G->arc[6][7]=2; 
	G->arc[6][8]=7;

	G->arc[7][8]=4;


	for(i = 0; i < G->numVertexes; i++)
	{
		for(j = i; j < G->numVertexes; j++)
		{
			G->arc[j][i] =G->arc[i][j];
		}
	}

}

/*  Dijkstra算法，求有向網G的v0頂點到其余頂點v的最短路徑P[v]及帶權長度D[v] */    
/*  P[v]的值為前驅頂點索引,D[v]表示v0到v的最短路徑長度和 */  
void ShortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D)
{    
	int v,w,k,min;    
	int final[MAXVEX];/* final[w]=1表示求得頂點v0至vw的最短路徑 */
	for(v=0; v<G.numVertexes; v++)    /* 起始化資料 */
	{        
		final[v] = 0;			/* 全部頂點起始化為不詳最短路徑狀態 */
		(*D)[v] = G.arc[v0][v];/* 將與v0點有連線的頂點加上權值 */
		(*P)[v] = -1;				/* 起始化路徑陣列P為-1  */       
	}

	(*D)[v0] = 0;  /* v0至v0路徑為0 */  
	final[v0] = 1;    /* v0至v0不需要求路徑 */        
	/* 開始主循環，每次求得v0到某個v頂點的最短路徑 */   
	for(v=1; v<G.numVertexes; v++)   
	{
		min=GRAPH_INFINITY;    /* 目前所知離v0頂點的最近距離 */        
		for(w=0; w<G.numVertexes; w++) /* 尋找離v0最近的頂點 */    
		{            
			if(!final[w] && (*D)[w]<min)             
			{                   
				k=w;                    
				min = (*D)[w];    /* w頂點離v0頂點更近 */            
			}        
		}        
		final[k] = 1;    /* 將目前找到的最近的頂點置為1 */
		for(w=0; w<G.numVertexes; w++) /* 修正目前最短路徑及距離 */
		{
			/* 若果經由v頂點的路徑比現在這條路徑的長度短的話 */
			if(!final[w] && (min+G.arc[k][w]<(*D)[w]))   
			{ /*  說明找到了更短的路徑，修改D[w]和P[w] */
				(*D)[w] = min + G.arc[k][w];  /* 修改目前路徑長度 */               
				(*P)[w]=k;        
			}       
		}   
	}
}

int main(void)
{   
	int i,j,v0;
	MGraph G;    
	Patharc P;    
	ShortPathTable D; /* 求某點到其余各點的最短路徑 */   
	v0=0;
	
	CreateMGraph(&G);
	
	ShortestPath_Dijkstra(G, v0, &P, &D);  

	printf("最短路徑倒序如下:\n");    
	for(i=1;i<G.numVertexes;++i)   
	{       
		printf("v%d - v%d : ",v0,i);
		j=i;
		while(P[j]!=-1)
		{
			printf("%d ",P[j]);
			j=P[j];
		}
		printf("\n");
	}    
	printf("\n源點到各頂點的最短路徑長度為:\n");  
	for(i=1;i<G.numVertexes;++i)        
		printf("v%d - v%d : %d \n",G.vexs[0],G.vexs[i],D[i]);     
	return 0;
}