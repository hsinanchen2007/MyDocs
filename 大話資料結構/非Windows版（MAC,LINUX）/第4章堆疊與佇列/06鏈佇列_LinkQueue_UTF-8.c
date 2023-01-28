#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �x�s�Ŷ��_�l���t�q */

typedef int Status; 

typedef int QElemType; /* QElemType���A�ھڹ�ڱ��p�өw�A�o�̰��]��int */

typedef struct QNode	/* �`�I���c */
{
   QElemType data;
   struct QNode *next;
}QNode,*QueuePtr;

typedef struct			/* ��C���쵲��C���c */
{
   QueuePtr front,rear; /* �C���B��C������ */
}LinkQueue;

Status visit(QElemType c)
{
	printf("%d ",c);
	return OK;
}

/* �غc�@�ӪŦ�CQ */
Status InitQueue(LinkQueue *Q)
{ 
	Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q->front)
		exit(OVERFLOW);
	Q->front->next=NULL;
	return OK;
}

/* �P����CQ */
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

/* �NQ�M���Ŧ�C */
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

/* �YQ���Ŧ�C,�h�Ǧ^TRUE,�_�h�Ǧ^FALSE */
Status QueueEmpty(LinkQueue Q)
{ 
	if(Q.front==Q.rear)
		return TRUE;
	else
		return FALSE;
}

/* �D��C������ */
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

/* �Y��C����,�h��e�Ǧ^Q���C������,�öǦ^OK,�_�h�Ǧ^ERROR */
Status GetHead(LinkQueue Q,QElemType *e)
{ 
	QueuePtr p;
	if(Q.front==Q.rear)
		return ERROR;
	p=Q.front->next;
	*e=p->data;
	return OK;
}


/* ���J����e��Q���s����C������ */
Status EnQueue(LinkQueue *Q,QElemType e)
{ 
	QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
	if(!s) /* �x�s���t���� */
		exit(OVERFLOW);
	s->data=e;
	s->next=NULL;
	Q->rear->next=s;	/* ��֦�����e���s�`�Is�����ȵ����C���`�I�����~�A���Ϥ��� */
	Q->rear=s;		/* ��ثe��s�]�w����C���`�I�Arear���Vs�A���Ϥ��� */
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
	Q->front->next=p->next;/* �N��C���`�I�����~p->next�����ȵ��Y�`�I���~�A���Ϥ��� */
	if(Q->rear==p)		/* �Y�C���N�O��C���A�h������Nrear���V�Y�`�I�A���Ϥ��� */
		Q->rear=Q->front;
	free(p);
	return OK;
}

/* �q�C�����C���̦����CQ���C�Ӥ�����X */
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
		printf("���\�a�غc�F�@�ӪŦ�C!\n");
	printf("�O�_�Ŧ�C�H%d(1:�� 0:�_)  ",QueueEmpty(q));
	printf("��C�����׬�%d\n",QueueLength(q));
	EnQueue(&q,-5);
	EnQueue(&q,5);
	EnQueue(&q,10);
	printf("���J3�Ӥ���(-5,5,10)��,��C�����׬�%d\n",QueueLength(q));
	printf("�O�_�Ŧ�C�H%d(1:�� 0:�_)  ",QueueEmpty(q));
	printf("��C�������̦����G");
	QueueTraverse(q);
	i=GetHead(q,&d);
	if(i==OK)
	 printf("�C�������O�G%d\n",d);
	DeQueue(&q,&d);
	printf("�����F�C������%d\n",d);
	i=GetHead(q,&d);
	if(i==OK)
		printf("�s���C�������O�G%d\n",d);
	ClearQueue(&q);
	printf("�M�z��C��,q.front=%u q.rear=%u q.front->next=%u\n",q.front,q.rear,q.front->next);
	DestroyQueue(&q);
	printf("�P����C��,q.front=%u q.rear=%u\n",q.front, q.rear);
	
	return 0;
}

