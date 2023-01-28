Status InsertAVL(BiTree *T,int e,Status *taller)
{  
	if(!*T)						/* ���J�s�`�I�A�𡧪������A�mtaller��TRUE */ 
	{ 
		*T=(BiTree)malloc(sizeof(BiTNode));
		(*T)->data=e; 
		(*T)->lchild=(*T)->rchild=NULL; 
		(*T)->bf=EH;
		*taller=TRUE;
	}
	else
	{
		if (e==(*T)->data)		/* �𤤤w�s�b�Me���ۦP����r���`�I�h���A���J */
		{  
			*taller=FALSE; 
			return FALSE;
		}
		if (e<(*T)->data)		/* ���~��bT�����l�𤤶i��j�M */
		{  
			if(!InsertAVL(&(*T)->lchild,e,taller)) /*  �����J */ 
				return FALSE;
			if(*taller) 		/* �w���J��T�����l�𤤥B���l�𡧪����� */ 
			{
				switch((*T)->bf)/* �ˬdT�����ū� */ 
				{
					case LH: 	/* �쥻���l���k�l�𰪡A�ݭn�@�����ųB�z */ 
						LeftBalance(T);	
						*taller=FALSE; 
						break;
					case EH: 	/* �쥻���B�k�l�𵥰��A�{�]���l��W���ӨϾ�W�� */ 
						(*T)->bf=LH; 
						*taller=TRUE; 
						break;
					case RH: 	/* �쥻�k�l��񥪤l�𰪡A�{���B�k�l�𵥰� */  
						(*T)->bf=EH; 
						*taller=FALSE; 
						break;
				}
			}
		}
		else					/*  ���~��bT���k�l�𤤶i��j�M */ 
		{ 
			if(!InsertAVL(&(*T)->rchild,e,taller)) /* �����J */ 
				return FALSE;
			if(*taller) 		/* �w���J��T���k�l��B�k�l�𡧪����� */ 
			{
				switch((*T)->bf)/* �ˬdT�����ū� */ 
				{
					case LH: 	/* �쥻���l���k�l�𰪡A�{���B�k�l�𵥰� */ 
						(*T)->bf=EH; 
						*taller=FALSE;	
						break;
					case EH: 	/* �쥻���B�k�l�𵥰��A�{�]�k�l��W���ӨϾ�W�� */
						(*T)->bf=RH; 
						*taller=TRUE; 
						break;
					case RH: 	/* �쥻�k�l��񥪤l�𰪡A�ݭn�@�k���ųB�z */ 
						RightBalance(T); 
						*taller=FALSE; 
						break;
				}
			}
		}
	}
	return TRUE;
}

void LeftBalance(BiTree *T)
{ 
	BiTree L,Lr;
	L=(*T)->lchild; 					/* L���VT�����l��ڸ`�I */ 
	switch(L->bf)		/* �ˬdT�����l�𪺥��ūסA�ç@�������ųB�z */ 
	{ 
		 case LH:     	/* �s�`�I���J�bT�����Ĥl�����l��W�A�n�@��k�۳B�z */ 
			(*T)->bf=L->bf=EH;
			R_Rotate(T);
			break;
		 case RH:     	/* �s�`�I���J�bT�����Ĥl���k�l��W�A�n�@���۳B�z */ 
			Lr=L->rchild; 				/* Lr���VT�����Ĥl���k�l��� */ 
			switch(Lr->bf)				/* �ק�T�Ψ䥪�Ĥl�����Ŧ]�l */ 
			{ 							
				case LH: (*T)->bf=RH;
						 L->bf=EH;
						 break;
				case EH: (*T)->bf=L->bf=EH;
						 break;
				case RH: (*T)->bf=EH;
						 L->bf=LH;
						 break;
			}
			Lr->bf=EH;
			L_Rotate(&(*T)->lchild); 	/* ��T�����l��@���ۥ��ųB�z */ 
			R_Rotate(T); 				/* ��T�@�k�ۥ��ųB�z */ 
	}
}

Status Delete(BiTree *p)
{/* �q�G�e�ƧǾ𤤲����`�Ip�A�í����������Υk�l��C */
	BiTree q,s;
	if((*p)->rchild==NULL) /* �k�l��ūh�u�ݭ����������l��]�ݧR�`�I�O���l�]��������) */
	{
		q=*p; *p=(*p)->lchild; free(q);
	}
	else if((*p)->lchild==NULL) /* �u�ݭ��������k�l�� */
	{
		q=*p; *p=(*p)->rchild; free(q);
	}
	else 						/* ���k�l�𧡤��� */
	{
		q=*p; s=(*p)->lchild;
		while(s->rchild) 		/* �४�A�M��V�k����Y�]��ݧR�`�I���e�X�^*/
		{
			q=s; s=s->rchild;
		}
		(*p)->data=s->data; /* s���V�Q�R�`�I�����e�X(�N�Q�R�`�I�e�X���Ȩ��N�Q�R�`�I����) */
		if(q!=*p)
			q->rchild=s->lchild;/*  ����q���k�l�� */ 
		else
			q->lchild=s->lchild;/*  ����q�����l�� */
		free(s);
	}
	return TRUE;
}

Status DeleteBST(BiTree *T,int key)
{/* �Y�G�e�ƧǾ�T���s�b����r����key����Ƥ����ɡA�h�����Ӹ�Ƹ`�I */
	if(!*T) 					/* ���s�b����r����key����Ƥ��� */ 
		return FALSE;
	else
	{
		if (key==(*T)->data) 	/* �������r����key����Ƥ��� */ 
			return Delete(T);
		else if (key<(*T)->data)
			return DeleteBST(&(*T)->lchild,key);
		else
			return DeleteBST(&(*T)->rchild,key);
		 
	}
}

Status SearchBST(BiTree T, int key, BiTree f, BiTree *p) 
{ /* ���k�d�ߤG�e�ƧǾ�T���O�_�s�bkey, */ 
	if (!T)		/* �Y�d�ߤ����\�A����p���V�d�߸��|�W�s�����̫�@�Ӹ`�I�öǦ^FALSE */
	{ 
		*p = f;  
		return FALSE; 
	}
	else if (key==T->data) /* �Y�d�ߦ��\�A�h����p���V�Ӹ�Ƥ����`�I�A�öǦ^TRUE */
	{ 
		*p = T;  
		return TRUE; 
	} 
	else if (key<T->data) 
		return SearchBST(T->lchild, key, T, p);  	/* �b���l���~��d�� */
	else  
		return SearchBST(T->rchild, key, T, p);  	/* �b�k�l���~��d�� */
}

int Fibonacci_Search(int *a,int n,int key) /* �O��d�� */
{
	int low,high,mid,i,k;
	low=1;						/* �w�q�̧C���ެ��O������ */
	high=n;						/* �w�q�̰����ެ��O������ */
	k=0;
	while(n>F[k]-1)				/* �p��n���O��ƦC����m */
		k++;
	for (i=n;i<F[k]-1;i++)		/* �N�������ƭȸɥ� */
		a[i]=a[n];
	while(low<=high)
	{
		mid=low+F[k-1]-1;		/* �p��ثe���j������ */
		if (key<a[mid])			/* �Y�d�߰O���p��ثe���j�O�� */
		{
			high=mid-1;			/* �̰����޽վ����j����mid-1�B */
			k=k-1;				/* �O��ƦC���޴�@�� */
		}
		else if (key>a[mid])	/* �Y�d�߰O���j��ثe���j�O�� */
		{
			low=mid+1;			/* �̧C���޽վ����j����mid+1�B */
			k=k-2;				/* �O��ƦC���޴��� */
		}
		else
		{
			if (mid<=n)
				return mid;		/* �Y�۵��h����mid�Y���d�ߨ쪺��m */
			else 
				return n;		/* �Ymid>n�����O�ɥ��ƭȡA�Ǧ^n */
		}
	}
	return 0;
}

/* ���Ǭd�ߡAa���}�C�An���n�d�ߪ��}�C�ӼơAkey���n�d�ߪ�����r */
int Sequential_Search(int *a,int n,int key)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if (a[i]==key)
			return i;
	}
	return 0;
}

/* ����L���Ǭd�� */
int Sequential_Search2(int *a,int n,int key)
{
	int i;
	a[0]=key;			/* �]�wa[0]������r�ȡA�ڭ̺٤�������L��*/
	i=n;				/* �`���q�}�C�����}�l */
	while(a[i]!=key)
	{
		i--;
	}
	return i;			/* �Ǧ^0�h�����d�ߥ��� */
}

/* ��b�d�� */
int Binary_Search(int *a,int n,int key)
{
	int low,high,mid;
	low=1;					/* �w�q�̧C���ެ��O������ */
	high=n;					/* �w�q�̰����ެ��O������ */
	while(low<=high)
	{
		mid=(low+high)/2;	/* ��b */
		if (key<a[mid])		/* �Y�d�߭Ȥ񤤭Ȥp */
			high=mid-1;		/* �̰����޽վ�줤����ޤp�@�� */
		else if (key>a[mid])/* �Y�d�߭Ȥ񤤭Ȥj */
			low=mid+1;		/* �̧C���޽վ�줤����ޤj�@�� */
		else
			return mid;		/* �Y�۵��h����mid�Y���d�ߨ쪺��m */
	}
	return 0;
}

/* ���Ȭd�� */
int Interpolation_Search(int *a,int n,int key)
{
	int low,high,mid;
	low=1;	/* �w�q�̧C���ެ��O������ */
	high=n;	/* �w�q�̰����ެ��O������ */
	while(low<=high)
	{
		mid=low+ (high-low)*(key-a[low])/(a[high]-a[low]); /* ���� */
		if (key<a[mid])		/* �Y�d�߭Ȥ񴡭Ȥp */
			high=mid-1;		/* �̰����޽վ�촡�ȯ��ޤp�@�� */
		else if (key>a[mid])/* �Y�d�߭Ȥ񴡭Ȥj */
			low=mid+1;		/* �̧C���޽վ�촡�ȯ��ޤj�@�� */
		else
			return mid;		/* �Y�۵��h����mid�Y���d�ߨ쪺��m */
	}
	return 0;
}

/* �G���𪺤G�e�쵲��C�`�I���c�w�q */
typedef  struct BiTNode					/* �`�I���c */
{
	int data;							/* �`�I��� */
	struct BiTNode *lchild, *rchild;	/* ���k�Ĥl���� */
} BiTNode, *BiTree;


Status InsertBST(BiTree *T, int key) 
{  
	BiTree p,s;
	if (!SearchBST(*T, key, NULL, &p)) 	/* �d�ߤ����\ */
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;  
		s->lchild = s->rchild = NULL;  
		if (!p) 
			*T = s;						/*  ���Js���s���ڸ`�I */
		else if (key<p->data) 
			p->lchild = s;				/*  ���Js�����Ĥl */
		else 
			p->rchild = s;  			/*  ���Js���k�Ĥl */
		return TRUE;
	} 
	else 
		return FALSE;  					/*  �𤤤w������r�ۦP���`�I�A���A���J */
}


int i;
int a[10]={62,88,58,47,35,73,51,99,37,93};
BiTree T=NULL;
for(i=0;i<10;i++)
{
	InsertBST(&T, a[i]);
}



/* �G���𪺤G�e�쵲��C�`�I���c�w�q */
typedef  struct BiTNode					/* �`�I���c */
{
	int data;							/* �`�I��� */
	int bf; 							/*  �`�I�����Ŧ]�l */ 
	struct BiTNode *lchild, *rchild;	/* ���k�Ĥl���� */
} BiTNode, *BiTree;


/* ��Hp���ڪ��G�e�ƧǾ�@�k�۳B�z�A */
/* �B�z����p���V�s����ڸ`�I�A�Y����B�z���e�����l�𪺮ڸ`�I */
void R_Rotate(BiTree *P)
{ 
	BiTree L;
	L=(*P)->lchild; 		/*  L���VP�����l��ڸ`�I */ 
	(*P)->lchild=L->rchild; /*  L���k�l�𱾱���P�����l�� */ 
	L->rchild=(*P);
	*P=L; 					/*  P���V�s���ڸ`�I */ 
}

/* ��HP���ڪ��G�e�ƧǾ�@���۳B�z�A */
/* �B�z����P���V�s����ڸ`�I�A�Y����B�z���e���k�l�𪺮ڸ`�I0  */
void L_Rotate(BiTree *P)
{ 
	BiTree R;
	R=(*P)->rchild; 		/*  R���VP���k�l��ڸ`�I */ 
	(*P)->rchild=R->lchild; /* R�����l�𱾱���P���k�l�� */ 
	R->lchild=(*P);
	*P=R; 					/*  P���V�s���ڸ`�I */ 
}

#define LH +1 /*  ���� */ 
#define EH 0  /*  ���� */ 
#define RH -1 /*  �k�� */ 

/*  ��H����T�ҫ��`�I���ڪ��G����@�����ű���B�z */
/*  ����k�����ɡA����T���V�s���ڸ`�I */



/*  ��H����T�ҫ��`�I���ڪ��G����@�k���ű���B�z�A */ 
/*  ����k�����ɡA����T���V�s���ڸ`�I */ 
void RightBalance(BiTree *T)
{ 
	BiTree R,Rl;
	R=(*T)->rchild; 					/* R���VT���k�l��ڸ`�I */ 
	switch(R->bf)
	{ /* �ˬdT���k�l�𪺥��ūסA�ç@�������ųB�z */ 
	 case RH: /* �s�`�I���J�bT���k�Ĥl���k�l��W�A�n�@�楪�۳B�z */ 
			  (*T)->bf=R->bf=EH;
			  L_Rotate(T);
			  break;
	 case LH: /* �s�`�I���J�bT���k�Ĥl�����l��W�A�n�@���۳B�z */ 
			  Rl=R->lchild; 			/* Rl���VT���k�Ĥl�����l��� */ 
			  switch(Rl->bf)			/* �ק�T�Ψ�k�Ĥl�����Ŧ]�l */ 
			  { 						
				case RH: (*T)->bf=LH;
						 R->bf=EH;
						 break;
				case EH: (*T)->bf=R->bf=EH;
						 break;
				case LH: (*T)->bf=EH;
						 R->bf=RH;
						 break;
			  }
			  Rl->bf=EH;
			  R_Rotate(&(*T)->rchild); 	/* ��T���k�l��@�k�ۥ��ųB�z */ 
			  L_Rotate(T); 				/* ��T�@���ۥ��ųB�z */ 
	}
}



int i;
int a[10]={3,2,1,4,5,6,7,10,9,8};
BiTree T=NULL;
Status taller;
for(i=0;i<10;i++)
{
	InsertAVL(&T,a[i],&taller);
}


#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12 	/* �w�q���������}�C������ */
#define NULLKEY -32768 

typedef struct
{
   int *elem; 			/* ��Ƥ����x�s��}�A�ʺA���t�}�C */
   int count; 			/*  �ثe��Ƥ����Ӽ� */
}HashTable;

int m=0; 				/* ��������A�����ܼ� */

/* �_�l������� */
Status InitHashTable(HashTable *H)
{
	int i;
	m=HASHSIZE;
	H->count=m;
	H->elem=(int *)malloc(m*sizeof(int));
	for(i=0;i<m;i++)
		H->elem[i]=NULLKEY; 
	return OK;
}

/* ������ */
int Hash(int key)
{
	return key % m; /* ���d�E�ƪk */
}

/* ���J����r�i����� */
void InsertHash(HashTable *H,int key)
{
	int addr = Hash(key); 				/* �D�����} */
	while (H->elem[addr] != NULLKEY) 	/* �Y�G�����šA�h�R�� */
	{
		addr = (addr+1) % m; 			/* �}��w�}�k���u�ʱ��� */
	}
	H->elem[addr] = key; 				/* ���즳�Ŧ�ᴡ�J����r */
}


/* �����d������r */
Status SearchHash(HashTable H,int key,int *addr)
{
	*addr = Hash(key);  									/* �D�����} */
	while(H.elem[*addr] != key) 							/* �Y�G�����šA�h�R�� */
	{
		*addr = (*addr+1) % m; 								/* �}��w�}�k���u�ʱ��� */
		if (H.elem[*addr] == NULLKEY || *addr == Hash(key)) /* �Y�G�`���^����I */
			return UNSUCCESS;								/* �h��������r���s�b */
	}
	return SUCCESS;
}






