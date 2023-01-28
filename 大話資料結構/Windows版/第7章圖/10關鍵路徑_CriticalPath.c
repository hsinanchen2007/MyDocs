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

typedef int Status;	/* Status������ ��,���������������á���OK�R*/  

int *etv,*ltv; /* �������M���������M������ */
int *stack2;   /* ������������P����/
int top2;	   /* ����stack2���� */

/* Z��������*/
typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

/* Z�����k***************** */
typedef struct EdgeNode /* �����b */
{
	int adjvex;    /* Z������ϫ���N�N�b����*/
	int weight;		/* ���������������������롼���� */
	struct EdgeNode *next; /* t�����᡼���X������/
}EdgeNode;

typedef struct VertexNode /* ��������/
{
	int in;	/* �����r*/
	int data; /* ������ϫ������ */
	EdgeNode *firstedge;/* �������� */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int numVertexes,numEdges; /* �����Z���a������/
}graphAdjList,*GraphAdjList;
/* **************************** */


void CreateMGraph(MGraph *G)/* �P�� */
{
	int i, j;
	/* printf("��������������:"); */
	G->numEdges=13;
	G->numVertexes=10;

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

/* ;��Z��������������/
void CreateALGraph(MGraph G,GraphAdjList *GL)
{
	int i,j;
	EdgeNode *e;

	*GL = (GraphAdjList)malloc(sizeof(graphAdjList));

	(*GL)->numVertexes=G.numVertexes;
	(*GL)->numEdges=G.numEdges;
	for(i= 0;i <G.numVertexes;i++) /* ����â������������/
	{
		(*GL)->adjList[i].in=0;
		(*GL)->adjList[i].data=G.vexs[i];
		(*GL)->adjList[i].firstedge=NULL; 	/* ������������/
	}
	
	for(i=0;i<G.numVertexes;i++) /* ������*/
	{ 
		for(j=0;j<G.numVertexes;j++)
		{
			if (G.arc[i][j]!=0 && G.arc[i][j]<GRAPH_INFINITY)
			{
				e=(EdgeNode *)malloc(sizeof(EdgeNode));
				e->adjvex=j;					/* Z������j */   
				e->weight=G.arc[i][j];
				e->next=(*GL)->adjList[i].firstedge;	/* ���������ʵ��С��������`e */
				(*GL)->adjList[i].firstedge=e;		/* ����������������e  */  
				(*GL)->adjList[j].in++;
				
			}
		}
	}
	
}


/* �������� */
Status TopologicalSort(GraphAdjList GL)
{    /* ��GL�Q���k��������������P���1�������G����*/    
	EdgeNode *e;    
	int i,k,gettop;   
	int top=0;  /* �������������� */
	int count=0;/* ���������������V��/   
	int *stack;	/* �������������N����  */   
	stack=(int *)malloc(GL->numVertexes * sizeof(int) );    
	for(i = 0; i<GL->numVertexes; i++)                
		if(0 == GL->adjList[i].in) /* ������0���N���� */           
			stack[++top]=i;    

	top2=0;    
	etv=(int *)malloc(GL->numVertexes * sizeof(int) ); /* �������M������ */    
	for(i=0; i<GL->numVertexes; i++)        
		etv[i]=0;    /* ���� */
	stack2=(int *)malloc(GL->numVertexes * sizeof(int) );/* ����������P�� */

	printf("TopologicalSort:\t");
	while(top!=0)    
	{        
		gettop=stack[top--];        
		printf("%d -> ",GL->adjList[gettop].data);        
		count++;        /* �������N������ */ 

		stack2[++top2]=gettop;        /* �������N�����t������P����/

		for(e = GL->adjList[gettop].firstedge; e; e = e->next)        
		{            
			k=e->adjvex;            
			if( !(--GL->adjList[k].in) )        /* �����N�T���������fᢡ����ס�0���졼 */                
				stack[++top]=k; 

			if((etv[gettop] + e->weight)>etv[k])    /* ��ľ�N���������M����tv�� */                
				etv[k] = etv[gettop] + e->weight;
		}    
	}    
	printf("\n");   
	if(count < GL->numVertexes)        
		return ERROR;    
	else       
		return OK;
}

/* ���ڡ��nGL������������G�د\�ڡ��j*/
void CriticalPath(GraphAdjList GL) 
{    
	EdgeNode *e;    
	int i,gettop,k,j;    
	int ete,lte;  /* ���ҡ��١��M���������M������ */        
	TopologicalSort(GL);   /* ��������P��������etv��tack2�ʳ�/ 
	ltv=(int *)malloc(GL->numVertexes*sizeof(int));/* �������M������ */   
	for(i=0; i<GL->numVertexes; i++)        
		ltv[i]=etv[GL->numVertexes-1];    /* ���� */        
	
	printf("etv:\t");   
	for(i=0; i<GL->numVertexes; i++)        
		printf("%d -> ",etv[i]);    
	printf("\n"); 

	while(top2!=0)    /* ������ltv */    
	{        
		gettop=stack2[top2--];        
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)        /* ��ľ�N���������M����tv�� */        
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

	for(j=0; j<GL->numVertexes; j++)        /* ��ete,lte�������j*/        
	{            
		for(e = GL->adjList[j].firstedge; e; e = e->next)            
		{                
			k=e->adjvex;                
			ete = etv[j];        /* ���١��M����*/                
			lte = ltv[k] - e->weight; /* ���١�������*/               
			if(ete == lte)    /* }�����T���ڡ��K��*/                    
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
