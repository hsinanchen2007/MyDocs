

typedef char VertexType; 			/* ·¥¡¼¡¼¡¼¡¼¡¼¡¼¡¼  */
typedef int EdgeType; 				/* ¡¼¡¼¡¼ðª ¡¼¡¼¡¼¡¼¡¼¡¼ */
#define MAXVEX 100 					/* ¡¼¡¼ÝN¡¼¡¼é¨¡¼¡¼¡¼ */
#define INFINITY 65535				/* ¡¼655354©]¡¼ */
typedef struct
{
	VertexType vexs[MAXVEX]; 		/* ·¥¡¼ */
	EdgeType arc[MAXVEX][MAXVEX];	/* Z¡¼¡¼¡¼‡Y¡¼¡¼¡¼/
	int numNodes, numEdges; 		/* ¡¼¡¼ÌZ¡¼·¥¡¼¡¼¡¼¡¼*/
}MGraph;


/* ¡¼¡¼¡¼¡¼¡¼«T¡¼¡¼¡¼¡¼¡¼ */
void CreateMGraph(MGraph *G)
{
	int i,j,k,w;
	printf("¡¼¡¼·¥¡¼¡¼¡¼¡¼n");
	scanf("%d,%d",&G->numNodes,&G->numEdges); 		/* ¡¼¡¼·¥¡¼¡¼¡¼¡¼/
	for(i = 0;i <G->numNodes;i++) 					/* ¡¼¡¼Ã¢¡¼¡¼¡¼·¥¡¼ */
		scanf(&G->vexs[i]);
	for(i = 0;i <G->numNodes;i++)
		for(j = 0;j <G->numNodes;j++)
			G->arc[i][j]=INFINITY;					/* Z¡¼¡¼¡¼¡¼¡¼*/
	for(k = 0;k <G->numEdges;k++) 					/* ¡¼¡¼mEdges¡¼¡¼¡¼bZ¡¼¡¼¡¼/
	{
		printf("¡¼¡¼¡¼vi,vj)¡¼ßT¡Ó¡¼¡¼¡¼¡¼¸ö\n");
		scanf("%d,%d,%d",&i,&j,&w); 				/* ¡¼¡¼¡¼vi,vj)¡¼»ûàh*/
		G->arc[i][j]=w; 
		G->arc[j][i]= G->arc[i][j]; 				/* ¡¼¡¼¡¼£Q¡¼¡¼¡¼¡¼¡¼¡¼*/
	}
}


typedef char VertexType; 	/* ·¥¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */
typedef int EdgeType; 		/* ¡¼¡¼¡¼ðª ¡¼¡¼¡¼¡¼¡¼¡¼ */

typedef struct EdgeNode 	/* ¡¼¡¼Ãb */
{
	int adjvex;    			/* Z¡¼¡¼,¡¼¡¼·¥¡¼¡¼ßT¡Ó¡¼/
	EdgeType info;			/* ¡¼¡¼¡¼£¾¡¼,ôN¡¼¡¼²þ†ë¡¼¡¼¡¼ */
	struct EdgeNode *next; 	/* t¡¼,¡¼¡¼¡¼¡¼¶X¡¼¡¼¡¼/
}EdgeNode;

typedef struct VertexNode 	/* ·¥¡¼¡¼¡¼/
{
	VertexType data; 		/* ·¥¡¼,¡¼¡¼Ã¢¡¼¡¼/
	EdgeNode *firstedge;	/* ¡¼¡¼¡¼¡¼ */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int numNodes,numEdges; 	/* ¡¼¡¼ÌZ¡¼Ãa¡¼¡¼¡¼/
}GraphAdjList;


/* ¡¼¡¼«T¡¼¡¼¡¼ö¿*/
void  CreateALGraph(GraphAdjList *G)
{
	int i,j,k;
	EdgeNode *e;
	printf("¡¼¡¼·¥¡¼¡¼¡¼¡¼n");
	scanf("%d,%d",&G->numNodes,&G->numEdges); 	/* ¡¼¡¼·¥¡¼¡¼¡¼¡¼/
	for(i = 0;i < G->numNodes;i++) 				/* ¡¼¡¼Ã¢¡¼¡¼¡¼·¥¡¼ */
	{
		scanf(&G->adjList[i].data); 			/* ¡¼¡¼·¥¡¼¡¼ */
		G->adjList[i].firstedge=NULL; 			/* ¡¼¡¼¡¼¡¼‹ù¡¼/
	}
	
	
	for(k = 0;k < G->numEdges;k++)				/* ¡¼¡¼¡¼*/
	{
		printf("¡¼¡¼¡¼vi,vj)¡¼ÄâÝN¡¼¡¼\n");
		scanf("%d,%d",&i,&j); 					/* ¡¼¡¼¡¼vi,vj)¡¼ÄâÝN¡¼¡¼*/     
		e=(EdgeNode *)malloc(sizeof(EdgeNode)); /* ¡¼¡¼¡¼¡¼ŒE¡¼¡¼¡¼¡¼Ãb*/     
		e->adjvex=j;							/* Z¡¼¡¼¡¼j */                  
		e->next=G->adjList[i].firstedge;		/* ¡¼ºÊêú¡¼¡¼ÌZ¡¼éK¡¼µá÷Ð¡¼ */
		G->adjList[i].firstedge=e;				/* ¡¼¡¼·¥¡¼¡¼¡¼¡¼¡¼e */          
		e=(EdgeNode *)malloc(sizeof(EdgeNode)); /* ¡¼¡¼¡¼¡¼ŒE¡¼¡¼¡¼¡¼Ãb*/     
		e->adjvex=i;							/* Z¡¼¡¼¡¼i */                  
		e->next=G->adjList[j].firstedge;		/* ¡¼ºÊêú¡¼¡¼ÌZ¡¼éK¡¼µá÷Ð¡¼ */
		G->adjList[j].firstedge=e;				/* ¡¼¡¼·¥¡¼¡¼¡¼¡¼¡¼e */           
	}
}


#define MAXVEX 9
Boolean visited[MAXVEX]; 				/* Ò{¡¼¡¼äñ¡¼ */

/* Z¡¼¡¼¡¼¡¼©Î¡¼¡¼¡¼¨¸¸Y*/
void DFS(MGraph G, int i)
{
	int j;
 	visited[i] = TRUE;
 	printf("%c ", G.vexs[i]);			/* ¡¼¡¼ôB¡¼†ë¡¼¡¼¡¼Òä/
	for(j = 0; j < G.numVertexes; j++)
		if(G.arc[i][j] == 1 && !visited[j])
 			DFS(G, j);					/* òG¡¼¡¼«T¡¼¡¼ÝN¥ÞóØ¡¼ */
}

/* Z¡¼¡¼¡¼¡¼À¸»·¡¼Òä/
void DFSTraverse(MGraph G)
{
	int i;
 	for(i = 0; i < G.numVertexes; i++)
 		visited[i] = FALSE; 			/* ¡¼¡¼¡¼·¥¡¼¡¼â~¡¼¡¼¡¼óû¡¼ */
	for(i = 0; i < G.numVertexes; i++)
 		if(!visited[i]) 				/* òG¡¼¡¼øì¡¼ÝNÅqAFS¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼*/ 
			DFS(G, i);
}

/* Z¡¼¡¼¡¼©Î¡¼¡¼¡¼¨¸¸Y*/
void DFS(GraphAdjList GL, int i)
{
	EdgeNode *p;
 	visited[i] = TRUE;
 	printf("%c ",GL->adjList[i].data);	/* ¡¼¡¼¤Ð¡¼†ë¡¼¡¼¡¼Òä/
	p = GL->adjList[i].firstedge;
	while(p)
	{
 		if(!visited[p->adjvex])
 			DFS(GL, p->adjvex);			/* òG¡¼¡¼«T¡¼¡¼ÝN¥ÞóØ¡¼ */
		p = p->next;
 	}
}

/* Z¡¼¡¼¡¼À¸»·¡¼Òä/
void DFSTraverse(GraphAdjList GL)
{
	int i;
 	for(i = 0; i < GL->numVertexes; i++)
 		visited[i] = FALSE; 			/* ¡¼¡¼¡¼·¥¡¼¡¼â~¡¼¡¼¡¼óû¡¼ */
	for(i = 0; i < GL->numVertexes; i++)
 		if(!visited[i]) 				/* òG¡¼¡¼øì¡¼ÝNÅqAFS,¡¼¡¼l¡¼¡¼,¡¼¡¼¡¼¡¼¡¼*/ 
			DFS(GL, i);
}


/* Z¡¼¡¼¡¼àâ¡¼»·¡¼¸Y*/
void BFSTraverse(MGraph G)
{
	int i, j;
	Queue Q;
	for(i = 0; i < G.numVertexes; i++)
       	visited[i] = FALSE;
    InitQueue(&Q);									/* ¡¼¡¼¡¼°W¡¼Äâ¡¼¡¼*/
    for(i = 0; i < G.numVertexes; i++)  			/* ïÖŠàÓçÝN¡¼¡¼¡¼*/
    {
		if (!visited[i])							/* ¡¼¡¼£_Ò{¡¼¡¼¡¼¡¼/
		{
			visited[i]=TRUE;						/* ¡¼¡¼ÌZ¡¼³ýI¡¼¡¼/
			printf("%c ", G.vexs[i]);				/* ¡¼¡¼ôB¡¼†ë¡¼¡¼¡¼Òä/
			EnQueue(&Q,i);							/* ¡¼¡¼ÝN¡¼¾Ö¡¼*/
			while(!QueueEmpty(Q))					/* ¡¼ÌZ¡¼P¡¼¡¼ */
			{
				DeQueue(&Q,&i);						/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼½ò */
				for(j=0;j<G.numVertexes;j++) 
				{ 							
													/* ¡¼´}¡¼·¥¦W¡¼ÌZ¡¼Î_¡¼ */
													/* ¡¼¡¼¡¼¡¼õ»*/
					if(G.arc[i][j] == 1 && !visited[j]) 
					{ 					
 						visited[j]=TRUE;			/* ¡¼¡¼¡¼¡¼ÝN¡¼¡¼¡¼Ò{¡¼*/
						printf("%c ", G.vexs[j]);	/* ¡¼¡¼Ãb*/
						EnQueue(&Q,j);				/* ¡¼¡¼¡¼¡¼ÝN¡¼¾Ö¡¼ */
					} 
				} 
			}
		}
	}
}

/* Z¡¼¡¼àâ¡¼»·¡¼¸Y*/
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
			printf("%c ",GL->adjList[i].data);	/* ¡¼¡¼¤Ð¡¼†ë¡¼¡¼¡¼Òä/
			EnQueue(&Q,i);
			while(!QueueEmpty(Q))
			{
				DeQueue(&Q,&i);
				p = GL->adjList[i].firstedge;	/* ¡¼­£¡¼·¥¡¼¡¼¡¼¡¼¯n¡¼ */
				while(p)
				{
					if(!visited[p->adjvex])		/* ¡¼¡¼ÝN£_¡¼I¡¼*/
 					{
 						visited[p->adjvex]=TRUE;
						printf("%c ",GL->adjList[p->adjvex].data);
						EnQueue(&Q,p->adjvex);	/* ¡¼¡¼ÝN¡¼¾Ö¡¼*/
					}
					p = p->next;				/* ¡¼¡¼¡¼¡¼¡¼¡¼¶X¡¼¡¼¡¼/
				}
			}
		}
	}
}


















































































































































































































































































































































































































































/* Prim¡¼±ð¡¼¡¼¡¼¡¼¡¼¯£*/
void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];					/* ¡¼Ù]¶¥ÝN¡¼¡¼¡¼ðªìÌ¡Ó¡¼/
	int lowcost[MAXVEX];				/* ¡¼Ù]¶¥ÝN¡¼¡¼¡¼ðª */
	lowcost[0] = 0;						/* ¡¼¡¼»ò¡¼¡¼¡¼¡¼0¡¼¡¼¡¼¡¼¡¼¡¼*/
	adjvex[0] = 0;						/* ¡¼¡¼»ò¡¼·¥¡¼¡¼¡¼*/
	for(i = 1; i < G.numVertexes; i++)	/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ÝN */
	{
		lowcost[i] = G.arc[0][i];		/* ¡¼0·¥¡¼¡¼¡¼¡¼¡¼ðª¡¼¡¼¡¼ */
		adjvex[i] = 0;					/* ¡¼¡¼â¬¡¼ßT¡Ó¡¼/
	}
	for(i = 1; i < G.numVertexes; i++)
	{
		min = INFINITY;					/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼65535§R*/
		j = 1;k = 0;
		while(j < G.numVertexes)		/* ¡¼¡¼¡¼·¥¡¼/
		{
			if(lowcost[j]!=0 && lowcost[j] < min)
			{							/* ¡¼ï®ðª¡¼¡¼¡¼ðª¡¼¡¼min */
				min = lowcost[j];		/* ¡¼¡¼ÌZ¡¼¡¼¡¼¡¼¡¼¡¼ */
				k = j;					/* ¡¼¡¼¡¼¡¼¡¼ßT¡Ó¡¼¡¼k */
			}
			j++;
		}
		printf("(%d, %d)\n", adjvex[k], k);	/* ¡¼¡¼¡¼·¥¡¼¡¼¡¼¡¼¡¼¡¼ï·¡¼*/
		lowcost[k] = 0;						/* ¡¼¡¼·¥¤E¡¼¡¼¡¼¡¼0,¡¼ÝN¡¼¡¼¡¼¡¼¡¼/
		for(j = 1; j < G.numVertexes; j++)	/* ¡¼¡¼¾R·¥¡¼/
		{	/* ¡¼ÂH¡Ó¡¼k·¥¡¼¡¼ðª¡¼¡¼¡¼¡¼¡¼·¥¡¼¡¼¡¼¡¼¡¼Æy¡¼ */
			if(lowcost[j]!=0 && G.arc[k][j] < lowcost[j]) 
			{	
				lowcost[j] = G.arc[k][j];	/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼wcost¡¼¡¼£f¡¼ */
				adjvex[j] = k;				/* ¡¼¡Ó¡¼kÄâÝN¡¼¡¼jvex */
			}
		}
	}
}

/* ÊÍ¡¼‡¹¡¼Edge¡¼ì®¡¼³ô/
typedef struct
{
	int begin;
	int end;
	int weight;
}Edge;   




/* Kruskal¡¼±ð¡¼¡¼¡¼¡¼¡¼Òä/
void MiniSpanTree_Kruskal(MGraph G)
{
	int i, n, m;
	Edge edges[MAXEDGE];/* ¡¼±P¡¼¡¼,edge÷Ð¡¼¡¼begin,end,weight, s¡¼¡¼ */
	int parent[MAXVEX];	/* ¡¼«¦¡¼¡¼¡¼4¡¼Ýx¡¼¡¼¡¼Äð£^¡¼Ï® */
	
	/* ¡¼±Á¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼‡¹¡¼edges¡¼¡¼¡¼¡¼Éß¡¼¡¼ñë¡¼*/

	for (i = 0; i < G.numVertexes; i++)
		parent[i] = 0;					/* ¡¼¡¼¡¼¡¼¡¼¡¼0 */
	for (i = 0; i < G.numEdges; i++)	/* ¡¼¡¼Šà¡¼¡¼*/
	{
		n = Find(parent,edges[i].begin);
		m = Find(parent,edges[i].end);
		if (n != m) /* ¡¼Ûw¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼»ü¡¼¡¼¡¼¡¼Ï® */
		{/* ¡¼¡¼¡¼¡¼¡¼·¥¡¼¡¼¡¼¡¼¡¼§§¡¼arent¡¼¡¼¡¼¡¼ÝN¡¼›¬¡¼¡¼¡¼¡¼¡¼¡¼*/
			parent[n] = m;
			printf("(%d, %d) %d\n", edges[i].begin, 
				edges[i].end, edges[i].weight);
		}
	}
}

/* ¡¼¡¼¡¼·¥¡¼£]¡¼¡Ó¡¼/
int Find(int *parent, int f)
{
	while ( parent[f] > 0)
	{
		f = parent[f];
	}
	return f;
}

/*  Dijkstra¡¼¿q¡¼¡¼¡¼¡¼GÄâ0·¥¡¼¡¼¡¼·¥¡¼¡¼ŸN¡PŸR[v]¡¼¯ê¡¼¡¼[v] */    
/*  P[v]ºÊá¶¡¼¡¼·¥¡¼¡¼D[v]¡¼ŸrÊÕèöŸN¡PŸu¡¼¡¼*/  
void ShortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D)
{    
	int v,w,k,min;    
	int final[MAXVEX];/* final[w]=1¡¼ý\äìÝNv0¡¼vwèöŸN¡PŸb*/
	for(v=0; v<G.numVertexes; v++)    /* ¡¼¡¼¡¼•D*/
	{        
		final[v] = 0;			/* ¡¼¡¼ÝN¡¼¡¼¡¼£_¡¼¡¼±¾Ã»¡¼¡¼ */
		(*D)[v] = G.arc[v0][v];/* ¡¼¡¼À£¡¼¡¼ÄâÝN¡¼£rðª */
		(*P)[v] = -1;				/* ¡¼¡¼¡PŸL¡¼P¡¼-1  */       
	}

	(*D)[v0] = 0;  /* v0¡¼v0¡PŸP¡¼*/  
	final[v0] = 1;    /* v0¡¼v0¡¼ãº¡¼¡PŸb*/        
	/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼v0á¾¡¼v·¥¡¼¡¼±¾Ã» */   
	for(v=1; v<G.numVertexes; v++)   
	{
		min=INFINITY;    /* ÌZ¡¼¡¼+v0·¥¡¼¡¼¡¼+ */        
		for(w=0; w<G.numVertexes; w++) /* ¡¼¡¼+v0¡¼¡¼¡¼ÝN */    
		{            
			if(!final[w] && (*D)[w]<min)             
			{                   
				k=w;                    
				min = (*D)[w];    /* w·¥¡¼v0·¥¡¼¡¼*/            
			}        
		}        
		final[k] = 1;    /* ¡¼†g¡¼­£¡¼‚gÄâÝN¡¼¡¼1 */
		for(w=0; w<G.numVertexes; w++) /* ¡¼¡¼ÌZ¡¼±¾Ã»¡¼+ */
		{
			/* ¡¼àï¡¼v·¥¡¼¡PŸs¡¼¡¼¡¼¡¼¡PŸw¡¼¡¼§Ë¡¼¡¼/
			if(!final[w] && (min+G.arc[k][w]<(*D)[w]))   
			{ /*  ¡¼¡Ò¡¼¡¼¡¼¡¼»úÃ»¡¼¡¼¡¼[w]¡¼[w] */
				(*D)[w] = min + G.arc[k][w];  /* ¡¼¡¼¡¼¡PŸu¡¼ */               
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

typedef int Patharc[MAXVEX];    	/* ¡¼¡¼¡¼¡¼±¾Ã»¡¼¡¼¡¼¡¼ */
typedef int ShortPathTable[MAXVEX];	/* ¡¼¡¼¡¼¡¼½î¡¼±¾Ã»»ûðª¡¼*/

/*  Dijkstra¡¼¿q¡¼¡¼¡¼¡¼GÄâ0·¥¡¼¡¼¡¼·¥¡¼¡¼ŸN¡PŸR[v]¡¼¯ê¡¼¡¼[v] */    
/*  P[v]ºÊá¶¡¼¡¼·¥¡¼¡¼D[v]¡¼ŸrÊÕèöŸN¡PŸu¡¼¡¼*/  
void ShortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D)
{    
	int v,w,k,min;    
	int final[MAXVEX];				/* final[w]=1¡¼ý\äìÝNv0¡¼vwèöŸN¡PŸb*/
	for(v=0; v<G.numVertexes; v++)  /* ¡¼¡¼¡¼•D*/
	{        
		final[v] = 0;				/* ¡¼¡¼ÝN¡¼¡¼¡¼£_¡¼¡¼±¾Ã»¡¼¡¼ */
		(*D)[v] = G.arc[v0][v];		/* ¡¼¡¼À£¡¼¡¼ÄâÝN¡¼£rðª */
		(*P)[v] = -1;				/* ¡¼¡¼¡PŸL¡¼P¡¼-1  */       
	}
	(*D)[v0] = 0;  					/* v0¡¼v0¡PŸP¡¼*/  
	final[v0] = 1;    				/* v0¡¼v0¡¼ãº¡¼¡PŸb*/        
	/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼v0á¾¡¼v·¥¡¼¡¼±¾Ã» */   
	for(v=1; v<G.numVertexes; v++)   
	{
		min=INFINITY;    			/* ÌZ¡¼¡¼+v0·¥¡¼¡¼¡¼+ */        
		for(w=0; w<G.numVertexes; w++) /* ¡¼¡¼+v0¡¼¡¼¡¼ÝN */    
		{            
			if(!final[w] && (*D)[w]<min)             
			{                   
				k=w;                    
				min = (*D)[w];    	/* w·¥¡¼v0·¥¡¼¡¼*/            
			}        
		}        
		final[k] = 1;    			/* ¡¼†g¡¼­£¡¼‚gÄâÝN¡¼¡¼1 */
		for(w=0; w<G.numVertexes; w++) /* ¡¼¡¼ÌZ¡¼±¾Ã»¡¼+ */
		{
			/* ¡¼àï¡¼v·¥¡¼¡PŸs¡¼¡¼¡¼¡¼¡PŸw¡¼¡¼§Ë¡¼¡¼/
			if(!final[w] && (min+G.arc[k][w]<(*D)[w]))   
			{ 						/*  ¡¼¡Ò¡¼¡¼¡¼¡¼»úÃ»¡¼¡¼¡¼[w]¡¼[w] */
				(*D)[w] = min + G.arc[k][w]; /* ¡¼¡¼¡¼¡PŸu¡¼ */               
				(*P)[w]=k;        
			}       
		}   
	}
}


typedef int Patharc[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];

/* Floyd¡¼¿q¡¼¡¼¡¼G¡¼Ä¾ÝNv¹û¡¼·¥¡¼¡¼ŸN¡PŸR[v][w]¡¼¯ê¡¼¡¼[v][w]¡¼*/    
void ShortestPath_Floyd(MGraph G, Patharc *P, ShortPathTable *D)
{    
	int v,w,k;    
	for(v=0; v<G.numVertexes; ++v) 		/* ¡¼¡¼D¡¼P */  
	{        
		for(w=0; w<G.numVertexes; ++w)  
		{
			(*D)[v][w]=G.arc[v][w];		/* D[v][w]¡¼¡¼¡¼¡¼Üò¡¼¡¼¡¼ */
			(*P)[v][w]=w;				/* ¡¼¡¼P */
		}
	}
	for(k=0; k<G.numVertexes; ++k)   
	{
		for(v=0; v<G.numVertexes; ++v)  
		{        
			for(w=0; w<G.numVertexes; ++w)    
			{
				if ((*D)[v][w]>(*D)[v][k]+(*D)[k][w])
				{/* ¡¼àï¡¼¡¼¡¼¡¼ÝN¡PŸs¡¼¡¼Üò¡¼Ÿz¡¼ */
					(*D)[v][w]=(*D)[v][k]+(*D)[k][w];/* ¡¼¡¼}Üò¡¼¡¼¡¼äd¡¼çï*/
					(*P)[v][w]=(*P)[v][k];			 /* ¡PŸKíó¡¼›Ñ¡¼¡¼¡¼¡¼ÝN */
				}
			}
		}
	}
}


printf("Ä¾ÝN¡¼ŸN¡PŸJÏÈ:\n");    
for(v=0; v<G.numVertexes; ++v)   
{        
	for(w=v+1; w<G.numVertexes; w++)  
	{
		printf("v%d-v%d weight: %d ",v,w,D[v][w]);
		k=P[v][w];				/* ¡¼o¡¼¡¼¡PŸxÝN¡¼¡¼*/
		printf(" path: %d",v);	/* ¡¼¡¼Ãb*/
		while(k!=w)				/* ¡¼øtÃ»·¥¡¼¡¼¡¼¡¼Ãb*/
		{
			printf(" -> %d",k);	/* ¡¼¡¼ŸxÝN */
			k=P[k][w];			/* ¡¼I¡¼¡¼¡PŸxÝN¡¼¡¼*/
		}
		printf(" -> %d\n",w);	/* ¡¼¡¼Ãb*/
	}
	printf("\n");
}


typedef struct EdgeNode 		/* ¡¼¡¼Ãb */
{
	int adjvex;    				/* Z¡¼¡¼¡¼Ï«½¦ÝNôN²b¡¼¡¼*/
	int weight;					/* ¡¼¡¼¡¼£¾¡¼¡¼¡¼¡¼¡¼²þ†ë¡¼¡¼¡¼ */
	struct EdgeNode *next; 		/* t¡¼¡¼µá¡¼¡¼¶X¡¼¡¼¡¼/
}EdgeNode;

typedef struct VertexNode 		/* ·¥¡¼¡¼¡¼/
{
	int in;						/* ·¥¤õÝr*/
	int data; 					/* ·¥¡¼¡¼Ï«·¥¡¼¡¼ */
	EdgeNode *firstedge;		/* ¡¼¡¼¡¼¡¼ */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int numVertexes,numEdges; 	/* ¡¼¡¼ÌZ¡¼Ãa¡¼¡¼¡¼/
}graphAdjList,*GraphAdjList;



/* ¡¼¡¼¡¼¡¼¡¼¡¼£Q¡¼¿k¡¼¡¼¡¼¡¼¡¼¡¼¡¼P¡¼áµ1¡¼¡¼¡¼ãG¡¼¡¼*/
Status TopologicalSort(GraphAdjList GL)
{    
	EdgeNode *e;    
	int i,k,gettop;   
	int top=0;  									/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */
	int count=0;									/* ¡¼¡¼¡¼¡¼¡¼·¥¡¼¶V¡¼*/    
	int *stack;										/* ¡¼¡¼¡¼¦¥¡¼¡¼ÝN¡¼¡¼  */   
	stack=(int *)malloc(GL->numVertexes * sizeof(int) );    
	for(i = 0; i<GL->numVertexes; i++)                
		if(0 == GL->adjList[i].in) 					/* ¡¼¡¼¡¼0ÄâÝN¡¼¡¼ */         
			stack[++top]=i;    
	while(top!=0)    
	{        
		gettop=stack[top--];       					/* ¡¼¡¼/ 
		printf("%d -> ",GL->adjList[gettop].data);  /* ¡¼¡¼·¥¡¼/   
		count++;        							/* ¡¼¡¼¡¼·¥¡¼ */        
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)/* ¡¼¡¼ÝN¡¼¡¼: */      
		{            
			k=e->adjvex;            
			if( !(--GL->adjList[k].in) )  			/* ¡¼¡¼ÝNZ¡¼¡¼¡¼¥fïÃ/                 
				stack[++top]=k;        				/* ¡¼¡¼0¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼*/
		}
	}   
	if(count < GL->numVertexes)  					/* count¡¼¡¼·¥¡¼¡¼¡¼¡¼¡¼Òä/      
		return ERROR;    
	else       
		return OK;
}


int *etv,*ltv; /* ¡¼¡¼‘¡¸M¡¼¡¼¡¼÷¸M¡¼¡¼¡¼ */
int *stack2;   /* ¡¼¡¼¡¼¡¼¡¼¡¼P¾«¡¼/
int top2;	   /* ¡¼¡¼stack2ºÊêú */

/* ¡¼¡¼¡¼¡¼ */
Status TopologicalSort(GraphAdjList GL)
{   /* ¡¼GL£Q¡¼¿k¡¼¡¼¡¼¡¼¡¼¡¼¡¼P¡¼áµ1¡¼¡¼¡¼ãG¡¼¡¼*/    
	EdgeNode *e;    
	int i,k,gettop;   
	int top=0;  										/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */
	int count=0;										/* ¡¼¡¼¡¼¡¼¡¼·¥¡¼¶V¡¼/   
	int *stack;											/* ¡¼¡¼¡¼¦¥¡¼¡¼ÝN¡¼¡¼ */   
	stack=(int *)malloc(GL->numVertexes * sizeof(int) );    
	for(i = 0; i<GL->numVertexes; i++)                
		if(0 == GL->adjList[i].in) 						/* ¡¼¡¼¡¼0ÄâÝN¡¼¡¼ */           
			stack[++top]=i;    
	top2=0;    											/* ¡¼¡¼ */
	etv=(int *)malloc(GL->numVertexes * sizeof(int) ); 	/* ¡¼¡¼‘¡¸M¡¼¡¼¡¼ */
	for(i=0; i<GL->numVertexes; i++)        
		etv[i]=0;    									/* ¡¼¡¼ */
	stack2=(int *)malloc(GL->numVertexes * sizeof(int) );/* ¡¼¡¼¡¼¡¼¡¼P¡¼ */
	while(top!=0)    
	{        
		gettop=stack[top--];        
		count++;        				/* ¡¼¡¼¡¼ÝN¡¼¡¼¡¼ */ 
		stack2[++top2]=gettop;        	/* ¡¼¡¼ÄâÝN¡¼¡¼Üt¡¼¡¼¡¼P¾«¡¼/
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)        
		{            
			k=e->adjvex;            
			if( !(--GL->adjList[k].in))                
				stack[++top]=k; 
			if((etv[gettop] + e->weight) > etv[k]) /* ¡¼Ä¾ÝN¡¼¡¼¡¼‘¡¸M¡¼¡¼tv¡¼ */
				etv[k] = etv[gettop] + e->weight;
		}    
	}    
	if(count < GL->numVertexes)        
		return ERROR;    
	else       
		return OK;
}


int *etv,*ltv; /* ¡¼¡¼‘¡¸M¡¼¡¼¡¼÷¸M¡¼¡¼¡¼ */
int *stack2;   /* ¡¼¡¼¡¼¡¼¡¼¡¼P¾«¡¼/
int top2;	   /* ¡¼¡¼stack2ºÊêú */



/* ¡¼ÍÚ¡¼ŸnGL¡¼¡¼¡¼¡¼¡¼¡¼GÄØ¯\ÍÚ¡¼Ïj*/
void CriticalPath(GraphAdjList GL) 
{    
	EdgeNode *e;    
	int i,gettop,k,j;    
	int ete,lte;  			/* ¡¼¡Ò¡¼ŒÙ¡¼¸M¡¼¡¼¡¼÷¸M¡¼¡¼¡¼ */        
	TopologicalSort(GL);   	/* ¡¼¡¼¡¼¡¼P¡¼¡¼¡¼¡¼etv¡¼tack2ºÊ³ô/ 
	ltv=(int *)malloc(GL->numVertexes*sizeof(int));/* ¡¼¡¼‘¡¸M¡¼¡¼¡¼ */   
	for(i=0; i<GL->numVertexes; i++)        
		ltv[i]=etv[GL->numVertexes-1];    		/* ¡¼¡¼ltv */        
	while(top2!=0)    							/* ¡¼¡¼v */    
	{        
		gettop=stack2[top2--];        
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)         
		{          
			k=e->adjvex;            
			if(ltv[k] - e->weight < ltv[gettop])/*¡¼Ä¾ÝN¡¼¡¼Ž¾¸M¡¼¡¼tv*/               
				ltv[gettop] = ltv[k] - e->weight;        
		}   
	}    
	for(j=0; j<GL->numVertexes; j++)        	/* ¡¼ete,lte¡¼¡¼¡¼Ïj*/        
	{            
		for(e = GL->adjList[j].firstedge; e; e = e->next)            
		{                
			k=e->adjvex;                
			ete = etv[j];        				/* ¡¼ŒÙ¡¼¸M¡¼¡¼*/                
			lte = ltv[k] - e->weight; 			/* ¡¼ŒÙ¡¼¡¼¡¼¡¼*/               
			if(ete == lte)    					/* }¡¼¡¼§T¡¼ÍÚ¡¼ŸK¡¼*/                    
				printf("<v%d - v%d> length: %d \n",
					GL->adjList[j].data,GL->adjList[k].data,e->weight);
		}        
	}
}




