Status ListInsert(StaticLinkList L, int i, ElemType e)   
{  
	int j, k, l;   
	k = MAXSIZE - 1;   					/* ����k���r�������������T�ӡ�/
	if (i < 1 || i > ListLength(L) + 1)   
		return ERROR;   
	j = Malloc_SSL(L);   				/* ��y������������*/
	if (j)   
	{   
		L[j].data = e;   				/* �������`������data */
		for(l = 1; l <= i - 1; l++)   	/* �������d���������� */
		   k = L[k].cur;           
		L[j].cur = L[k].cur;    		/* �����d�������sur���`�������sur */
		L[k].cur = j;           		/* �������T�ӡ����桼�d������������r */
		return OK;   
	}   
	return ERROR;   
}

/*���R����������������La���񡼡�������La��*/
void unionL(SqList *La,SqList Lb)
{
	int La_len,Lb_len,i;
	ElemType e;                        /*���ҡ�La��b�����񡼡���e*/
	La_len=ListLength(*La);            /*������������ */
	Lb_len=ListLength(Lb);
	for (i=1;i<=Lb_len;i++)
	{
		GetElem(Lb,i,&e);              /*��Lb�����V����������/
		if (!LocateElem(*La,e))        /*La������������������*/
			ListInsert(La,++La_len,e); /*����
	}
}



#define MAXSIZE 20          /* ��������æ�� */
typedef int ElemType;       /* ElemType ���ۡ��������͡�����int */
typedef struct
{
	ElemType data[MAXSIZE]; /* ������ϫ������ */
	int length;             /* ������������*/
}SqList;


#define OK 1
#define ERROR 0
/* Status������ ��,���������������á���OK�R*/
typedef int Status;         

/* ����������������������������istLength(L) */
/* ���\����e�_�������V�������ʤС���i�����f�������`���񡼡�������/
Status GetElem(SqList L,int i,ElemType *e)
{
	if(L.length==0 || i<1 || i>L.length)
		return ERROR;
	*e=L.data[i-1];

	return OK;
}

/* ����������������������1����istLength(L)��*/
/* ���\����L�����`�����������񡼡���e���_���� */
Status ListInsert(SqList *L,int i,ElemType e)
{ 
	int k;
	if (L->length==MAXSIZE)  			/* �������������� */
		return ERROR;
	if (i<1 || i>L->length+1)			/* �¡��������������������f�������������� */
		return ERROR;				

	if (i<=L->length)        			/* �������񡼡����� */
	{
		for(k=L->length-1;k>=i-1;k--)  	/* �������f���������������� */
			L->data[k+1]=L->data[k];
	}
	L->data[i-1]=e;          			/* ����������/
	L->length++;

	return OK;
}


/* ����������������������������istLength(L) */
/* ���\�������졼�V����������e�_�������_���� */
Status ListDelete(SqList *L,int i,ElemType *e) 
{ 
	int k;
	if (L->length==0)               /* �������� */
		return ERROR;
	if (i<1 || i>L->length)         /* ���������� */
		return ERROR;
	*e=L->data[i-1];
	if (i<L->length)                /* ���d�\�������f�� */
	{
		for(k=i;k<L->length;k++)	/* ���\�f������������ */
			L->data[k-1]=L->data[k];
	}
	L->length--;
	return OK;
}

/* ������������ϫ�����O/
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;
typedef struct Node *LinkList; /* ���JnkList */


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


s->next = p->next;    /* �����������������  */
p->next = s;          /* �����`p���� */


/* ����������������������1����istLength(L)��*/
/* ���\����L�����`�����������񡼡���e���_���� */
Status ListInsert(LinkList *L,int i,ElemType e)
{ 
	int j;
	LinkList p,s;
	p = *L;   
	j = 1;
	while (p && j < i)     				/* ���������� */
	{
		p = p->next;
		++j;
	} 
	if (!p || j > i) 
		return ERROR;   				/* ���d������ */

	s = (LinkList)malloc(sizeof(Node)); /* ��������(C����������) */
	s->data = e;  
	s->next = p->next;    				/* ����������������� */
	p->next = s;          				/* �����`p���� */
	return OK;
}

q = p->next;
p->next = q->next;			/* ���������`p���� */


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

/*  ������n�d���ʤС������\�����������������q���O/
void CreateListHead(LinkList *L, int n) 
{
	LinkList p;
	int i;
	srand(time(0));                         /* ������������ */
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;                      /* �r�����w�������ݡ� */
	for (i=0; i<n; i++) 
	{
		p = (LinkList)malloc(sizeof(Node)); /* �������� */
		p->data = rand()%100+1;             /* ������100������ */
		p->next = (*L)->next;    
		(*L)->next = p;						/* ��������/
	}
}

/*  ������n�d���ʤС������\�����������������q���O/
void CreateListTail(LinkList *L, int n) 
{
	LinkList p,r;
	int i;
	srand(time(0));                     	/* ������������ */
	*L = (LinkList)malloc(sizeof(Node)); 	/* L�����a������/
	r=*L;                                	/* r�������]������ */
	for (i=0; i<n; i++) 
	{
		p = (Node *)malloc(sizeof(Node)); 	/* �������� */
		p->data = rand()%100+1;           	/* ������100������ */
		r->next=p;                        	/* ������������������������/
		r = p;                            	/* ������������ᶡ��y���� */
	}
	r->next = NULL;                       	/* ����t���� */
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


#define MAXSIZE 1000 	/* ��������æ�� */

/* ����������t��ϫ�����O/
typedef struct 
{
	ElemType data;
	int cur;  			/* ����Cursor) ���������Q���� */
} Component,StaticLinkList[MAXSIZE];



/* ��������space���ߡ��䡼����A����pace[0].cur����������0"���⡼�� */
Status InitList(StaticLinkList space) 
{
	int i;
	for (i=0; i<MAXSIZE-1; i++)  
		space[i].cur = i+1;
	space[MAXSIZE-1].cur = 0; 	/* �������������������d���sur��0 */
	return OK;
}

/* ����y�������������_�����������������_�� */
int Malloc_SSL(StaticLinkList space) 
{ 
	int i = space[0].cur;           		/* �Z�����򡼡����sur������/
											/* �y��������������y�������ӡ�/
	if (space[0]. cur)         
		space[0]. cur = space[i].cur;       /* ��������������������K��*/
											/* �����EC��e����������*/
											/* ����4����a*/
	return i;
}

/*  �����������V������   */
Status ListDelete(StaticLinkList L, int i)   
{ 
	int j, k;   
	if (i < 1 || i > ListLength(L))   
		return ERROR;   
	k = MAXSIZE - 1;   
	for (j = 1; j <= i - 1; j++)   
		k = L[k].cur;   
	j = L[k].cur;   
	L[k].cur = L[j].cur;   
	Free_SSL(L, j);   
	return OK;   
} 

/*  ���ӡ�k�ࡼ������������t��*/
void Free_SSL(StaticLinkList space, int k) 
{  
	space[k].cur = space[0].cur;    /* �����������sur����㺡��������r */
	space[0].cur = k;               /* �����������b�����桼�������sur */
}

/* ����������t�����������������_�����������V��/
int ListLength(StaticLinkList L)
{
	int j=0;
	int i=L[MAXSIZE-1].cur;
	while(i)
	{
		i=L[i].cur;
		j++;
	}
	return j;
}

p=rearA->next;   			    /* ����������������*/
rearA->next=rearB->next->next;	/* ���S����B�����������������\�B��
                 				/* ���`reaA->next���� */
q=rearB->next;
rearB->next=p;				   	/* ���������������PearB->next���� */
free����					   	/* ���� */



/*����������t��ϫ����
typedef struct DulNode
{
		ElemType data;
		struct DuLNode *prior;    	/*����������*/
		struct DuLNode *next;		/*����������*/
} DulNode, *DuLinkList;


p->next->prior = p = p->prior->next

s - >prior = p;   			/*�����`s�롼���n����/
s -> next = p -> next;		/*��->next���`s�������n����/
p -> next -> prior = s;		/*�����`p->next�롼���n����/
p -> next = s;				/*�����`p�������n����/


p->prior->next=p->next;   	/*��->next���`p->prior�������n����/
p->next->prior=p->prior;	/*��->prior���`p->next�롼���n����/
free����					/*������*/














































































































































































































































































































































































































































































































































































































































































































































































