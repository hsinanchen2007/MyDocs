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

typedef int Status;	/* Status〖〖〖 〖,〖〖〖〖〖〖〖睹〖〖OK*/ 


typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

typedef int Patharc[MAXVEX];    /* 〖〖〖〖本没〖〖〖〖 */
typedef int ShortPathTable[MAXVEX];/* 〖〖〖〖筋〖本没畸皙〖*/

/* 芇幫 */
void CreateMGraph(MGraph *G)
{
	int i, j;

	/* printf("〖〖〖〖〖伐〖:"); */
	G->numEdges=16;
	G->numVertexes=9;

	for (i = 0; i < G->numVertexes; i++)/* 〖〖〖 */
	{
		G->vexs[i]=i;
	}

	for (i = 0; i < G->numVertexes; i++)/* 〖〖〖 */
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

/*  Dijkstra〖縬〖〖〖〖G拟0伐〖〖〖伐〖〖烴烺[v]〖〖〖[v] */    
/*  P[v]菏岫〖〖伐〖〖D[v]〖焤收桷烴焨〖〖*/  
void ShortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D)
{    
	int v,w,k,min;    
	int final[MAXVEX];/* final[w]=1〖齖潇軳v0〖vw桷烴焍*/
	for(v=0; v<G.numVertexes; v++)    /* 〖〖〖旸*/
	{        
		final[v] = 0;			/* 〖〖軳〖〖〖〖〖本没〖〖 */
		(*D)[v] = G.arc[v0][v];/* 〖〖溃〖〖拟軳〖皙 */
		(*P)[v] = -1;				/* 〖〖烲〖P〖-1  */       
	}

	(*D)[v0] = 0;  /* v0〖v0烶〖*/  
	final[v0] = 1;    /* v0〖v0〖愫〖焍*/        
	/* 〖〖〖〖〖〖〖v0峋〖v伐〖〖本没 */   
	for(v=1; v<G.numVertexes; v++)   
	{
		min=GRAPH_INFINITY;    /* 蘘〖〖+v0伐〖〖〖+ */        
		for(w=0; w<G.numVertexes; w++) /* 〖〖+v0〖〖〖軳 */    
		{            
			if(!final[w] && (*D)[w]<min)             
			{                   
				k=w;                    
				min = (*D)[w];    /* w伐〖v0伐〖〖*/            
			}        
		}        
		final[k] = 1;    /* 〖唃〖〖俫拟軳〖〖1 */
		for(w=0; w<G.numVertexes; w++) /* 〖〖蘘〖本没〖+ */
		{
			/* 〖囡〖v伐〖焥〖〖〖〖焪〖〖〖〖/
			if(!final[w] && (min+G.arc[k][w]<(*D)[w]))   
			{ /*  〖∫〖〖〖〖机没〖〖〖[w]〖[w] */
				(*D)[w] = min + G.arc[k][w];  /* 〖〖〖焨〖 */               
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
	ShortPathTable D; /* 〖〖Ё〖〖筋〖〖本没 */   
	v0=0;
	
	CreateMGraph(&G);
	
	ShortestPath_Dijkstra(G, v0, &P, &D);  

	printf("〖本没苕〖:\n");    
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
	printf("\n〖Ё〖伐〖〖本没〖〖〖n");  
	for(i=1;i<G.numVertexes;++i)        
		printf("v%d - v%d : %d \n",G.vexs[0],G.vexs[i],D[i]);     
	return 0;
}