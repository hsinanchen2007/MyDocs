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


/* ����|�@�ɪŶ����c */
typedef struct 
{
        SElemType data[MAXSIZE];
        int top1;	/* ���|1���|������ */
        int top2;	/* ���|2���|������ */
}SqDoubleStack;


Status visit(SElemType c)
{
        printf("%d ",c);
        return OK;
}

/*  �غc�@�ӪŰ��|S */
Status InitStack(SqDoubleStack *S)
{ 
        S->top1=-1;
        S->top2=MAXSIZE;
        return OK;
}

/* ��S�m���Ű��| */
Status ClearStack(SqDoubleStack *S)
{ 
        S->top1=-1;
        S->top2=MAXSIZE;
        return OK;
}

/* �Y���|S���Ű��|�A�h�Ǧ^TRUE�A�_�h�Ǧ^FALSE */
Status StackEmpty(SqDoubleStack S)
{ 
        if (S.top1==-1 && S.top2==MAXSIZE)
                return TRUE;
        else
                return FALSE;
}

/* �Ǧ^S�������ӼơA�Y���|������ */
int StackLength(SqDoubleStack S)
{ 
        return (S.top1+1)+(MAXSIZE-S.top2);
}

/* ���J����e���s�����|������ */
Status Push(SqDoubleStack *S,SElemType e,int stackNumber)
{
        if (S->top1+1==S->top2)	/* ���|�w���A����Apush�s�����F */
                return ERROR;	
        if (stackNumber==1)			/* ���|1�������i���| */
                S->data[++S->top1]=e; /* �Y�O���|1�h��top1+1�ᵹ�}�C���������ȡC */
        else if (stackNumber==2)	/* ���|2�������i���| */
                S->data[--S->top2]=e; /* �Y�O���|2�h��top2-1�ᵹ�}�C���������ȡC */
        return OK;
}

/* �Y���|���šA�h����S�����|�������A��e�Ǧ^��ȡA�öǦ^OK�F�_�h�Ǧ^ERROR */
Status Pop(SqDoubleStack *S,SElemType *e,int stackNumber)
{ 
        if (stackNumber==1) 
        {
                if (S->top1==-1) 
                        return ERROR; /* �������|1�w�g�O�Ű��|�A���� */
                *e=S->data[S->top1--]; /* �N���|1�����|�������X���| */
        }
        else if (stackNumber==2)
        { 
                if (S->top2==MAXSIZE) 
                        return ERROR; /* �������|2�w�g�O�Ű��|�A���� */
                *e=S->data[S->top2++]; /* �N���|2�����|�������X���| */
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

        printf("���|�������̦����G");
        StackTraverse(s);

        printf("�ثe���|���������G%d \n",StackLength(s));

        Pop(&s,&e,2);
        printf("�X�{�����|������ e=%d\n",e);
        printf("���|�ŧ_�G%d(1:�� 0:�_)\n",StackEmpty(s));

        for(j=6;j<=MAXSIZE-2;j++)
                Push(&s,j,1);

        printf("���|�������̦����G");
        StackTraverse(s);

        printf("���|���_�G%d(1:�_ 0:��)\n",Push(&s,100,1));

        
        ClearStack(&s);
        printf("�M�z���|��A���|�ŧ_�G%d(1:�� 0:�_)\n",StackEmpty(s));
        
        return 0;
}