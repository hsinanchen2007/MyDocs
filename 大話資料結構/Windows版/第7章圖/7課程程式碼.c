

typedef char VertexType; 			/* 轡ーーーーーーー  */
typedef int EdgeType; 				/* ーーー險 ーーーーーー */
#define MAXVEX 100 					/* ーー�Nーー薑ーーー */
#define INFINITY 65535				/* ー655354�]ー */
typedef struct
{
	VertexType vexs[MAXVEX]; 		/* 轡ー */
	EdgeType arc[MAXVEX][MAXVEX];	/* Zーーー�Yーーー/
	int numNodes, numEdges; 		/* ーー�Zー轡ーーーー*/
}MGraph;


/* ーーーーー�Tーーーーー */
void CreateMGraph(MGraph *G)
{
	int i,j,k,w;
	printf("ーー轡ーーーーn");
	scanf("%d,%d",&G->numNodes,&G->numEdges); 		/* ーー轡ーーーー/
	for(i = 0;i <G->numNodes;i++) 					/* ーー但ーーー轡ー */
		scanf(&G->vexs[i]);
	for(i = 0;i <G->numNodes;i++)
		for(j = 0;j <G->numNodes;j++)
			G->arc[i][j]=INFINITY;					/* Zーーーーー*/
	for(k = 0;k <G->numEdges;k++) 					/* ーーmEdgesーーーbZーーー/
	{
		printf("ーーーvi,vj)ー�T〉ーーーー倖\n");
		scanf("%d,%d,%d",&i,&j,&w); 				/* ーーーvi,vj)ー寺�h*/
		G->arc[i][j]=w; 
		G->arc[j][i]= G->arc[i][j]; 				/* ーーー�Qーーーーーー*/
	}
}


typedef char VertexType; 	/* 轡ーーーーーーー */
typedef int EdgeType; 		/* ーーー險 ーーーーーー */

typedef struct EdgeNode 	/* ーー�b */
{
	int adjvex;    			/* Zーー,ーー轡ーー�T〉ー/
	EdgeType info;			/* ーーー�勝�,�Nーー改�襦次次� */
	struct EdgeNode *next; 	/* tー,ーーーー�Xーーー/
}EdgeNode;

typedef struct VertexNode 	/* 轡ーーー/
{
	VertexType data; 		/* 轡ー,ーー但ーー/
	EdgeNode *firstedge;	/* ーーーー */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int numNodes,numEdges; 	/* ーー�Zー�aーーー/
}GraphAdjList;


/* ーー�Tーーー��*/
void  CreateALGraph(GraphAdjList *G)
{
	int i,j,k;
	EdgeNode *e;
	printf("ーー轡ーーーーn");
	scanf("%d,%d",&G->numNodes,&G->numEdges); 	/* ーー轡ーーーー/
	for(i = 0;i < G->numNodes;i++) 				/* ーー但ーーー轡ー */
	{
		scanf(&G->adjList[i].data); 			/* ーー轡ーー */
		G->adjList[i].firstedge=NULL; 			/* ーーーー��ー/
	}
	
	
	for(k = 0;k < G->numEdges;k++)				/* ーーー*/
	{
		printf("ーーーvi,vj)ー亭�Nーー\n");
		scanf("%d,%d",&i,&j); 					/* ーーーvi,vj)ー亭�Nーー*/     
		e=(EdgeNode *)malloc(sizeof(EdgeNode)); /* ーーーー�Eーーーー�b*/     
		e->adjvex=j;							/* Zーーーj */                  
		e->next=G->adjList[i].firstedge;		/* ー妻褸ーー�Zー�Kー求�弌� */
		G->adjList[i].firstedge=e;				/* ーー轡ーーーーーe */          
		e=(EdgeNode *)malloc(sizeof(EdgeNode)); /* ーーーー�Eーーーー�b*/     
		e->adjvex=i;							/* Zーーーi */                  
		e->next=G->adjList[j].firstedge;		/* ー妻褸ーー�Zー�Kー求�弌� */
		G->adjList[j].firstedge=e;				/* ーー轡ーーーーーe */           
	}
}


#define MAXVEX 9
Boolean visited[MAXVEX]; 				/* �{ーー糀ー */

/* Zーーーー�痢次次示幻Y*/
void DFS(MGraph G, int i)
{
	int j;
 	visited[i] = TRUE;
 	printf("%c ", G.vexs[i]);			/* ーー�Bー�襦次次社�/
	for(j = 0; j < G.numVertexes; j++)
		if(G.arc[i][j] == 1 && !visited[j])
 			DFS(G, j);					/* �Gーー�Tーー�Nマ黔ー */
}

/* Zーーーー生桟ー吮/
void DFSTraverse(MGraph G)
{
	int i;
 	for(i = 0; i < G.numVertexes; i++)
 		visited[i] = FALSE; 			/* ーーー轡ーー�~ーーー齶ー */
	for(i = 0; i < G.numVertexes; i++)
 		if(!visited[i]) 				/* �Gーー�譟杓N�qAFSーーーーーーーー*/ 
			DFS(G, i);
}

/* Zーーー�痢次次示幻Y*/
void DFS(GraphAdjList GL, int i)
{
	EdgeNode *p;
 	visited[i] = TRUE;
 	printf("%c ",GL->adjList[i].data);	/* ーーばー�襦次次社�/
	p = GL->adjList[i].firstedge;
	while(p)
	{
 		if(!visited[p->adjvex])
 			DFS(GL, p->adjvex);			/* �Gーー�Tーー�Nマ黔ー */
		p = p->next;
 	}
}

/* Zーーー生桟ー吮/
void DFSTraverse(GraphAdjList GL)
{
	int i;
 	for(i = 0; i < GL->numVertexes; i++)
 		visited[i] = FALSE; 			/* ーーー轡ーー�~ーーー齶ー */
	for(i = 0; i < GL->numVertexes; i++)
 		if(!visited[i]) 				/* �Gーー�譟杓N�qAFS,ーーlーー,ーーーーー*/ 
			DFS(GL, i);
}


/* Zーーー珥ー桟ー�Y*/
void BFSTraverse(MGraph G)
{
	int i, j;
	Queue Q;
	for(i = 0; i < G.numVertexes; i++)
       	visited[i] = FALSE;
    InitQueue(&Q);									/* ーーー�Wー亭ーー*/
    for(i = 0; i < G.numVertexes; i++)  			/* 鑾�獏艚Nーーー*/
    {
		if (!visited[i])							/* ーー�_�{ーーーー/
		{
			visited[i]=TRUE;						/* ーー�Zー茅Iーー/
			printf("%c ", G.vexs[i]);				/* ーー�Bー�襦次次社�/
			EnQueue(&Q,i);							/* ーー�Nー蕉ー*/
			while(!QueueEmpty(Q))					/* ー�ZーPーー */
			{
				DeQueue(&Q,&i);						/* ーーーーーーーーー薯 */
				for(j=0;j<G.numVertexes;j++) 
				{ 							
													/* ー�}ー轡�Wー�Zー�_ー */
													/* ーーーー��*/
					if(G.arc[i][j] == 1 && !visited[j]) 
					{ 					
 						visited[j]=TRUE;			/* ーーーー�Nーーー�{ー*/
						printf("%c ", G.vexs[j]);	/* ーー�b*/
						EnQueue(&Q,j);				/* ーーーー�Nー蕉ー */
					} 
				} 
			}
		}
	}
}

/* Zーー珥ー桟ー�Y*/
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
			printf("%c ",GL->adjList[i].data);	/* ーーばー�襦次次社�/
			EnQueue(&Q,i);
			while(!QueueEmpty(Q))
			{
				DeQueue(&Q,&i);
				p = GL->adjList[i].firstedge;	/* ー��ー轡ーーーー�nー */
				while(p)
				{
					if(!visited[p->adjvex])		/* ーー�N�_ーIー*/
 					{
 						visited[p->adjvex]=TRUE;
						printf("%c ",GL->adjList[p->adjvex].data);
						EnQueue(&Q,p->adjvex);	/* ーー�Nー蕉ー*/
					}
					p = p->next;				/* ーーーーーー�Xーーー/
				}
			}
		}
	}
}


















































































































































































































































































































































































































































/* Primー艶ーーーーー��*/
void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];					/* ー�]競�Nーーー險賁〉ー/
	int lowcost[MAXVEX];				/* ー�]競�Nーーー險 */
	lowcost[0] = 0;						/* ーー賜ーーーー0ーーーーーー*/
	adjvex[0] = 0;						/* ーー賜ー轡ーーー*/
	for(i = 1; i < G.numVertexes; i++)	/* ーーーーーーーー�N */
	{
		lowcost[i] = G.arc[0][i];		/* ー0轡ーーーーー險ーーー */
		adjvex[i] = 0;					/* ーー皙ー�T〉ー/
	}
	for(i = 1; i < G.numVertexes; i++)
	{
		min = INFINITY;					/* ーーーーーーーーーーーーーーー65535�R*/
		j = 1;k = 0;
		while(j < G.numVertexes)		/* ーーー轡ー/
		{
			if(lowcost[j]!=0 && lowcost[j] < min)
			{							/* ー鎬險ーーー險ーーmin */
				min = lowcost[j];		/* ーー�Zーーーーーー */
				k = j;					/* ーーーーー�T〉ーーk */
			}
			j++;
		}
		printf("(%d, %d)\n", adjvex[k], k);	/* ーーー轡ーーーーーー鏃ー*/
		lowcost[k] = 0;						/* ーー轡�Eーーーー0,ー�Nーーーーー/
		for(j = 1; j < G.numVertexes; j++)	/* ーー�R轡ー/
		{	/* ー�H〉ーk轡ーー險ーーーーー轡ーーーーー�yー */
			if(lowcost[j]!=0 && G.arc[k][j] < lowcost[j]) 
			{	
				lowcost[j] = G.arc[k][j];	/* ーーーーーーーwcostーー�fー */
				adjvex[j] = k;				/* ー〉ーk亭�Nーーjvex */
			}
		}
	}
}

/* 瞥ー�后�Edgeー谺ー株/
typedef struct
{
	int begin;
	int end;
	int weight;
}Edge;   




/* Kruskalー艶ーーーーー吮/
void MiniSpanTree_Kruskal(MGraph G)
{
	int i, n, m;
	Edge edges[MAXEDGE];/* ー�Pーー,edge�弌次�begin,end,weight,�sーー */
	int parent[MAXVEX];	/* ー�Α次次�4ー�xーーー悌�^ー弄 */
	
	/* ー荏ーーーーーーーーー�后�edgesーーーー敷ーー驪ー*/

	for (i = 0; i < G.numVertexes; i++)
		parent[i] = 0;					/* ーーーーーー0 */
	for (i = 0; i < G.numEdges; i++)	/* ーー�燹次�*/
	{
		n = Find(parent,edges[i].begin);
		m = Find(parent,edges[i].end);
		if (n != m) /* ー�wーーーーーーーーーー慈ーーーー弄 */
		{/* ーーーーー轡ーーーーーЁーarentーーーー�Nー��ーーーーーー*/
			parent[n] = m;
			printf("(%d, %d) %d\n", edges[i].begin, 
				edges[i].end, edges[i].weight);
		}
	}
}

/* ーーー轡ー�]ー〉ー/
int Find(int *parent, int f)
{
	while ( parent[f] > 0)
	{
		f = parent[f];
	}
	return f;
}

/*  Dijkstraー�qーーーーG亭0轡ーーー轡ーー�N�P�R[v]ー�蝓次�[v] */    
/*  P[v]妻甼ーー轡ーーD[v]ー�r辺蔬�N�P�uーー*/  
void ShortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D)
{    
	int v,w,k,min;    
	int final[MAXVEX];/* final[w]=1ー�\粲�Nv0ーvw蔬�N�P�b*/
	for(v=0; v<G.numVertexes; v++)    /* ーーー�D*/
	{        
		final[v] = 0;			/* ーー�Nーーー�_ーー云短ーー */
		(*D)[v] = G.arc[v0][v];/* ーー寸ーー亭�Nー�r險 */
		(*P)[v] = -1;				/* ーー�P�LーPー-1  */       
	}

	(*D)[v0] = 0;  /* v0ーv0�P�Pー*/  
	final[v0] = 1;    /* v0ーv0ー禳ー�P�b*/        
	/* ーーーーーーーv0畩ーv轡ーー云短 */   
	for(v=1; v<G.numVertexes; v++)   
	{
		min=INFINITY;    /* �Zーー+v0轡ーーー+ */        
		for(w=0; w<G.numVertexes; w++) /* ーー+v0ーーー�N */    
		{            
			if(!final[w] && (*D)[w]<min)             
			{                   
				k=w;                    
				min = (*D)[w];    /* w轡ーv0轡ーー*/            
			}        
		}        
		final[k] = 1;    /* ー�gー��ー�g亭�Nーー1 */
		for(w=0; w<G.numVertexes; w++) /* ーー�Zー云短ー+ */
		{
			/* ー瑙ーv轡ー�P�sーーーー�P�wーー�法次�/
			if(!final[w] && (min+G.arc[k][w]<(*D)[w]))   
			{ /*  ー〈ーーーー字短ーーー[w]ー[w] */
				(*D)[w] = min + G.arc[k][w];  /* ーーー�P�uー */               
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

typedef int Patharc[MAXVEX];    	/* ーーーー云短ーーーー */
typedef int ShortPathTable[MAXVEX];	/* ーーーー庶ー云短寺險ー*/

/*  Dijkstraー�qーーーーG亭0轡ーーー轡ーー�N�P�R[v]ー�蝓次�[v] */    
/*  P[v]妻甼ーー轡ーーD[v]ー�r辺蔬�N�P�uーー*/  
void ShortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D)
{    
	int v,w,k,min;    
	int final[MAXVEX];				/* final[w]=1ー�\粲�Nv0ーvw蔬�N�P�b*/
	for(v=0; v<G.numVertexes; v++)  /* ーーー�D*/
	{        
		final[v] = 0;				/* ーー�Nーーー�_ーー云短ーー */
		(*D)[v] = G.arc[v0][v];		/* ーー寸ーー亭�Nー�r險 */
		(*P)[v] = -1;				/* ーー�P�LーPー-1  */       
	}
	(*D)[v0] = 0;  					/* v0ーv0�P�Pー*/  
	final[v0] = 1;    				/* v0ーv0ー禳ー�P�b*/        
	/* ーーーーーーーv0畩ーv轡ーー云短 */   
	for(v=1; v<G.numVertexes; v++)   
	{
		min=INFINITY;    			/* �Zーー+v0轡ーーー+ */        
		for(w=0; w<G.numVertexes; w++) /* ーー+v0ーーー�N */    
		{            
			if(!final[w] && (*D)[w]<min)             
			{                   
				k=w;                    
				min = (*D)[w];    	/* w轡ーv0轡ーー*/            
			}        
		}        
		final[k] = 1;    			/* ー�gー��ー�g亭�Nーー1 */
		for(w=0; w<G.numVertexes; w++) /* ーー�Zー云短ー+ */
		{
			/* ー瑙ーv轡ー�P�sーーーー�P�wーー�法次�/
			if(!final[w] && (min+G.arc[k][w]<(*D)[w]))   
			{ 						/*  ー〈ーーーー字短ーーー[w]ー[w] */
				(*D)[w] = min + G.arc[k][w]; /* ーーー�P�uー */               
				(*P)[w]=k;        
			}       
		}   
	}
}


typedef int Patharc[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];

/* Floydー�qーーーGー直�Nv惚ー轡ーー�N�P�R[v][w]ー�蝓次�[v][w]ー*/    
void ShortestPath_Floyd(MGraph G, Patharc *P, ShortPathTable *D)
{    
	int v,w,k;    
	for(v=0; v<G.numVertexes; ++v) 		/* ーーDーP */  
	{        
		for(w=0; w<G.numVertexes; ++w)  
		{
			(*D)[v][w]=G.arc[v][w];		/* D[v][w]ーーーー橇ーーー */
			(*P)[v][w]=w;				/* ーーP */
		}
	}
	for(k=0; k<G.numVertexes; ++k)   
	{
		for(v=0; v<G.numVertexes; ++v)  
		{        
			for(w=0; w<G.numVertexes; ++w)    
			{
				if ((*D)[v][w]>(*D)[v][k]+(*D)[k][w])
				{/* ー瑙ーーーー�N�P�sーー橇ー�zー */
					(*D)[v][w]=(*D)[v][k]+(*D)[k][w];/* ーー}橇ーーー�dー苡*/
					(*P)[v][w]=(*P)[v][k];			 /* �P�K逑ー�僉次次次杓N */
				}
			}
		}
	}
}


printf("直�Nー�N�P�J枠:\n");    
for(v=0; v<G.numVertexes; ++v)   
{        
	for(w=v+1; w<G.numVertexes; w++)  
	{
		printf("v%d-v%d weight: %d ",v,w,D[v][w]);
		k=P[v][w];				/* ーoーー�P�x�Nーー*/
		printf(" path: %d",v);	/* ーー�b*/
		while(k!=w)				/* ー�t短轡ーーーー�b*/
		{
			printf(" -> %d",k);	/* ーー�x�N */
			k=P[k][w];			/* ーIーー�P�x�Nーー*/
		}
		printf(" -> %d\n",w);	/* ーー�b*/
	}
	printf("\n");
}


typedef struct EdgeNode 		/* ーー�b */
{
	int adjvex;    				/* Zーーー労拾�N�N�bーー*/
	int weight;					/* ーーー�勝次次次次鴫��襦次次� */
	struct EdgeNode *next; 		/* tーー求ーー�Xーーー/
}EdgeNode;

typedef struct VertexNode 		/* 轡ーーー/
{
	int in;						/* 轡���r*/
	int data; 					/* 轡ーー労轡ーー */
	EdgeNode *firstedge;		/* ーーーー */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int numVertexes,numEdges; 	/* ーー�Zー�aーーー/
}graphAdjList,*GraphAdjList;



/* ーーーーーー�Qー�kーーーーーーーPー甬1ーーー�Gーー*/
Status TopologicalSort(GraphAdjList GL)
{    
	EdgeNode *e;    
	int i,k,gettop;   
	int top=0;  									/* ーーーーーーー */
	int count=0;									/* ーーーーー轡ー�Vー*/    
	int *stack;										/* ーーーΕーー�Nーー  */   
	stack=(int *)malloc(GL->numVertexes * sizeof(int) );    
	for(i = 0; i<GL->numVertexes; i++)                
		if(0 == GL->adjList[i].in) 					/* ーーー0亭�Nーー */         
			stack[++top]=i;    
	while(top!=0)    
	{        
		gettop=stack[top--];       					/* ーー/ 
		printf("%d -> ",GL->adjList[gettop].data);  /* ーー轡ー/   
		count++;        							/* ーーー轡ー */        
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)/* ーー�Nーー: */      
		{            
			k=e->adjvex;            
			if( !(--GL->adjList[k].in) )  			/* ーー�NZーーー�f鐫/                 
				stack[++top]=k;        				/* ーー0ーーーーーーーーーー*/
		}
	}   
	if(count < GL->numVertexes)  					/* countーー轡ーーーーー吮/      
		return ERROR;    
	else       
		return OK;
}


int *etv,*ltv; /* ーー�仝Mーーー���Mーーー */
int *stack2;   /* ーーーーーーP娼ー/
int top2;	   /* ーーstack2妻褸 */

/* ーーーー */
Status TopologicalSort(GraphAdjList GL)
{   /* ーGL�Qー�kーーーーーーーPー甬1ーーー�Gーー*/    
	EdgeNode *e;    
	int i,k,gettop;   
	int top=0;  										/* ーーーーーーー */
	int count=0;										/* ーーーーー轡ー�Vー/   
	int *stack;											/* ーーーΕーー�Nーー */   
	stack=(int *)malloc(GL->numVertexes * sizeof(int) );    
	for(i = 0; i<GL->numVertexes; i++)                
		if(0 == GL->adjList[i].in) 						/* ーーー0亭�Nーー */           
			stack[++top]=i;    
	top2=0;    											/* ーー */
	etv=(int *)malloc(GL->numVertexes * sizeof(int) ); 	/* ーー�仝Mーーー */
	for(i=0; i<GL->numVertexes; i++)        
		etv[i]=0;    									/* ーー */
	stack2=(int *)malloc(GL->numVertexes * sizeof(int) );/* ーーーーーPー */
	while(top!=0)    
	{        
		gettop=stack[top--];        
		count++;        				/* ーーー�Nーーー */ 
		stack2[++top2]=gettop;        	/* ーー亭�Nーー�tーーーP娼ー/
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)        
		{            
			k=e->adjvex;            
			if( !(--GL->adjList[k].in))                
				stack[++top]=k; 
			if((etv[gettop] + e->weight) > etv[k]) /* ー直�Nーーー�仝Mーーtvー */
				etv[k] = etv[gettop] + e->weight;
		}    
	}    
	if(count < GL->numVertexes)        
		return ERROR;    
	else       
		return OK;
}


int *etv,*ltv; /* ーー�仝Mーーー���Mーーー */
int *stack2;   /* ーーーーーーP娼ー/
int top2;	   /* ーーstack2妻褸 */



/* ー遥ー�nGLーーーーーーG椿�\遥ー�j*/
void CriticalPath(GraphAdjList GL) 
{    
	EdgeNode *e;    
	int i,gettop,k,j;    
	int ete,lte;  			/* ー〈ー�戞叱Mーーー���Mーーー */        
	TopologicalSort(GL);   	/* ーーーーPーーーーetvーtack2妻株/ 
	ltv=(int *)malloc(GL->numVertexes*sizeof(int));/* ーー�仝Mーーー */   
	for(i=0; i<GL->numVertexes; i++)        
		ltv[i]=etv[GL->numVertexes-1];    		/* ーーltv */        
	while(top2!=0)    							/* ーーv */    
	{        
		gettop=stack2[top2--];        
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)         
		{          
			k=e->adjvex;            
			if(ltv[k] - e->weight < ltv[gettop])/*ー直�Nーーｾ�Mーーtv*/               
				ltv[gettop] = ltv[k] - e->weight;        
		}   
	}    
	for(j=0; j<GL->numVertexes; j++)        	/* ーete,lteーーー�j*/        
	{            
		for(e = GL->adjList[j].firstedge; e; e = e->next)            
		{                
			k=e->adjvex;                
			ete = etv[j];        				/* ー�戞叱Mーー*/                
			lte = ltv[k] - e->weight; 			/* ー�戞次次次�*/               
			if(ete == lte)    					/* }ーー�Tー遥ー�Kー*/                    
				printf("<v%d - v%d> length: %d \n",
					GL->adjList[j].data,GL->adjList[k].data,e->weight);
		}        
	}
}




