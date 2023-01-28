
#include "stdio.h"    

#include "stdlib.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20          /* ��������æ�� */
typedef int ElemType;       /* ElemType ���ۡ��������͡������mint */
typedef struct
{
    ElemType data[MAXSIZE]; /* ������ϫ������ */
    int length;             /* ������������*/
}SqList;

typedef int Status;         /* Status������ ��,���������������á���OK�R*/


Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}

/* ��������������*/
Status InitList(SqList *L) 
{ 
    L->length=0;
    return OK;
}

/* ��������������������������������L���������_��RUE�����_��ALSE */
Status ListEmpty(SqList L)
{ 
	if(L.length==0)
		return TRUE;
	else
		return FALSE;
}

/* ������������������������������������������/
Status ClearList(SqList *L)
{ 
    L->length=0;
    return OK;
}

/* �������������������������������_�����������V��/
int ListLength(SqList L)
{
	return L.length;
}

/* ����������������������������istLength(L) */
/* ���\����e�_�������V���������Q��i�����f�������`���񡼡�������/
Status GetElem(SqList L,int i,ElemType *e)
{
    if(L.length==0 || i<1 || i>L.length)
            return ERROR;
    *e=L.data[i-1];

    return OK;
}

/* ����������������������*/
/* ���\�����������c�����F��������������*/
/* �������񡼡��������������0 */
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


/* ����������������������1����istLength(L)��*/
/* ���\����L�����`�����������񡼡���e���_���� */
Status ListInsert(SqList *L,int i,ElemType e)
{ 
	int k;
	if (L->length==MAXSIZE)  /* �������������� */
		return ERROR;
	if (i<1 || i>L->length+1)/* �¡��������������������f�������������� */
		return ERROR;

	if (i<=L->length)        /* �������񡼡����� */
	{
		for(k=L->length-1;k>=i-1;k--)  /* �������f����������������������f */
			L->data[k+1]=L->data[k];
	}
	L->data[i-1]=e;          /* ����������/
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
        for(k=i;k<L->length;k++)/* ���\�f������������ */
			L->data[k-1]=L->data[k];
    }
    L->length--;
    return OK;
}

/* ����������������������*/
/* ���\����������`����������*/
Status ListTraverse(SqList L)
{
	int i;
    for(i=0;i<L.length;i++)
            visit(L.data[i]);
    printf("\n");
    return OK;
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

int main()
{
        
    SqList L;
	SqList Lb;
    
    ElemType e;
    Status i;
    int j,k;
    i=InitList(&L);
    printf("����L����length=%d\n",L.length);
    for(j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
    printf("��L﷡������O1������data=");
    ListTraverse(L); 

    printf("L.length=%d \n",L.length);
    i=ListEmpty(L);
    printf("L���G����%d(1:�� 0:��\n",i);

    i=ClearList(&L);
    printf("���ԡ���length=%d\n",L.length);
    i=ListEmpty(L);
    printf("L���G����%d(1:�� 0:��\n",i);

    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);
    printf("��L﷡������O1��0����data=");
    ListTraverse(L); 

    printf("L.length=%d \n",L.length);

    ListInsert(&L,1,0);
    printf("��L﷡�������L.data=");
    ListTraverse(L); 
    printf("L.length=%d \n",L.length);

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

	//�e���c��0�V��Lb
	i=InitList(&Lb);
    for(j=6;j<=15;j++)
            i=ListInsert(&Lb,1,j);

	unionL(&L,Lb);

	printf("����������Lb�ﾩ����);
    ListTraverse(L); 

    return 0;
}

