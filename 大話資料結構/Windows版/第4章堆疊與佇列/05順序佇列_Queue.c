#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* ��������æ�� */

typedef int Status; 
typedef int QElemType; /* QElemType ���ۡ��������͡������mint */

/* ������������������*/
typedef struct
{
	QElemType data[MAXSIZE];
	int front;    	/* ������ */
	int rear;		/* �]��������P���������֡��t���T�����f�� */
}SqQueue;

Status visit(QElemType c)
{
	printf("%d ",c);
	return OK;
}

/* �������١����� */
Status InitQueue(SqQueue *Q)
{
	Q->front=0;
	Q->rear=0;
	return  OK;
}

/* ������������*/
Status ClearQueue(SqQueue *Q)
{
	Q->front=Q->rear=0;
	return OK;
}

/* ���֡������������_��RUE,�䡼��ALSE */
Status QueueEmpty(SqQueue Q)
{ 
	if(Q.front==Q.rear) /* �֡������� */
		return TRUE;
	else
		return FALSE;
}

/* �_�������V�����y��������������*/
int QueueLength(SqQueue Q)
{
	return  (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

/* ���֡���,����e�_���⡼�F��,���OK,�䡼��RROR */
Status GetHead(SqQueue Q,QElemType *e)
{
	if(Q.front==Q.rear) /* �֡���*/
		return ERROR;
	*e=Q.data[Q.front];
	return OK;
}

/* ���֡�������������e��Q���⡼�t�� */
Status EnQueue(SqQueue *Q,QElemType e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)	/* �֡������]*/
		return ERROR;
	Q->data[Q->rear]=e;			/* ����e���`����/
	Q->rear=(Q->rear+1)%MAXSIZE;/* rear����������������*/
								/* ���k�������ʡ�����*/
	return  OK;
}

/* ���֡��������������F����a�_���� */
Status DeQueue(SqQueue *Q,QElemType *e)
{
	if (Q->front == Q->rear)			/* �֡���������*/
		return ERROR;
	*e=Q->data[Q->front];				/* �����F�����`e */
	Q->front=(Q->front+1)%MAXSIZE;	/* front����������������*/
									/* ���k�������ʡ�����*/
	return  OK;
}

/* �����e��������������y�d������*/
Status QueueTraverse(SqQueue Q)
{ 
	int i;
	i=Q.front;
	while((i+Q.front)!=Q.rear)
	{
		visit(Q.data[i]);
		i=(i+1)%MAXSIZE;
	}
	printf("\n");
	return OK;
}

int main()
{
	Status j;
	int i=0,l;
	QElemType d;
	SqQueue Q;
	InitQueue(&Q);
	printf("�����֡����֡�����%u(1:��0:��\n",QueueEmpty(Q));

	printf("�����������֡���(����%d��,-1���������E: ",MAXSIZE-1);
	do
	{
		/* scanf("%d",&d); */
		d=i+100;
		if(d==-1)
			break;
		i++;
		EnQueue(&Q,d);
	}while(i<MAXSIZE-1);

	printf("�֡�����: %d\n",QueueLength(Q));
	printf("�����֡�����%u(1:��0:��\n",QueueEmpty(Q));
	printf("l��%d�������\����,����������:\n",MAXSIZE);
	for(l=1;l<=MAXSIZE;l++)
	{
		DeQueue(&Q,&d);
		printf("����������%d,��������:%d \n",d,l+1000);
		/* scanf("%d",&d); */
		d=l+1000;
		EnQueue(&Q,d);
	}
	l=QueueLength(Q);

	printf("�����֡���������: \n");
	QueueTraverse(Q);
	printf("�����]����%d�d��\n",i+MAXSIZE);
	if(l-2>0)
		printf("���������\��d�d��:\n",l-2);
	while(QueueLength(Q)>2)
	{
		DeQueue(&Q,&d);
		printf("������������%d\n",d);
	}

	j=GetHead(Q,&d);
	if(j)
		printf("�������F����: %d\n",d);
	ClearQueue(&Q);
	printf("�����������֡�����%u(1:��0:��\n",QueueEmpty(Q));
	return 0;
}

