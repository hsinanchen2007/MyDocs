#include "stdio.h"    
#include "stdlib.h"   

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

typedef int Patharc[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];

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

/* Floyd算法，求網圖G中各頂點v到其余頂點w的最短路徑P[v][w]及帶權長度D[v][w]。 */    
void ShortestPath_Floyd(MGraph G, Patharc *P, ShortPathTable *D)
{    
	int v,w,k;    
	for(v=0; v<G.numVertexes; ++v) /* 起始化D與P */  
	{        
		for(w=0; w<G.numVertexes; ++w)  
		{
			(*D)[v][w]=G.arc[v][w];	/* D[v][w]值即為對應點間的權值 */
			(*P)[v][w]=w;				/* 起始化P */
		}
	}
	for(k=0; k<G.numVertexes; ++k)   
	{
		for(v=0; v<G.numVertexes; ++v)  
		{        
			for(w=0; w<G.numVertexes; ++w)    
			{
				if ((*D)[v][w]>(*D)[v][k]+(*D)[k][w])
				{/* 若果經由索引為k頂點路徑比原兩點間路徑更短 */
					(*D)[v][w]=(*D)[v][k]+(*D)[k][w];/* 將目前兩點間權值設為更小的一個 */
					(*P)[v][w]=(*P)[v][k];/* 路徑設定為經由索引為k的頂點 */
				}
			}
		}
	}
}

int main(void)
{    
	int v,w,k;  
	MGraph G;    
	
	Patharc P;    
	ShortPathTable D; /* 求某點到其余各點的最短路徑 */   
	
	CreateMGraph(&G);
	
	ShortestPath_Floyd(G,&P,&D);  

	printf("各頂點間最短路徑如下:\n");    
	for(v=0; v<G.numVertexes; ++v)   
	{        
		for(w=v+1; w<G.numVertexes; w++)  
		{
			printf("v%d-v%d weight: %d ",v,w,D[v][w]);
			k=P[v][w];				/* 獲得第一個路徑頂點索引 */
			printf(" path: %d",v);	/* 列印源點 */
			while(k!=w)				/* 若果路徑頂點索引不是終點 */
			{
				printf(" -> %d",k);	/* 列印路徑頂點 */
				k=P[k][w];			/* 獲得下一個路徑頂點索引 */
			}
			printf(" -> %d\n",w);	/* 列印終點 */
		}
		printf("\n");
	}

	printf("最短路徑D\n");
	for(v=0; v<G.numVertexes; ++v)  
	{        
		for(w=0; w<G.numVertexes; ++w)    
		{
			printf("%d\t",D[v][w]);
		}
		printf("\n");
	}
	printf("最短路徑P\n");
	for(v=0; v<G.numVertexes; ++v)  
	{        
		for(w=0; w<G.numVertexes; ++w)    
		{
			printf("%d ",P[v][w]);
		}
		printf("\n");
	}

	return 0;
}
