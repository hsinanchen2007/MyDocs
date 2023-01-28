#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* ¡¼¡¼¡¼ËÕÃ¦¡¼ */

typedef int Status; 
typedef int SElemType; /* SElemType ¡¼ÃÛ¡¼¹ú¡¼¡¼ÁÍ¡¼¡¼¡¼×mint */


/* t¡¼¡¼Ãþ§O/
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

/*  øe¡¼×Ù¡¼¡¼*/
Status InitStack(LinkStack *S)
{ 
        S->top = (LinkStackPtr)malloc(sizeof(StackNode));
        if(!S->top)
                return ERROR;
        S->top=NULL;
        S->count=0;
        return OK;
}

/* ¡¼¡¼¡¼‹Ý¡¼/
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

/* ¡¼¡¼S¡¼‹Ý¡¼¡¼ß_¡¼RUE¡¼¡¼ß_¡¼ALSE */
Status StackEmpty(LinkStack S)
{ 
        if (S.count==0)
                return TRUE;
        else
                return FALSE;
}

/* ß_¡¼¾©¡¼¶V¡¼¡¼¡¼¡¼¡¼*/
int StackLength(LinkStack S)
{ 
        return S.count;
}

/* ¡¼¡¼¡¼¡¼¡¼¡¼eß_¡¼¾«¡¼¡¼¡¼¡¼¡¼¡¼K¡¼¡¼ß_¡¼RROR */
Status GetTop(LinkStack S,SElemType *e)
{
        if (S.top==NULL)
                return ERROR;
        else
                *e=S.top->data;
        return OK;
}

/* ¡¼¡¼¡¼e¡¼¡¼¾«¡¼¡¼¡¼ */
Status Push(LinkStack *S,SElemType e)
{
        LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode)); 
        s->data=e; 
        s->next=S->top;	/* ¡¼¡¼¾«¡¼¡¼¡¼»­±`¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼*/
        S->top=s;         /* ¡¼£g¡¼¡¼s»­±`¡¼Õ¸êú¡¼¡¼¡¼¡¼*/
        S->count++;
        return OK;
}

/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¾«¡¼¡¼¡¼¡¼aß_¡¼¡¼¡¼¡¼¡¼K¡¼¡¼ß_¡¼RROR */
Status Pop(LinkStack *S,SElemType *e)
{ 
        LinkStackPtr p;
        if(StackEmpty(*S))
                return ERROR;
        *e=S->top->data;
        p=S->top;					/* ¡¼¡¼¡¼¡¼¡¼ëÆ¡¼¡¼¡¼¡¼*/
        S->top=S->top->next;    /* ¡¼¹²¡¼¡¼¡¼¡¼¡¼¡¼£f¡¼µá¡¼¡¼ôB¡¼¡¼¡¼¡¼*/
        free(p);                    /* ¡¼º´¡¼p */        
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
        printf("¡¼¡¼¡¼¡¼¡¼¡¼¡¼");
        StackTraverse(s);
        Pop(&s,&e);
        printf("Ä_²b¡¼·¤¡¼ e=%d\n",e);
        printf("¡¼Œ@¡¼%d(1:‹è0:øû\n",StackEmpty(s));
        GetTop(s,&e);
        printf("¡¼·¤¡¼ e=%d ¡¼Ã_¡¼¡¼%d\n",e,StackLength(s));
        ClearStack(&s);
        printf("¡¼‹Ý¡¼¡¼¡¼ÅÓ¡¼(1:‹è0:øû\n",StackEmpty(s));
        return 0;
}