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

typedef int Status;	/* Statusーーー ー,ーーーーーーー驚ーーOK�R*/ 


typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

typedef int Patharc[MAXVEX];    /* ーーーー云短ーーーー */
typedef int ShortPathTable[MAXVEX];/* ーーーー庶ー云短寺險ー*/

/* �Pﾍ */
void CreateMGraph(MGraph *G)
{
	int i, j;

	/* printf("ーーーーー轡ー:"); */
	G->numEdges=16;
	G->numVertexes=9;

	for (i = 0; i < G->numVertexes; i++)/* ーーー */
	{
		G->vexs[i]=i;
	}

	for (i = 0; i < G->numVertexes; i++)/* ーーー */
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

/*  Dijkstraー�qーーーーG亭0轡ーーー轡ーー�N�P�R[v]ー�蝓次�[v] */    
/*  P[v]妻甼ーー轡ーーD[v]ー�r辺蔬�N�P�uーー*/  
void ShortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D)
{    
	int v,w,k,min;    
	int final[MAXVEX];/* final[w]=1ー�\粲�Nv0ーvw蔬�N�P�b*/
	for(v=0; v<G.numVertexes; v++)    /* ーーー�D*/
	{        
		final[v] = 0;			/* ーー�Nーーー�_ーー云短ーー */
		(*D)[v] = G.arc[v0][v];/* ーー寸ーー亭�Nー�r險 */
		(*P)[v] = -1;				/* ーー�P�LーPー-1  */       
	}

	(*D)[v0] = 0;  /* v0ーv0�P�Pー*/  
	final[v0] = 1;    /* v0ーv0ー禳ー�P�b*/        
	/* ーーーーーーーv0畩ーv轡ーー云短 */   
	for(v=1; v<G.numVertexes; v++)   
	{
		min=GRAPH_INFINITY;    /* �Zーー+v0轡ーーー+ */        
		for(w=0; w<G.numVertexes; w++) /* ーー+v0ーーー�N */    
		{            
			if(!final[w] && (*D)[w]<min)             
			{                   
				k=w;                    
				min = (*D)[w];    /* w轡ーv0轡ーー*/            
			}        
		}        
		final[k] = 1;    /* ー�gー��ー�g亭�Nーー1 */
		for(w=0; w<G.numVertexes; w++) /* ーー�Zー云短ー+ */
		{
			/* ー瑙ーv轡ー�P�sーーーー�P�wーー�法次�/
			if(!final[w] && (min+G.arc[k][w]<(*D)[w]))   
			{ /*  ー〈ーーーー字短ーーー[w]ー[w] */
				(*D)[w] = min + G.arc[k][w];  /* ーーー�P�uー */               
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
	ShortPathTable D; /* ーーЁーー庶ーー云短 */   
	v0=0;
	
	CreateMGraph(&G);
	
	ShortestPath_Dijkstra(G, v0, &P, &D);  

	printf("ー云短樔�Nー:\n");    
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
	printf("\nーЁー轡ーー云短ーーーn");  
	for(i=1;i<G.numVertexes;++i)        
		printf("v%d - v%d : %d \n",G.vexs[0],G.vexs[i],D[i]);     
	return 0;
}