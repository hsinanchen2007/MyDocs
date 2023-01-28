

typedef char VertexType; 			/* ���I���A���ѨϥΪ̩w�q  */
typedef int EdgeType; 				/* ��W���v�ȫ��A���ѨϥΪ̩w�q */
#define MAXVEX 100 					/* �̤j���I�ơA���ѨϥΪ̩w�q */
#define INFINITY 65535				/* ��65535�ӥN��� */
typedef struct
{
	VertexType vexs[MAXVEX]; 		/* ���I�� */
	EdgeType arc[MAXVEX][MAXVEX];	/* �F���x�}�A�i�ݧ@��� */
	int numNodes, numEdges; 		/* �Ϥ��ثe�����I�ƩM���  */
}MGraph;


/* �إߵL�V���Ϫ��F���x�}��� */
void CreateMGraph(MGraph *G)
{
	int i,j,k,w;
	printf("��J���I�ƩM���:\n");
	scanf("%d,%d",&G->numNodes,&G->numEdges); 		/* ��J���I�ƩM��� */
	for(i = 0;i <G->numNodes;i++) 					/* Ū�J���I�T��,�إ߳��I�� */
		scanf(&G->vexs[i]);
	for(i = 0;i <G->numNodes;i++)
		for(j = 0;j <G->numNodes;j++)
			G->arc[i][j]=INFINITY;					/* �F���x�}�_�l�� */
	for(k = 0;k <G->numEdges;k++) 					/* Ū�JnumEdges����A�إ߾F���x�} */
	{
		printf("��J��(vi,vj)�W������i�A����j�M�vw:\n");
		scanf("%d,%d,%d",&i,&j,&w); 				/* ��J��(vi,vj)�W���vw */
		G->arc[i][j]=w; 
		G->arc[j][i]= G->arc[i][j]; 				/* �]���O�L�V�ϡA�x�}��� */
	}
}


typedef char VertexType; 	/* ���I���A���ѨϥΪ̩w�q */
typedef int EdgeType; 		/* ��W���v�ȫ��A���ѨϥΪ̩w�q */

typedef struct EdgeNode 	/* ���`�I  */
{
	int adjvex;    			/* �F���I��,�x�s�ӳ��I���������� */
	EdgeType info;			/* �Ω��x�s�v��,���D���ϥi�H���ݭn */
	struct EdgeNode *next; 	/* ���,���V�U�@�ӾF���I */
}EdgeNode;

typedef struct VertexNode 	/* ���I��`�I */
{
	VertexType data; 		/* ���I��,�x�s���I�T�� */
	EdgeNode *firstedge;	/* ����Y���� */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int numNodes,numEdges; 	/* �Ϥ��ثe���I�ƩM��� */
}GraphAdjList;


/* �إ߹Ϫ��F�����c */
void  CreateALGraph(GraphAdjList *G)
{
	int i,j,k;
	EdgeNode *e;
	printf("��J���I�ƩM���:\n");
	scanf("%d,%d",&G->numNodes,&G->numEdges); 	/* ��J���I�ƩM��� */
	for(i = 0;i < G->numNodes;i++) 				/* Ū�J���I�T��,�إ߳��I�� */
	{
		scanf(&G->adjList[i].data); 			/* ��J���I�T�� */
		G->adjList[i].firstedge=NULL; 			/* �N���m���Ū� */
	}
	
	
	for(k = 0;k < G->numEdges;k++)				/* �إ���� */
	{
		printf("��J��(vi,vj)�W�����I�Ǹ�:\n");
		scanf("%d,%d",&i,&j); 					/* ��J��(vi,vj)�W�����I�Ǹ� */     
		e=(EdgeNode *)malloc(sizeof(EdgeNode)); /* �V�O����ӽЪŶ�,�������`�I */     
		e->adjvex=j;							/* �F���Ǹ���j */                  
		e->next=G->adjList[i].firstedge;		/* �Ne�����Ы��V�ثe���I�W���V���`�I */
		G->adjList[i].firstedge=e;				/* �N�ثe���I�����Ы��Ve */          
		e=(EdgeNode *)malloc(sizeof(EdgeNode)); /* �V�O����ӽЪŶ�,�������`�I */     
		e->adjvex=i;							/* �F���Ǹ���i */                  
		e->next=G->adjList[j].firstedge;		/* �Ne�����Ы��V�ثe���I�W���V���`�I */
		G->adjList[j].firstedge=e;				/* �N�ثe���I�����Ы��Ve */           
	}
}


#define MAXVEX 9
Boolean visited[MAXVEX]; 				/* �s���ЧӪ��}�C */

/* �F���x�}���`���u�����k��k */
void DFS(MGraph G, int i)
{
	int j;
 	visited[i] = TRUE;
 	printf("%c ", G.vexs[i]);			/* �C�L���I�A�]�i�H�䥦�ʧ@ */
	for(j = 0; j < G.numVertexes; j++)
		if(G.arc[i][j] == 1 && !visited[j])
 			DFS(G, j);					/* �אּ�s�����F�����I���k�I�s */
}

/* �F���x�}���`���ˬd�ʧ@ */
void DFSTraverse(MGraph G)
{
	int i;
 	for(i = 0; i < G.numVertexes; i++)
 		visited[i] = FALSE; 			/* �_�l�Ҧ����I���A���O���s���L���A */
	for(i = 0; i < G.numVertexes; i++)
 		if(!visited[i]) 				/* �良�s���L�����I�I�sDFS�A�Y�s�q�϶Ȱ���@�� */ 
			DFS(G, i);
}

/* �F�����`���u�����k��k */
void DFS(GraphAdjList GL, int i)
{
	EdgeNode *p;
 	visited[i] = TRUE;
 	printf("%c ",GL->adjList[i].data);	/* �C�L���I,�]�i�H�䥦�ʧ@ */
	p = GL->adjList[i].firstedge;
	while(p)
	{
 		if(!visited[p->adjvex])
 			DFS(GL, p->adjvex);			/* �אּ�s�����F�����I���k�I�s */
		p = p->next;
 	}
}

/* �F�����`���ˬd�ʧ@ */
void DFSTraverse(GraphAdjList GL)
{
	int i;
 	for(i = 0; i < GL->numVertexes; i++)
 		visited[i] = FALSE; 			/* �_�l�Ҧ����I���A���O���s���L���A */
	for(i = 0; i < GL->numVertexes; i++)
 		if(!visited[i]) 				/* �良�s���L�����I�I�sDFS,�Y�O�s�q��,�u�|����@�� */ 
			DFS(GL, i);
}


/* �F���x�}���s���ˬd��k */
void BFSTraverse(MGraph G)
{
	int i, j;
	Queue Q;
	for(i = 0; i < G.numVertexes; i++)
       	visited[i] = FALSE;
    InitQueue(&Q);									/* �_�l�Ƥ@���U�Ϊ���C */
    for(i = 0; i < G.numVertexes; i++)  			/* ��C�@�ӳ��I���`�� */
    {
		if (!visited[i])							/* �Y�O���s���L�N�B�z */
		{
			visited[i]=TRUE;						/* �]�w�ثe���I�s���L */
			printf("%c ", G.vexs[i]);				/* �C�L���I�A�]�i�H�䥦�ʧ@ */
			EnQueue(&Q,i);							/* �N�����I�[�J��C�C */
			while(!QueueEmpty(Q))					/* �Y�ثe��C������ */
			{
				DeQueue(&Q,&i);						/* �N��C�������X��C�A�����ȵ�i */
				for(j=0;j<G.numVertexes;j++) 
				{ 							
													/* �P�_�䥦���I�Y�P�ثe���I�s�b */
													/* ��B���s���L */
					if(G.arc[i][j] == 1 && !visited[j]) 
					{ 					
 						visited[j]=TRUE;			/* �N��쪺�����I�Хܬ��w�s�� */
						printf("%c ", G.vexs[j]);	/* �C�L���I */
						EnQueue(&Q,j);				/* �N��쪺�����I�[�J��C�C  */
					} 
				} 
			}
		}
	}
}

/* �F�����s���ˬd��k */
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
			printf("%c ",GL->adjList[i].data);	/* �C�L���I,�]�i�H�䥦�ʧ@ */
			EnQueue(&Q,i);
			while(!QueueEmpty(Q))
			{
				DeQueue(&Q,&i);
				p = GL->adjList[i].firstedge;	/* ���ثe���I������쵲��C�Y���� */
				while(p)
				{
					if(!visited[p->adjvex])		/* �Y�����I���Q�s�� */
 					{
 						visited[p->adjvex]=TRUE;
						printf("%c ",GL->adjList[p->adjvex].data);
						EnQueue(&Q,p->adjvex);	/* �N�����I�[�J��C�C */
					}
					p = p->next;				/* ���Ы��V�U�@�ӾF���I */
				}
			}
		}
	}
}


















































































































































































































































































































































































































































/* Prim��k���ͳ̤p���;�  */
void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];					/* �x�s���p���I���䪺�v���I���� */
	int lowcost[MAXVEX];				/* �x�s���p���I���䪺�v�� */
	lowcost[0] = 0;						/* �_�l�ƲĤ@���v�Ȭ�0�A�Yv0�[�J���;�C*/
	adjvex[0] = 0;						/* �_�l�ƲĤ@�ӳ��I���ެ�0 */
	for(i = 1; i < G.numVertexes; i++)	/* �`�������ެ�0�~���������I */
	{
		lowcost[i] = G.arc[0][i];		/* �Nv0���I�P�����䪺�v�Ȧs�J�}�C */
		adjvex[i] = 0;					/* �_�l�Ƴ���v0������ */
	}
	for(i = 1; i < G.numVertexes; i++)
	{
		min = INFINITY;					/* �_�l�Ƴ̤p�v�Ȭ��ۡA�i�H�O���j�Ʀr�p65535�� */
		j = 1;k = 0;
		while(j < G.numVertexes)		/* �`���������I */
		{
			if(lowcost[j]!=0 && lowcost[j] < min)
			{							/* �Y�G�v�Ȥ���0�B�v�Ȥp��min */
				min = lowcost[j];		/* �h���ثe�v�Ȧ����̤p�� */
				k = j;					/* �N�ثe�̤p�Ȫ����ަs�Jk */
			}
			j++;
		}
		printf("(%d, %d)\n", adjvex[k], k);	/* �C�L�ثe���I�䤤�v�ȳ̤p���� */
		lowcost[k] = 0;						/* �N�ثe���I�v�ȳ]�w��0,�����I�w�����u�@ */
		for(j = 1; j < G.numVertexes; j++)	/* �`���Ҧ����I */
		{	/* �Y�G���ެ�k���I�U���v�Ȥp�󦹫e�o�ǳ��I���Q�[�J���;��v�� */
			if(lowcost[j]!=0 && G.arc[k][j] < lowcost[j]) 
			{	
				lowcost[j] = G.arc[k][j];	/* �N���p���v�Ȧs�Jlowcost������m */
				adjvex[j] = k;				/* �N���ެ�k�����I�s�Jadjvex */
			}
		}
	}
}

/* ���䶰�}�CEdge���c���w�q */
typedef struct
{
	int begin;
	int end;
	int weight;
}Edge;   




/* Kruskal��k���ͳ̤p���;� */
void MiniSpanTree_Kruskal(MGraph G)
{
	int i, n, m;
	Edge edges[MAXEDGE];/* �w�q�䶰�}�C,edge�����c��begin,end,weight,������� */
	int parent[MAXVEX];	/* �w�q�@�}�C�ΨӧP�_��P��O�_�Φ����� */
	
	/* ���B�ٲ��N�F���x�}G��Ƭ��䶰�}�Cedges�ë��v�Ѥp��j�ƧǪ��{���X*/

	for (i = 0; i < G.numVertexes; i++)
		parent[i] = 0;					/* �_�l�ư}�C�Ȭ�0 */
	for (i = 0; i < G.numEdges; i++)	/* �`���C�@���� */
	{
		n = Find(parent,edges[i].begin);
		m = Find(parent,edges[i].end);
		if (n != m) /* ���pn�Pm�����A��������S���P�{�������;𪬦����� */
		{/* �N���䪺�������I��J���ެ��_�I��parent���C��ܦ����I�w�g�b���;𶰦X�� */
			parent[n] = m;
			printf("(%d, %d) %d\n", edges[i].begin, 
				edges[i].end, edges[i].weight);
		}
	}
}

/* �d�߳s�u���I���������� */
int Find(int *parent, int f)
{
	while ( parent[f] > 0)
	{
		f = parent[f];
	}
	return f;
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
		min=INFINITY;    /* �ثe�Ҫ���v0���I���̪�Z�� */        
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

#define MAXEDGE 20
#define MAXVEX 20
#define INFINITY 65535

typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

typedef int Patharc[MAXVEX];    	/* �Ω��x�s�̵u���|���ު��}�C */
typedef int ShortPathTable[MAXVEX];	/* �Ω��x�s��U�I�̵u���|���v�ȩM */

/*  Dijkstra��k�A�D���V��G��v0���I���E���Iv���̵u���|P[v]�αa�v����D[v] */    
/*  P[v]���Ȭ��e�X���I����,D[v]���v0��v���̵u���|���שM */  
void ShortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D)
{    
	int v,w,k,min;    
	int final[MAXVEX];				/* final[w]=1��ܨD�o���Iv0��vw���̵u���| */
	for(v=0; v<G.numVertexes; v++)  /* �_�l�Ƹ�� */
	{        
		final[v] = 0;				/* �������I�_�l�Ƭ����Գ̵u���|���A */
		(*D)[v] = G.arc[v0][v];		/* �N�Pv0�I���s�u�����I�[�W�v�� */
		(*P)[v] = -1;				/* �_�l�Ƹ��|�}�CP��-1  */       
	}
	(*D)[v0] = 0;  					/* v0��v0���|��0 */  
	final[v0] = 1;    				/* v0��v0���ݭn�D���| */        
	/* �}�l�D�`���A�C���D�ov0��Y��v���I���̵u���| */   
	for(v=1; v<G.numVertexes; v++)   
	{
		min=INFINITY;    			/* �ثe�Ҫ���v0���I���̪�Z�� */        
		for(w=0; w<G.numVertexes; w++) /* �M����v0�̪񪺳��I */    
		{            
			if(!final[w] && (*D)[w]<min)             
			{                   
				k=w;                    
				min = (*D)[w];    	/* w���I��v0���I��� */            
			}        
		}        
		final[k] = 1;    			/* �N�ثe��쪺�̪񪺳��I�m��1 */
		for(w=0; w<G.numVertexes; w++) /* �ץ��ثe�̵u���|�ζZ�� */
		{
			/* �Y�G�g��v���I�����|��{�b�o�����|�����׵u���� */
			if(!final[w] && (min+G.arc[k][w]<(*D)[w]))   
			{ 						/*  �������F��u�����|�A�ק�D[w]�MP[w] */
				(*D)[w] = min + G.arc[k][w]; /* �ק�ثe���|���� */               
				(*P)[w]=k;        
			}       
		}   
	}
}


typedef int Patharc[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];

/* Floyd��k�A�D����G���U���Iv���E���Iw���̵u���|P[v][w]�αa�v����D[v][w]�C */    
void ShortestPath_Floyd(MGraph G, Patharc *P, ShortPathTable *D)
{    
	int v,w,k;    
	for(v=0; v<G.numVertexes; ++v) 		/* �_�l��D�PP */  
	{        
		for(w=0; w<G.numVertexes; ++w)  
		{
			(*D)[v][w]=G.arc[v][w];		/* D[v][w]�ȧY�������I�����v�� */
			(*P)[v][w]=w;				/* �_�l��P */
		}
	}
	for(k=0; k<G.numVertexes; ++k)   
	{
		for(v=0; v<G.numVertexes; ++v)  
		{        
			for(w=0; w<G.numVertexes; ++w)    
			{
				if ((*D)[v][w]>(*D)[v][k]+(*D)[k][w])
				{/* �Y�G�g�ѯ��ެ�k���I���|�����I�����|��u */
					(*D)[v][w]=(*D)[v][k]+(*D)[k][w];/* �N�ثe���I���v�ȳ]��p�@�� */
					(*P)[v][w]=(*P)[v][k];			 /* ���|�]�w���g�ѯ��ެ�k�����I */
				}
			}
		}
	}
}


printf("�U���I���̵u���|�p�U:\n");    
for(v=0; v<G.numVertexes; ++v)   
{        
	for(w=v+1; w<G.numVertexes; w++)  
	{
		printf("v%d-v%d weight: %d ",v,w,D[v][w]);
		k=P[v][w];				/* ��o�Ĥ@�Ӹ��|���I���� */
		printf(" path: %d",v);	/* �C�L���I */
		while(k!=w)				/* �Y�G���|���I���ޤ��O���I */
		{
			printf(" -> %d",k);	/* �C�L���|���I */
			k=P[k][w];			/* ��o�U�@�Ӹ��|���I���� */
		}
		printf(" -> %d\n",w);	/* �C�L���I */
	}
	printf("\n");
}


typedef struct EdgeNode 		/* ���`�I  */
{
	int adjvex;    				/* �F���I��A�x�s�ӳ��I���������� */
	int weight;					/* �Ω��x�s�v�ȡA���D���ϥi�H���ݭn */
	struct EdgeNode *next; 		/* ���A���V�U�@�ӾF���I */
}EdgeNode;

typedef struct VertexNode 		/* ���I��`�I */
{
	int in;						/* ���I������� */
	int data; 					/* ���I��A�x�s���I�T�� */
	EdgeNode *firstedge;		/* ����Y���� */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int numVertexes,numEdges; 	/* �Ϥ��ثe���I�ƩM��� */
}graphAdjList,*GraphAdjList;



/* �ݼ��ƧǡA�YGL�L�^���A�h��X�ݼ��ƧǧǦC�öǦ^1�A�Y���^���Ǧ^0�C */
Status TopologicalSort(GraphAdjList GL)
{    
	EdgeNode *e;    
	int i,k,gettop;   
	int top=0;  									/* �Ω���|���Я���  */
	int count=0;									/* �Ω�έp��X���I���Ӽ�  */    
	int *stack;										/* �ذ��|�N������׬�0�����I�J���|  */   
	stack=(int *)malloc(GL->numVertexes * sizeof(int) );    
	for(i = 0; i<GL->numVertexes; i++)                
		if(0 == GL->adjList[i].in) 					/* �N������׬�0�����I�J���| */         
			stack[++top]=i;    
	while(top!=0)    
	{        
		gettop=stack[top--];       					/* �X���| */ 
		printf("%d -> ",GL->adjList[gettop].data);  /* �C�L�����I */   
		count++;        							/* �έp��X���I�� */        
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)/* �惡���I�����ˬd */      
		{            
			k=e->adjvex;            
			if( !(--GL->adjList[k].in) )  			/* �Nk�����I�F���I��������״�1*/                 
				stack[++top]=k;        				/* �Y��0�h�J���|�A�H�K�U���`����X */
		}
	}   
	if(count < GL->numVertexes)  					/* count�p���I�ơA�����s�b�� */      
		return ERROR;    
	else       
		return OK;
}


int *etv,*ltv; /* �ƥ�̦��o�ͮɶ��M�̿�o�ͮɶ��}�C */
int *stack2;   /* �Ω��x�s�ݼ��ǦC�����| */
int top2;	   /* �Ω�stack2������ */

/* �ݼ��Ƨ� */
Status TopologicalSort(GraphAdjList GL)
{   /* �YGL�L�^���A�h��X�ݼ��ƧǧǦC�öǦ^1�A�Y���^���Ǧ^0�C */    
	EdgeNode *e;    
	int i,k,gettop;   
	int top=0;  										/* �Ω���|���Я���  */
	int count=0;										/* �Ω�έp��X���I���Ӽ� */   
	int *stack;											/* �ذ��|�N������׬�0�����I�J���| */   
	stack=(int *)malloc(GL->numVertexes * sizeof(int) );    
	for(i = 0; i<GL->numVertexes; i++)                
		if(0 == GL->adjList[i].in) 						/* �N������׬�0�����I�J���| */           
			stack[++top]=i;    
	top2=0;    											/* �_�l�� */
	etv=(int *)malloc(GL->numVertexes * sizeof(int) ); 	/* �ƥ�̦��o�ͮɶ��}�C */
	for(i=0; i<GL->numVertexes; i++)        
		etv[i]=0;    									/* �_�l�� */
	stack2=(int *)malloc(GL->numVertexes * sizeof(int) );/* �_�l�Ʃݼ��ǦC���| */
	while(top!=0)    
	{        
		gettop=stack[top--];        
		count++;        				/* ��Xi�����I�A�íp�� */ 
		stack2[++top2]=gettop;        	/* �N�X�{�����I�Ǹ��s�J�ݼ��ǦC�����| */
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)        
		{            
			k=e->adjvex;            
			if( !(--GL->adjList[k].in))                
				stack[++top]=k; 
			if((etv[gettop] + e->weight) > etv[k]) /* �D�U���I�ƥ󪺳̦��o�ͮɶ�etv�� */
				etv[k] = etv[gettop] + e->weight;
		}    
	}    
	if(count < GL->numVertexes)        
		return ERROR;    
	else       
		return OK;
}


int *etv,*ltv; /* �ƥ�̦��o�ͮɶ��M�̿�o�ͮɶ��}�C */
int *stack2;   /* �Ω��x�s�ݼ��ǦC�����| */
int top2;	   /* �Ω�stack2������ */



/* �D������|,GL�����V���A��XG���U�����䬡�� */
void CriticalPath(GraphAdjList GL) 
{    
	EdgeNode *e;    
	int i,gettop,k,j;    
	int ete,lte;  			/* �ŧi���ʳ̦��o�ͮɶ��M�̿�o�ͮɶ��ܼ� */        
	TopologicalSort(GL);   	/* �D�ݼ��ǦC�A�p��}�Cetv�Mstack2���� */ 
	ltv=(int *)malloc(GL->numVertexes*sizeof(int));/* �ƥ�̦��o�ͮɶ��}�C */   
	for(i=0; i<GL->numVertexes; i++)        
		ltv[i]=etv[GL->numVertexes-1];    		/* �_�l��ltv */        
	while(top2!=0)    							/* �p��ltv */    
	{        
		gettop=stack2[top2--];        
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)         
		{          
			k=e->adjvex;            
			if(ltv[k] - e->weight < ltv[gettop])/*�D�U���I�ƥ�̱ߵo�ͮɶ�ltv*/               
				ltv[gettop] = ltv[k] - e->weight;        
		}   
	}    
	for(j=0; j<GL->numVertexes; j++)        	/* �Dete,lte�M���䬡�� */        
	{            
		for(e = GL->adjList[j].firstedge; e; e = e->next)            
		{                
			k=e->adjvex;                
			ete = etv[j];        				/* ���ʳ̦��o�ͮɶ� */                
			lte = ltv[k] - e->weight; 			/* ���ʳ̿�o�ͮɶ� */               
			if(ete == lte)    					/* ��̬۵��Y�b������|�W */                    
				printf("<v%d - v%d> length: %d \n",
					GL->adjList[j].data,GL->adjList[k].data,e->weight);
		}        
	}
}




