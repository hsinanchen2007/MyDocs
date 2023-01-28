

typedef char VertexType; 			/* 頂點型態應由使用者定義  */
typedef int EdgeType; 				/* 邊上的權值型態應由使用者定義 */
#define MAXVEX 100 					/* 最大頂點數，應由使用者定義 */
#define INFINITY 65535				/* 用65535來代表∞ */
typedef struct
{
	VertexType vexs[MAXVEX]; 		/* 頂點表 */
	EdgeType arc[MAXVEX][MAXVEX];	/* 鄰接矩陣，可看作邊表 */
	int numNodes, numEdges; 		/* 圖中目前的頂點數和邊數  */
}MGraph;


/* 建立無向網圖的鄰接矩陣表示 */
void CreateMGraph(MGraph *G)
{
	int i,j,k,w;
	printf("輸入頂點數和邊數:\n");
	scanf("%d,%d",&G->numNodes,&G->numEdges); 		/* 輸入頂點數和邊數 */
	for(i = 0;i <G->numNodes;i++) 					/* 讀入頂點訊息,建立頂點表 */
		scanf(&G->vexs[i]);
	for(i = 0;i <G->numNodes;i++)
		for(j = 0;j <G->numNodes;j++)
			G->arc[i][j]=INFINITY;					/* 鄰接矩陣起始化 */
	for(k = 0;k <G->numEdges;k++) 					/* 讀入numEdges條邊，建立鄰接矩陣 */
	{
		printf("輸入邊(vi,vj)上的索引i，索引j和權w:\n");
		scanf("%d,%d,%d",&i,&j,&w); 				/* 輸入邊(vi,vj)上的權w */
		G->arc[i][j]=w; 
		G->arc[j][i]= G->arc[i][j]; 				/* 因為是無向圖，矩陣對稱 */
	}
}


typedef char VertexType; 	/* 頂點型態應由使用者定義 */
typedef int EdgeType; 		/* 邊上的權值型態應由使用者定義 */

typedef struct EdgeNode 	/* 邊表節點  */
{
	int adjvex;    			/* 鄰接點域,儲存該頂點對應的索引 */
	EdgeType info;			/* 用於儲存權值,對於非網圖可以不需要 */
	struct EdgeNode *next; 	/* 鏈域,指向下一個鄰接點 */
}EdgeNode;

typedef struct VertexNode 	/* 頂點表節點 */
{
	VertexType data; 		/* 頂點域,儲存頂點訊息 */
	EdgeNode *firstedge;	/* 邊標頭指標 */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int numNodes,numEdges; 	/* 圖中目前頂點數和邊數 */
}GraphAdjList;


/* 建立圖的鄰接表結構 */
void  CreateALGraph(GraphAdjList *G)
{
	int i,j,k;
	EdgeNode *e;
	printf("輸入頂點數和邊數:\n");
	scanf("%d,%d",&G->numNodes,&G->numEdges); 	/* 輸入頂點數和邊數 */
	for(i = 0;i < G->numNodes;i++) 				/* 讀入頂點訊息,建立頂點表 */
	{
		scanf(&G->adjList[i].data); 			/* 輸入頂點訊息 */
		G->adjList[i].firstedge=NULL; 			/* 將邊表置為空表 */
	}
	
	
	for(k = 0;k < G->numEdges;k++)				/* 建立邊表 */
	{
		printf("輸入邊(vi,vj)上的頂點序號:\n");
		scanf("%d,%d",&i,&j); 					/* 輸入邊(vi,vj)上的頂點序號 */     
		e=(EdgeNode *)malloc(sizeof(EdgeNode)); /* 向記憶體申請空間,產生邊表節點 */     
		e->adjvex=j;							/* 鄰接序號為j */                  
		e->next=G->adjList[i].firstedge;		/* 將e的指標指向目前頂點上指向的節點 */
		G->adjList[i].firstedge=e;				/* 將目前頂點的指標指向e */          
		e=(EdgeNode *)malloc(sizeof(EdgeNode)); /* 向記憶體申請空間,產生邊表節點 */     
		e->adjvex=i;							/* 鄰接序號為i */                  
		e->next=G->adjList[j].firstedge;		/* 將e的指標指向目前頂點上指向的節點 */
		G->adjList[j].firstedge=e;				/* 將目前頂點的指標指向e */           
	}
}


#define MAXVEX 9
Boolean visited[MAXVEX]; 				/* 存取標志的陣列 */

/* 鄰接矩陣的深度優先遞歸算法 */
void DFS(MGraph G, int i)
{
	int j;
 	visited[i] = TRUE;
 	printf("%c ", G.vexs[i]);			/* 列印頂點，也可以其它動作 */
	for(j = 0; j < G.numVertexes; j++)
		if(G.arc[i][j] == 1 && !visited[j])
 			DFS(G, j);					/* 對為存取的鄰接頂點遞歸呼叫 */
}

/* 鄰接矩陣的深度檢查動作 */
void DFSTraverse(MGraph G)
{
	int i;
 	for(i = 0; i < G.numVertexes; i++)
 		visited[i] = FALSE; 			/* 起始所有頂點狀態都是未存取過狀態 */
	for(i = 0; i < G.numVertexes; i++)
 		if(!visited[i]) 				/* 對未存取過的頂點呼叫DFS，若連通圖僅執行一次 */ 
			DFS(G, i);
}

/* 鄰接表的深度優先遞歸算法 */
void DFS(GraphAdjList GL, int i)
{
	EdgeNode *p;
 	visited[i] = TRUE;
 	printf("%c ",GL->adjList[i].data);	/* 列印頂點,也可以其它動作 */
	p = GL->adjList[i].firstedge;
	while(p)
	{
 		if(!visited[p->adjvex])
 			DFS(GL, p->adjvex);			/* 對為存取的鄰接頂點遞歸呼叫 */
		p = p->next;
 	}
}

/* 鄰接表的深度檢查動作 */
void DFSTraverse(GraphAdjList GL)
{
	int i;
 	for(i = 0; i < GL->numVertexes; i++)
 		visited[i] = FALSE; 			/* 起始所有頂點狀態都是未存取過狀態 */
	for(i = 0; i < GL->numVertexes; i++)
 		if(!visited[i]) 				/* 對未存取過的頂點呼叫DFS,若是連通圖,只會執行一次 */ 
			DFS(GL, i);
}


/* 鄰接矩陣的廣度檢查算法 */
void BFSTraverse(MGraph G)
{
	int i, j;
	Queue Q;
	for(i = 0; i < G.numVertexes; i++)
       	visited[i] = FALSE;
    InitQueue(&Q);									/* 起始化一輔助用的佇列 */
    for(i = 0; i < G.numVertexes; i++)  			/* 對每一個頂點做循環 */
    {
		if (!visited[i])							/* 若是未存取過就處理 */
		{
			visited[i]=TRUE;						/* 設定目前頂點存取過 */
			printf("%c ", G.vexs[i]);				/* 列印頂點，也可以其它動作 */
			EnQueue(&Q,i);							/* 將此頂點加入佇列列 */
			while(!QueueEmpty(Q))					/* 若目前佇列不為空 */
			{
				DeQueue(&Q,&i);						/* 將佇列首元素出佇列，給予值給i */
				for(j=0;j<G.numVertexes;j++) 
				{ 							
													/* 判斷其它頂點若與目前頂點存在 */
													/* 邊且未存取過 */
					if(G.arc[i][j] == 1 && !visited[j]) 
					{ 					
 						visited[j]=TRUE;			/* 將找到的此頂點標示為已存取 */
						printf("%c ", G.vexs[j]);	/* 列印頂點 */
						EnQueue(&Q,j);				/* 將找到的此頂點加入佇列列  */
					} 
				} 
			}
		}
	}
}

/* 鄰接表的廣度檢查算法 */
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
			printf("%c ",GL->adjList[i].data);	/* 列印頂點,也可以其它動作 */
			EnQueue(&Q,i);
			while(!QueueEmpty(Q))
			{
				DeQueue(&Q,&i);
				p = GL->adjList[i].firstedge;	/* 找到目前頂點的邊表鏈結串列頭指標 */
				while(p)
				{
					if(!visited[p->adjvex])		/* 若此頂點未被存取 */
 					{
 						visited[p->adjvex]=TRUE;
						printf("%c ",GL->adjList[p->adjvex].data);
						EnQueue(&Q,p->adjvex);	/* 將此頂點加入佇列列 */
					}
					p = p->next;				/* 指標指向下一個鄰接點 */
				}
			}
		}
	}
}


















































































































































































































































































































































































































































/* Prim算法產生最小產生樹  */
void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];					/* 儲存關聯頂點間邊的權值點索引 */
	int lowcost[MAXVEX];				/* 儲存關聯頂點間邊的權值 */
	lowcost[0] = 0;						/* 起始化第一個權值為0，即v0加入產生樹。*/
	adjvex[0] = 0;						/* 起始化第一個頂點索引為0 */
	for(i = 1; i < G.numVertexes; i++)	/* 循環除索引為0外的全部頂點 */
	{
		lowcost[i] = G.arc[0][i];		/* 將v0頂點與之有邊的權值存入陣列 */
		adjvex[i] = 0;					/* 起始化都為v0的索引 */
	}
	for(i = 1; i < G.numVertexes; i++)
	{
		min = INFINITY;					/* 起始化最小權值為∞，可以是較大數字如65535等 */
		j = 1;k = 0;
		while(j < G.numVertexes)		/* 循環全部頂點 */
		{
			if(lowcost[j]!=0 && lowcost[j] < min)
			{							/* 若果權值不為0且權值小於min */
				min = lowcost[j];		/* 則讓目前權值成為最小值 */
				k = j;					/* 將目前最小值的索引存入k */
			}
			j++;
		}
		printf("(%d, %d)\n", adjvex[k], k);	/* 列印目前頂點邊中權值最小的邊 */
		lowcost[k] = 0;						/* 將目前頂點權值設定為0,此頂點已完成工作 */
		for(j = 1; j < G.numVertexes; j++)	/* 循環所有頂點 */
		{	/* 若果索引為k頂點各邊權值小於此前這些頂點未被加入產生樹權值 */
			if(lowcost[j]!=0 && G.arc[k][j] < lowcost[j]) 
			{	
				lowcost[j] = G.arc[k][j];	/* 將較小的權值存入lowcost對應位置 */
				adjvex[j] = k;				/* 將索引為k的頂點存入adjvex */
			}
		}
	}
}

/* 對邊集陣列Edge結構的定義 */
typedef struct
{
	int begin;
	int end;
	int weight;
}Edge;   




/* Kruskal算法產生最小產生樹 */
void MiniSpanTree_Kruskal(MGraph G)
{
	int i, n, m;
	Edge edges[MAXEDGE];/* 定義邊集陣列,edge的結構為begin,end,weight,均為整數 */
	int parent[MAXVEX];	/* 定義一陣列用來判斷邊與邊是否形成環路 */
	
	/* 此處省略將鄰接矩陣G轉化為邊集陣列edges並按權由小到大排序的程式碼*/

	for (i = 0; i < G.numVertexes; i++)
		parent[i] = 0;					/* 起始化陣列值為0 */
	for (i = 0; i < G.numEdges; i++)	/* 循環每一條邊 */
	{
		n = Find(parent,edges[i].begin);
		m = Find(parent,edges[i].end);
		if (n != m) /* 假如n與m不等，說明此邊沒有與現有的產生樹狀成環路 */
		{/* 將此邊的結尾頂點放入索引為起點的parent中。表示此頂點已經在產生樹集合中 */
			parent[n] = m;
			printf("(%d, %d) %d\n", edges[i].begin, 
				edges[i].end, edges[i].weight);
		}
	}
}

/* 查詢連線頂點的尾部索引 */
int Find(int *parent, int f)
{
	while ( parent[f] > 0)
	{
		f = parent[f];
	}
	return f;
}

/*  Dijkstra算法，求有向網G的v0頂點到其余頂點v的最短路徑P[v]及帶權長度D[v] */    
/*  P[v]的值為前驅頂點索引,D[v]表示v0到v的最短路徑長度和 */  
void ShortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D)
{    
	int v,w,k,min;    
	int final[MAXVEX];/* final[w]=1表示求得頂點v0至vw的最短路徑 */
	for(v=0; v<G.numVertexes; v++)    /* 起始化資料 */
	{        
		final[v] = 0;			/* 全部頂點起始化為不詳最短路徑狀態 */
		(*D)[v] = G.arc[v0][v];/* 將與v0點有連線的頂點加上權值 */
		(*P)[v] = -1;				/* 起始化路徑陣列P為-1  */       
	}

	(*D)[v0] = 0;  /* v0至v0路徑為0 */  
	final[v0] = 1;    /* v0至v0不需要求路徑 */        
	/* 開始主循環，每次求得v0到某個v頂點的最短路徑 */   
	for(v=1; v<G.numVertexes; v++)   
	{
		min=INFINITY;    /* 目前所知離v0頂點的最近距離 */        
		for(w=0; w<G.numVertexes; w++) /* 尋找離v0最近的頂點 */    
		{            
			if(!final[w] && (*D)[w]<min)             
			{                   
				k=w;                    
				min = (*D)[w];    /* w頂點離v0頂點更近 */            
			}        
		}        
		final[k] = 1;    /* 將目前找到的最近的頂點置為1 */
		for(w=0; w<G.numVertexes; w++) /* 修正目前最短路徑及距離 */
		{
			/* 若果經由v頂點的路徑比現在這條路徑的長度短的話 */
			if(!final[w] && (min+G.arc[k][w]<(*D)[w]))   
			{ /*  說明找到了更短的路徑，修改D[w]和P[w] */
				(*D)[w] = min + G.arc[k][w];  /* 修改目前路徑長度 */               
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

typedef int Patharc[MAXVEX];    	/* 用於儲存最短路徑索引的陣列 */
typedef int ShortPathTable[MAXVEX];	/* 用於儲存到各點最短路徑的權值和 */

/*  Dijkstra算法，求有向網G的v0頂點到其余頂點v的最短路徑P[v]及帶權長度D[v] */    
/*  P[v]的值為前驅頂點索引,D[v]表示v0到v的最短路徑長度和 */  
void ShortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D)
{    
	int v,w,k,min;    
	int final[MAXVEX];				/* final[w]=1表示求得頂點v0至vw的最短路徑 */
	for(v=0; v<G.numVertexes; v++)  /* 起始化資料 */
	{        
		final[v] = 0;				/* 全部頂點起始化為不詳最短路徑狀態 */
		(*D)[v] = G.arc[v0][v];		/* 將與v0點有連線的頂點加上權值 */
		(*P)[v] = -1;				/* 起始化路徑陣列P為-1  */       
	}
	(*D)[v0] = 0;  					/* v0至v0路徑為0 */  
	final[v0] = 1;    				/* v0至v0不需要求路徑 */        
	/* 開始主循環，每次求得v0到某個v頂點的最短路徑 */   
	for(v=1; v<G.numVertexes; v++)   
	{
		min=INFINITY;    			/* 目前所知離v0頂點的最近距離 */        
		for(w=0; w<G.numVertexes; w++) /* 尋找離v0最近的頂點 */    
		{            
			if(!final[w] && (*D)[w]<min)             
			{                   
				k=w;                    
				min = (*D)[w];    	/* w頂點離v0頂點更近 */            
			}        
		}        
		final[k] = 1;    			/* 將目前找到的最近的頂點置為1 */
		for(w=0; w<G.numVertexes; w++) /* 修正目前最短路徑及距離 */
		{
			/* 若果經由v頂點的路徑比現在這條路徑的長度短的話 */
			if(!final[w] && (min+G.arc[k][w]<(*D)[w]))   
			{ 						/*  說明找到了更短的路徑，修改D[w]和P[w] */
				(*D)[w] = min + G.arc[k][w]; /* 修改目前路徑長度 */               
				(*P)[w]=k;        
			}       
		}   
	}
}


typedef int Patharc[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];

/* Floyd算法，求網圖G中各頂點v到其余頂點w的最短路徑P[v][w]及帶權長度D[v][w]。 */    
void ShortestPath_Floyd(MGraph G, Patharc *P, ShortPathTable *D)
{    
	int v,w,k;    
	for(v=0; v<G.numVertexes; ++v) 		/* 起始化D與P */  
	{        
		for(w=0; w<G.numVertexes; ++w)  
		{
			(*D)[v][w]=G.arc[v][w];		/* D[v][w]值即為對應點間的權值 */
			(*P)[v][w]=w;				/* 起始化P */
		}
	}
	for(k=0; k<G.numVertexes; ++k)   
	{
		for(v=0; v<G.numVertexes; ++v)  
		{        
			for(w=0; w<G.numVertexes; ++w)    
			{
				if ((*D)[v][w]>(*D)[v][k]+(*D)[k][w])
				{/* 若果經由索引為k頂點路徑比原兩點間路徑更短 */
					(*D)[v][w]=(*D)[v][k]+(*D)[k][w];/* 將目前兩點間權值設更小一個 */
					(*P)[v][w]=(*P)[v][k];			 /* 路徑設定為經由索引為k的頂點 */
				}
			}
		}
	}
}


printf("各頂點間最短路徑如下:\n");    
for(v=0; v<G.numVertexes; ++v)   
{        
	for(w=v+1; w<G.numVertexes; w++)  
	{
		printf("v%d-v%d weight: %d ",v,w,D[v][w]);
		k=P[v][w];				/* 獲得第一個路徑頂點索引 */
		printf(" path: %d",v);	/* 列印源點 */
		while(k!=w)				/* 若果路徑頂點索引不是終點 */
		{
			printf(" -> %d",k);	/* 列印路徑頂點 */
			k=P[k][w];			/* 獲得下一個路徑頂點索引 */
		}
		printf(" -> %d\n",w);	/* 列印終點 */
	}
	printf("\n");
}


typedef struct EdgeNode 		/* 邊表節點  */
{
	int adjvex;    				/* 鄰接點域，儲存該頂點對應的索引 */
	int weight;					/* 用於儲存權值，對於非網圖可以不需要 */
	struct EdgeNode *next; 		/* 鏈域，指向下一個鄰接點 */
}EdgeNode;

typedef struct VertexNode 		/* 頂點表節點 */
{
	int in;						/* 頂點內分支度 */
	int data; 					/* 頂點域，儲存頂點訊息 */
	EdgeNode *firstedge;		/* 邊標頭指標 */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int numVertexes,numEdges; 	/* 圖中目前頂點數和邊數 */
}graphAdjList,*GraphAdjList;



/* 拓撲排序，若GL無回路，則輸出拓撲排序序列並傳回1，若有回路傳回0。 */
Status TopologicalSort(GraphAdjList GL)
{    
	EdgeNode *e;    
	int i,k,gettop;   
	int top=0;  									/* 用於堆疊指標索引  */
	int count=0;									/* 用於統計輸出頂點的個數  */    
	int *stack;										/* 建堆疊將內分支度為0的頂點入堆疊  */   
	stack=(int *)malloc(GL->numVertexes * sizeof(int) );    
	for(i = 0; i<GL->numVertexes; i++)                
		if(0 == GL->adjList[i].in) 					/* 將內分支度為0的頂點入堆疊 */         
			stack[++top]=i;    
	while(top!=0)    
	{        
		gettop=stack[top--];       					/* 出堆疊 */ 
		printf("%d -> ",GL->adjList[gettop].data);  /* 列印此頂點 */   
		count++;        							/* 統計輸出頂點數 */        
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)/* 對此頂點弧表檢查 */      
		{            
			k=e->adjvex;            
			if( !(--GL->adjList[k].in) )  			/* 將k號頂點鄰接點的內分支度減1*/                 
				stack[++top]=k;        				/* 若為0則入堆疊，以便下次循環輸出 */
		}
	}   
	if(count < GL->numVertexes)  					/* count小於頂點數，說明存在環 */      
		return ERROR;    
	else       
		return OK;
}


int *etv,*ltv; /* 事件最早發生時間和最遲發生時間陣列 */
int *stack2;   /* 用於儲存拓撲序列的堆疊 */
int top2;	   /* 用於stack2的指標 */

/* 拓撲排序 */
Status TopologicalSort(GraphAdjList GL)
{   /* 若GL無回路，則輸出拓撲排序序列並傳回1，若有回路傳回0。 */    
	EdgeNode *e;    
	int i,k,gettop;   
	int top=0;  										/* 用於堆疊指標索引  */
	int count=0;										/* 用於統計輸出頂點的個數 */   
	int *stack;											/* 建堆疊將內分支度為0的頂點入堆疊 */   
	stack=(int *)malloc(GL->numVertexes * sizeof(int) );    
	for(i = 0; i<GL->numVertexes; i++)                
		if(0 == GL->adjList[i].in) 						/* 將內分支度為0的頂點入堆疊 */           
			stack[++top]=i;    
	top2=0;    											/* 起始化 */
	etv=(int *)malloc(GL->numVertexes * sizeof(int) ); 	/* 事件最早發生時間陣列 */
	for(i=0; i<GL->numVertexes; i++)        
		etv[i]=0;    									/* 起始化 */
	stack2=(int *)malloc(GL->numVertexes * sizeof(int) );/* 起始化拓撲序列堆疊 */
	while(top!=0)    
	{        
		gettop=stack[top--];        
		count++;        				/* 輸出i號頂點，並計數 */ 
		stack2[++top2]=gettop;        	/* 將出現的頂點序號存入拓撲序列的堆疊 */
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)        
		{            
			k=e->adjvex;            
			if( !(--GL->adjList[k].in))                
				stack[++top]=k; 
			if((etv[gettop] + e->weight) > etv[k]) /* 求各頂點事件的最早發生時間etv值 */
				etv[k] = etv[gettop] + e->weight;
		}    
	}    
	if(count < GL->numVertexes)        
		return ERROR;    
	else       
		return OK;
}


int *etv,*ltv; /* 事件最早發生時間和最遲發生時間陣列 */
int *stack2;   /* 用於儲存拓撲序列的堆疊 */
int top2;	   /* 用於stack2的指標 */



/* 求關鍵路徑,GL為有向網，輸出G的各項關鍵活動 */
void CriticalPath(GraphAdjList GL) 
{    
	EdgeNode *e;    
	int i,gettop,k,j;    
	int ete,lte;  			/* 宣告活動最早發生時間和最遲發生時間變數 */        
	TopologicalSort(GL);   	/* 求拓撲序列，計算陣列etv和stack2的值 */ 
	ltv=(int *)malloc(GL->numVertexes*sizeof(int));/* 事件最早發生時間陣列 */   
	for(i=0; i<GL->numVertexes; i++)        
		ltv[i]=etv[GL->numVertexes-1];    		/* 起始化ltv */        
	while(top2!=0)    							/* 計算ltv */    
	{        
		gettop=stack2[top2--];        
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)         
		{          
			k=e->adjvex;            
			if(ltv[k] - e->weight < ltv[gettop])/*求各頂點事件最晚發生時間ltv*/               
				ltv[gettop] = ltv[k] - e->weight;        
		}   
	}    
	for(j=0; j<GL->numVertexes; j++)        	/* 求ete,lte和關鍵活動 */        
	{            
		for(e = GL->adjList[j].firstedge; e; e = e->next)            
		{                
			k=e->adjvex;                
			ete = etv[j];        				/* 活動最早發生時間 */                
			lte = ltv[k] - e->weight; 			/* 活動最遲發生時間 */               
			if(ete == lte)    					/* 兩者相等即在關鍵路徑上 */                    
				printf("<v%d - v%d> length: %d \n",
					GL->adjList[j].data,GL->adjList[k].data,e->weight);
		}        
	}
}




