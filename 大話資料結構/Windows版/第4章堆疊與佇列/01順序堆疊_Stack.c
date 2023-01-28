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

/* ¡¼¡¼¡¼¡¼Ãþ§O/
typedef struct
{
        SElemType data[MAXSIZE];
        int top; /* ¡¼¡¼¡¼Õ¸êú */
}SqStack;

Status visit(SElemType c)
{
        printf("%d ",c);
        return OK;
}

/*  øe¡¼×Ù¡¼¡¼*/
Status InitStack(SqStack *S)
{ 
        /* S.data=(SElemType *)malloc(MAXSIZE*sizeof(SElemType)); */
        S->top=-1;
        return OK;
}

/* ¡¼¡¼¡¼‹Ý¡¼/
Status ClearStack(SqStack *S)
{ 
        S->top=-1;
        return OK;
}

/* ¡¼¡¼S¡¼‹Ý¡¼¡¼ß_¡¼RUE¡¼¡¼ß_¡¼ALSE */
Status StackEmpty(SqStack S)
{ 
        if (S.top==-1)
                return TRUE;
        else
                return FALSE;
}

/* ß_¡¼¾©¡¼¶V¡¼¡¼¡¼¡¼¡¼*/
int StackLength(SqStack S)
{ 
        return S.top+1;
}

/* ¡¼¡¼¡¼¡¼¡¼¡¼eß_¡¼¾«¡¼¡¼¡¼¡¼¡¼¡¼K¡¼¡¼ß_¡¼RROR */
Status GetTop(SqStack S,SElemType *e)
{
        if (S.top==-1)
                return ERROR;
        else
                *e=S.data[S.top];
        return OK;
}

/* ¡¼¡¼¡¼e¡¼¡¼¾«¡¼¡¼¡¼ */
Status Push(SqStack *S,SElemType e)
{
        if(S->top == MAXSIZE -1) /* ¡¼o */
        {
                return ERROR;
        }
        S->top++;				/* ¡¼Õ¸êú¡¼¡¼¡¼/
        S->data[S->top]=e;  /* ¡¼2§O¡¼¡¼»­±`¡¼¡¼¡¼¡¼/
        return OK;
}

/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¾«¡¼¡¼¡¼¡¼aß_¡¼¡¼¡¼¡¼¡¼K¡¼¡¼ß_¡¼RROR */
Status Pop(SqStack *S,SElemType *e)
{ 
        if(S->top==-1)
                return ERROR;
        *e=S->data[S->top];	/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼»­±`e */
        S->top--;				/* ¡¼Õ¸êú¡¼¡¼/
        return OK;
}

/* ¡¼¡¼¿ý¡¼¡¼¡¼¡¼¡¼yàd¡¼¡¼¡¼ */
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

