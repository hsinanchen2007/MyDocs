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


/* ����|���c */
typedef struct StackNode
{
        SElemType data;
        struct StackNode *next;
}StackNode,*LinkStackPtr;


typedef struct
{
        LinkStackPtr top;
        int count;
}LinkStack;

Status visit(SElemType c)
{
        printf("%d ",c);
        return OK;
}

/*  �غc�@�ӪŰ��|S */
Status InitStack(LinkStack *S)
{ 
        S->top = (LinkStackPtr)malloc(sizeof(StackNode));
        if(!S->top)
                return ERROR;
        S->top=NULL;
        S->count=0;
        return OK;
}

/* ��S�m���Ű��| */
Status ClearStack(LinkStack *S)
{ 
        LinkStackPtr p,q;
        p=S->top;
        while(p)
        {  
                q=p;
                p=p->next;
                free(q);
        } 
        S->count=0;
        return OK;
}

/* �Y���|S���Ű��|�A�h�Ǧ^TRUE�A�_�h�Ǧ^FALSE */
Status StackEmpty(LinkStack S)
{ 
        if (S.count==0)
                return TRUE;
        else
                return FALSE;
}

/* �Ǧ^S�������ӼơA�Y���|������ */
int StackLength(LinkStack S)
{ 
        return S.count;
}

/* �Y���|���šA�h��e�Ǧ^S�����|�������A�öǦ^OK�F�_�h�Ǧ^ERROR */
Status GetTop(LinkStack S,SElemType *e)
{
        if (S.top==NULL)
                return ERROR;
        else
                *e=S.top->data;
        return OK;
}

/* ���J����e���s�����|������ */
Status Push(LinkStack *S,SElemType e)
{
        LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode)); 
        s->data=e; 
        s->next=S->top;	/* ��ثe�����|�����������ȵ��s�`�I�����~�A���Ϥ��� */
        S->top=s;         /* �N�s���`�Is�����ȵ����|�����СA���Ϥ��� */
        S->count++;
        return OK;
}

/* �Y���|���šA�h����S�����|�������A��e�Ǧ^��ȡA�öǦ^OK�F�_�h�Ǧ^ERROR */
Status Pop(LinkStack *S,SElemType *e)
{ 
        LinkStackPtr p;
        if(StackEmpty(*S))
                return ERROR;
        *e=S->top->data;
        p=S->top;					/* �N���|���`�I�����ȵ�p�A���Ϥ��� */
        S->top=S->top->next;    /* �ϱo���|�����ФU���@��A���V��@�`�I�A���Ϥ��� */
        free(p);                    /* ����`�Ip */        
        S->count--;
        return OK;
}

Status StackTraverse(LinkStack S)
{
        LinkStackPtr p;
        p=S.top;
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
        int j;
        LinkStack s;
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