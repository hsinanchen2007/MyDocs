
#include "stdio.h"    

#include "stdlib.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20          /* �x�s�Ŷ��_�l���t�q */
typedef int ElemType;       /* ElemType���A�ھڹ�ڱ��p�өw�A�o�̰��]��int */
typedef struct
{
    ElemType data[MAXSIZE]; /* �}�C�A�x�s��Ƥ��� */
    int length;             /* �u�ʦ�C�ثe���� */
}SqList;

typedef int Status;         /* Status�O��ƪ����A,��ȬO��Ƶ��G���A�{���X�A�pOK�� */


Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}

/* �_�l�ƶ��ǽu�ʦ�C */
Status InitList(SqList *L) 
{ 
    L->length=0;
    return OK;
}

/* �_�l����G���ǽu�ʦ�CL�w�s�b�C�ʧ@���G�G�YL���Ū�A�h�Ǧ^TRUE�A�_�h�Ǧ^FALSE */
Status ListEmpty(SqList L)
{ 
	if(L.length==0)
		return TRUE;
	else
		return FALSE;
}

/* �_�l����G���ǽu�ʦ�CL�w�s�b�C�ʧ@���G�G�NL���]���Ū� */
Status ClearList(SqList *L)
{ 
    L->length=0;
    return OK;
}

/* �_�l����G���ǽu�ʦ�CL�w�s�b�C�ʧ@���G�G�Ǧ^L����Ƥ����Ӽ� */
int ListLength(SqList L)
{
	return L.length;
}

/* �_�l����G���ǽu�ʦ�CL�w�s�b�A1��i��ListLength(L) */
/* �ʧ@���G�G��e�Ǧ^L����i�Ӹ�Ƥ�������,�`�Ni�O����m�A��1�Ӧ�m���}�C�O�q0�}�l */
Status GetElem(SqList L,int i,ElemType *e)
{
    if(L.length==0 || i<1 || i>L.length)
            return ERROR;
    *e=L.data[i-1];

    return OK;
}

/* �_�l����G���ǽu�ʦ�CL�w�s�b */
/* �ʧ@���G�G�Ǧ^L����1�ӻPe�������t����Ƥ�������ǡC */
/* �Y�o�˪���Ƥ������s�b�A�h�Ǧ^�Ȭ�0 */
int LocateElem(SqList L,ElemType e)
{
    int i;
    if (L.length==0)
            return 0;
    for(i=0;i<L.length;i++)
    {
            if (L.data[i]==e)
                    break;
    }
    if(i>=L.length)
            return 0;

    return i+1;
}


/* �_�l����G���ǽu�ʦ�CL�w�s�b,1��i��ListLength(L)�A */
/* �ʧ@���G�G�bL����i�Ӧ�m���e���J�s����Ƥ���e�AL�����ץ[1 */
Status ListInsert(SqList *L,int i,ElemType e)
{ 
	int k;
	if (L->length==MAXSIZE)  /* ���ǽu�ʦ�C�w�g�� */
		return ERROR;
	if (i<1 || i>L->length+1)/* ��i��Ĥ@��m�p�άO��̫�@��m��@��m�٭n�j�� */
		return ERROR;

	if (i<=L->length)        /* �Y���J��Ʀ�m���b��� */
	{
		for(k=L->length-1;k>=i-1;k--)  /* �N�n���J��m���᪺��Ƥ����V��h���@�� */
			L->data[k+1]=L->data[k];
	}
	L->data[i-1]=e;          /* �N�s�������J */
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
        for(k=i;k<L->length;k++)/* �N������m���~�����e�� */
			L->data[k-1]=L->data[k];
    }
    L->length--;
    return OK;
}

/* �_�l����G���ǽu�ʦ�CL�w�s�b */
/* �ʧ@���G�G�̦���L���C�Ӹ�Ƥ�����X */
Status ListTraverse(SqList L)
{
	int i;
    for(i=0;i<L.length;i++)
            visit(L.data[i]);
    printf("\n");
    return OK;
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

int main()
{
        
    SqList L;
	SqList Lb;
    
    ElemType e;
    Status i;
    int j,k;
    i=InitList(&L);
    printf("�_�l��L��GL.length=%d\n",L.length);
    for(j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
    printf("�bL�����Y�̦����J1��5��GL.data=");
    ListTraverse(L); 

    printf("L.length=%d \n",L.length);
    i=ListEmpty(L);
    printf("L�O�_�šGi=%d(1:�O 0:�_)\n",i);

    i=ClearList(&L);
    printf("�M�zL��GL.length=%d\n",L.length);
    i=ListEmpty(L);
    printf("L�O�_�šGi=%d(1:�O 0:�_)\n",i);

    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);
    printf("�bL������̦����J1��10��GL.data=");
    ListTraverse(L); 

    printf("L.length=%d \n",L.length);

    ListInsert(&L,1,0);
    printf("�bL�����Y���J0��GL.data=");
    ListTraverse(L); 
    printf("L.length=%d \n",L.length);

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

	//�غc�@�Ӧ�10�Ӽƪ�Lb
	i=InitList(&Lb);
    for(j=6;j<=15;j++)
            i=ListInsert(&Lb,1,j);

	unionL(&L,Lb);

	printf("�̦���X�X�äFLb��L�������G");
    ListTraverse(L); 

    return 0;
}

