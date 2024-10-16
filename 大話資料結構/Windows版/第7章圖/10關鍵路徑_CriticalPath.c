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

typedef int Status;	/* Statusーーー ー,ーーーーーーー驚ーーOK�R*/  

int *etv,*ltv; /* ーー�仝Mーーー���Mーーー */
int *stack2;   /* ーーーーーーP娼ー/
int top2;	   /* ーーstack2妻褸 */

/* Zーーー��*/
typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

/* Zーー�k***************** */
typedef struct EdgeNode /* ーー�b */
{
	int adjvex;    /* Zーーー労拾�N�N�bーー*/
	int weight;		/* ーーー�勝次次次次鴫��襦次次� */
	struct EdgeNode *next; /* tーー求ーー�Xーーー/
}EdgeNode;

typedef struct VertexNode /* 轡ーーー/
{
	int in;	/* 轡���r*/
	int data; /* 轡ーー労轡ーー */
	EdgeNode *firstedge;/* ーーーー */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int numVertexes,numEdges; /* ーー�Zー�aーーー/
}graphAdjList,*GraphAdjList;
/* **************************** */


void CreateMGraph(MGraph *G)/* �Pﾍ */
{
	int i, j;
	/* printf("ーーーーー轡ー:"); */
	G->numEdges=13;
	G->numVertexes=10;

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

/* ;ーZーーーーーーー/
void CreateALGraph(MGraph G,GraphAdjList *GL)
{
	int i,j;
	EdgeNode *e;

	*GL = (GraphAdjList)malloc(sizeof(graphAdjList));

	(*GL)->numVertexes=G.numVertexes;
	(*GL)->numEdges=G.numEdges;
	for(i= 0;i <G.numVertexes;i++) /* ーー但ーーーー栢ー/
	{
		(*GL)->adjList[i].in=0;
		(*GL)->adjList[i].data=G.vexs[i];
		(*GL)->adjList[i].firstedge=NULL; 	/* ーーーー��ー/
	}
	
	for(i=0;i<G.numVertexes;i++) /* ーーー*/
	{ 
		for(j=0;j<G.numVertexes;j++)
		{
			if (G.arc[i][j]!=0 && G.arc[i][j]<GRAPH_INFINITY)
			{
				e=(EdgeNode *)malloc(sizeof(EdgeNode));
				e->adjvex=j;					/* Zーーーj */   
				e->weight=G.arc[i][j];
				e->next=(*GL)->adjList[i].firstedge;	/* ーー轡ー妻求�弌次次嫉��`e */
				(*GL)->adjList[i].firstedge=e;		/* ーー轡ーーーーーe  */  
				(*GL)->adjList[j].in++;
				
			}
		}
	}
	
}


/* ーーーー */
Status TopologicalSort(GraphAdjList GL)
{    /* ーGL�Qー�kーーーーーーーPー甬1ーーー�Gーー*/    
	EdgeNode *e;    
	int i,k,gettop;   
	int top=0;  /* ーーーーーーー */
	int count=0;/* ーーーーー轡ー�Vー/   
	int *stack;	/* ーーーΕーー�Nーー  */   
	stack=(int *)malloc(GL->numVertexes * sizeof(int) );    
	for(i = 0; i<GL->numVertexes; i++)                
		if(0 == GL->adjList[i].in) /* ーーー0亭�Nーー */           
			stack[++top]=i;    

	top2=0;    
	etv=(int *)malloc(GL->numVertexes * sizeof(int) ); /* ーー�仝Mーーー */    
	for(i=0; i<GL->numVertexes; i++)        
		etv[i]=0;    /* ーー */
	stack2=(int *)malloc(GL->numVertexes * sizeof(int) );/* ーーーーーPー */

	printf("TopologicalSort:\t");
	while(top!=0)    
	{        
		gettop=stack[top--];        
		printf("%d -> ",GL->adjList[gettop].data);        
		count++;        /* ーーー�Nーーー */ 

		stack2[++top2]=gettop;        /* ーー亭�Nーー�tーーーP娼ー/

		for(e = GL->adjList[gettop].firstedge; e; e = e->next)        
		{            
			k=e->adjvex;            
			if( !(--GL->adjList[k].in) )        /* ーー�N�Tーーーー�f瓣ー齦夫ー0ー′ー */                
				stack[++top]=k; 

			if((etv[gettop] + e->weight)>etv[k])    /* ー直�Nーーー�仝Mーーtvー */                
				etv[k] = etv[gettop] + e->weight;
		}    
	}    
	printf("\n");   
	if(count < GL->numVertexes)        
		return ERROR;    
	else       
		return OK;
}

/* ー遥ー�nGLーーーーーーG椿�\遥ー�j*/
void CriticalPath(GraphAdjList GL) 
{    
	EdgeNode *e;    
	int i,gettop,k,j;    
	int ete,lte;  /* ー〈ー�戞叱Mーーー���Mーーー */        
	TopologicalSort(GL);   /* ーーーーPーーーーetvーtack2妻株/ 
	ltv=(int *)malloc(GL->numVertexes*sizeof(int));/* ーー�仝Mーーー */   
	for(i=0; i<GL->numVertexes; i++)        
		ltv[i]=etv[GL->numVertexes-1];    /* ーー */        
	
	printf("etv:\t");   
	for(i=0; i<GL->numVertexes; i++)        
		printf("%d -> ",etv[i]);    
	printf("\n"); 

	while(top2!=0)    /* ーーーltv */    
	{        
		gettop=stack2[top2--];        
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)        /* ー直�Nーーー���Mーーtvー */        
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

	for(j=0; j<GL->numVertexes; j++)        /* ーete,lteーーー�j*/        
	{            
		for(e = GL->adjList[j].firstedge; e; e = e->next)            
		{                
			k=e->adjvex;                
			ete = etv[j];        /* ー�戞叱Mーー*/                
			lte = ltv[k] - e->weight; /* ー�戞次次次�*/               
			if(ete == lte)    /* }ーー�Tー遥ー�Kー*/                    
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
