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

typedef int Status;	/* Status¡¼¡¼¡¼ ¡¼,¡¼¡¼¡¼¡¼¡¼¡¼¡¼¶Ã¡¼¡¼OK§R*/

/* Z¡¼¡¼¡¼ö¿*/
typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

/* Z¡¼¡¼øk***************** */
typedef struct EdgeNode /* ¡¼¡¼Ãb */
{
	int adjvex;    /* Z¡¼¡¼¡¼Ï«½¦ÝNôN²b¡¼¡¼*/
	int weight;		/* ¡¼¡¼¡¼£¾¡¼¡¼¡¼¡¼¡¼²þ†ë¡¼¡¼¡¼ */
	struct EdgeNode *next; /* t¡¼¡¼µá¡¼¡¼¶X¡¼¡¼¡¼/
}EdgeNode;

typedef struct VertexNode /* ·¥¡¼¡¼¡¼/
{
	int in;	/* ·¥¤õÝr*/
	int data; /* ·¥¡¼¡¼Ï«·¥¡¼¡¼ */
	EdgeNode *firstedge;/* ¡¼¡¼¡¼¡¼ */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int numVertexes,numEdges; /* ¡¼¡¼ÌZ¡¼Ãa¡¼¡¼¡¼/
}graphAdjList,*GraphAdjList;
/* **************************** */


void CreateMGraph(MGraph *G)/* ÆPŽÍ */
{
	int i, j;
	
	/* printf("¡¼¡¼¡¼¡¼¡¼·¥¡¼:"); */
	G->numEdges=MAXEDGE;
	G->numVertexes=MAXVEX;

	for (i = 0; i < G->numVertexes; i++)/* ¡¼¡¼¡¼ */
	{
		G->vexs[i]=i;
	}

	for (i = 0; i < G->numVertexes; i++)/* ¡¼¡¼¡¼ */
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

/* ;¡¼Z¡¼¡¼¡¼¡¼¡¼¡¼¡¼/
void CreateALGraph(MGraph G,GraphAdjList *GL)
{
	int i,j;
	EdgeNode *e;

	*GL = (GraphAdjList)malloc(sizeof(graphAdjList));

	(*GL)->numVertexes=G.numVertexes;
	(*GL)->numEdges=G.numEdges;
	for(i= 0;i <G.numVertexes;i++) /* ¡¼¡¼Ã¢¡¼¡¼¡¼¡¼³ü¡¼/
	{
		(*GL)->adjList[i].in=0;
		(*GL)->adjList[i].data=G.vexs[i];
		(*GL)->adjList[i].firstedge=NULL; 	/* ¡¼¡¼¡¼¡¼‹ù¡¼/
	}
	
	for(i=0;i<G.numVertexes;i++) /* ¡¼¡¼¡¼*/
	{ 
		for(j=0;j<G.numVertexes;j++)
		{
			if (G.arc[i][j]==1)
			{
				e=(EdgeNode *)malloc(sizeof(EdgeNode));
				e->adjvex=j;					/* Z¡¼¡¼¡¼j  */                        
				e->next=(*GL)->adjList[i].firstedge;	/* ¡¼¡¼·¥¡¼ºÊµá÷Ð¡¼¡¼¡¼»­±`e */
				(*GL)->adjList[i].firstedge=e;		/* ¡¼¡¼·¥¡¼¡¼¡¼¡¼¡¼e  */  
				(*GL)->adjList[j].in++;
				
			}
		}
	}
	
}


/* ¡¼¡¼¡¼¡¼¡¼¡¼£Q¡¼¿k¡¼¡¼¡¼¡¼¡¼¡¼¡¼P¡¼áµ1¡¼¡¼¡¼ãG¡¼¡¼*/
Status TopologicalSort(GraphAdjList GL)
{    
	EdgeNode *e;    
	int i,k,gettop;   
	int top=0;  /* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */
	int count=0;/* ¡¼¡¼¡¼¡¼¡¼·¥¡¼¶V¡¼*/    
	int *stack;	/* ¡¼¡¼¡¼¦¥¡¼¡¼ÝN¡¼¡¼  */   
	stack=(int *)malloc(GL->numVertexes * sizeof(int) );    

	for(i = 0; i<GL->numVertexes; i++)                
		if(0 == GL->adjList[i].in) /* ¡¼¡¼¡¼0ÄâÝN¡¼¡¼ */         
			stack[++top]=i;    
	while(top!=0)    
	{        
		gettop=stack[top--];        
		printf("%d -> ",GL->adjList[gettop].data);        
		count++;        /* ¡¼¡¼¡¼ÝN¡¼¡¼¡¼ */        
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)        
		{            
			k=e->adjvex;            
			if( !(--GL->adjList[k].in) )  /* ¡¼¡¼ÝN«T¡¼¡¼¡¼¡¼¥fá¢¡¼óõÉ×¡¼0¡¼¡ì¡¼ */                
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