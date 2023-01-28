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

typedef int Status;	/* Status�O��ƪ����A,��ȬO��Ƶ��G���A�{���X�A�pOK�� */ 


typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

typedef int Patharc[MAXVEX];    /* �Ω��x�s�̵u���|���ު��}�C */
typedef int ShortPathTable[MAXVEX];/* �Ω��x�s��U�I�̵u���|���v�ȩM */

/* �ե�� */
void CreateMGraph(MGraph *G)
{
	int i, j;

	/* printf("�п�J��ƩM���I��:"); */
	G->numEdges=16;
	G->numVertexes=9;

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

/*  Dijkstra��k�A�D���V��G��v0���I���E���Iv���̵u���|P[v]�αa�v����D[v] */    
/*  P[v]���Ȭ��e�X���I����,D[v]���v0��v���̵u���|���שM */  
void ShortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D)
{    
	int v,w,k,min;    
	int final[MAXVEX];/* final[w]=1��ܨD�o���Iv0��vw���̵u���| */
	for(v=0; v<G.numVertexes; v++)    /* �_�l�Ƹ�� */
	{        
		final[v] = 0;			/* �������I�_�l�Ƭ����Գ̵u���|���A */
		(*D)[v] = G.arc[v0][v];/* �N�Pv0�I���s�u�����I�[�W�v�� */
		(*P)[v] = -1;				/* �_�l�Ƹ��|�}�CP��-1  */       
	}

	(*D)[v0] = 0;  /* v0��v0���|��0 */  
	final[v0] = 1;    /* v0��v0���ݭn�D���| */        
	/* �}�l�D�`���A�C���D�ov0��Y��v���I���̵u���| */   
	for(v=1; v<G.numVertexes; v++)   
	{
		min=GRAPH_INFINITY;    /* �ثe�Ҫ���v0���I���̪�Z�� */        
		for(w=0; w<G.numVertexes; w++) /* �M����v0�̪񪺳��I */    
		{            
			if(!final[w] && (*D)[w]<min)             
			{                   
				k=w;                    
				min = (*D)[w];    /* w���I��v0���I��� */            
			}        
		}        
		final[k] = 1;    /* �N�ثe��쪺�̪񪺳��I�m��1 */
		for(w=0; w<G.numVertexes; w++) /* �ץ��ثe�̵u���|�ζZ�� */
		{
			/* �Y�G�g��v���I�����|��{�b�o�����|�����׵u���� */
			if(!final[w] && (min+G.arc[k][w]<(*D)[w]))   
			{ /*  �������F��u�����|�A�ק�D[w]�MP[w] */
				(*D)[w] = min + G.arc[k][w];  /* �ק�ثe���|���� */               
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
	ShortPathTable D; /* �D�Y�I���E�U�I���̵u���| */   
	v0=0;
	
	CreateMGraph(&G);
	
	ShortestPath_Dijkstra(G, v0, &P, &D);  

	printf("�̵u���|�˧Ǧp�U:\n");    
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
	printf("\n���I��U���I���̵u���|���׬�:\n");  
	for(i=1;i<G.numVertexes;++i)        
		printf("v%d - v%d : %d \n",G.vexs[0],G.vexs[i],D[i]);     
	return 0;
}