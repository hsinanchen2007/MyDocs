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

typedef struct QNode	/* ������*/
{
   QElemType data;
   struct QNode *next;
}QNode,*QueuePtr;

typedef struct			/* �֡����������O/
{
   QueuePtr front,rear; /* ���������� */
}LinkQueue;

Status visit(QElemType c)
{
	printf("%d ",c);
	return OK;
}

/* �e���١����� */
Status InitQueue(LinkQueue *Q)
{ 
	Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q->front)
		exit(OVERFLOW);
	Q->front->next=NULL;
	return OK;
}

/* �������� */
Status DestroyQueue(LinkQueue *Q)
{
	while(Q->front)
	{
		 Q->rear=Q->front->next;
		 free(Q->front);
		 Q->front=Q->rear;
	}
	return OK;
}

/* ������������*/
Status ClearQueue(LinkQueue *Q)
{
	QueuePtr p,q;
	Q->rear=Q->front;
	p=Q->front->next;
	Q->front->next=NULL;
	while(p)
	{
		 q=p;
		 p=p->next;
		 free(q);
	}
	return OK;
}

/* ��Q�����������_��RUE,�䡼��ALSE */
Status QueueEmpty(LinkQueue Q)
{ 
	if(Q.front==Q.rear)
		return TRUE;
	else
		return FALSE;
}

/* ���֡����� */
int QueueLength(LinkQueue Q)
{ 
	int i=0;
	QueuePtr p;
	p=Q.front;
	while(Q.rear!=p)
	{
		 i++;
		 p=p->next;
	}
	return i;
}

/* ���֡���,����e�_���⡼�F��,���OK,�䡼��RROR */
Status GetHead(LinkQueue Q,QElemType *e)
{ 
	QueuePtr p;
	if(Q.front==Q.rear)
		return ERROR;
	p=Q.front->next;
	*e=p->data;
	return OK;
}


/* ������e��Q���g�����t�� */
Status EnQueue(LinkQueue *Q,QElemType e)
{ 
	QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
	if(!s) /* ����������*/
		exit(OVERFLOW);
	s->data=e;
	s->next=NULL;
	Q->rear->next=s;	/* ���J����e������s���`��������������������*/
	Q->rear=s;		/* �����_�����������B��ar����s��������*/
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
	Q->front->next=p->next;/* ��������������->next���`����������������*/
	if(Q->rear==p)		/* �����O��������������rear����������������*/
		Q->rear=Q->front;
	free(p);
	return OK;
}

/* �����e��������������y�d������*/
Status QueueTraverse(LinkQueue Q)
{
	QueuePtr p;
	p=Q.front->next;
	while(p)
	{
		 visit(p->data);
		 p=p->next;
	}
	printf("\n");
	return OK;
}

int main()
{
	int i;
	QElemType d;
	LinkQueue q;
	i=InitQueue(&q);
	if(i)
		printf("���L�e�����١�����\n");
	printf("���G�������(1:��0:��  ",QueueEmpty(q));
	printf("�֡�������%d\n",QueueLength(q));
	EnQueue(&q,-5);
	EnQueue(&q,5);
	EnQueue(&q,10);
	printf("�����͡�(-5,5,10)���֡�������%d\n",QueueLength(q));
	printf("���G�������(1:��0:��  ",QueueEmpty(q));
	printf("�֡�����������");
	QueueTraverse(q);
	i=GetHead(q,&d);
	if(i==OK)
	 printf("���F������d\n",d);
	DeQueue(&q,&d);
	printf("���������F��%d\n",d);
	i=GetHead(q,&d);
	if(i==OK)
		printf("���⡼�F������d\n",d);
	ClearQueue(&q);
	printf("����������.front=%u q.rear=%u q.front->next=%u\n",q.front,q.rear,q.front->next);
	DestroyQueue(&q);
	printf("����������.front=%u q.rear=%u\n",q.front, q.rear);
	
	return 0;
}

