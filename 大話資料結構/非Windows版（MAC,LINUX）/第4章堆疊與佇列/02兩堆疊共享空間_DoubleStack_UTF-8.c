#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 儲存空間起始分配量 */

typedef int Status; 

typedef int SElemType; /* SElemType型態根據實際情況而定，這裡假設為int */


/* 兩堆疊共享空間結構 */
typedef struct 
{
        SElemType data[MAXSIZE];
        int top1;	/* 堆疊1堆疊頂指標 */
        int top2;	/* 堆疊2堆疊頂指標 */
}SqDoubleStack;


Status visit(SElemType c)
{
        printf("%d ",c);
        return OK;
}

/*  建構一個空堆疊S */
Status InitStack(SqDoubleStack *S)
{ 
        S->top1=-1;
        S->top2=MAXSIZE;
        return OK;
}

/* 把S置為空堆疊 */
Status ClearStack(SqDoubleStack *S)
{ 
        S->top1=-1;
        S->top2=MAXSIZE;
        return OK;
}

/* 若堆疊S為空堆疊，則傳回TRUE，否則傳回FALSE */
Status StackEmpty(SqDoubleStack S)
{ 
        if (S.top1==-1 && S.top2==MAXSIZE)
                return TRUE;
        else
                return FALSE;
}

/* 傳回S的元素個數，即堆疊的長度 */
int StackLength(SqDoubleStack S)
{ 
        return (S.top1+1)+(MAXSIZE-S.top2);
}

/* 插入元素e為新的堆疊頂元素 */
Status Push(SqDoubleStack *S,SElemType e,int stackNumber)
{
        if (S->top1+1==S->top2)	/* 堆疊已滿，不能再push新元素了 */
                return ERROR;	
        if (stackNumber==1)			/* 堆疊1有元素進堆疊 */
                S->data[++S->top1]=e; /* 若是堆疊1則先top1+1後給陣列元素給予值。 */
        else if (stackNumber==2)	/* 堆疊2有元素進堆疊 */
                S->data[--S->top2]=e; /* 若是堆疊2則先top2-1後給陣列元素給予值。 */
        return OK;
}

/* 若堆疊不空，則移除S的堆疊頂元素，用e傳回其值，並傳回OK；否則傳回ERROR */
Status Pop(SqDoubleStack *S,SElemType *e,int stackNumber)
{ 
        if (stackNumber==1) 
        {
                if (S->top1==-1) 
                        return ERROR; /* 說明堆疊1已經是空堆疊，溢位 */
                *e=S->data[S->top1--]; /* 將堆疊1的堆疊頂元素出堆疊 */
        }
        else if (stackNumber==2)
        { 
                if (S->top2==MAXSIZE) 
                        return ERROR; /* 說明堆疊2已經是空堆疊，溢位 */
                *e=S->data[S->top2++]; /* 將堆疊2的堆疊頂元素出堆疊 */
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

        printf("堆疊中元素依次為：");
        StackTraverse(s);

        printf("目前堆疊中元素有：%d \n",StackLength(s));

        Pop(&s,&e,2);
        printf("出現的堆疊頂元素 e=%d\n",e);
        printf("堆疊空否：%d(1:空 0:否)\n",StackEmpty(s));

        for(j=6;j<=MAXSIZE-2;j++)
                Push(&s,j,1);

        printf("堆疊中元素依次為：");
        StackTraverse(s);

        printf("堆疊滿否：%d(1:否 0:滿)\n",Push(&s,100,1));

        
        ClearStack(&s);
        printf("清理堆疊後，堆疊空否：%d(1:空 0:否)\n",StackEmpty(s));
        
        return 0;
}