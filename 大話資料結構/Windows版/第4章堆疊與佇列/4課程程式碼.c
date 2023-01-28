typedef int SElemType; 	/* SElemType ¡¼ÃÛ¡¼¹ú¡¼¡¼ÁÍ¡¼¡¼¡¼×mint */

/* ¡¼¡¼¡¼¡¼Ãþ§O/
typedef struct
{
        SElemType data[MAXSIZE];
        int top; 		/* ¡¼¡¼¡¼Õ¸êú */
}SqStack;

/* ¡¼¡¼¡¼e¡¼¡¼¾«¡¼¡¼¡¼ */
Status Push(SqStack *S,SElemType e)
{
    if(S->top == MAXSIZE -1) 	/* ¡¼o */
    {
    	return ERROR;
    }
    S->top++;					/* ¡¼Õ¸êú¡¼¡¼¡¼/
    S->data[S->top]=e;  		/* ¡¼2§O¡¼¡¼»­±`¡¼¡¼¡¼¡¼/
    return OK;
}

/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¾«¡¼¡¼¡¼¡¼aß_¡¼¡¼¡¼¡¼¡¼K¡¼¡¼ß_¡¼RROR */
Status Pop(SqStack *S,SElemType *e)
{ 
    if(S->top==-1)
    	return ERROR;
    *e=S->data[S->top];		/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼»­±`e */
    S->top--;				/* ¡¼Õ¸êú¡¼¡¼/
    return OK;
}

/* }¡¼¡¼¡¼¡¼¡¼ */
typedef struct 
{
        SElemType data[MAXSIZE];
        int top1;	/* ¡¼1¡¼Õ¸êú */
        int top2;	/* ¡¼2¡¼Õ¸êú */
}SqDoubleStack;

/* ¡¼¡¼¡¼e¡¼¡¼¾«¡¼¡¼¡¼ */
Status Push(SqDoubleStack *S,SElemType e,int stackNumber)
{
    if (S->top1+1==S->top2)		/* ¡¼¡¼o¡¼¡¼¡¼push¡¼¡¼¡¼K */
    	return ERROR;	
    if (stackNumber==1)			/* ¡¼1¡¼¡¼¡¼¡¼¡¼/
        S->data[++S->top1]=e; 	/* ¡¼¡¼¡¼1¡¼£rtop1+1¡¼ªÞ¡¼¡¼¡¼»­Üð */
    else if (stackNumber==2)	/* ¡¼2¡¼¡¼¡¼¡¼¡¼/
        S->data[--S->top2]=e; 	/* ¡¼¡¼¡¼2¡¼£rtop2-1¡¼ªÞ¡¼¡¼¡¼»­Üð */
    return OK;
}

/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¾«¡¼¡¼¡¼¡¼aß_¡¼¡¼¡¼¡¼¡¼K¡¼¡¼ß_¡¼RROR */
Status Pop(SqDoubleStack *S,SElemType *e,int stackNumber)
{ 
    if (stackNumber==1) 
    {
        if (S->top1==-1) 
            return ERROR; 		/* ¡¼¡Ò¡¼1¡¼›¢¡¼¡¼¡¼¡¼¡¼*/
        *e=S->data[S->top1--]; 	/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼/
    }
    else if (stackNumber==2)
    { 
        if (S->top2==MAXSIZE) 
            return ERROR; 		/* ¡¼¡Ò¡¼2¡¼›¢¡¼¡¼¡¼¡¼¡¼*/
        *e=S->data[S->top2++]; 	/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼/
    }
    return OK;
}

/* t¡¼¡¼Ãþ§O/
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;


typedef struct
{
    LinkStackPtr top;
    int count;
}LinkStack;

/* ¡¼¡¼¡¼e¡¼¡¼¾«¡¼¡¼¡¼ */
Status Push(LinkStack *S,SElemType e)
{
    LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode)); 
    s->data=e; 
    s->next=S->top;	/* ¡¼¡¼¾«¡¼¡¼¡¼»­±`¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼*/
    S->top=s;  		/* ¡¼£g¡¼¡¼s»­±`¡¼Õ¸êú¡¼¡¼¡¼¡¼*/
    S->count++;
    return OK;
}

/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¾«¡¼¡¼¡¼¡¼aß_¡¼¡¼¡¼¡¼¡¼K¡¼¡¼ß_¡¼RROR */
Status Pop(LinkStack *S,SElemType *e)
{ 
    LinkStackPtr p;
    if(StackEmpty(*S))
    	return ERROR;
    *e=S->top->data;
    p=S->top;				/* ¡¼¡¼¡¼¡¼¡¼ëÆ¡¼¡¼¡¼¡¼*/
    S->top=S->top->next;    /* ¡¼¹²¡¼¡¼¡¼¡¼¡¼¡¼£f¡¼µá¡¼¡¼ôB¡¼¡¼¡¼¡¼*/
    free(p);                /* ¡¼º´¡¼p */        
    S->count--;
    return OK;
}

int main()
{
	int i;
	int a[40];  
	a[0]=0;
	a[1]=1;
	printf("%d ",a[0]);  
	printf("%d ",a[1]);  
	for(i = 2;i < 40;i++)  
	{ 
		a[i] = a[i-1] + a[i-2];  
		printf("%d ",a[i]);  
	} 
    return 0;
}

/* ¡¼¯Ù¡¼ñì¡¼¦±¡¼ */
int Fbi(int i)  
{
	if( i < 2 )
		return i == 0 ? 0 : 1;  
    return Fbi(i-1)+Fbi(i-2);  /* ¡¼/FbiŽy¡¼‡¹¡¼¡¼¡¼¡¼¡¼Åq¡Ñ¡¼¡¼/
}  

int main()
{
	int i;
	printf("¥Þóm¡¼¡¼¯Ù¡¼¡¼P¡¼n");
	for(i = 0;i < 40;i++)  
		printf("%d ", Fbi(i));  
    return 0;
}

typedef int QElemType; 	/* QElemType ¡¼ÃÛ¡¼¹ú¡¼¡¼ÁÍ¡¼¡¼¡¼×mint */
/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ö¿*/
typedef struct
{
	QElemType data[MAXSIZE];
	int front;    		/* ¡¼¡¼¡¼ */
	int rear;			/* £]¡¼¡¼¡¼¡¼P¡¼¡¼¡¼¡¼¾Ö¡¼¢t¡¼ßT¡¼¡¼£f¡¼ */
}SqQueue;

/* ¡¼¡¼¡¼×Ù¡¼¡¼¡¼ */
Status InitQueue(SqQueue *Q)
{
	Q->front=0;
	Q->rear=0;
	return  OK;
}

/* ß_¡¼¾©¡¼¶V¡¼¡¼Žy¡¼¡¼¡¼¡¼¡¼¡¼¡¼*/
int QueueLength(SqQueue Q)
{
	return  (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

/* ¡¼¾Ö¡¼¡¼¡¼¡¼¡¼¡¼¡¼e¡¼Q¡¼Äâ¡¼¢t¡¼ */
Status EnQueue(SqQueue *Q,QElemType e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)	/* ¾Ö¡¼¡¼¡¼Ù]*/
		return ERROR;
	Q->data[Q->rear]=e;						/* ¡¼¡¼e»­±`Àº¡¼/
	Q->rear=(Q->rear+1)%MAXSIZE;			/* rear¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼*/
											/* ¡¼±k ú¡¼¡¼¾Ê¡¼¡¼¡¼*/
	return  OK;
}

/* ¡¼¾Ö¡¼¡¼¡¼¡¼¡¼¡¼¾ÞÊF¡¼¡¼aß_¡¼¡¼ */
Status DeQueue(SqQueue *Q,QElemType *e)
{
	if (Q->front == Q->rear)			/* ¾Ö¡¼¡¼¡¼¡¼¡¼*/
		return ERROR;
	*e=Q->data[Q->front];				/* ¡¼¡¼ÊF¡¼»­±`e */
	Q->front=(Q->front+1)%MAXSIZE;		/* front¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼*/
										/* ¡¼±k ú¡¼¡¼¾Ê¡¼¡¼¡¼*/
	return  OK;
}

typedef int QElemType; 	/* QElemType ¡¼ÃÛ¡¼¹ú¡¼¡¼ÁÍ¡¼¡¼¡¼×mint */

typedef struct QNode	/* ¡¼¡¼ö¿*/
{
   QElemType data;
   struct QNode *next;
}QNode,*QueuePtr;

typedef struct			/* ¾Ö¡¼¡¼¡¼¡¼Ãþ§O/
{
   QueuePtr front,rear; /* ¾ÞÚÑÀº¡¼¡¼ */
}LinkQueue;

/* ¡¼¡¼¡¼e¡¼Q¾ª£g¡¼¡¼¢t¡¼ */
Status EnQueue(LinkQueue *Q,QElemType e)
{ 
	QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
	if(!s) 				/* ¡¼¡¼¡¼¡¼¡¼*/
		exit(OVERFLOW);
	s->data=e;
	s->next=NULL;
	Q->rear->next=s;	/* ¡¼¦J¡¼¡¼e¾ª¡¼¡¼s»­±`¡¼Àº¡¼§§¡¼¡¼¡¼¡¼¡¼¡¼*/
	Q->rear=s;			/* ¡¼¡¼Ã_¡¼¡¼¡¼Àº¡¼ôB¡¼ar¡¼¡¼s¡¼¡¼¡¼¡¼*/
	return OK;
}

/* ¡¼¾Ö¡¼¡¼,¡¼¡¼Äâ¡¼ÊF¡¼,¡¼eß_¡¼¡¼,¡¼áµOK,õä¡¼¡¼RROR */
Status DeQueue(LinkQueue *Q,QElemType *e)
{
	QueuePtr p;
	if(Q->front==Q->rear)
		return ERROR;
	p=Q->front->next;		/* ¡¼¡¼¡¼¡¼¡¼Ó\ìË¡¼´åp¡¼¡¼¡¼¡¼*/
	*e=p->data;				/* ¡¼¡¼¡¼¡¼¡¼Ó\§§¡¼±b¡¼çõ */
	Q->front->next=p->next;	/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼->next»­±`¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼*/
	if(Q->rear==p)			/* ¡¼¾ÞÐO¡¼Àº¡¼¡¼¡¼¡¼¡¼rear¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼*/
		Q->rear=Q->front;
	free(p);
	return OK;
}


