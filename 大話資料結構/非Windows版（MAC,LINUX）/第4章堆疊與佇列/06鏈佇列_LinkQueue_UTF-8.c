#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 儲存空間起始分配量 */

typedef int Status; 

typedef int QElemType; /* QElemType型態根據實際情況而定，這裡假設為int */

typedef struct QNode	/* 節點結構 */
{
   QElemType data;
   struct QNode *next;
}QNode,*QueuePtr;

typedef struct			/* 佇列的鏈結串列結構 */
{
   QueuePtr front,rear; /* 列首、佇列尾指標 */
}LinkQueue;

Status visit(QElemType c)
{
	printf("%d ",c);
	return OK;
}

/* 建構一個空佇列Q */
Status InitQueue(LinkQueue *Q)
{ 
	Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q->front)
		exit(OVERFLOW);
	Q->front->next=NULL;
	return OK;
}

/* 銷毀佇列Q */
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

/* 將Q清為空佇列 */
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

/* 若Q為空佇列,則傳回TRUE,否則傳回FALSE */
Status QueueEmpty(LinkQueue Q)
{ 
	if(Q.front==Q.rear)
		return TRUE;
	else
		return FALSE;
}

/* 求佇列的長度 */
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

/* 若佇列不空,則用e傳回Q的列首元素,並傳回OK,否則傳回ERROR */
Status GetHead(LinkQueue Q,QElemType *e)
{ 
	QueuePtr p;
	if(Q.front==Q.rear)
		return ERROR;
	p=Q.front->next;
	*e=p->data;
	return OK;
}


/* 插入元素e為Q的新的佇列尾元素 */
Status EnQueue(LinkQueue *Q,QElemType e)
{ 
	QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
	if(!s) /* 儲存分配失敗 */
		exit(OVERFLOW);
	s->data=e;
	s->next=NULL;
	Q->rear->next=s;	/* 把擁有元素e的新節點s給予值給原佇列尾節點的後繼，見圖中１ */
	Q->rear=s;		/* 把目前的s設定為佇列尾節點，rear指向s，見圖中２ */
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
	Q->front->next=p->next;/* 將原列首節點的後繼p->next給予值給頭節點後繼，見圖中２ */
	if(Q->rear==p)		/* 若列首就是佇列尾，則移除後將rear指向頭節點，見圖中３ */
		Q->rear=Q->front;
	free(p);
	return OK;
}

/* 從列首到佇列尾依次對佇列Q中每個元素輸出 */
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
		printf("成功地建構了一個空佇列!\n");
	printf("是否空佇列？%d(1:空 0:否)  ",QueueEmpty(q));
	printf("佇列的長度為%d\n",QueueLength(q));
	EnQueue(&q,-5);
	EnQueue(&q,5);
	EnQueue(&q,10);
	printf("插入3個元素(-5,5,10)後,佇列的長度為%d\n",QueueLength(q));
	printf("是否空佇列？%d(1:空 0:否)  ",QueueEmpty(q));
	printf("佇列的元素依次為：");
	QueueTraverse(q);
	i=GetHead(q,&d);
	if(i==OK)
	 printf("列首元素是：%d\n",d);
	DeQueue(&q,&d);
	printf("移除了列首元素%d\n",d);
	i=GetHead(q,&d);
	if(i==OK)
		printf("新的列首元素是：%d\n",d);
	ClearQueue(&q);
	printf("清理佇列後,q.front=%u q.rear=%u q.front->next=%u\n",q.front,q.rear,q.front->next);
	DestroyQueue(&q);
	printf("銷毀佇列後,q.front=%u q.rear=%u\n",q.front, q.rear);
	
	return 0;
}

