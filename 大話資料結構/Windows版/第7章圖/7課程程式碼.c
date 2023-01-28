

typedef char VertexType; 			/* ����������������  */
typedef int EdgeType; 				/* ������� ������������ */
#define MAXVEX 100 					/* �����N����騡����� */
#define INFINITY 65535				/* ��655354�]�� */
typedef struct
{
	VertexType vexs[MAXVEX]; 		/* ���� */
	EdgeType arc[MAXVEX][MAXVEX];	/* Z�������Y������/
	int numNodes, numEdges; 		/* �����Z������������*/
}MGraph;


/* �����������T���������� */
void CreateMGraph(MGraph *G)
{
	int i,j,k,w;
	printf("��������������n");
	scanf("%d,%d",&G->numNodes,&G->numEdges); 		/* ��������������/
	for(i = 0;i <G->numNodes;i++) 					/* ����â���������� */
		scanf(&G->vexs[i]);
	for(i = 0;i <G->numNodes;i++)
		for(j = 0;j <G->numNodes;j++)
			G->arc[i][j]=INFINITY;					/* Z����������*/
	for(k = 0;k <G->numEdges;k++) 					/* ����mEdges������bZ������/
	{
		printf("������vi,vj)���T�ӡ���������\n");
		scanf("%d,%d,%d",&i,&j,&w); 				/* ������vi,vj)�����h*/
		G->arc[i][j]=w; 
		G->arc[j][i]= G->arc[i][j]; 				/* �������Q������������*/
	}
}


typedef char VertexType; 	/* ���������������� */
typedef int EdgeType; 		/* ������� ������������ */

typedef struct EdgeNode 	/* �����b */
{
	int adjvex;    			/* Z����,�����������T�ӡ�/
	EdgeType info;			/* ����������,�N�������롼���� */
	struct EdgeNode *next; 	/* t��,���������X������/
}EdgeNode;

typedef struct VertexNode 	/* ��������/
{
	VertexType data; 		/* ����,����â����/
	EdgeNode *firstedge;	/* �������� */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int numNodes,numEdges; 	/* �����Z���a������/
}GraphAdjList;


/* �����T��������*/
void  CreateALGraph(GraphAdjList *G)
{
	int i,j,k;
	EdgeNode *e;
	printf("��������������n");
	scanf("%d,%d",&G->numNodes,&G->numEdges); 	/* ��������������/
	for(i = 0;i < G->numNodes;i++) 				/* ����â���������� */
	{
		scanf(&G->adjList[i].data); 			/* ���������� */
		G->adjList[i].firstedge=NULL; 			/* ������������/
	}
	
	
	for(k = 0;k < G->numEdges;k++)				/* ������*/
	{
		printf("������vi,vj)�����N����\n");
		scanf("%d,%d",&i,&j); 					/* ������vi,vj)�����N����*/     
		e=(EdgeNode *)malloc(sizeof(EdgeNode)); /* ���������E���������b*/     
		e->adjvex=j;							/* Z������j */                  
		e->next=G->adjList[i].firstedge;		/* �����������Z���K�����С� */
		G->adjList[i].firstedge=e;				/* ����������������e */          
		e=(EdgeNode *)malloc(sizeof(EdgeNode)); /* ���������E���������b*/     
		e->adjvex=i;							/* Z������i */                  
		e->next=G->adjList[j].firstedge;		/* �����������Z���K�����С� */
		G->adjList[j].firstedge=e;				/* ����������������e */           
	}
}


#define MAXVEX 9
Boolean visited[MAXVEX]; 				/* �{������ */

/* Z���������Ρ��������Y*/
void DFS(MGraph G, int i)
{
	int j;
 	visited[i] = TRUE;
 	printf("%c ", G.vexs[i]);			/* �����B���롼������/
	for(j = 0; j < G.numVertexes; j++)
		if(G.arc[i][j] == 1 && !visited[j])
 			DFS(G, j);					/* �G�����T�����N���ء� */
}

/* Z����������������/
void DFSTraverse(MGraph G)
{
	int i;
 	for(i = 0; i < G.numVertexes; i++)
 		visited[i] = FALSE; 			/* �������������~���������� */
	for(i = 0; i < G.numVertexes; i++)
 		if(!visited[i]) 				/* �G�����졼�N�qAFS����������������*/ 
			DFS(G, i);
}

/* Z�������Ρ��������Y*/
void DFS(GraphAdjList GL, int i)
{
	EdgeNode *p;
 	visited[i] = TRUE;
 	printf("%c ",GL->adjList[i].data);	/* �����С��롼������/
	p = GL->adjList[i].firstedge;
	while(p)
	{
 		if(!visited[p->adjvex])
 			DFS(GL, p->adjvex);			/* �G�����T�����N���ء� */
		p = p->next;
 	}
}

/* Z��������������/
void DFSTraverse(GraphAdjList GL)
{
	int i;
 	for(i = 0; i < GL->numVertexes; i++)
 		visited[i] = FALSE; 			/* �������������~���������� */
	for(i = 0; i < GL->numVertexes; i++)
 		if(!visited[i]) 				/* �G�����졼�N�qAFS,����l����,����������*/ 
			DFS(GL, i);
}


/* Z�������⡼�����Y*/
void BFSTraverse(MGraph G)
{
	int i, j;
	Queue Q;
	for(i = 0; i < G.numVertexes; i++)
       	visited[i] = FALSE;
    InitQueue(&Q);									/* �������W���⡼��*/
    for(i = 0; i < G.numVertexes; i++)  			/* �֊����N������*/
    {
		if (!visited[i])							/* �����_�{��������/
		{
			visited[i]=TRUE;						/* �����Z����I����/
			printf("%c ", G.vexs[i]);				/* �����B���롼������/
			EnQueue(&Q,i);							/* �����N���֡�*/
			while(!QueueEmpty(Q))					/* ���Z��P���� */
			{
				DeQueue(&Q,&i);						/* �������������������� */
				for(j=0;j<G.numVertexes;j++) 
				{ 							
													/* ���}�����W���Z���_�� */
													/* ����������*/
					if(G.arc[i][j] == 1 && !visited[j]) 
					{ 					
 						visited[j]=TRUE;			/* ���������N�������{��*/
						printf("%c ", G.vexs[j]);	/* �����b*/
						EnQueue(&Q,j);				/* ���������N���֡� */
					} 
				} 
			}
		}
	}
}

/* Z�����⡼�����Y*/
void BFSTraverse(GraphAdjList GL)
{
	int i;
    EdgeNode *p;
	Queue Q;
	for(i = 0; i < GL->numVertexes; i++)
       	visited[i] = FALSE;
    InitQueue(&Q);
   	for(i = 0; i < GL->numVertexes; i++)
   	{
		if (!visited[i])
		{
			visited[i]=TRUE;
			printf("%c ",GL->adjList[i].data);	/* �����С��롼������/
			EnQueue(&Q,i);
			while(!QueueEmpty(Q))
			{
				DeQueue(&Q,&i);
				p = GL->adjList[i].firstedge;	/* �����������������n�� */
				while(p)
				{
					if(!visited[p->adjvex])		/* �����N�_��I��*/
 					{
 						visited[p->adjvex]=TRUE;
						printf("%c ",GL->adjList[p->adjvex].data);
						EnQueue(&Q,p->adjvex);	/* �����N���֡�*/
					}
					p = p->next;				/* �������������X������/
				}
			}
		}
	}
}


















































































































































































































































































































































































































































/* Prim���𡼡���������*/
void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];					/* ���]���N��������̡ӡ�/
	int lowcost[MAXVEX];				/* ���]���N������� */
	lowcost[0] = 0;						/* �����򡼡�����0������������*/
	adjvex[0] = 0;						/* �����򡼷�������*/
	for(i = 1; i < G.numVertexes; i++)	/* �����������������N */
	{
		lowcost[i] = G.arc[0][i];		/* ��0������������𪡼���� */
		adjvex[i] = 0;					/* ����⬡��T�ӡ�/
	}
	for(i = 1; i < G.numVertexes; i++)
	{
		min = INFINITY;					/* ������������������������������65535�R*/
		j = 1;k = 0;
		while(j < G.numVertexes)		/* ����������/
		{
			if(lowcost[j]!=0 && lowcost[j] < min)
			{							/* ���𪡼����𪡼��min */
				min = lowcost[j];		/* �����Z������������ */
				k = j;					/* �����������T�ӡ���k */
			}
			j++;
		}
		printf("(%d, %d)\n", adjvex[k], k);	/* ��������������������﷡�*/
		lowcost[k] = 0;						/* �������E��������0,���N����������/
		for(j = 1; j < G.numVertexes; j++)	/* �����R����/
		{	/* ���H�ӡ�k������𪡼���������������������y�� */
			if(lowcost[j]!=0 && G.arc[k][j] < lowcost[j]) 
			{	
				lowcost[j] = G.arc[k][j];	/* ��������������wcost�����f�� */
				adjvex[j] = k;				/* ���ӡ�k���N����jvex */
			}
		}
	}
}

/* �͡�����Edge��쮡���/
typedef struct
{
	int begin;
	int end;
	int weight;
}Edge;   




/* Kruskal���𡼡���������/
void MiniSpanTree_Kruskal(MGraph G)
{
	int i, n, m;
	Edge edges[MAXEDGE];/* ���P����,edge�С���begin,end,weight,�s���� */
	int parent[MAXVEX];	/* ����������4���x��������^��Ϯ */
	
	/* ��������������������������edges���������ߡ����롼*/

	for (i = 0; i < G.numVertexes; i++)
		parent[i] = 0;					/* ������������0 */
	for (i = 0; i < G.numEdges; i++)	/* �����ࡼ��*/
	{
		n = Find(parent,edges[i].begin);
		m = Find(parent,edges[i].end);
		if (n != m) /* ���w������������������������������Ϯ */
		{/* ��������������������������arent���������N����������������*/
			parent[n] = m;
			printf("(%d, %d) %d\n", edges[i].begin, 
				edges[i].end, edges[i].weight);
		}
	}
}

/* �����������]���ӡ�/
int Find(int *parent, int f)
{
	while ( parent[f] > 0)
	{
		f = parent[f];
	}
	return f;
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
		min=INFINITY;    /* �Z����+v0��������+ */        
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

#define MAXEDGE 20
#define MAXVEX 20
#define INFINITY 65535

typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

typedef int Patharc[MAXVEX];    	/* ����������û�������� */
typedef int ShortPathTable[MAXVEX];	/* �����������û��𪡼*/

/*  Dijkstra���q��������G��0���������������N�P�R[v]���꡼��[v] */    
/*  P[v]��ᶡ���������D[v]���r�����N�P�u����*/  
void ShortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D)
{    
	int v,w,k,min;    
	int final[MAXVEX];				/* final[w]=1���\���Nv0��vw���N�P�b*/
	for(v=0; v<G.numVertexes; v++)  /* �������D*/
	{        
		final[v] = 0;				/* �����N�������_������û���� */
		(*D)[v] = G.arc[v0][v];		/* �������������N���r� */
		(*P)[v] = -1;				/* �����P�L��P��-1  */       
	}
	(*D)[v0] = 0;  					/* v0��v0�P�P��*/  
	final[v0] = 1;    				/* v0��v0��㺡��P�b*/        
	/* ��������������v0ᾡ�v��������û */   
	for(v=1; v<G.numVertexes; v++)   
	{
		min=INFINITY;    			/* �Z����+v0��������+ */        
		for(w=0; w<G.numVertexes; w++) /* ����+v0�������N */    
		{            
			if(!final[w] && (*D)[w]<min)             
			{                   
				k=w;                    
				min = (*D)[w];    	/* w����v0������*/            
			}        
		}        
		final[k] = 1;    			/* ���g�������g���N����1 */
		for(w=0; w<G.numVertexes; w++) /* �����Z����û��+ */
		{
			/* ���v�����P�s���������P�w�����ˡ���/
			if(!final[w] && (min+G.arc[k][w]<(*D)[w]))   
			{ 						/*  ���ҡ���������û������[w]��[w] */
				(*D)[w] = min + G.arc[k][w]; /* �������P�u�� */               
				(*P)[w]=k;        
			}       
		}   
	}
}


typedef int Patharc[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];

/* Floyd���q������G��ľ�Nv�����������N�P�R[v][w]���꡼��[v][w]��*/    
void ShortestPath_Floyd(MGraph G, Patharc *P, ShortPathTable *D)
{    
	int v,w,k;    
	for(v=0; v<G.numVertexes; ++v) 		/* ����D��P */  
	{        
		for(w=0; w<G.numVertexes; ++w)  
		{
			(*D)[v][w]=G.arc[v][w];		/* D[v][w]���������򡼡��� */
			(*P)[v][w]=w;				/* ����P */
		}
	}
	for(k=0; k<G.numVertexes; ++k)   
	{
		for(v=0; v<G.numVertexes; ++v)  
		{        
			for(w=0; w<G.numVertexes; ++w)    
			{
				if ((*D)[v][w]>(*D)[v][k]+(*D)[k][w])
				{/* ����������N�P�s�����򡼟z�� */
					(*D)[v][w]=(*D)[v][k]+(*D)[k][w];/* ����}�򡼡����d����*/
					(*P)[v][w]=(*P)[v][k];			 /* �P�K�󡼛ѡ��������N */
				}
			}
		}
	}
}


printf("ľ�N���N�P�J��:\n");    
for(v=0; v<G.numVertexes; ++v)   
{        
	for(w=v+1; w<G.numVertexes; w++)  
	{
		printf("v%d-v%d weight: %d ",v,w,D[v][w]);
		k=P[v][w];				/* ��o�����P�x�N����*/
		printf(" path: %d",v);	/* �����b*/
		while(k!=w)				/* ���tû�����������b*/
		{
			printf(" -> %d",k);	/* �����x�N */
			k=P[k][w];			/* ��I�����P�x�N����*/
		}
		printf(" -> %d\n",w);	/* �����b*/
	}
	printf("\n");
}


typedef struct EdgeNode 		/* �����b */
{
	int adjvex;    				/* Z������ϫ���N�N�b����*/
	int weight;					/* ���������������������롼���� */
	struct EdgeNode *next; 		/* t�����᡼���X������/
}EdgeNode;

typedef struct VertexNode 		/* ��������/
{
	int in;						/* �����r*/
	int data; 					/* ������ϫ������ */
	EdgeNode *firstedge;		/* �������� */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int numVertexes,numEdges; 	/* �����Z���a������/
}graphAdjList,*GraphAdjList;



/* �������������Q���k��������������P���1�������G����*/
Status TopologicalSort(GraphAdjList GL)
{    
	EdgeNode *e;    
	int i,k,gettop;   
	int top=0;  									/* �������������� */
	int count=0;									/* ���������������V��*/    
	int *stack;										/* �������������N����  */   
	stack=(int *)malloc(GL->numVertexes * sizeof(int) );    
	for(i = 0; i<GL->numVertexes; i++)                
		if(0 == GL->adjList[i].in) 					/* ������0���N���� */         
			stack[++top]=i;    
	while(top!=0)    
	{        
		gettop=stack[top--];       					/* ����/ 
		printf("%d -> ",GL->adjList[gettop].data);  /* ��������/   
		count++;        							/* ���������� */        
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)/* �����N����: */      
		{            
			k=e->adjvex;            
			if( !(--GL->adjList[k].in) )  			/* �����NZ�������f��/                 
				stack[++top]=k;        				/* ����0��������������������*/
		}
	}   
	if(count < GL->numVertexes)  					/* count������������������/      
		return ERROR;    
	else       
		return OK;
}


int *etv,*ltv; /* �������M���������M������ */
int *stack2;   /* ������������P����/
int top2;	   /* ����stack2���� */

/* �������� */
Status TopologicalSort(GraphAdjList GL)
{   /* ��GL�Q���k��������������P���1�������G����*/    
	EdgeNode *e;    
	int i,k,gettop;   
	int top=0;  										/* �������������� */
	int count=0;										/* ���������������V��/   
	int *stack;											/* �������������N���� */   
	stack=(int *)malloc(GL->numVertexes * sizeof(int) );    
	for(i = 0; i<GL->numVertexes; i++)                
		if(0 == GL->adjList[i].in) 						/* ������0���N���� */           
			stack[++top]=i;    
	top2=0;    											/* ���� */
	etv=(int *)malloc(GL->numVertexes * sizeof(int) ); 	/* �������M������ */
	for(i=0; i<GL->numVertexes; i++)        
		etv[i]=0;    									/* ���� */
	stack2=(int *)malloc(GL->numVertexes * sizeof(int) );/* ����������P�� */
	while(top!=0)    
	{        
		gettop=stack[top--];        
		count++;        				/* �������N������ */ 
		stack2[++top2]=gettop;        	/* �������N�����t������P����/
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)        
		{            
			k=e->adjvex;            
			if( !(--GL->adjList[k].in))                
				stack[++top]=k; 
			if((etv[gettop] + e->weight) > etv[k]) /* ��ľ�N���������M����tv�� */
				etv[k] = etv[gettop] + e->weight;
		}    
	}    
	if(count < GL->numVertexes)        
		return ERROR;    
	else       
		return OK;
}


int *etv,*ltv; /* �������M���������M������ */
int *stack2;   /* ������������P����/
int top2;	   /* ����stack2���� */



/* ���ڡ��nGL������������G�د\�ڡ��j*/
void CriticalPath(GraphAdjList GL) 
{    
	EdgeNode *e;    
	int i,gettop,k,j;    
	int ete,lte;  			/* ���ҡ��١��M���������M������ */        
	TopologicalSort(GL);   	/* ��������P��������etv��tack2�ʳ�/ 
	ltv=(int *)malloc(GL->numVertexes*sizeof(int));/* �������M������ */   
	for(i=0; i<GL->numVertexes; i++)        
		ltv[i]=etv[GL->numVertexes-1];    		/* ����ltv */        
	while(top2!=0)    							/* ����v */    
	{        
		gettop=stack2[top2--];        
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)         
		{          
			k=e->adjvex;            
			if(ltv[k] - e->weight < ltv[gettop])/*��ľ�N�������M����tv*/               
				ltv[gettop] = ltv[k] - e->weight;        
		}   
	}    
	for(j=0; j<GL->numVertexes; j++)        	/* ��ete,lte�������j*/        
	{            
		for(e = GL->adjList[j].firstedge; e; e = e->next)            
		{                
			k=e->adjvex;                
			ete = etv[j];        				/* ���١��M����*/                
			lte = ltv[k] - e->weight; 			/* ���١�������*/               
			if(ete == lte)    					/* }�����T���ڡ��K��*/                    
				printf("<v%d - v%d> length: %d \n",
					GL->adjList[j].data,GL->adjList[k].data,e->weight);
		}        
	}
}




