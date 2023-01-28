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

#define MAXSIZE 20 /* �x�s�Ŷ��_�l���t�q */

typedef int Status;/* Status�O��ƪ����A,��ȬO��Ƶ��G���A�{���X�A�pOK�� */
typedef int ElemType;/* ElemType���A�ھڹ�ڱ��p�өw�A�o�̰��]��int */


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
typedef struct Node *LinkList; /* �w�qLinkList */

/* �_�l���즡�u�ʦ�C */
Status InitList(LinkList *L) 
{ 
    *L=(LinkList)malloc(sizeof(Node)); /* �����Y�`�I,�è�L���V���Y�`�I */
    if(!(*L)) /* �x�s���t���� */
            return ERROR;
    (*L)->next=NULL; /* ���а쬰�� */

    return OK;
}

/* �_�l����G�즡�u�ʦ�CL�w�s�b�C�ʧ@���G�G�YL���Ū�A�h�Ǧ^TRUE�A�_�h�Ǧ^FALSE */
Status ListEmpty(LinkList L)
{ 
    if(L->next)
            return FALSE;
    else
            return TRUE;
}

/* �_�l����G�즡�u�ʦ�CL�w�s�b�C�ʧ@���G�G�NL���]���Ū� */
Status ClearList(LinkList *L)
{ 
	LinkList p,q;
	p=(*L)->next;           /*  p���V�Ĥ@�Ӹ`�I */
	while(p)                /*  �S���� */
	{
		q=p->next;
		free(p);
		p=q;
	}
	(*L)->next=NULL;        /* �Y�`�I���а쬰�� */
	return OK;
}

/* �_�l����G�즡�u�ʦ�CL�w�s�b�C�ʧ@���G�G�Ǧ^L����Ƥ����Ӽ� */
int ListLength(LinkList L)
{
    int i=0;
    LinkList p=L->next; /* p���V�Ĥ@�Ӹ`�I */
    while(p)                        
    {
        i++;
        p=p->next;
    }
    return i;
}

/* �_�l����G�즡�u�ʦ�CL�w�s�b�A1��i��ListLength(L) */
/* �ʧ@���G�G��e�Ǧ^L����i�Ӹ�Ƥ������� */
Status GetElem(LinkList L,int i,ElemType *e)
{
	int j;
	LinkList p;		/* �ŧi�@�`�Ip */
	p = L->next;		/* ��p���V�쵲��CL���Ĥ@�Ӹ`�I */
	j = 1;		/*  j���p�ƾ� */
	while (p && j<i)  /* p�����ũάO�p�ƾ�j�٨S������i�ɡA�`���~�� */
	{   
		p = p->next;  /* ��p���V�U�@�Ӹ`�I */
		++j;
	}
	if ( !p || j>i ) 
		return ERROR;  /*  ��i�Ӥ������s�b */
	*e = p->data;   /*  ����i�Ӥ�������� */
	return OK;
}

/* �_�l����G�즡�u�ʦ�CL�w�s�b */
/* �ʧ@���G�G�Ǧ^L����1�ӻPe�������t����Ƥ�������ǡC */
/* �Y�o�˪���Ƥ������s�b�A�h�Ǧ^�Ȭ�0 */
int LocateElem(LinkList L,ElemType e)
{
    int i=0;
    LinkList p=L->next;
    while(p)
    {
        i++;
        if(p->data==e) /* ���o�˪���Ƥ��� */
                return i;
        p=p->next;
    }

    return 0;
}


/* �_�l����G�즡�u�ʦ�CL�w�s�b,1��i��ListLength(L)�A */
/* �ʧ@���G�G�bL����i�Ӧ�m���e���J�s����Ƥ���e�AL�����ץ[1 */
Status ListInsert(LinkList *L,int i,ElemType e)
{ 
	int j;
	LinkList p,s;
	p = *L;   
	j = 1;
	while (p && j < i)     /* �M���i�Ӹ`�I */
	{
		p = p->next;
		++j;
	} 
	if (!p || j > i) 
		return ERROR;   /* ��i�Ӥ������s�b */
	s = (LinkList)malloc(sizeof(Node));  /*  ���ͷs�`�I(C�y�t�Э���) */
	s->data = e;  
	s->next = p->next;      /* �Np�����~�`�I�����ȵ�s�����~  */
	p->next = s;          /* �Ns�����ȵ�p�����~ */
	return OK;
}

/* �_�l����G�즡�u�ʦ�CL�w�s�b�A1��i��ListLength(L) */
/* �ʧ@���G�G����L����i�Ӹ�Ƥ����A�å�e�Ǧ^��ȡAL�����״�1 */
Status ListDelete(LinkList *L,int i,ElemType *e) 
{ 
	int j;
	LinkList p,q;
	p = *L;
	j = 1;
	while (p->next && j < i)	/* �ˬd�M���i�Ӥ��� */
	{
        p = p->next;
        ++j;
	}
	if (!(p->next) || j > i) 
	    return ERROR;           /* ��i�Ӥ������s�b */
	q = p->next;
	p->next = q->next;			/* �Nq�����~�����ȵ�p�����~ */
	*e = q->data;               /* �Nq�`�I������Ƶ�e */
	free(q);                    /* ���t�Φ^�����`�I�A����O���� */
	return OK;
}

/* �_�l����G�즡�u�ʦ�CL�w�s�b */
/* �ʧ@���G�G�̦���L���C�Ӹ�Ƥ�����X */
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

/*  �H������n�Ӥ������ȡA�إ߱a���Y�`�I������u�ʦ�CL�]�Y���k�^ */
void CreateListHead(LinkList *L, int n) 
{
	LinkList p;
	int i;
	srand(time(0));                         /* �_�l���H���ƺؤl */
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;                      /*  ���إߤ@�ӱa�Y�`�I�����쵲��C */
	for (i=0; i<n; i++) 
	{
		p = (LinkList)malloc(sizeof(Node)); /*  ���ͷs�`�I */
		p->data = rand()%100+1;             /*  �H������100�H�����Ʀr */
		p->next = (*L)->next;    
		(*L)->next = p;						/*  ���J����Y */
	}
}

/*  �H������n�Ӥ������ȡA�إ߱a���Y�`�I������u�ʦ�CL�]�����k�^ */
void CreateListTail(LinkList *L, int n) 
{
	LinkList p,r;
	int i;
	srand(time(0));                      /* �_�l���H���ƺؤl */
	*L = (LinkList)malloc(sizeof(Node)); /* L����ӽu�ʦ�C */
	r=*L;                                /* r�����V�������`�I */
	for (i=0; i<n; i++) 
	{
		p = (Node *)malloc(sizeof(Node)); /*  ���ͷs�`�I */
		p->data = rand()%100+1;           /*  �H������100�H�����Ʀr */
		r->next=p;                        /* �N����׺ݸ`�I�����Ы��V�s�`�I */
		r = p;                            /* �N�ثe���s�`�I�w�q������׺ݸ`�I */
	}
	r->next = NULL;                       /* ��ܥثe�쵲��C���� */
}

int main()
{        
    LinkList L;
    ElemType e;
    Status i;
    int j,k;
    i=InitList(&L);
    printf("�_�l��L��GListLength(L)=%d\n",ListLength(L));
    for(j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
    printf("�bL�����Y�̦����J1��5��GL.data=");
    ListTraverse(L); 

    printf("ListLength(L)=%d \n",ListLength(L));
    i=ListEmpty(L);
    printf("L�O�_�šGi=%d(1:�O 0:�_)\n",i);

    i=ClearList(&L);
    printf("�M�zL��GListLength(L)=%d\n",ListLength(L));
    i=ListEmpty(L);
    printf("L�O�_�šGi=%d(1:�O 0:�_)\n",i);

    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);
    printf("�bL������̦����J1��10��GL.data=");
    ListTraverse(L); 

    printf("ListLength(L)=%d \n",ListLength(L));

    ListInsert(&L,1,0);
    printf("�bL�����Y���J0��GL.data=");
    ListTraverse(L); 
    printf("ListLength(L)=%d \n",ListLength(L));

    GetElem(L,5,&e);
    printf("��5�Ӥ������Ȭ��G%d\n",e);
    for(j=3;j<=4;j++)
    {
            k=LocateElem(L,j);
            if(k)
                    printf("��%d�Ӥ������Ȭ�%d\n",k,j);
            else
                    printf("�S���Ȭ�%d������\n",j);
    }
    

    k=ListLength(L); /* k����� */
    for(j=k+1;j>=k;j--)
    {
            i=ListDelete(&L,j,&e); /* ������j�Ӹ�� */
            if(i==ERROR)
                    printf("������%d�Ӹ�ƥ���\n",j);
            else
                    printf("������%d�Ӫ������Ȭ��G%d\n",j,e);
    }
    printf("�̦���XL�������G");
    ListTraverse(L); 

    j=5;
    ListDelete(&L,j,&e); /* ������5�Ӹ�� */
    printf("������%d�Ӫ������Ȭ��G%d\n",j,e);

    printf("�̦���XL�������G");
    ListTraverse(L); 

    i=ClearList(&L);
    printf("\n�M�zL��GListLength(L)=%d\n",ListLength(L));
    CreateListHead(&L,20);
    printf("����إ�L������(�Y���k)�G");
    ListTraverse(L); 
    
    i=ClearList(&L);
    printf("\n����L��GListLength(L)=%d\n",ListLength(L));
    CreateListTail(&L,20);
    printf("����إ�L������(�����k)�G");
    ListTraverse(L); 


    return 0;
}

