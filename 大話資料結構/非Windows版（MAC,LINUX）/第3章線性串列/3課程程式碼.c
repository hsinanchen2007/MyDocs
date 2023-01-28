Status ListInsert(StaticLinkList L, int i, ElemType e)   
{  
	int j, k, l;   
	k = MAXSIZE - 1;   					/* �`�Nk�����O�̫�@�Ӥ��������� */
	if (i < 1 || i > ListLength(L) + 1)   
		return ERROR;   
	j = Malloc_SSL(L);   				/* ��o���m���q������ */
	if (j)   
	{   
		L[j].data = e;   				/* �N��Ƶ����ȵ������q��data */
		for(l = 1; l <= i - 1; l++)   	/* ����i�Ӥ������e����m */
		   k = L[k].cur;           
		L[j].cur = L[k].cur;    		/* ���i�Ӥ������e��cur�����ȵ��s������cur */
		L[k].cur = j;           		/* ��s���������޵����ȵ���i�Ӥ������e������ur */
		return OK;   
	}   
	return ERROR;   
}

/*�N�Ҧ����u�W�ʪ�Lb�������bLa������Ƥ������J��La��*/
void unionL(SqList *La,SqList Lb)
{
	int La_len,Lb_len,i;
	ElemType e;                        /*�ŧi�PLa�MLb�ۦP����Ƥ���e*/
	La_len=ListLength(*La);            /*�D�u�ʦ�C������ */
	Lb_len=ListLength(Lb);
	for (i=1;i<=Lb_len;i++)
	{
		GetElem(Lb,i,&e);              /*��Lb����i�Ӹ�Ƥ����ᵹe*/
		if (!LocateElem(*La,e))        /*La�����s�b�Me�ۦP��Ƥ���*/
			ListInsert(La,++La_len,e); /*���J*/
	}
}



#define MAXSIZE 20          /* �x�s�Ŷ��_�l���t�q */
typedef int ElemType;       /* ElemType���A�ھڹ�ڱ��p�өw�A�o�̬�int */
typedef struct
{
	ElemType data[MAXSIZE]; /* �}�C�A�x�s��Ƥ��� */
	int length;             /* �u�ʦ�C�ثe���� */
}SqList;


#define OK 1
#define ERROR 0
/* Status�O��ƪ����A,��ȬO��Ƶ��G���A�{���X�A�pOK�� */
typedef int Status;         

/* �_�l����G���ǽu�ʦ�CL�w�s�b�A1��i��ListLength(L) */
/* �ʧ@���G�G��e�Ǧ^L����i�Ӹ�Ƥ������ȡA�`�Ni�O����m�A��1�Ӧ�m���}�C�O�q0�}�l */
Status GetElem(SqList L,int i,ElemType *e)
{
	if(L.length==0 || i<1 || i>L.length)
		return ERROR;
	*e=L.data[i-1];

	return OK;
}

/* �_�l����G���ǽu�ʦ�CL�w�s�b,1��i��ListLength(L)�A */
/* �ʧ@���G�G�bL����i�Ӧ�m���e���J�s����Ƥ���e�AL�����ץ[1 */
Status ListInsert(SqList *L,int i,ElemType e)
{ 
	int k;
	if (L->length==MAXSIZE)  			/* ���ǽu�ʦ�C�w�g�� */
		return ERROR;
	if (i<1 || i>L->length+1)			/* ��i��Ĥ@��m�p�άO��̫�@��m��@��m�٭n�j�� */
		return ERROR;				

	if (i<=L->length)        			/* �Y���J��Ʀ�m���b��� */
	{
		for(k=L->length-1;k>=i-1;k--)  	/* �N�n���J��m�᪺�����V�Ჾ�@�� */
			L->data[k+1]=L->data[k];
	}
	L->data[i-1]=e;          			/* �N�s�������J */
	L->length++;

	return OK;
}


/* �_�l����G���ǽu�ʦ�CL�w�s�b�A1��i��ListLength(L) */
/* �ʧ@���G�G����L����i�Ӹ�Ƥ����A�å�e�Ǧ^��ȡAL�����״�1 */
Status ListDelete(SqList *L,int i,ElemType *e) 
{ 
	int k;
	if (L->length==0)               /* �u�ʦ�C���� */
		return ERROR;
	if (i<1 || i>L->length)         /* ������m�����T */
		return ERROR;
	*e=L->data[i-1];
	if (i<L->length)                /* �Y�G�������O�̫��m */
	{
		for(k=i;k<L->length;k++)	/* �N������m���~�����e�� */
			L->data[k-1]=L->data[k];
	}
	L->length--;
	return OK;
}

/* �u�ʦ�C�����쵲��C�x�s���c */
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;
typedef struct Node *LinkList; /* �w�qLinkList */


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


s->next = p->next;    /* �Np�����~�`�I�����ȵ�s�����~  */
p->next = s;          /* �Ns�����ȵ�p�����~ */


/* �_�l����G�즡�u�ʦ�CL�w�s�b,1��i��ListLength(L)�A */
/* �ʧ@���G�G�bL����i�Ӧ�m���e���J�s����Ƥ���e�AL�����ץ[1 */
Status ListInsert(LinkList *L,int i,ElemType e)
{ 
	int j;
	LinkList p,s;
	p = *L;   
	j = 1;
	while (p && j < i)     				/* �M���i�Ӹ`�I */
	{
		p = p->next;
		++j;
	} 
	if (!p || j > i) 
		return ERROR;   				/* ��i�Ӥ������s�b */

	s = (LinkList)malloc(sizeof(Node)); /* ���ͷs�`�I(C�y�t�Э���) */
	s->data = e;  
	s->next = p->next;    				/* �Np�����~�`�I�����ȵ�s�����~ */
	p->next = s;          				/* �Ns�����ȵ�p�����~ */
	return OK;
}

q = p->next;
p->next = q->next;			/* �Nq�����~�����ȵ�p�����~ */


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

/*  �H������n�Ӥ������ȡA�إ߱a���Y�`�I������u�ʦ�CL�]�Y���k�^ */
void CreateListHead(LinkList *L, int n) 
{
	LinkList p;
	int i;
	srand(time(0));                         /* �_�l���H���ƺؤl */
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;                      /* ���إߤ@�ӱa�Y�`�I�����쵲��C */
	for (i=0; i<n; i++) 
	{
		p = (LinkList)malloc(sizeof(Node)); /* ���ͷs�`�I */
		p->data = rand()%100+1;             /* �H������100�H�����Ʀr */
		p->next = (*L)->next;    
		(*L)->next = p;						/* ���J����Y */
	}
}

/*  �H������n�Ӥ������ȡA�إ߱a���Y�`�I������u�ʦ�CL�]�����k�^ */
void CreateListTail(LinkList *L, int n) 
{
	LinkList p,r;
	int i;
	srand(time(0));                     	/* �_�l���H���ƺؤl */
	*L = (LinkList)malloc(sizeof(Node)); 	/* L����ӽu�ʦ�C */
	r=*L;                                	/* r�����V�������`�I */
	for (i=0; i<n; i++) 
	{
		p = (Node *)malloc(sizeof(Node)); 	/* ���ͷs�`�I */
		p->data = rand()%100+1;           	/* �H������100�H�����Ʀr */
		r->next=p;                        	/* �N����׺ݸ`�I�����Ы��V�s�`�I */
		r = p;                            	/* �N�ثe���s�`�I�w�q������׺ݸ`�I */
	}
	r->next = NULL;                       	/* ��ܥثe�쵲��C���� */
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


#define MAXSIZE 1000 	/* �x�s�Ŷ��_�l���t�q */

/* �u�ʦ�C���R�A�쵲��C�x�s���c */
typedef struct 
{
	ElemType data;
	int cur;  			/* ���(Cursor) �A��0�ɪ�ܵL���V */
} Component,StaticLinkList[MAXSIZE];



/* �N�@���}�Cspace���U���q�즨�@�ӳƥ��쵲��C�Aspace[0].cur���Y���СA"0"��ܪū��� */
Status InitList(StaticLinkList space) 
{
	int i;
	for (i=0; i<MAXSIZE-1; i++)  
		space[i].cur = i+1;
	space[MAXSIZE-1].cur = 0; 	/* �ثe�R�A�쵲��C���šA�̫�@�Ӥ�����cur��0 */
	return OK;
}

/* �Y�ƥΪŶ��쵲��C�D�šA�h�Ǧ^���t���`�I���ޡA�_�h�Ǧ^0 */
int Malloc_SSL(StaticLinkList space) 
{ 
	int i = space[0].cur;           		/* �ثe�}�C�Ĥ@�Ӥ�����cur�s���� */
											/* �N�O�n�Ǧ^���Ĥ@�ӳƥζ��m������ */
	if (space[0]. cur)         
		space[0]. cur = space[i].cur;       /* �ѩ�n���X�@�Ӥ��q�ӨϥΤF�A */
											/* �ҥH�ڭ̴N�o�⥦���U�@�� */
											/* ���q�ΨӰ��ƥ� */
	return i;
}

/*  �����bL����i�Ӹ�Ƥ���   */
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

/*  �N���ެ�k�����m�`�I�^����ƥ��쵲��C */
void Free_SSL(StaticLinkList space, int k) 
{  
	space[k].cur = space[0].cur;    /* ��Ĥ@�Ӥ�����cur�Ƚᵹ�n���������qcur */
	space[0].cur = k;               /* ��n���������q���޵����ȵ��Ĥ@�Ӥ�����cur */
}

/* �_�l����G�R�A�쵲��CL�w�s�b�C�ʧ@���G�G�Ǧ^L����Ƥ����Ӽ� */
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

p=rearA->next;   			    /* �x�sA���Y�`�I�A�Y�� */
rearA->next=rearB->next->next;	/* �N���O���VB���Ĥ@�Ӹ`�I�]���O�Y�`�I�^*/
                 				/* �����ȵ�reaA->next�A�Y�� */
q=rearB->next;
rearB->next=p;				   	/* �N��A���Y�`�I�����ȵ�rearB->next�A�Y�� */
free�]q�^;					   	/* ����q */



/*�u�ʦ�C�����V�쵲��C�x�s���c*/
typedef struct DulNode
{
		ElemType data;
		struct DuLNode *prior;    	/*�����e�X����*/
		struct DuLNode *next;		/*���~����*/
} DulNode, *DuLinkList;


p->next->prior = p = p->prior->next

s - >prior = p;   			/*��p�����ȵ�s���e�X�A�p�Ϥ���*/
s -> next = p -> next;		/*��p->next�����ȵ�s�����~�A�p�Ϥ���*/
p -> next -> prior = s;		/*��s�����ȵ�p->next���e�X�A�p�Ϥ���*/
p -> next = s;				/*��s�����ȵ�p�����~�A�p�Ϥ���*/


p->prior->next=p->next;   	/*��p->next�����ȵ�p->prior�����~�A�p�Ϥ���*/
p->next->prior=p->prior;	/*��p->prior�����ȵ�p->next���e�X�A�p�Ϥ���*/
free�]p�^;					/*����`�I*/














































































































































































































































































































































































































































































































































































































































































































































































