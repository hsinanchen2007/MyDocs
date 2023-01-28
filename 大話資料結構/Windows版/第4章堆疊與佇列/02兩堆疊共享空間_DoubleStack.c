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

typedef int SElemType; /* SElemType ���ۡ��������͡������mint */


/* }���������� */
typedef struct 
{
        SElemType data[MAXSIZE];
        int top1;	/* ��1��ո�� */
        int top2;	/* ��2��ո�� */
}SqDoubleStack;


Status visit(SElemType c)
{
        printf("%d ",c);
        return OK;
}

/*  �e���١���*/
Status InitStack(SqDoubleStack *S)
{ 
        S->top1=-1;
        S->top2=MAXSIZE;
        return OK;
}

/* �������ݡ�/
Status ClearStack(SqDoubleStack *S)
{ 
        S->top1=-1;
        S->top2=MAXSIZE;
        return OK;
}

/* ����S���ݡ����_��RUE�����_��ALSE */
Status StackEmpty(SqDoubleStack S)
{ 
        if (S.top1==-1 && S.top2==MAXSIZE)
                return TRUE;
        else
                return FALSE;
}

/* �_�������V����������*/
int StackLength(SqDoubleStack S)
{ 
        return (S.top1+1)+(MAXSIZE-S.top2);
}

/* ������e������������ */
Status Push(SqDoubleStack *S,SElemType e,int stackNumber)
{
        if (S->top1+1==S->top2)	/* ����o������push������K */
                return ERROR;	
        if (stackNumber==1)			/* ��1����������/
                S->data[++S->top1]=e; /* ������1���rtop1+1���ޡ��������� */
        else if (stackNumber==2)	/* ��2����������/
                S->data[--S->top2]=e; /* ������2���rtop2-1���ޡ��������� */
        return OK;
}

/* ������������������������a�_����������K�����_��RROR */
Status Pop(SqDoubleStack *S,SElemType *e,int stackNumber)
{ 
        if (stackNumber==1) 
        {
                if (S->top1==-1) 
                        return ERROR; /* ���ҡ�1��������������*/
                *e=S->data[S->top1--]; /* ����������������/
        }
        else if (stackNumber==2)
        { 
                if (S->top2==MAXSIZE) 
                        return ERROR; /* ���ҡ�2��������������*/
                *e=S->data[S->top2++]; /* ����������������/
        }
        return OK;
}

Status StackTraverse(SqDoubleStack S)
{
        int i;
        i=0;
        while(i<=S.top1)
        {
                visit(S.data[i++]);
        }
        i=S.top2;
        while(i<MAXSIZE)
        {
                visit(S.data[i++]);
        }
        printf("\n");
        return OK;
}

int main()
{
        int j;
        SqDoubleStack s;
        int e;
        if(InitStack(&s)==OK)
        {
                for(j=1;j<=5;j++)
                        Push(&s,j,1);
                for(j=MAXSIZE;j>=MAXSIZE-2;j--)
                        Push(&s,j,2);
        }

        printf("��������������");
        StackTraverse(s);

        printf("�Z������������d \n",StackLength(s));

        Pop(&s,&e,2);
        printf("�_�b������ e=%d\n",e);
        printf("���@��%d(1:��0:��\n",StackEmpty(s));

        for(j=6;j<=MAXSIZE-2;j++)
                Push(&s,j,1);

        printf("��������������");
        StackTraverse(s);

        printf("��o�ӡ�(1:Ţ0:o)\n",Push(&s,100,1));

        
        ClearStack(&s);
        printf("���ݡ������ӡ�(1:��0:��\n",StackEmpty(s));
        
        return 0;
}