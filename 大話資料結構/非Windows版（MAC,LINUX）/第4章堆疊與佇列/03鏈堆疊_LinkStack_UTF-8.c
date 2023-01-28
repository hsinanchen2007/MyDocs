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


/* 鏈堆疊結構 */
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

/*  建構一個空堆疊S */
Status InitStack(LinkStack *S)
{ 
        S->top = (LinkStackPtr)malloc(sizeof(StackNode));
        if(!S->top)
                return ERROR;
        S->top=NULL;
        S->count=0;
        return OK;
}

/* 把S置為空堆疊 */
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

/* 若堆疊S為空堆疊，則傳回TRUE，否則傳回FALSE */
Status StackEmpty(LinkStack S)
{ 
        if (S.count==0)
                return TRUE;
        else
                return FALSE;
}

/* 傳回S的元素個數，即堆疊的長度 */
int StackLength(LinkStack S)
{ 
        return S.count;
}

/* 若堆疊不空，則用e傳回S的堆疊頂元素，並傳回OK；否則傳回ERROR */
Status GetTop(LinkStack S,SElemType *e)
{
        if (S.top==NULL)
                return ERROR;
        else
                *e=S.top->data;
        return OK;
}

/* 插入元素e為新的堆疊頂元素 */
Status Push(LinkStack *S,SElemType e)
{
        LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode)); 
        s->data=e; 
        s->next=S->top;	/* 把目前的堆疊頂元素給予值給新節點的後繼，見圖中１ */
        S->top=s;         /* 將新的節點s給予值給堆疊頂指標，見圖中２ */
        S->count++;
        return OK;
}

/* 若堆疊不空，則移除S的堆疊頂元素，用e傳回其值，並傳回OK；否則傳回ERROR */
Status Pop(LinkStack *S,SElemType *e)
{ 
        LinkStackPtr p;
        if(StackEmpty(*S))
                return ERROR;
        *e=S->top->data;
        p=S->top;					/* 將堆疊頂節點給予值給p，見圖中３ */
        S->top=S->top->next;    /* 使得堆疊頂指標下移一位，指向後一節點，見圖中４ */
        free(p);                    /* 釋放節點p */        
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