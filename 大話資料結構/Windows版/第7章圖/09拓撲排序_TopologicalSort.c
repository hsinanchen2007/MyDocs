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

typedef int Status;	/* Status������ ��,���������������á���OK�R*/

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
	G->numEdges=MAXEDGE;
	G->numVertexes=MAXVEX;

	for (i = 0; i < G->numVertexes; i++)/* ������ */
	{
		G->vexs[i]=i;
	}

	for (i = 0; i < G->numVertexes; i++)/* ������ */
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
			if (G.arc[i][j]==1)
			{
				e=(EdgeNode *)malloc(sizeof(EdgeNode));
				e->adjvex=j;					/* Z������j  */                        
				e->next=(*GL)->adjList[i].firstedge;	/* ���������ʵ��С��������`e */
				(*GL)->adjList[i].firstedge=e;		/* ����������������e  */  
				(*GL)->adjList[j].in++;
				
			}
		}
	}
	
}


/* �������������Q���k��������������P���1�������G����*/
Status TopologicalSort(GraphAdjList GL)
{    
	EdgeNode *e;    
	int i,k,gettop;   
	int top=0;  /* �������������� */
	int count=0;/* ���������������V��*/    
	int *stack;	/* �������������N����  */   
	stack=(int *)malloc(GL->numVertexes * sizeof(int) );    

	for(i = 0; i<GL->numVertexes; i++)                
		if(0 == GL->adjList[i].in) /* ������0���N���� */         
			stack[++top]=i;    
	while(top!=0)    
	{        
		gettop=stack[top--];        
		printf("%d -> ",GL->adjList[gettop].data);        
		count++;        /* �������N������ */        
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)        
		{            
			k=e->adjvex;            
			if( !(--GL->adjList[k].in) )  /* �����N�T���������fᢡ����ס�0���졼 */                
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