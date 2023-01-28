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

typedef int Status;	/* Status������ ��,���������������á���OK�R*/ 


typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

typedef int Patharc[MAXVEX];    /* ����������û�������� */
typedef int ShortPathTable[MAXVEX];/* �����������û��𪡼*/

/* �P�� */
void CreateMGraph(MGraph *G)
{
	int i, j;

	/* printf("��������������:"); */
	G->numEdges=16;
	G->numVertexes=9;

	for (i = 0; i < G->numVertexes; i++)/* ������ */
	{
		G->vexs[i]=i;
	}

	for (i = 0; i < G->numVertexes; i++)/* ������ */
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

/*  Dijkstra���q��������G��0���������������N�P�R[v]���꡼��[v] */    
/*  P[v]��ᶡ���������D[v]���r�����N�P�u����*/  
void ShortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D)
{    
	int v,w,k,min;    
	int final[MAXVEX];/* final[w]=1���\���Nv0��vw���N�P�b*/
	for(v=0; v<G.numVertexes; v++)    /* �������D*/
	{        
		final[v] = 0;			/* �����N�������_������û���� */
		(*D)[v] = G.arc[v0][v];/* �������������N���r� */
		(*P)[v] = -1;				/* �����P�L��P��-1  */       
	}

	(*D)[v0] = 0;  /* v0��v0�P�P��*/  
	final[v0] = 1;    /* v0��v0��㺡��P�b*/        
	/* ��������������v0ᾡ�v��������û */   
	for(v=1; v<G.numVertexes; v++)   
	{
		min=GRAPH_INFINITY;    /* �Z����+v0��������+ */        
		for(w=0; w<G.numVertexes; w++) /* ����+v0�������N */    
		{            
			if(!final[w] && (*D)[w]<min)             
			{                   
				k=w;                    
				min = (*D)[w];    /* w����v0������*/            
			}        
		}        
		final[k] = 1;    /* ���g�������g���N����1 */
		for(w=0; w<G.numVertexes; w++) /* �����Z����û��+ */
		{
			/* ���v�����P�s���������P�w�����ˡ���/
			if(!final[w] && (min+G.arc[k][w]<(*D)[w]))   
			{ /*  ���ҡ���������û������[w]��[w] */
				(*D)[w] = min + G.arc[k][w];  /* �������P�u�� */               
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
	ShortPathTable D; /* ���������������û */   
	v0=0;
	
	CreateMGraph(&G);
	
	ShortestPath_Dijkstra(G, v0, &P, &D);  

	printf("����û��N��:\n");    
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
	printf("\n��������������û������n");  
	for(i=1;i<G.numVertexes;++i)        
		printf("v%d - v%d : %d \n",G.vexs[0],G.vexs[i],D[i]);     
	return 0;
}