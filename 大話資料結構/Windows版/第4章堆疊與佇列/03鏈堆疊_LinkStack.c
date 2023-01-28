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


/* t�������O/
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

/*  �e���١���*/
Status InitStack(LinkStack *S)
{ 
        S->top = (LinkStackPtr)malloc(sizeof(StackNode));
        if(!S->top)
                return ERROR;
        S->top=NULL;
        S->count=0;
        return OK;
}

/* �������ݡ�/
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

/* ����S���ݡ����_��RUE�����_��ALSE */
Status StackEmpty(LinkStack S)
{ 
        if (S.count==0)
                return TRUE;
        else
                return FALSE;
}

/* �_�������V����������*/
int StackLength(LinkStack S)
{ 
        return S.count;
}

/* ������������e�_����������������K�����_��RROR */
Status GetTop(LinkStack S,SElemType *e)
{
        if (S.top==NULL)
                return ERROR;
        else
                *e=S.top->data;
        return OK;
}

/* ������e������������ */
Status Push(LinkStack *S,SElemType e)
{
        LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode)); 
        s->data=e; 
        s->next=S->top;	/* ���������������`��������������������*/
        S->top=s;         /* ���g����s���`��ո����������*/
        S->count++;
        return OK;
}

/* ������������������������a�_����������K�����_��RROR */
Status Pop(LinkStack *S,SElemType *e)
{ 
        LinkStackPtr p;
        if(StackEmpty(*S))
                return ERROR;
        *e=S->top->data;
        p=S->top;					/* �����������ơ�������*/
        S->top=S->top->next;    /* �����������������f���᡼���B��������*/
        free(p);                    /* ������p */        
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