typedef int SElemType; 	/* SElemType型態根據實際情況而定，這裡假設為int */

/* 順序堆疊結構 */
typedef struct
{
        SElemType data[MAXSIZE];
        int top; 		/* 用於堆疊頂指標 */
}SqStack;

/* 插入元素e為新的堆疊頂元素 */
Status Push(SqStack *S,SElemType e)
{
    if(S->top == MAXSIZE -1) 	/* 堆疊滿 */
    {
    	return ERROR;
    }
    S->top++;					/* 堆疊頂指標增加一 */
    S->data[S->top]=e;  		/* 將新插入元素給予值給堆疊頂空間 */
    return OK;
}

/* 若堆疊不空，則移除S的堆疊頂元素，用e傳回其值，並傳回OK；否則傳回ERROR */
Status Pop(SqStack *S,SElemType *e)
{ 
    if(S->top==-1)
    	return ERROR;
    *e=S->data[S->top];		/* 將要移除的堆疊頂元素給予值給e */
    S->top--;				/* 堆疊頂指標減一 */
    return OK;
}

/* 兩堆疊共享空間結構 */
typedef struct 
{
        SElemType data[MAXSIZE];
        int top1;	/* 堆疊1堆疊頂指標 */
        int top2;	/* 堆疊2堆疊頂指標 */
}SqDoubleStack;

/* 插入元素e為新的堆疊頂元素 */
Status Push(SqDoubleStack *S,SElemType e,int stackNumber)
{
    if (S->top1+1==S->top2)		/* 堆疊已滿，不能再push新元素了 */
    	return ERROR;	
    if (stackNumber==1)			/* 堆疊1有元素進堆疊 */
        S->data[++S->top1]=e; 	/* 若是堆疊1則先top1+1後給陣列元素給予值。 */
    else if (stackNumber==2)	/* 堆疊2有元素進堆疊 */
        S->data[--S->top2]=e; 	/* 若是堆疊2則先top2-1後給陣列元素給予值。 */
    return OK;
}

/* 若堆疊不空，則移除S的堆疊頂元素，用e傳回其值，並傳回OK；否則傳回ERROR */
Status Pop(SqDoubleStack *S,SElemType *e,int stackNumber)
{ 
    if (stackNumber==1) 
    {
        if (S->top1==-1) 
            return ERROR; 		/* 說明堆疊1已經是空堆疊，溢位 */
        *e=S->data[S->top1--]; 	/* 將堆疊1的堆疊頂元素出堆疊 */
    }
    else if (stackNumber==2)
    { 
        if (S->top2==MAXSIZE) 
            return ERROR; 		/* 說明堆疊2已經是空堆疊，溢位 */
        *e=S->data[S->top2++]; 	/* 將堆疊2的堆疊頂元素出堆疊 */
    }
    return OK;
}

/* 鏈堆疊結構 */
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

/* 插入元素e為新的堆疊頂元素 */
Status Push(LinkStack *S,SElemType e)
{
    LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode)); 
    s->data=e; 
    s->next=S->top;	/* 把目前的堆疊頂元素給予值給新節點的後繼，見圖中１ */
    S->top=s;  		/* 將新的節點s給予值給堆疊頂指標，見圖中２ */
    S->count++;
    return OK;
}

/* 若堆疊不空，則移除S的堆疊頂元素，用e傳回其值，並傳回OK；否則傳回ERROR */
Status Pop(LinkStack *S,SElemType *e)
{ 
    LinkStackPtr p;
    if(StackEmpty(*S))
    	return ERROR;
    *e=S->top->data;
    p=S->top;				/* 將堆疊頂節點給予值給p，見圖中３ */
    S->top=S->top->next;    /* 使得堆疊頂指標下移一位，指向後一節點，見圖中４ */
    free(p);                /* 釋放節點p */        
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

/* 費氏的遞歸函數 */
int Fbi(int i)  
{
	if( i < 2 )
		return i == 0 ? 0 : 1;  
    return Fbi(i-1)+Fbi(i-2);  /* 這裡Fbi就是函數自己，等於在呼叫自己 */
}  

int main()
{
	int i;
	printf("遞歸顯示費氏數列：\n");
	for(i = 0;i < 40;i++)  
		printf("%d ", Fbi(i));  
    return 0;
}

typedef int QElemType; 	/* QElemType型態根據實際情況而定，這裡假設為int */
/* 循環佇列的連序儲存結構 */
typedef struct
{
	QElemType data[MAXSIZE];
	int front;    		/* 頭指標 */
	int rear;			/* 尾指標，若佇列不空，指向佇列尾元素的下一個位置 */
}SqQueue;

/* 起始化一個空佇列Q */
Status InitQueue(SqQueue *Q)
{
	Q->front=0;
	Q->rear=0;
	return  OK;
}

/* 傳回Q的元素個數，也就是佇列的目前長度 */
int QueueLength(SqQueue Q)
{
	return  (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

/* 若佇列未滿，則插入元素e為Q新的佇列尾元素 */
Status EnQueue(SqQueue *Q,QElemType e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)	/* 佇列滿的判斷 */
		return ERROR;
	Q->data[Q->rear]=e;						/* 將元素e給予值給佇列尾 */
	Q->rear=(Q->rear+1)%MAXSIZE;			/* rear指標向後移一位置， */
											/* 若到最後則轉到陣列頁首 */
	return  OK;
}

/* 若佇列不空，則移除Q中列首元素，用e傳回其值 */
Status DeQueue(SqQueue *Q,QElemType *e)
{
	if (Q->front == Q->rear)			/* 佇列空的判斷 */
		return ERROR;
	*e=Q->data[Q->front];				/* 將列首元素給予值給e */
	Q->front=(Q->front+1)%MAXSIZE;		/* front指標向後移一位置， */
										/* 若到最後則轉到陣列頁首 */
	return  OK;
}

typedef int QElemType; 	/* QElemType型態根據實際情況而定，這裡假設為int */

typedef struct QNode	/* 節點結構 */
{
   QElemType data;
   struct QNode *next;
}QNode,*QueuePtr;

typedef struct			/* 佇列的鏈結串列結構 */
{
   QueuePtr front,rear; /* 列首、佇列尾指標 */
}LinkQueue;

/* 插入元素e為Q的新的佇列尾元素 */
Status EnQueue(LinkQueue *Q,QElemType e)
{ 
	QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
	if(!s) 				/* 儲存分配失敗 */
		exit(OVERFLOW);
	s->data=e;
	s->next=NULL;
	Q->rear->next=s;	/* 把擁有元素e的新節點s給予值給原佇列尾節點的後繼，見圖中１ */
	Q->rear=s;			/* 把目前的s設定為佇列尾節點，rear指向s，見圖中２ */
	return OK;
}

/* 若佇列不空,移除Q的列首元素,用e傳回其值,並傳回OK,否則傳回ERROR */
Status DeQueue(LinkQueue *Q,QElemType *e)
{
	QueuePtr p;
	if(Q->front==Q->rear)
		return ERROR;
	p=Q->front->next;		/* 將欲移除的列首節點暫存給p，見圖中１ */
	*e=p->data;				/* 將欲移除的列首節點的值給予值給e */
	Q->front->next=p->next;	/* 將原列首節點的後繼p->next給予值給頭節點後繼，見圖中２ */
	if(Q->rear==p)			/* 若列首就是佇列尾，則移除後將rear指向頭節點，見圖中３ */
		Q->rear=Q->front;
	free(p);
	return OK;
}


