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
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

void CreateMGraph(MGraph *G)/* 組件圖 */
{
	int i, j;

	/* printf("請輸入邊數和頂點數:"); */
	G->numEdges=15;
	G->numVertexes=9;

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

	G->arc[0][1]=10;
	G->arc[0][5]=11; 
	G->arc[1][2]=18; 
	G->arc[1][8]=12; 
	G->arc[1][6]=16; 
	G->arc[2][8]=8; 
	G->arc[2][3]=22; 
	G->arc[3][8]=21; 
	G->arc[3][6]=24; 
	G->arc[3][7]=16;
	G->arc[3][4]=20;
	G->arc[4][7]=7; 
	G->arc[4][5]=26; 
	G->arc[5][6]=17; 
	G->arc[6][7]=19; 

	for(i = 0; i < G->numVertexes; i++)
	{
		for(j = i; j < G->numVertexes; j++)
		{
			G->arc[j][i] =G->arc[i][j];
		}
	}

}

/* Prim算法產生最小產生樹  */
void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];		/* 儲存關聯頂點索引 */
	int lowcost[MAXVEX];	/* 儲存關聯頂點間邊的權值 */
	lowcost[0] = 0;/* 起始化第一個權值為0，即v0加入產生樹 */
			/* lowcost的值為0，在這裡就是此索引的頂點已經加入產生樹 */
	adjvex[0] = 0;			/* 起始化第一個頂點索引為0 */
	for(i = 1; i < G.numVertexes; i++)	/* 循環除索引為0外的全部頂點 */
	{
		lowcost[i] = G.arc[0][i];	/* 將v0頂點與之有邊的權值存入陣列 */
		adjvex[i] = 0;					/* 起始化都為v0的索引 */
	}
	for(i = 1; i < G.numVertexes; i++)
	{
		min = GRAPH_INFINITY;	/* 起始化最小權值為∞， */
						/* 通常設定為不可能的大數字如32767、65535等 */
		j = 1;k = 0;
		while(j < G.numVertexes)	/* 循環全部頂點 */
		{
			if(lowcost[j]!=0 && lowcost[j] < min)/* 若果權值不為0且權值小於min */
			{	
				min = lowcost[j];	/* 則讓目前權值成為最小值 */
				k = j;			/* 將目前最小值的索引存入k */
			}
			j++;
		}
		printf("(%d, %d)\n", adjvex[k], k);/* 列印目前頂點邊中權值最小的邊 */
		lowcost[k] = 0;/* 將目前頂點的權值設定為0,表示此頂點已經完成工作 */
		for(j = 1; j < G.numVertexes; j++)	/* 循環所有頂點 */
		{
			if(lowcost[j]!=0 && G.arc[k][j] < lowcost[j]) 
			{/* 若果索引為k頂點各邊權值小於此前這些頂點未被加入產生樹權值 */
				lowcost[j] = G.arc[k][j];/* 將較小的權值存入lowcost對應位置 */
				adjvex[j] = k;				/* 將索引為k的頂點存入adjvex */
			}
		}
	}
}

int main(void)
{
	MGraph G;
	CreateMGraph(&G);
	MiniSpanTree_Prim(G);
  
	return 0;
 
}