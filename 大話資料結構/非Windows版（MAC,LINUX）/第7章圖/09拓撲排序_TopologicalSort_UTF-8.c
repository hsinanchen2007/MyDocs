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

typedef int Status;	/* Status�O��ƪ����A,��ȬO��Ƶ��G���A�{���X�A�pOK�� */

/* �F���x�}���c */
typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

/* �F�����c****************** */
typedef struct EdgeNode /* ���`�I  */
{
	int adjvex;    /* �F���I��A�x�s�ӳ��I���������� */
	int weight;		/* �Ω��x�s�v�ȡA���D���ϥi�H���ݭn */
	struct EdgeNode *next; /* ���A���V�U�@�ӾF���I */
}EdgeNode;

typedef struct VertexNode /* ���I��`�I */
{
	int in;	/* ���I������� */
	int data; /* ���I��A�x�s���I�T�� */
	EdgeNode *firstedge;/* ����Y���� */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int numVertexes,numEdges; /* �Ϥ��ثe���I�ƩM��� */
}graphAdjList,*GraphAdjList;
/* **************************** */


void CreateMGraph(MGraph *G)/* �ե�� */
{
	int i, j;
	
	/* printf("�п�J��ƩM���I��:"); */
	G->numEdges=MAXEDGE;
	G->numVertexes=MAXVEX;

	for (i = 0; i < G->numVertexes; i++)/* �_�l�ƹ� */
	{
		G->vexs[i]=i;
	}

	for (i = 0; i < G->numVertexes; i++)/* �_�l�ƹ� */
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

/* �Q�ξF���x�}�غc�F���� */
void CreateALGraph(MGraph G,GraphAdjList *GL)
{
	int i,j;
	EdgeNode *e;

	*GL = (GraphAdjList)malloc(sizeof(graphAdjList));

	(*GL)->numVertexes=G.numVertexes;
	(*GL)->numEdges=G.numEdges;
	for(i= 0;i <G.numVertexes;i++) /* Ū�J���I�T���A�إ߳��I�� */
	{
		(*GL)->adjList[i].in=0;
		(*GL)->adjList[i].data=G.vexs[i];
		(*GL)->adjList[i].firstedge=NULL; 	/* �N���m���Ū� */
	}
	
	for(i=0;i<G.numVertexes;i++) /* �إ���� */
	{ 
		for(j=0;j<G.numVertexes;j++)
		{
			if (G.arc[i][j]==1)
			{
				e=(EdgeNode *)malloc(sizeof(EdgeNode));
				e->adjvex=j;					/* �F���Ǹ���j  */                        
				e->next=(*GL)->adjList[i].firstedge;	/* �N�ثe���I�W�����V���`�I���е����ȵ�e */
				(*GL)->adjList[i].firstedge=e;		/* �N�ثe���I�����Ы��Ve  */  
				(*GL)->adjList[j].in++;
				
			}
		}
	}
	
}


/* �ݼ��ƧǡA�YGL�L�^���A�h��X�ݼ��ƧǧǦC�öǦ^1�A�Y���^���Ǧ^0�C */
Status TopologicalSort(GraphAdjList GL)
{    
	EdgeNode *e;    
	int i,k,gettop;   
	int top=0;  /* �Ω���|���Я���  */
	int count=0;/* �Ω�έp��X���I���Ӽ�  */    
	int *stack;	/* �ذ��|�N������׬�0�����I�J���|  */   
	stack=(int *)malloc(GL->numVertexes * sizeof(int) );    

	for(i = 0; i<GL->numVertexes; i++)                
		if(0 == GL->adjList[i].in) /* �N������׬�0�����I�J���| */         
			stack[++top]=i;    
	while(top!=0)    
	{        
		gettop=stack[top--];        
		printf("%d -> ",GL->adjList[gettop].data);        
		count++;        /* ��Xi�����I�A�íp�� */        
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)        
		{            
			k=e->adjvex;            
			if( !(--GL->adjList[k].in) )  /* �Ni�����I���F���I��������״�1�A�Y�G��1�ᬰ0�A�h�J���| */                
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