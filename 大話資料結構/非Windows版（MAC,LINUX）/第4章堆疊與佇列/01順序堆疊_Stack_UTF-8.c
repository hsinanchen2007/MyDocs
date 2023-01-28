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
typedef int SElemType; /* SElemType���A�ھڹ�ڱ��p�өw�A�o�̰��]��int */

/* ���ǰ��|���c */
typedef struct
{
        SElemType data[MAXSIZE];
        int top; /* �Ω���|������ */
}SqStack;

Status visit(SElemType c)
{
        printf("%d ",c);
        return OK;
}

/*  �غc�@�ӪŰ��|S */
Status InitStack(SqStack *S)
{ 
        /* S.data=(SElemType *)malloc(MAXSIZE*sizeof(SElemType)); */
        S->top=-1;
        return OK;
}

/* ��S�m���Ű��| */
Status ClearStack(SqStack *S)
{ 
        S->top=-1;
        return OK;
}

/* �Y���|S���Ű��|�A�h�Ǧ^TRUE�A�_�h�Ǧ^FALSE */
Status StackEmpty(SqStack S)
{ 
        if (S.top==-1)
                return TRUE;
        else
                return FALSE;
}

/* �Ǧ^S�������ӼơA�Y���|������ */
int StackLength(SqStack S)
{ 
        return S.top+1;
}

/* �Y���|���šA�h��e�Ǧ^S�����|�������A�öǦ^OK�F�_�h�Ǧ^ERROR */
Status GetTop(SqStack S,SElemType *e)
{
        if (S.top==-1)
                return ERROR;
        else
                *e=S.data[S.top];
        return OK;
}

/* ���J����e���s�����|������ */
Status Push(SqStack *S,SElemType e)
{
        if(S->top == MAXSIZE -1) /* ���|�� */
        {
                return ERROR;
        }
        S->top++;				/* ���|�����мW�[�@ */
        S->data[S->top]=e;  /* �N�s���J���������ȵ����|���Ŷ� */
        return OK;
}

/* �Y���|���šA�h����S�����|�������A��e�Ǧ^��ȡA�öǦ^OK�F�_�h�Ǧ^ERROR */
Status Pop(SqStack *S,SElemType *e)
{ 
        if(S->top==-1)
                return ERROR;
        *e=S->data[S->top];	/* �N�n���������|�����������ȵ�e */
        S->top--;				/* ���|�����д�@ */
        return OK;
}

/* �q���|������|���̦�����|���C�Ӥ������ */
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
        printf("���|�������̦����G");
        StackTraverse(s);
        Pop(&s,&e);
        printf("�X�{�����|������ e=%d\n",e);
        printf("���|�ŧ_�G%d(1:�� 0:�_)\n",StackEmpty(s));
        GetTop(s,&e);
        printf("���|������ e=%d ���|�����׬�%d\n",e,StackLength(s));
        ClearStack(&s);
        printf("�M�z���|��A���|�ŧ_�G%d(1:�� 0:�_)\n",StackEmpty(s));
        
        return 0;
}

