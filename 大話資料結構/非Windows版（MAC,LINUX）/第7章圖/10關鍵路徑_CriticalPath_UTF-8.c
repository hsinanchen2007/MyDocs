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

typedef int Status;	/* Status�O��ƪ����A,��ȬO��Ƶ��G���A�{���X�A�pOK�� */  

int *etv,*ltv; /* �ƥ�̦��o�ͮɶ��M�̿�o�ͮɶ��}�C */
int *stack2;   /* �Ω��x�s�ݼ��ǦC�����| */
int top2;	   /* �Ω�stack2������ */

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
	G->numEdges=13;
	G->numVertexes=10;

	for (i = 0; i < G->numVertexes; i++)/* �_�l�ƹ� */
	{
		G->vexs[i]=i;
	}

	for (i = 0; i < G->numVertexes; i++)/* �_�l�ƹ� */
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
			if (G.arc[i][j]!=0 && G.arc[i][j]<GRAPH_INFINITY)
			{
				e=(EdgeNode *)malloc(sizeof(EdgeNode));
				e->adjvex=j;					/* �F���Ǹ���j */   
				e->weight=G.arc[i][j];
				e->next=(*GL)->adjList[i].firstedge;	/* �N�ثe���I�W�����V���`�I���е����ȵ�e */
				(*GL)->adjList[i].firstedge=e;		/* �N�ثe���I�����Ы��Ve  */  
				(*GL)->adjList[j].in++;
				
			}
		}
	}
	
}


/* �ݼ��Ƨ� */
Status TopologicalSort(GraphAdjList GL)
{    /* �YGL�L�^���A�h��X�ݼ��ƧǧǦC�öǦ^1�A�Y���^���Ǧ^0�C */    
	EdgeNode *e;    
	int i,k,gettop;   
	int top=0;  /* �Ω���|���Я���  */
	int count=0;/* �Ω�έp��X���I���Ӽ� */   
	int *stack;	/* �ذ��|�N������׬�0�����I�J���|  */   
	stack=(int *)malloc(GL->numVertexes * sizeof(int) );    
	for(i = 0; i<GL->numVertexes; i++)                
		if(0 == GL->adjList[i].in) /* �N������׬�0�����I�J���| */           
			stack[++top]=i;    

	top2=0;    
	etv=(int *)malloc(GL->numVertexes * sizeof(int) ); /* �ƥ�̦��o�ͮɶ��}�C */    
	for(i=0; i<GL->numVertexes; i++)        
		etv[i]=0;    /* �_�l�� */
	stack2=(int *)malloc(GL->numVertexes * sizeof(int) );/* �_�l�Ʃݼ��ǦC���| */

	printf("TopologicalSort:\t");
	while(top!=0)    
	{        
		gettop=stack[top--];        
		printf("%d -> ",GL->adjList[gettop].data);        
		count++;        /* ��Xi�����I�A�íp�� */ 

		stack2[++top2]=gettop;        /* �N�X�{�����I�Ǹ��s�J�ݼ��ǦC�����| */

		for(e = GL->adjList[gettop].firstedge; e; e = e->next)        
		{            
			k=e->adjvex;            
			if( !(--GL->adjList[k].in) )        /* �Ni�����I���F���I��������״�1�A�Y�G��1�ᬰ0�A�h�J���| */                
				stack[++top]=k; 

			if((etv[gettop] + e->weight)>etv[k])    /* �D�U���I�ƥ󪺳̦��o�ͮɶ�etv�� */                
				etv[k] = etv[gettop] + e->weight;
		}    
	}    
	printf("\n");   
	if(count < GL->numVertexes)        
		return ERROR;    
	else       
		return OK;
}

/* �D������|,GL�����V���A��XG���U�����䬡�� */
void CriticalPath(GraphAdjList GL) 
{    
	EdgeNode *e;    
	int i,gettop,k,j;    
	int ete,lte;  /* �ŧi���ʳ̦��o�ͮɶ��M�̿�o�ͮɶ��ܼ� */        
	TopologicalSort(GL);   /* �D�ݼ��ǦC�A�p��}�Cetv�Mstack2���� */ 
	ltv=(int *)malloc(GL->numVertexes*sizeof(int));/* �ƥ�̦��o�ͮɶ��}�C */   
	for(i=0; i<GL->numVertexes; i++)        
		ltv[i]=etv[GL->numVertexes-1];    /* �_�l�� */        
	
	printf("etv:\t");   
	for(i=0; i<GL->numVertexes; i++)        
		printf("%d -> ",etv[i]);    
	printf("\n"); 

	while(top2!=0)    /* �X���|�O�Dltv */    
	{        
		gettop=stack2[top2--];        
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)        /* �D�U���I�ƥ󪺳̿�o�ͮɶ�ltv�� */        
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

	for(j=0; j<GL->numVertexes; j++)        /* �Dete,lte�M���䬡�� */        
	{            
		for(e = GL->adjList[j].firstedge; e; e = e->next)            
		{                
			k=e->adjvex;                
			ete = etv[j];        /* ���ʳ̦��o�ͮɶ� */                
			lte = ltv[k] - e->weight; /* ���ʳ̿�o�ͮɶ� */               
			if(ete == lte)    /* ��̬۵��Y�b������|�W */                    
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
