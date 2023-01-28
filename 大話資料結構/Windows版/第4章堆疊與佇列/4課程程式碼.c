typedef int SElemType; 	/* SElemType ���ۡ��������͡������mint */

/* �����������O/
typedef struct
{
        SElemType data[MAXSIZE];
        int top; 		/* ������ո�� */
}SqStack;

/* ������e������������ */
Status Push(SqStack *S,SElemType e)
{
    if(S->top == MAXSIZE -1) 	/* ��o */
    {
    	return ERROR;
    }
    S->top++;					/* ��ո��������/
    S->data[S->top]=e;  		/* ��2�O�������`��������/
    return OK;
}

/* ������������������������a�_����������K�����_��RROR */
Status Pop(SqStack *S,SElemType *e)
{ 
    if(S->top==-1)
    	return ERROR;
    *e=S->data[S->top];		/* �����������������`e */
    S->top--;				/* ��ո������/
    return OK;
}

/* }���������� */
typedef struct 
{
        SElemType data[MAXSIZE];
        int top1;	/* ��1��ո�� */
        int top2;	/* ��2��ո�� */
}SqDoubleStack;

/* ������e������������ */
Status Push(SqDoubleStack *S,SElemType e,int stackNumber)
{
    if (S->top1+1==S->top2)		/* ����o������push������K */
    	return ERROR;	
    if (stackNumber==1)			/* ��1����������/
        S->data[++S->top1]=e; 	/* ������1���rtop1+1���ޡ��������� */
    else if (stackNumber==2)	/* ��2����������/
        S->data[--S->top2]=e; 	/* ������2���rtop2-1���ޡ��������� */
    return OK;
}

/* ������������������������a�_����������K�����_��RROR */
Status Pop(SqDoubleStack *S,SElemType *e,int stackNumber)
{ 
    if (stackNumber==1) 
    {
        if (S->top1==-1) 
            return ERROR; 		/* ���ҡ�1��������������*/
        *e=S->data[S->top1--]; 	/* ����������������/
    }
    else if (stackNumber==2)
    { 
        if (S->top2==MAXSIZE) 
            return ERROR; 		/* ���ҡ�2��������������*/
        *e=S->data[S->top2++]; 	/* ����������������/
    }
    return OK;
}

/* t�������O/
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

/* ������e������������ */
Status Push(LinkStack *S,SElemType e)
{
    LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode)); 
    s->data=e; 
    s->next=S->top;	/* ���������������`��������������������*/
    S->top=s;  		/* ���g����s���`��ո����������*/
    S->count++;
    return OK;
}

/* ������������������������a�_����������K�����_��RROR */
Status Pop(LinkStack *S,SElemType *e)
{ 
    LinkStackPtr p;
    if(StackEmpty(*S))
    	return ERROR;
    *e=S->top->data;
    p=S->top;				/* �����������ơ�������*/
    S->top=S->top->next;    /* �����������������f���᡼���B��������*/
    free(p);                /* ������p */        
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

/* ���١��졼���� */
int Fbi(int i)  
{
	if( i < 2 )
		return i == 0 ? 0 : 1;  
    return Fbi(i-1)+Fbi(i-2);  /* ��/Fbi�y���������������q�ѡ���/
}  

int main()
{
	int i;
	printf("���m�����١���P��n");
	for(i = 0;i < 40;i++)  
		printf("%d ", Fbi(i));  
    return 0;
}

typedef int QElemType; 	/* QElemType ���ۡ��������͡������mint */
/* ������������������*/
typedef struct
{
	QElemType data[MAXSIZE];
	int front;    		/* ������ */
	int rear;			/* �]��������P���������֡��t���T�����f�� */
}SqQueue;

/* �������١����� */
Status InitQueue(SqQueue *Q)
{
	Q->front=0;
	Q->rear=0;
	return  OK;
}

/* �_�������V�����y��������������*/
int QueueLength(SqQueue Q)
{
	return  (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

/* ���֡�������������e��Q���⡼�t�� */
Status EnQueue(SqQueue *Q,QElemType e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)	/* �֡������]*/
		return ERROR;
	Q->data[Q->rear]=e;						/* ����e���`����/
	Q->rear=(Q->rear+1)%MAXSIZE;			/* rear����������������*/
											/* ���k�������ʡ�����*/
	return  OK;
}

/* ���֡��������������F����a�_���� */
Status DeQueue(SqQueue *Q,QElemType *e)
{
	if (Q->front == Q->rear)			/* �֡���������*/
		return ERROR;
	*e=Q->data[Q->front];				/* �����F�����`e */
	Q->front=(Q->front+1)%MAXSIZE;		/* front����������������*/
										/* ���k�������ʡ�����*/
	return  OK;
}

typedef int QElemType; 	/* QElemType ���ۡ��������͡������mint */

typedef struct QNode	/* ������*/
{
   QElemType data;
   struct QNode *next;
}QNode,*QueuePtr;

typedef struct			/* �֡����������O/
{
   QueuePtr front,rear; /* ���������� */
}LinkQueue;

/* ������e��Q���g�����t�� */
Status EnQueue(LinkQueue *Q,QElemType e)
{ 
	QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
	if(!s) 				/* ����������*/
		exit(OVERFLOW);
	s->data=e;
	s->next=NULL;
	Q->rear->next=s;	/* ���J����e������s���`��������������������*/
	Q->rear=s;			/* �����_�����������B��ar����s��������*/
	return OK;
}

/* ���֡���,�����⡼�F��,��e�_����,���OK,�䡼��RROR */
Status DeQueue(LinkQueue *Q,QElemType *e)
{
	QueuePtr p;
	if(Q->front==Q->rear)
		return ERROR;
	p=Q->front->next;		/* �����������\�ˡ���p��������*/
	*e=p->data;				/* �����������\�����b���� */
	Q->front->next=p->next;	/* ��������������->next���`����������������*/
	if(Q->rear==p)			/* �����O��������������rear����������������*/
		Q->rear=Q->front;
	free(p);
	return OK;
}


