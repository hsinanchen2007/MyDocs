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

/* 循環佇列的連序儲存結構 */
typedef struct
{
	QElemType data[MAXSIZE];
	int front;    	/* 頭指標 */
	int rear;		/* 尾指標，若佇列不空，指向佇列尾元素的下一個位置 */
}SqQueue;

Status visit(QElemType c)
{
	printf("%d ",c);
	return OK;
}

/* 起始化一個空佇列Q */
Status InitQueue(SqQueue *Q)
{
	Q->front=0;
	Q->rear=0;
	return  OK;
}

/* 將Q清為空佇列 */
Status ClearQueue(SqQueue *Q)
{
	Q->front=Q->rear=0;
	return OK;
}

/* 若佇列Q為空佇列,則傳回TRUE,否則傳回FALSE */
Status QueueEmpty(SqQueue Q)
{ 
	if(Q.front==Q.rear) /* 佇列空的標志 */
		return TRUE;
	else
		return FALSE;
}

/* 傳回Q的元素個數，也就是佇列的目前長度 */
int QueueLength(SqQueue Q)
{
	return  (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

/* 若佇列不空,則用e傳回Q的列首元素,並傳回OK,否則傳回ERROR */
Status GetHead(SqQueue Q,QElemType *e)
{
	if(Q.front==Q.rear) /* 佇列空 */
		return ERROR;
	*e=Q.data[Q.front];
	return OK;
}

/* 若佇列未滿，則插入元素e為Q新的佇列尾元素 */
Status EnQueue(SqQueue *Q,QElemType e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)	/* 佇列滿的判斷 */
		return ERROR;
	Q->data[Q->rear]=e;			/* 將元素e給予值給佇列尾 */
	Q->rear=(Q->rear+1)%MAXSIZE;/* rear指標向後移一位置， */
								/* 若到最後則轉到陣列頁首 */
	return  OK;
}

/* 若佇列不空，則移除Q中列首元素，用e傳回其值 */
Status DeQueue(SqQueue *Q,QElemType *e)
{
	if (Q->front == Q->rear)			/* 佇列空的判斷 */
		return ERROR;
	*e=Q->data[Q->front];				/* 將列首元素給予值給e */
	Q->front=(Q->front+1)%MAXSIZE;	/* front指標向後移一位置， */
									/* 若到最後則轉到陣列頁首 */
	return  OK;
}

/* 從列首到佇列尾依次對佇列Q中每個元素輸出 */
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
	printf("起始化佇列後，佇列空否？%u(1:空 0:否)\n",QueueEmpty(Q));

	printf("請輸入整數佇列元素(不超過%d個),-1為提前結束符: ",MAXSIZE-1);
	do
	{
		/* scanf("%d",&d); */
		d=i+100;
		if(d==-1)
			break;
		i++;
		EnQueue(&Q,d);
	}while(i<MAXSIZE-1);

	printf("佇列長度為: %d\n",QueueLength(Q));
	printf("現在佇列空否？%u(1:空 0:否)\n",QueueEmpty(Q));
	printf("連續%d次由列首移除元素,佇列尾插入元素:\n",MAXSIZE);
	for(l=1;l<=MAXSIZE;l++)
	{
		DeQueue(&Q,&d);
		printf("移除的元素是%d,插入的元素:%d \n",d,l+1000);
		/* scanf("%d",&d); */
		d=l+1000;
		EnQueue(&Q,d);
	}
	l=QueueLength(Q);

	printf("現在佇列中的元素為: \n");
	QueueTraverse(Q);
	printf("共向佇列尾插入了%d個元素\n",i+MAXSIZE);
	if(l-2>0)
		printf("現在由列首移除%d個元素:\n",l-2);
	while(QueueLength(Q)>2)
	{
		DeQueue(&Q,&d);
		printf("移除的元素值為%d\n",d);
	}

	j=GetHead(Q,&d);
	if(j)
		printf("現在列首元素為: %d\n",d);
	ClearQueue(&Q);
	printf("清理佇列後, 佇列空否？%u(1:空 0:否)\n",QueueEmpty(Q));
	return 0;
}

