#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 〖〖〖苏忙〖 */

typedef int Status; 
typedef int QElemType; /* QElemType 〖蜜〖国〖〖镣〖〖〖譵int */

/* 〖〖〖〖〖〖〖〖隹*/
typedef struct
{
	QElemType data[MAXSIZE];
	int front;    	/* 〖〖〖 */
	int rear;		/* 〖〖〖〖P〖〖〖〖局〖〖逿〖〖〖 */
}SqQueue;

Status visit(QElemType c)
{
	printf("%d ",c);
	return OK;
}

/* 〖〖〖踪〖〖〖 */
Status InitQueue(SqQueue *Q)
{
	Q->front=0;
	Q->rear=0;
	return  OK;
}

/* 〖〖〖孇〖〖*/
Status ClearQueue(SqQueue *Q)
{
	Q->front=Q->rear=0;
	return OK;
}

/* 〖局〖〖孇〖〖〖達〖RUE,蹁〖〖ALSE */
Status QueueEmpty(SqQueue Q)
{ 
	if(Q.front==Q.rear) /* 局〖〖〖〖 */
		return TRUE;
	else
		return FALSE;
}

/* 達〖京〖禫〖〖巠〖〖〖〖〖〖〖*/
int QueueLength(SqQueue Q)
{
	return  (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

/* 〖局〖〖,〖〖e達〖拟〖蔉〖,〖岬OK,蹁〖〖RROR */
Status GetHead(SqQueue Q,QElemType *e)
{
	if(Q.front==Q.rear) /* 局〖〖*/
		return ERROR;
	*e=Q.data[Q.front];
	return OK;
}

/* 〖局〖〖〖〖〖〖〖e〖Q〖拟〖〖 */
Status EnQueue(SqQueue *Q,QElemType e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)	/* 局〖〖〖賋*/
		return ERROR;
	Q->data[Q->rear]=e;			/* 〖〖e画盽篮〖/
	Q->rear=(Q->rear+1)%MAXSIZE;/* rear〖〖〖〖〖〖〖〖*/
								/* 〖眐狕〖〖臼〖〖〖*/
	return  OK;
}

/* 〖局〖〖〖〖〖〖巨蔉〖〖a達〖〖 */
Status DeQueue(SqQueue *Q,QElemType *e)
{
	if (Q->front == Q->rear)			/* 局〖〖〖〖〖*/
		return ERROR;
	*e=Q->data[Q->front];				/* 〖〖蔉〖画盽e */
	Q->front=(Q->front+1)%MAXSIZE;	/* front〖〖〖〖〖〖〖〖*/
									/* 〖眐狕〖〖臼〖〖〖*/
	return  OK;
}

/* 〖〖遝篮〖〖〖〖〖〖y郿〖〖〖*/
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
	printf("〖〖局〖〖局〖〖〖%u(1:嬭0:\n",QueueEmpty(Q));

	printf("〖〖〖〖〖局〖〖(〖〖%d〖,-1〖〖〖〖臙: ",MAXSIZE-1);
	do
	{
		/* scanf("%d",&d); */
		d=i+100;
		if(d==-1)
			break;
		i++;
		EnQueue(&Q,d);
	}while(i<MAXSIZE-1);

	printf("局〖〖〖: %d\n",QueueLength(Q));
	printf("〖〖局〖〖〖%u(1:嬭0:\n",QueueEmpty(Q));
	printf("l〖%d〖〖〖謀〖〖,篮〖〖〖〖:\n",MAXSIZE);
	for(l=1;l<=MAXSIZE;l++)
	{
		DeQueue(&Q,&d);
		printf("〖〖〖〖〖%d,〖〖〖〖:%d \n",d,l+1000);
		/* scanf("%d",&d); */
		d=l+1000;
		EnQueue(&Q,d);
	}
	l=QueueLength(Q);

	printf("〖〖局〖〖〖〖〖: \n");
	QueueTraverse(Q);
	printf("〖〖〖〖%d郿〖\n",i+MAXSIZE);
	if(l-2>0)
		printf("〖〖〖巨謀〖d郿〖:\n",l-2);
	while(QueueLength(Q)>2)
	{
		DeQueue(&Q,&d);
		printf("〖〖〖〖〖〖%d\n",d);
	}

	j=GetHead(Q,&d);
	if(j)
		printf("〖〖巨蔉〖〖: %d\n",d);
	ClearQueue(&Q);
	printf("〖孇〖〖〖局〖〖〖%u(1:嬭0:\n",QueueEmpty(Q));
	return 0;
}

