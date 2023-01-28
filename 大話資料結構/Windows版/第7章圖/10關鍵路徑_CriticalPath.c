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

typedef int Status;	/* Status¡¼¡¼¡¼ ¡¼,¡¼¡¼¡¼¡¼¡¼¡¼¡¼¶Ã¡¼¡¼OK§R*/  

int *etv,*ltv; /* ¡¼¡¼‘¡¸M¡¼¡¼¡¼÷¸M¡¼¡¼¡¼ */
int *stack2;   /* ¡¼¡¼¡¼¡¼¡¼¡¼P¾«¡¼/
int top2;	   /* ¡¼¡¼stack2ºÊêú */

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
	G->numEdges=13;
	G->numVertexes=10;

	for (i = 0; i < G->numVertexes; i++)/* ¡¼¡¼¡¼ */
	{
		G->vexs[i]=i;
	}

	for (i = 0; i < G->numVertexes; i++)/* ¡¼¡¼¡¼ */
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
			if (G.arc[i][j]!=0 && G.arc[i][j]<GRAPH_INFINITY)
			{
				e=(EdgeNode *)malloc(sizeof(EdgeNode));
				e->adjvex=j;					/* Z¡¼¡¼¡¼j */   
				e->weight=G.arc[i][j];
				e->next=(*GL)->adjList[i].firstedge;	/* ¡¼¡¼·¥¡¼ºÊµá÷Ð¡¼¡¼¡¼»­±`e */
				(*GL)->adjList[i].firstedge=e;		/* ¡¼¡¼·¥¡¼¡¼¡¼¡¼¡¼e  */  
				(*GL)->adjList[j].in++;
				
			}
		}
	}
	
}


/* ¡¼¡¼¡¼¡¼ */
Status TopologicalSort(GraphAdjList GL)
{    /* ¡¼GL£Q¡¼¿k¡¼¡¼¡¼¡¼¡¼¡¼¡¼P¡¼áµ1¡¼¡¼¡¼ãG¡¼¡¼*/    
	EdgeNode *e;    
	int i,k,gettop;   
	int top=0;  /* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */
	int count=0;/* ¡¼¡¼¡¼¡¼¡¼·¥¡¼¶V¡¼/   
	int *stack;	/* ¡¼¡¼¡¼¦¥¡¼¡¼ÝN¡¼¡¼  */   
	stack=(int *)malloc(GL->numVertexes * sizeof(int) );    
	for(i = 0; i<GL->numVertexes; i++)                
		if(0 == GL->adjList[i].in) /* ¡¼¡¼¡¼0ÄâÝN¡¼¡¼ */           
			stack[++top]=i;    

	top2=0;    
	etv=(int *)malloc(GL->numVertexes * sizeof(int) ); /* ¡¼¡¼‘¡¸M¡¼¡¼¡¼ */    
	for(i=0; i<GL->numVertexes; i++)        
		etv[i]=0;    /* ¡¼¡¼ */
	stack2=(int *)malloc(GL->numVertexes * sizeof(int) );/* ¡¼¡¼¡¼¡¼¡¼P¡¼ */

	printf("TopologicalSort:\t");
	while(top!=0)    
	{        
		gettop=stack[top--];        
		printf("%d -> ",GL->adjList[gettop].data);        
		count++;        /* ¡¼¡¼¡¼ÝN¡¼¡¼¡¼ */ 

		stack2[++top2]=gettop;        /* ¡¼¡¼ÄâÝN¡¼¡¼Üt¡¼¡¼¡¼P¾«¡¼/

		for(e = GL->adjList[gettop].firstedge; e; e = e->next)        
		{            
			k=e->adjvex;            
			if( !(--GL->adjList[k].in) )        /* ¡¼¡¼ÝN«T¡¼¡¼¡¼¡¼¥fá¢¡¼óõÉ×¡¼0¡¼¡ì¡¼ */                
				stack[++top]=k; 

			if((etv[gettop] + e->weight)>etv[k])    /* ¡¼Ä¾ÝN¡¼¡¼¡¼‘¡¸M¡¼¡¼tv¡¼ */                
				etv[k] = etv[gettop] + e->weight;
		}    
	}    
	printf("\n");   
	if(count < GL->numVertexes)        
		return ERROR;    
	else       
		return OK;
}

/* ¡¼ÍÚ¡¼ŸnGL¡¼¡¼¡¼¡¼¡¼¡¼GÄØ¯\ÍÚ¡¼Ïj*/
void CriticalPath(GraphAdjList GL) 
{    
	EdgeNode *e;    
	int i,gettop,k,j;    
	int ete,lte;  /* ¡¼¡Ò¡¼ŒÙ¡¼¸M¡¼¡¼¡¼÷¸M¡¼¡¼¡¼ */        
	TopologicalSort(GL);   /* ¡¼¡¼¡¼¡¼P¡¼¡¼¡¼¡¼etv¡¼tack2ºÊ³ô/ 
	ltv=(int *)malloc(GL->numVertexes*sizeof(int));/* ¡¼¡¼‘¡¸M¡¼¡¼¡¼ */   
	for(i=0; i<GL->numVertexes; i++)        
		ltv[i]=etv[GL->numVertexes-1];    /* ¡¼¡¼ */        
	
	printf("etv:\t");   
	for(i=0; i<GL->numVertexes; i++)        
		printf("%d -> ",etv[i]);    
	printf("\n"); 

	while(top2!=0)    /* ¡¼¡¼¡¼ltv */    
	{        
		gettop=stack2[top2--];        
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)        /* ¡¼Ä¾ÝN¡¼¡¼¡¼÷¸M¡¼¡¼tv¡¼ */        
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

	for(j=0; j<GL->numVertexes; j++)        /* ¡¼ete,lte¡¼¡¼¡¼Ïj*/        
	{            
		for(e = GL->adjList[j].firstedge; e; e = e->next)            
		{                
			k=e->adjvex;                
			ete = etv[j];        /* ¡¼ŒÙ¡¼¸M¡¼¡¼*/                
			lte = ltv[k] - e->weight; /* ¡¼ŒÙ¡¼¡¼¡¼¡¼*/               
			if(ete == lte)    /* }¡¼¡¼§T¡¼ÍÚ¡¼ŸK¡¼*/                    
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
