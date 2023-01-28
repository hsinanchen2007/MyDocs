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

/* 順序堆疊結構 */
typedef struct
{
        SElemType data[MAXSIZE];
        int top; /* 用於堆疊頂指標 */
}SqStack;

Status visit(SElemType c)
{
        printf("%d ",c);
        return OK;
}

/*  建構一個空堆疊S */
Status InitStack(SqStack *S)
{ 
        /* S.data=(SElemType *)malloc(MAXSIZE*sizeof(SElemType)); */
        S->top=-1;
        return OK;
}

/* 把S置為空堆疊 */
Status ClearStack(SqStack *S)
{ 
        S->top=-1;
        return OK;
}

/* 若堆疊S為空堆疊，則傳回TRUE，否則傳回FALSE */
Status StackEmpty(SqStack S)
{ 
        if (S.top==-1)
                return TRUE;
        else
                return FALSE;
}

/* 傳回S的元素個數，即堆疊的長度 */
int StackLength(SqStack S)
{ 
        return S.top+1;
}

/* 若堆疊不空，則用e傳回S的堆疊頂元素，並傳回OK；否則傳回ERROR */
Status GetTop(SqStack S,SElemType *e)
{
        if (S.top==-1)
                return ERROR;
        else
                *e=S.data[S.top];
        return OK;
}

/* 插入元素e為新的堆疊頂元素 */
Status Push(SqStack *S,SElemType e)
{
        if(S->top == MAXSIZE -1) /* 堆疊滿 */
        {
                return ERROR;
        }
        S->top++;				/* 堆疊頂指標增加一 */
        S->data[S->top]=e;  /* 將新插入元素給予值給堆疊頂空間 */
        return OK;
}

/* 若堆疊不空，則移除S的堆疊頂元素，用e傳回其值，並傳回OK；否則傳回ERROR */
Status Pop(SqStack *S,SElemType *e)
{ 
        if(S->top==-1)
                return ERROR;
        *e=S->data[S->top];	/* 將要移除的堆疊頂元素給予值給e */
        S->top--;				/* 堆疊頂指標減一 */
        return OK;
}

/* 從堆疊底到堆疊頂依次對堆疊中每個元素顯示 */
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
        printf("堆疊中元素依次為：");
        StackTraverse(s);
        Pop(&s,&e);
        printf("出現的堆疊頂元素 e=%d\n",e);
        printf("堆疊空否：%d(1:空 0:否)\n",StackEmpty(s));
        GetTop(s,&e);
        printf("堆疊頂元素 e=%d 堆疊的長度為%d\n",e,StackLength(s));
        ClearStack(&s);
        printf("清理堆疊後，堆疊空否：%d(1:空 0:否)\n",StackEmpty(s));
        
        return 0;
}

