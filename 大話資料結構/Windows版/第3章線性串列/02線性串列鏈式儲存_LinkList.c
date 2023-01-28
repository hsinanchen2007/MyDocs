#include "stdio.h"    
#include "string.h"
#include "ctype.h"      
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* ��������æ�� */

typedef int Status;/* Status������ ��,���������������á���OK�R*/
typedef int ElemType;/* ElemType ���ۡ��������͡������mint */


Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}

typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList; /* ���JnkList */

/* ����t��������*/
Status InitList(LinkList *L) 
{ 
    *L=(LinkList)malloc(sizeof(Node)); /* ����������L�������\�b*/
    if(!(*L)) /* ����������*/
            return ERROR;
    (*L)->next=NULL; /* ����������*/

    return OK;
}

/* ��������������������������������L���������_��RUE�����_��ALSE */
Status ListEmpty(LinkList L)
{ 
    if(L->next)
            return FALSE;
    else
            return TRUE;
}

/* ������������������������������������������/
Status ClearList(LinkList *L)
{ 
	LinkList p,q;
	p=(*L)->next;           /*  p�����򡼡���/
	while(p)                /*  u�v�� */
	{
		q=p->next;
		free(p);
		p=q;
	}
	(*L)->next=NULL;        /* ��������������*/
	return OK;
}

/* �������������������������������_�����������V��/
int ListLength(LinkList L)
{
    int i=0;
    LinkList p=L->next; /* p�����򡼡���/
    while(p)                        
    {
        i++;
        p=p->next;
    }
    return i;
}

/* ����������������������������istLength(L) */
/* ���\����e�_�������V�������ʳ�/
Status GetElem(LinkList L,int i,ElemType *e)
{
	int j;
	LinkList p;		/* ���ҡ�����*/
	p = L->next;		/* ��p����t���졼������/
	j = 1;		/*  j������ */
	while (p && j<i)  /* p������������j����ɽ�����������P/
	{   
		p = p->next;  /* ��p������������ */
		++j;
	}
	if ( !p || j>i ) 
		return ERROR;  /*  ���d������ */
	*e = p->data;   /*  �����d���� */
	return OK;
}

/* ����������������������*/
/* ���\�����������c�����F��������������*/
/* �������񡼡��������������0 */
int LocateElem(LinkList L,ElemType e)
{
    int i=0;
    LinkList p=L->next;
    while(p)
    {
        i++;
        if(p->data==e) /* �������񡼡��� */
                return i;
        p=p->next;
    }

    return 0;
}


/* ����������������������1����istLength(L)��*/
/* ���\����L�����`�����������񡼡���e���_���� */
Status ListInsert(LinkList *L,int i,ElemType e)
{ 
	int j;
	LinkList p,s;
	p = *L;   
	j = 1;
	while (p && j < i)     /* ���������� */
	{
		p = p->next;
		++j;
	} 
	if (!p || j > i) 
		return ERROR;   /* ���d������ */
	s = (LinkList)malloc(sizeof(Node));  /*  ��������(C����������) */
	s->data = e;  
	s->next = p->next;      /* �����������������  */
	p->next = s;          /* �����`p���� */
	return OK;
}

/* ����������������������������istLength(L) */
/* ���\�������졼�V����������e�_�������_���� */
Status ListDelete(LinkList *L,int i,ElemType *e) 
{ 
	int j;
	LinkList p,q;
	p = *L;
	j = 1;
	while (p->next && j < i)	/* ���������d�� */
	{
        p = p->next;
        ++j;
	}
	if (!(p->next) || j > i) 
	    return ERROR;           /* ���d������ */
	q = p->next;
	p->next = q->next;			/* ���������`p���� */
	*e = q->data;               /* ���������� */
	free(q);                    /* ������������������������/
	return OK;
}

/* ����������������������*/
/* ���\����������`����������*/
Status ListTraverse(LinkList L)
{
    LinkList p=L->next;
    while(p)
    {
        visit(p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}

/*  ������n�d���ʤС������\�����������������q���O/
void CreateListHead(LinkList *L, int n) 
{
	LinkList p;
	int i;
	srand(time(0));                         /* ������������ */
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;                      /*  �r�����w�������ݡ� */
	for (i=0; i<n; i++) 
	{
		p = (LinkList)malloc(sizeof(Node)); /*  �������� */
		p->data = rand()%100+1;             /*  ������100������ */
		p->next = (*L)->next;    
		(*L)->next = p;						/*  ��������/
	}
}

/*  ������n�d���ʤС������\�����������������q���O/
void CreateListTail(LinkList *L, int n) 
{
	LinkList p,r;
	int i;
	srand(time(0));                      /* ������������ */
	*L = (LinkList)malloc(sizeof(Node)); /* L�����a������/
	r=*L;                                /* r�������]������ */
	for (i=0; i<n; i++) 
	{
		p = (Node *)malloc(sizeof(Node)); /*  �������� */
		p->data = rand()%100+1;           /*  ������100������ */
		r->next=p;                        /* ������������������������/
		r = p;                            /* ������������ᶡ��y���� */
	}
	r->next = NULL;                       /* ����t���� */
}

int main()
{        
    LinkList L;
    ElemType e;
    Status i;
    int j,k;
    i=InitList(&L);
    printf("����L����stLength(L)=%d\n",ListLength(L));
    for(j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
    printf("��L﷡������O1������data=");
    ListTraverse(L); 

    printf("ListLength(L)=%d \n",ListLength(L));
    i=ListEmpty(L);
    printf("L���G����%d(1:�� 0:��\n",i);

    i=ClearList(&L);
    printf("���ԡ���stLength(L)=%d\n",ListLength(L));
    i=ListEmpty(L);
    printf("L���G����%d(1:�� 0:��\n",i);

    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);
    printf("��L﷡������O1��0����data=");
    ListTraverse(L); 

    printf("ListLength(L)=%d \n",ListLength(L));

    ListInsert(&L,1,0);
    printf("��L﷡�������L.data=");
    ListTraverse(L); 
    printf("ListLength(L)=%d \n",ListLength(L));

    GetElem(L,5,&e);
    printf("�@�d����ᶡ�d\n",e);
    for(j=3;j<=4;j++)
    {
            k=LocateElem(L,j);
            if(k)
                    printf("�`d�d�����%d\n",k,j);
            else
                    printf("u������%d����\n",j);
    }
    

    k=ListLength(L); /* k������/
    for(j=k+1;j>=k;j--)
    {
            i=ListDelete(&L,j,&e); /* �������V�� */
            if(i==ERROR)
                    printf("������d�V������n",j);
            else
                    printf("������d�塼��������d\n",j,e);
    }
    printf("������L������);
    ListTraverse(L); 

    j=5;
    ListDelete(&L,j,&e); /* �������V�� */
    printf("������d�塼��������d\n",j,e);

    printf("������L������);
    ListTraverse(L); 

    i=ClearList(&L);
    printf("\n���ԡ���stLength(L)=%d\n",ListLength(L));
    CreateListHead(&L,20);
    printf("������������(�����ڡ�;
    ListTraverse(L); 
    
    i=ClearList(&L);
    printf("\n��������stLength(L)=%d\n",ListLength(L));
    CreateListTail(&L,20);
    printf("������������(�]���ڡ�;
    ListTraverse(L); 


    return 0;
}

