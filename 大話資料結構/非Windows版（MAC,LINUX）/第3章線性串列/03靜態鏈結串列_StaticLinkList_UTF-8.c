#include "string.h"
#include "ctype.h"      

#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 1000 /* �x�s�Ŷ��_�l���t�q */

typedef int Status;           /* Status�O��ƪ����A,��ȬO��Ƶ��G���A�{���X�A�pOK�� */
typedef char ElemType;        /* ElemType���A�ھڹ�ڱ��p�өw�A�o�̰��]��char */


Status visit(ElemType c)
{
    printf("%c ",c);
    return OK;
}

/* �u�ʦ�C���R�A�쵲��C�x�s���c */
typedef struct 
{
    ElemType data;
    int cur;  /* ���(Cursor) �A��0�ɪ�ܵL���V */
} Component,StaticLinkList[MAXSIZE];


/* �N�@���}�Cspace���U���q�즨�@�ӳƥ��쵲��C�Aspace[0].cur���Y���СA"0"��ܪū��� */
Status InitList(StaticLinkList space) 
{
	int i;
	for (i=0; i<MAXSIZE-1; i++)  
		space[i].cur = i+1;
	space[MAXSIZE-1].cur = 0; /* �ثe�R�A�쵲��C���šA�̫�@�Ӥ�����cur��0 */
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

/*  �bL����i�Ӥ������e���J�s����Ƥ���e   */
Status ListInsert(StaticLinkList L, int i, ElemType e)   
{  
    int j, k, l;   
    k = MAXSIZE - 1;   /* �`�Nk�����O�̫�@�Ӥ��������� */
    if (i < 1 || i > ListLength(L) + 1)   
        return ERROR;   
    j = Malloc_SSL(L);   /* ��o���m���q������ */
    if (j)   
    {   
		L[j].data = e;   /* �N��Ƶ����ȵ������q��data */
		for(l = 1; l <= i - 1; l++)   /* ����i�Ӥ������e����m */
		   k = L[k].cur;           
		L[j].cur = L[k].cur;    /* ���i�Ӥ������e��cur�����ȵ��s������cur */
		L[k].cur = j;           /* ��s���������޵����ȵ���i�Ӥ������e������ur */
		return OK;   
    }   
    return ERROR;   
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

Status ListTraverse(StaticLinkList L)
{
    int j=0;
    int i=L[MAXSIZE-1].cur;
    while(i)
    {
            visit(L[i].data);
            i=L[i].cur;
            j++;
    }
    return j;
    printf("\n");
    return OK;
}


int main()
{
    StaticLinkList L;
    Status i;
    i=InitList(L);
    printf("�_�l��L��GL.length=%d\n",ListLength(L));

    i=ListInsert(L,1,'F');
    i=ListInsert(L,1,'E');
    i=ListInsert(L,1,'D');
    i=ListInsert(L,1,'B');
    i=ListInsert(L,1,'A');

    printf("\n�bL�����Y�̦����JFEDBA��G\nL.data=");
    ListTraverse(L); 

    i=ListInsert(L,3,'C');
    printf("\n�bL����B���P��D���������J��C����G\nL.data=");
    ListTraverse(L); 

    i=ListDelete(L,1);
    printf("\n�bL��������A����G\nL.data=");
    ListTraverse(L); 

    printf("\n");

    return 0;
}

