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

/* �`����C���s���x�s���c */
typedef struct
{
	QElemType data[MAXSIZE];
	int front;    	/* �Y���� */
	int rear;		/* �����СA�Y��C���šA���V��C���������U�@�Ӧ�m */
}SqQueue;

Status visit(QElemType c)
{
	printf("%d ",c);
	return OK;
}

/* �_�l�Ƥ@�ӪŦ�CQ */
Status InitQueue(SqQueue *Q)
{
	Q->front=0;
	Q->rear=0;
	return  OK;
}

/* �NQ�M���Ŧ�C */
Status ClearQueue(SqQueue *Q)
{
	Q->front=Q->rear=0;
	return OK;
}

/* �Y��CQ���Ŧ�C,�h�Ǧ^TRUE,�_�h�Ǧ^FALSE */
Status QueueEmpty(SqQueue Q)
{ 
	if(Q.front==Q.rear) /* ��C�Ū��Ч� */
		return TRUE;
	else
		return FALSE;
}

/* �Ǧ^Q�������ӼơA�]�N�O��C���ثe���� */
int QueueLength(SqQueue Q)
{
	return  (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

/* �Y��C����,�h��e�Ǧ^Q���C������,�öǦ^OK,�_�h�Ǧ^ERROR */
Status GetHead(SqQueue Q,QElemType *e)
{
	if(Q.front==Q.rear) /* ��C�� */
		return ERROR;
	*e=Q.data[Q.front];
	return OK;
}

/* �Y��C�����A�h���J����e��Q�s����C������ */
Status EnQueue(SqQueue *Q,QElemType e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)	/* ��C�����P�_ */
		return ERROR;
	Q->data[Q->rear]=e;			/* �N����e�����ȵ���C�� */
	Q->rear=(Q->rear+1)%MAXSIZE;/* rear���ЦV�Ჾ�@��m�A */
								/* �Y��̫�h���}�C���� */
	return  OK;
}

/* �Y��C���šA�h����Q���C�������A��e�Ǧ^��� */
Status DeQueue(SqQueue *Q,QElemType *e)
{
	if (Q->front == Q->rear)			/* ��C�Ū��P�_ */
		return ERROR;
	*e=Q->data[Q->front];				/* �N�C�����������ȵ�e */
	Q->front=(Q->front+1)%MAXSIZE;	/* front���ЦV�Ჾ�@��m�A */
									/* �Y��̫�h���}�C���� */
	return  OK;
}

/* �q�C�����C���̦����CQ���C�Ӥ�����X */
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
	printf("�_�l�Ʀ�C��A��C�ŧ_�H%u(1:�� 0:�_)\n",QueueEmpty(Q));

	printf("�п�J��Ʀ�C����(���W�L%d��),-1�����e������: ",MAXSIZE-1);
	do
	{
		/* scanf("%d",&d); */
		d=i+100;
		if(d==-1)
			break;
		i++;
		EnQueue(&Q,d);
	}while(i<MAXSIZE-1);

	printf("��C���׬�: %d\n",QueueLength(Q));
	printf("�{�b��C�ŧ_�H%u(1:�� 0:�_)\n",QueueEmpty(Q));
	printf("�s��%d���ѦC����������,��C�����J����:\n",MAXSIZE);
	for(l=1;l<=MAXSIZE;l++)
	{
		DeQueue(&Q,&d);
		printf("�����������O%d,���J������:%d \n",d,l+1000);
		/* scanf("%d",&d); */
		d=l+1000;
		EnQueue(&Q,d);
	}
	l=QueueLength(Q);

	printf("�{�b��C����������: \n");
	QueueTraverse(Q);
	printf("�@�V��C�����J�F%d�Ӥ���\n",i+MAXSIZE);
	if(l-2>0)
		printf("�{�b�ѦC������%d�Ӥ���:\n",l-2);
	while(QueueLength(Q)>2)
	{
		DeQueue(&Q,&d);
		printf("�����������Ȭ�%d\n",d);
	}

	j=GetHead(Q,&d);
	if(j)
		printf("�{�b�C��������: %d\n",d);
	ClearQueue(&Q);
	printf("�M�z��C��, ��C�ŧ_�H%u(1:�� 0:�_)\n",QueueEmpty(Q));
	return 0;
}

