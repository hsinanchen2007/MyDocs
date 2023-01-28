typedef int SElemType; 	/* SElemType���A�ھڹ�ڱ��p�өw�A�o�̰��]��int */

/* ���ǰ��|���c */
typedef struct
{
        SElemType data[MAXSIZE];
        int top; 		/* �Ω���|������ */
}SqStack;

/* ���J����e���s�����|������ */
Status Push(SqStack *S,SElemType e)
{
    if(S->top == MAXSIZE -1) 	/* ���|�� */
    {
    	return ERROR;
    }
    S->top++;					/* ���|�����мW�[�@ */
    S->data[S->top]=e;  		/* �N�s���J���������ȵ����|���Ŷ� */
    return OK;
}

/* �Y���|���šA�h����S�����|�������A��e�Ǧ^��ȡA�öǦ^OK�F�_�h�Ǧ^ERROR */
Status Pop(SqStack *S,SElemType *e)
{ 
    if(S->top==-1)
    	return ERROR;
    *e=S->data[S->top];		/* �N�n���������|�����������ȵ�e */
    S->top--;				/* ���|�����д�@ */
    return OK;
}

/* ����|�@�ɪŶ����c */
typedef struct 
{
        SElemType data[MAXSIZE];
        int top1;	/* ���|1���|������ */
        int top2;	/* ���|2���|������ */
}SqDoubleStack;

/* ���J����e���s�����|������ */
Status Push(SqDoubleStack *S,SElemType e,int stackNumber)
{
    if (S->top1+1==S->top2)		/* ���|�w���A����Apush�s�����F */
    	return ERROR;	
    if (stackNumber==1)			/* ���|1�������i���| */
        S->data[++S->top1]=e; 	/* �Y�O���|1�h��top1+1�ᵹ�}�C���������ȡC */
    else if (stackNumber==2)	/* ���|2�������i���| */
        S->data[--S->top2]=e; 	/* �Y�O���|2�h��top2-1�ᵹ�}�C���������ȡC */
    return OK;
}

/* �Y���|���šA�h����S�����|�������A��e�Ǧ^��ȡA�öǦ^OK�F�_�h�Ǧ^ERROR */
Status Pop(SqDoubleStack *S,SElemType *e,int stackNumber)
{ 
    if (stackNumber==1) 
    {
        if (S->top1==-1) 
            return ERROR; 		/* �������|1�w�g�O�Ű��|�A���� */
        *e=S->data[S->top1--]; 	/* �N���|1�����|�������X���| */
    }
    else if (stackNumber==2)
    { 
        if (S->top2==MAXSIZE) 
            return ERROR; 		/* �������|2�w�g�O�Ű��|�A���� */
        *e=S->data[S->top2++]; 	/* �N���|2�����|�������X���| */
    }
    return OK;
}

/* ����|���c */
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

/* ���J����e���s�����|������ */
Status Push(LinkStack *S,SElemType e)
{
    LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode)); 
    s->data=e; 
    s->next=S->top;	/* ��ثe�����|�����������ȵ��s�`�I�����~�A���Ϥ��� */
    S->top=s;  		/* �N�s���`�Is�����ȵ����|�����СA���Ϥ��� */
    S->count++;
    return OK;
}

/* �Y���|���šA�h����S�����|�������A��e�Ǧ^��ȡA�öǦ^OK�F�_�h�Ǧ^ERROR */
Status Pop(LinkStack *S,SElemType *e)
{ 
    LinkStackPtr p;
    if(StackEmpty(*S))
    	return ERROR;
    *e=S->top->data;
    p=S->top;				/* �N���|���`�I�����ȵ�p�A���Ϥ��� */
    S->top=S->top->next;    /* �ϱo���|�����ФU���@��A���V��@�`�I�A���Ϥ��� */
    free(p);                /* ����`�Ip */        
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

/* �O�󪺻��k��� */
int Fbi(int i)  
{
	if( i < 2 )
		return i == 0 ? 0 : 1;  
    return Fbi(i-1)+Fbi(i-2);  /* �o��Fbi�N�O��Ʀۤv�A����b�I�s�ۤv */
}  

int main()
{
	int i;
	printf("���k��ܶO��ƦC�G\n");
	for(i = 0;i < 40;i++)  
		printf("%d ", Fbi(i));  
    return 0;
}

typedef int QElemType; 	/* QElemType���A�ھڹ�ڱ��p�өw�A�o�̰��]��int */
/* �`����C���s���x�s���c */
typedef struct
{
	QElemType data[MAXSIZE];
	int front;    		/* �Y���� */
	int rear;			/* �����СA�Y��C���šA���V��C���������U�@�Ӧ�m */
}SqQueue;

/* �_�l�Ƥ@�ӪŦ�CQ */
Status InitQueue(SqQueue *Q)
{
	Q->front=0;
	Q->rear=0;
	return  OK;
}

/* �Ǧ^Q�������ӼơA�]�N�O��C���ثe���� */
int QueueLength(SqQueue Q)
{
	return  (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

/* �Y��C�����A�h���J����e��Q�s����C������ */
Status EnQueue(SqQueue *Q,QElemType e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)	/* ��C�����P�_ */
		return ERROR;
	Q->data[Q->rear]=e;						/* �N����e�����ȵ���C�� */
	Q->rear=(Q->rear+1)%MAXSIZE;			/* rear���ЦV�Ჾ�@��m�A */
											/* �Y��̫�h���}�C���� */
	return  OK;
}

/* �Y��C���šA�h����Q���C�������A��e�Ǧ^��� */
Status DeQueue(SqQueue *Q,QElemType *e)
{
	if (Q->front == Q->rear)			/* ��C�Ū��P�_ */
		return ERROR;
	*e=Q->data[Q->front];				/* �N�C�����������ȵ�e */
	Q->front=(Q->front+1)%MAXSIZE;		/* front���ЦV�Ჾ�@��m�A */
										/* �Y��̫�h���}�C���� */
	return  OK;
}

typedef int QElemType; 	/* QElemType���A�ھڹ�ڱ��p�өw�A�o�̰��]��int */

typedef struct QNode	/* �`�I���c */
{
   QElemType data;
   struct QNode *next;
}QNode,*QueuePtr;

typedef struct			/* ��C���쵲��C���c */
{
   QueuePtr front,rear; /* �C���B��C������ */
}LinkQueue;

/* ���J����e��Q���s����C������ */
Status EnQueue(LinkQueue *Q,QElemType e)
{ 
	QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
	if(!s) 				/* �x�s���t���� */
		exit(OVERFLOW);
	s->data=e;
	s->next=NULL;
	Q->rear->next=s;	/* ��֦�����e���s�`�Is�����ȵ����C���`�I�����~�A���Ϥ��� */
	Q->rear=s;			/* ��ثe��s�]�w����C���`�I�Arear���Vs�A���Ϥ��� */
	return OK;
}

/* �Y��C����,����Q���C������,��e�Ǧ^���,�öǦ^OK,�_�h�Ǧ^ERROR */
Status DeQueue(LinkQueue *Q,QElemType *e)
{
	QueuePtr p;
	if(Q->front==Q->rear)
		return ERROR;
	p=Q->front->next;		/* �N���������C���`�I�Ȧs��p�A���Ϥ��� */
	*e=p->data;				/* �N���������C���`�I���ȵ����ȵ�e */
	Q->front->next=p->next;	/* �N��C���`�I�����~p->next�����ȵ��Y�`�I���~�A���Ϥ��� */
	if(Q->rear==p)			/* �Y�C���N�O��C���A�h������Nrear���V�Y�`�I�A���Ϥ��� */
		Q->rear=Q->front;
	free(p);
	return OK;
}


