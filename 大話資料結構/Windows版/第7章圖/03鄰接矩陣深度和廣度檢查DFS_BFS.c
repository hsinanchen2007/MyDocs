#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;	/* Status°º°º°º °º,°º°º°º°º°º°º°º∂√°º°ºOKßR*/  
typedef int Boolean; /* Boolean°º°º°º°º,°º°º°ºTRUE°ºALSE */

typedef char VertexType; /* ∑•°º°º°º°º°º°º°º */
typedef int EdgeType; /* °º°º°º™ °º°º°º°º°º°º */

#define MAXSIZE 9 /* °º°º°ºÀ’√¶°º */
#define MAXEDGE 15
#define MAXVEX 9

typedef struct
{
	VertexType vexs[MAXVEX]; /* ∑•°º */
	EdgeType arc[MAXVEX][MAXVEX];/* Z°º°º°ºáY°º°º°º/
	int numVertexes, numEdges; /* °º°ºÃZ°º∑•°º°º°º°º/ 
}MGraph;

/* °º≠£°º°º°º°º°º°º°º******************************** */

/* °º°º°º°º°º°º°º°ºˆø*/
typedef struct
{
	int data[MAXSIZE];
	int front;    	/* °º°º°º */
	int rear;		/* £]°º°º°º°ºP°º°º°º°ºæ÷°º¢t°ºﬂT°º°º£f°º */
}Queue;

/* °º°º°º◊Ÿ°º°º°º */
Status InitQueue(Queue *Q)
{
	Q->front=0;
	Q->rear=0;
	return  OK;
}

/* °ºæ÷°º°ºã˛°º°º°ºﬂ_°ºRUE,ı‰°º°ºALSE */
Status QueueEmpty(Queue Q)
{ 
	if(Q.front==Q.rear) /* æ÷°º°º°º°º */
		return TRUE;
	else
		return FALSE;
}

/* °ºæ÷°º°º°º°º°º°º°ºe°ºQ°ºƒ‚°º¢t°º */
Status EnQueue(Queue *Q,int e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)	/* æ÷°º°º°ºŸ]*/
		return ERROR;
	Q->data[Q->rear]=e;			/* °º°ºeª≠±`¿∫°º/
	Q->rear=(Q->rear+1)%MAXSIZE;/* rear°º°º°º°º°º°º°º°º*/
								/* °º±k†˙°º°ºæ °º°º°º*/
	return  OK;
}

/* °ºæ÷°º°º°º°º°º°ºæﬁ F°º°ºaﬂ_°º°º */
Status DeQueue(Queue *Q,int *e)
{
	if (Q->front == Q->rear)			/* æ÷°º°º°º°º°º*/
		return ERROR;
	*e=Q->data[Q->front];				/* °º°º F°ºª≠±`e */
	Q->front=(Q->front+1)%MAXSIZE;	/* front°º°º°º°º°º°º°º°º*/
									/* °º±k†˙°º°ºæ °º°º°º*/
	return  OK;
}
/* ****************************************************** */


void CreateMGraph(MGraph *G)
{
	int i, j;

	G->numEdges=15;
	G->numVertexes=9;

	/* °º°º√¢°º°º°º°º≥¸°º/
	G->vexs[0]='A';
	G->vexs[1]='B';
	G->vexs[2]='C';
	G->vexs[3]='D';
	G->vexs[4]='E';
	G->vexs[5]='F';
	G->vexs[6]='G';
	G->vexs[7]='H';
	G->vexs[8]='I';


	for (i = 0; i < G->numVertexes; i++)/* °º°º°º */
	{
		for ( j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j]=0;
		}
	}

	G->arc[0][1]=1;
	G->arc[0][5]=1;

	G->arc[1][2]=1; 
	G->arc[1][8]=1; 
	G->arc[1][6]=1; 
	
	G->arc[2][3]=1; 
	G->arc[2][8]=1; 
	
	G->arc[3][4]=1;
	G->arc[3][7]=1;
	G->arc[3][6]=1;
	G->arc[3][8]=1;

	G->arc[4][5]=1;
	G->arc[4][7]=1;

	G->arc[5][6]=1; 
	
	G->arc[6][7]=1; 

	
	for(i = 0; i < G->numVertexes; i++)
	{
		for(j = i; j < G->numVertexes; j++)
		{
			G->arc[j][i] =G->arc[i][j];
		}
	}

}
 
Boolean visited[MAXVEX]; /* “{°º°º‰Ò°º */

/* Z°º°º°º°º©Œ°º°º°º®∏∏Y*/
void DFS(MGraph G, int i)
{
	int j;
 	visited[i] = TRUE;
 	printf("%c ", G.vexs[i]);/* °º°ºÙB°ºÜÎ°º°º°º“‰/
	for(j = 0; j < G.numVertexes; j++)
		if(G.arc[i][j] == 1 && !visited[j])
 			DFS(G, j);/* ÚG°º°º´T°º°º›N•ﬁÛÿ°º */
}

/* Z°º°º°º°º¿∏ª∑°º“‰/
void DFSTraverse(MGraph G)
{
	int i;
 	for(i = 0; i < G.numVertexes; i++)
 		visited[i] = FALSE; /* °º°º°º∑•°º°º‚~°º°º°ºÛ˚°º */
	for(i = 0; i < G.numVertexes; i++)
 		if(!visited[i]) /* ÚG°º°º¯Ï°º›N≈qAFS°º°ºl°º°º°º°º°º°º°º°º*/ 
			DFS(G, i);
}

/* Z°º°º°º‡‚°ºª∑°º∏Y*/
void BFSTraverse(MGraph G)
{
	int i, j;
	Queue Q;
	for(i = 0; i < G.numVertexes; i++)
       	visited[i] = FALSE;
    InitQueue(&Q);		/* °º°º°º∞W°ºƒ‚°º°º*/
    for(i = 0; i < G.numVertexes; i++)  /* Ô÷ä‡”Á›N°º°º°º*/
    {
		if (!visited[i])	/* °º°º£_“{°º°º°º°º/
		{
			visited[i]=TRUE;		/* °º°ºÃZ°º≥˝I°º°º/
			printf("%c ", G.vexs[i]);/* °º°ºÙB°ºÜÎ°º°º°º“‰/
			EnQueue(&Q,i);		/* °º°º›N°ºæ÷°º*/
			while(!QueueEmpty(Q))	/* °ºÃZ°ºP°º°º */
			{
				DeQueue(&Q,&i);	/* °º°º°º°º°º°º°º°º°ºΩÚ */
				for(j=0;j<G.numVertexes;j++) 
				{ 
					/* °º¥}°º∑•¶W°ºÃZ°ºŒ_°º°º°º°º°ºıª */
					if(G.arc[i][j] == 1 && !visited[j]) 
					{ 
 						visited[j]=TRUE;			/* °º°º°º°º›N°º°º°º“{°º*/
						printf("%c ", G.vexs[j]);	/* °º°º√b*/
						EnQueue(&Q,j);				/* °º°º°º°º›N°ºæ÷°º */
					} 
				} 
			}
		}
	}
}


int main(void)
{    
	MGraph G;
	CreateMGraph(&G);
	printf("\n°º¿∏ª∑°º);
	DFSTraverse(G);
	printf("\n‡‚°ºª∑°º);
	BFSTraverse(G);
	return 0;
}

