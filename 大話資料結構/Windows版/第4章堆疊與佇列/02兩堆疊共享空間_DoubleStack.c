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


/* }¡¼¡¼¡¼¡¼¡¼ */
typedef struct 
{
        SElemType data[MAXSIZE];
        int top1;	/* ¡¼1¡¼Õ¸êú */
        int top2;	/* ¡¼2¡¼Õ¸êú */
}SqDoubleStack;


Status visit(SElemType c)
{
        printf("%d ",c);
        return OK;
}

/*  øe¡¼×Ù¡¼¡¼*/
Status InitStack(SqDoubleStack *S)
{ 
        S->top1=-1;
        S->top2=MAXSIZE;
        return OK;
}

/* ¡¼¡¼¡¼‹Ý¡¼/
Status ClearStack(SqDoubleStack *S)
{ 
        S->top1=-1;
        S->top2=MAXSIZE;
        return OK;
}

/* ¡¼¡¼S¡¼‹Ý¡¼¡¼ß_¡¼RUE¡¼¡¼ß_¡¼ALSE */
Status StackEmpty(SqDoubleStack S)
{ 
        if (S.top1==-1 && S.top2==MAXSIZE)
                return TRUE;
        else
                return FALSE;
}

/* ß_¡¼¾©¡¼¶V¡¼¡¼¡¼¡¼¡¼*/
int StackLength(SqDoubleStack S)
{ 
        return (S.top1+1)+(MAXSIZE-S.top2);
}

/* ¡¼¡¼¡¼e¡¼¡¼¾«¡¼¡¼¡¼ */
Status Push(SqDoubleStack *S,SElemType e,int stackNumber)
{
        if (S->top1+1==S->top2)	/* ¡¼¡¼o¡¼¡¼¡¼push¡¼¡¼¡¼K */
                return ERROR;	
        if (stackNumber==1)			/* ¡¼1¡¼¡¼¡¼¡¼¡¼/
                S->data[++S->top1]=e; /* ¡¼¡¼¡¼1¡¼£rtop1+1¡¼ªÞ¡¼¡¼¡¼»­Üð */
        else if (stackNumber==2)	/* ¡¼2¡¼¡¼¡¼¡¼¡¼/
                S->data[--S->top2]=e; /* ¡¼¡¼¡¼2¡¼£rtop2-1¡¼ªÞ¡¼¡¼¡¼»­Üð */
        return OK;
}

/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¾«¡¼¡¼¡¼¡¼aß_¡¼¡¼¡¼¡¼¡¼K¡¼¡¼ß_¡¼RROR */
Status Pop(SqDoubleStack *S,SElemType *e,int stackNumber)
{ 
        if (stackNumber==1) 
        {
                if (S->top1==-1) 
                        return ERROR; /* ¡¼¡Ò¡¼1¡¼›¢¡¼¡¼¡¼¡¼¡¼*/
                *e=S->data[S->top1--]; /* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼/
        }
        else if (stackNumber==2)
        { 
                if (S->top2==MAXSIZE) 
                        return ERROR; /* ¡¼¡Ò¡¼2¡¼›¢¡¼¡¼¡¼¡¼¡¼*/
                *e=S->data[S->top2++]; /* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼/
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

        printf("¡¼¡¼¡¼¡¼¡¼¡¼¡¼");
        StackTraverse(s);

        printf("ÌZ¡¼¡¼¡¼¡¼¡¼¡¼d \n",StackLength(s));

        Pop(&s,&e,2);
        printf("Ä_²b¡¼·¤¡¼ e=%d\n",e);
        printf("¡¼Œ@¡¼%d(1:‹è0:øû\n",StackEmpty(s));

        for(j=6;j<=MAXSIZE-2;j++)
                Push(&s,j,1);

        printf("¡¼¡¼¡¼¡¼¡¼¡¼¡¼");
        StackTraverse(s);

        printf("¡¼oÅÓ¡¼(1:Å¢0:o)\n",Push(&s,100,1));

        
        ClearStack(&s);
        printf("¡¼‹Ý¡¼¡¼¡¼ÅÓ¡¼(1:‹è0:øû\n",StackEmpty(s));
        
        return 0;
}