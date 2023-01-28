#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* ¡¼¡¼¡¼ËÕÃ¦¡¼ */

typedef int Status; 

typedef int QElemType; /* QElemType ¡¼ÃÛ¡¼¹ú¡¼¡¼ÁÍ¡¼¡¼¡¼×mint */

typedef struct QNode	/* ¡¼¡¼ö¿*/
{
   QElemType data;
   struct QNode *next;
}QNode,*QueuePtr;

typedef struct			/* ¾Ö¡¼¡¼¡¼¡¼Ãþ§O/
{
   QueuePtr front,rear; /* ¾ÞÚÑÀº¡¼¡¼ */
}LinkQueue;

Status visit(QElemType c)
{
	printf("%d ",c);
	return OK;
}

/* øe¡¼×Ù¡¼¡¼¡¼ */
Status InitQueue(LinkQueue *Q)
{ 
	Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q->front)
		exit(OVERFLOW);
	Q->front->next=NULL;
	return OK;
}

/* ¡¼¡¼¡¼¡¼ */
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

/* ¡¼¡¼¡¼‹þ¡¼¡¼*/
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

/* ¡¼Q¡¼‹þ¡¼¡¼¡¼ß_¡¼RUE,õä¡¼¡¼ALSE */
Status QueueEmpty(LinkQueue Q)
{ 
	if(Q.front==Q.rear)
		return TRUE;
	else
		return FALSE;
}

/* ¡¼¾Ö¡¼¡¼¡¼ */
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

/* ¡¼¾Ö¡¼¡¼,¡¼¡¼eß_¡¼Äâ¡¼ÊF¡¼,¡¼áµOK,õä¡¼¡¼RROR */
Status GetHead(LinkQueue Q,QElemType *e)
{ 
	QueuePtr p;
	if(Q.front==Q.rear)
		return ERROR;
	p=Q.front->next;
	*e=p->data;
	return OK;
}


/* ¡¼¡¼¡¼e¡¼Q¾ª£g¡¼¡¼¢t¡¼ */
Status EnQueue(LinkQueue *Q,QElemType e)
{ 
	QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
	if(!s) /* ¡¼¡¼¡¼¡¼¡¼*/
		exit(OVERFLOW);
	s->data=e;
	s->next=NULL;
	Q->rear->next=s;	/* ¡¼¦J¡¼¡¼e¾ª¡¼¡¼s»­±`¡¼Àº¡¼§§¡¼¡¼¡¼¡¼¡¼¡¼*/
	Q->rear=s;		/* ¡¼¡¼Ã_¡¼¡¼¡¼Àº¡¼ôB¡¼ar¡¼¡¼s¡¼¡¼¡¼¡¼*/
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
	Q->front->next=p->next;/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼->next»­±`¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼*/
	if(Q->rear==p)		/* ¡¼¾ÞÐO¡¼Àº¡¼¡¼¡¼¡¼¡¼rear¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼*/
		Q->rear=Q->front;
	free(p);
	return OK;
}

/* ¡¼¡¼ßeÀº¡¼¡¼¡¼¡¼¡¼¡¼yàd¡¼¡¼¡¼*/
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
		printf("¡¼ÒLøe¡¼¡¼×Ù¡¼¡¼¡¼\n");
	printf("¡¼ÐG¡¼¡¼¡¼í¨(1:‹è0:øû  ",QueueEmpty(q));
	printf("¾Ö¡¼¡¼¡¼¡¼%d\n",QueueLength(q));
	EnQueue(&q,-5);
	EnQueue(&q,5);
	EnQueue(&q,10);
	printf("¡¼¡¼ÅÍ¡¼(-5,5,10)¡¼¾Ö¡¼¡¼¡¼¡¼%d\n",QueueLength(q));
	printf("¡¼ÐG¡¼¡¼¡¼í¨(1:‹è0:øû  ",QueueEmpty(q));
	printf("¾Ö¡¼¡¼¡¼¡¼¡¼¡¼");
	QueueTraverse(q);
	i=GetHead(q,&d);
	if(i==OK)
	 printf("¾ÞÊF¡¼¡¼¡¼d\n",d);
	DeQueue(&q,&d);
	printf("¡¼¡¼¡¼¡¼ÊF¡¼%d\n",d);
	i=GetHead(q,&d);
	if(i==OK)
		printf("¡¼Äâ¡¼ÊF¡¼¡¼¡¼d\n",d);
	ClearQueue(&q);
	printf("¡¼‹þ¡¼¡¼¡¼.front=%u q.rear=%u q.front->next=%u\n",q.front,q.rear,q.front->next);
	DestroyQueue(&q);
	printf("¡¼¡¼¡¼¡¼¡¼.front=%u q.rear=%u\n",q.front, q.rear);
	
	return 0;
}

