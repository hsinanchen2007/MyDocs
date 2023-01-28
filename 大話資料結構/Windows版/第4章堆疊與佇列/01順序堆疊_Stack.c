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

/* �����������O/
typedef struct
{
        SElemType data[MAXSIZE];
        int top; /* ������ո�� */
}SqStack;

Status visit(SElemType c)
{
        printf("%d ",c);
        return OK;
}

/*  �e���١���*/
Status InitStack(SqStack *S)
{ 
        /* S.data=(SElemType *)malloc(MAXSIZE*sizeof(SElemType)); */
        S->top=-1;
        return OK;
}

/* �������ݡ�/
Status ClearStack(SqStack *S)
{ 
        S->top=-1;
        return OK;
}

/* ����S���ݡ����_��RUE�����_��ALSE */
Status StackEmpty(SqStack S)
{ 
        if (S.top==-1)
                return TRUE;
        else
                return FALSE;
}

/* �_�������V����������*/
int StackLength(SqStack S)
{ 
        return S.top+1;
}

/* ������������e�_����������������K�����_��RROR */
Status GetTop(SqStack S,SElemType *e)
{
        if (S.top==-1)
                return ERROR;
        else
                *e=S.data[S.top];
        return OK;
}

/* ������e������������ */
Status Push(SqStack *S,SElemType e)
{
        if(S->top == MAXSIZE -1) /* ��o */
        {
                return ERROR;
        }
        S->top++;				/* ��ո��������/
        S->data[S->top]=e;  /* ��2�O�������`��������/
        return OK;
}

/* ������������������������a�_����������K�����_��RROR */
Status Pop(SqStack *S,SElemType *e)
{ 
        if(S->top==-1)
                return ERROR;
        *e=S->data[S->top];	/* �����������������`e */
        S->top--;				/* ��ո������/
        return OK;
}

/* ����������������y�d������ */
Status StackTraverse(SqStack S)
{
        int i;
        i=0;
        while(i<=S.top)
        {
                visit(S.data[i++]);
        }
        printf("\n");
        return OK;
}

int main()
{
        int j;
        SqStack s;
        int e;
        if(InitStack(&s)==OK)
                for(j=1;j<=10;j++)
                        Push(&s,j);
        printf("��������������");
        StackTraverse(s);
        Pop(&s,&e);
        printf("�_�b������ e=%d\n",e);
        printf("���@��%d(1:��0:��\n",StackEmpty(s));
        GetTop(s,&e);
        printf("������ e=%d ���_����%d\n",e,StackLength(s));
        ClearStack(&s);
        printf("���ݡ������ӡ�(1:��0:��\n",StackEmpty(s));
        
        return 0;
}

