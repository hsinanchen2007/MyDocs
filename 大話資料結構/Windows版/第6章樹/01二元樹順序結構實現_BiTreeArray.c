#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* ��������æ�� */
#define MAX_TREE_SIZE 100 /* �E���������� */

typedef int Status;		/* Status������ ��,���������������á���OK�R*/
typedef int TElemType;  /* ���������㡼���g�������� */
typedef TElemType SqBiTree[MAX_TREE_SIZE]; /* 0���w��������*/

typedef struct
{
	int level,order; /* �������������������l��) */
}Position;

TElemType Nil=0; /*  ��������0����*/

Status visit(TElemType c)
{
	printf("%d ",c);
	return OK;
}

/* �e���E��T����T�����ޡ������桼�Z����& */
Status InitBiTree(SqBiTree T)
{
	int i;
	for(i=0;i<MAX_TREE_SIZE;i++)
		T[i]=Nil; /* ��ᶋ�*/
	return OK;
}

/* �����������E����������(��������), �e���������E��T */
Status CreateBiTree(SqBiTree T)
{ 
	int i=0;
 	printf("����������������(����)�����⡼����999���硼����d:\n",MAX_TREE_SIZE);
	while(i<10)
	{
		T[i]=i+1;
		
		if(i!=0&&T[(i+1)/2-1]==Nil&&T[i]!=Nil) /* ����(�����Q�������������O/
		{
			printf("���������ס����sd\n",T[i]);
			exit(ERROR);
		}
		i++;
	}
	while(i<MAX_TREE_SIZE)
	{
		T[i]=Nil; /* �������@�����С� */
		i++;
	}

	return OK;
}

#define ClearBiTree InitBiTree /* �������������������������� */

/* ������ �E��T����*/
/* ���\� ��T�����ġ�,���_��RUE,�䡼LSE */
Status BiTreeEmpty(SqBiTree T)
{ 
	if(T[0]==Nil) /* ��������������*/
		return TRUE;
	else
		return FALSE;
}

/* ������ �E��T�������������_�����J */
int BiTreeDepth(SqBiTree T)
{ 
   int i,j=-1;
   for(i=MAX_TREE_SIZE-1;i>=0;i--) /* ���k�������� */
     if(T[i]!=Nil)
       break;
   i++; 
   do
     j++;
   while(i>=powl(2,j));/* ������������/
   return j;
}

/* ������ �E��T����*/
/* ���\�  �k������e�_�������OK;�䡼��RROR,e�Q����/
Status Root(SqBiTree T,TElemType *e)
{ 
	if(BiTreeEmpty(T)) /* T��*/
		return ERROR;
	else
	{	
		*e=T[0];
		return OK;
	}
}

/* ������ �E��T����e��T��������(����) */
/* ���\� �_���ڣf��e(���������С��ʳ�/
TElemType Value(SqBiTree T,Position e)
{ 
	 return T[(int)powl(2,e.level-1)+e.order-2];
}

/* ������ �E��T����e��T��������(����) */
/* ���\� ��ڣf��e(���������С������klue */
Status Assign(SqBiTree T,Position e,TElemType value)
{ 
	int i=(int)powl(2,e.level-1)+e.order-2; /* �������������򡼡���*/
	if(value!=Nil&&T[(i+1)/2-1]==Nil) /* �Aݾ�������ۡ�������*/
		return ERROR;
	else if(value==Nil&&(T[i*2+1]!=Nil||T[i*2+2]!=Nil)) /*  �}�������ۡ�����������*/
		return ERROR;
	T[i]=value;
	return OK;
}

/* ������ �E��T����e��T�������� */
/* ���\� ��e��T�ס��֤С��_��������,�䡼������*/
TElemType Parent(SqBiTree T,TElemType e)
{ 
	int i;
	if(T[0]==Nil) /* ����/
		return Nil;
	for(i=1;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e) /* ���� */
			return T[(i+1)/2-1];
	return Nil; /* u���� */
}


/* ������ �E��T����e��T�������� */
/* ���\� �_������������������,���_������*/
TElemType LeftChild(SqBiTree T,TElemType e)
{ 
	int i;
	if(T[0]==Nil) /* ����/
		return Nil;
	for(i=0;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e) /* ���� */
			return T[i*2+1];
	return Nil; /* u���� */
}

/* ������ �E��T����e��T�������� */
/* ���\� �_������������������,���_������*/
TElemType RightChild(SqBiTree T,TElemType e)
{ 
	int i;
	if(T[0]==Nil) /* ����/
		return Nil;
	for(i=0;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e) /* ���� */
			return T[i*2+2];
	return Nil; /* u���� */
}

/* ������ �E��T����e��T�������� */
/* ���\� �_�������g�We��T�������������d���_������*/
TElemType LeftSibling(SqBiTree T,TElemType e)
{ 
	int i;
	if(T[0]==Nil) /* ����/
		return Nil;
	for(i=1;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e&&i%2==0) /* ���ۡ�����������(�������� */
			return T[i-1];
	return Nil; /* u���� */
}

/* ������ �E��T����e��T�������� */
/* ���\� �_�����������We��T�������������������_������*/
TElemType RightSibling(SqBiTree T,TElemType e)
{ 
	int i;
	if(T[0]==Nil) /* ����/
		return Nil;
	for(i=1;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e&&i%2) /* ���ۡ�����������(�������� */
			return T[i+1];
	return Nil; /* u���� */
}

/* PreOrderTraverse()�qa*/
void PreTraverse(SqBiTree T,int e)
{ 
	visit(T[e]);
	if(T[2*e+1]!=Nil) /* ����������*/
		PreTraverse(T,2*e+1);
	if(T[2*e+2]!=Nil) /* ����������*/
		PreTraverse(T,2*e+2);
}

/* ������ �E������*/
/* ���\� �r��������/
Status PreOrderTraverse(SqBiTree T)
{ 
	if(!BiTreeEmpty(T)) /* ������*/
	 PreTraverse(T,0);
	printf("\n");
	return OK;
}

/* InOrderTraverse()�qa*/
void InTraverse(SqBiTree T,int e)
{ 
	if(T[2*e+1]!=Nil) /* ����������*/
		InTraverse(T,2*e+1);
	visit(T[e]);
	if(T[2*e+2]!=Nil) /* ����������*/
		InTraverse(T,2*e+2);
}

/* ������ �E������*/
/* ���\� ����������/
Status InOrderTraverse(SqBiTree T)
{ 
	if(!BiTreeEmpty(T)) /* ������*/
		InTraverse(T,0);
	printf("\n");
	return OK;
}

/* PostOrderTraverse()�qa*/
void PostTraverse(SqBiTree T,int e)
{ 
	if(T[2*e+1]!=Nil) /* ����������*/
		PostTraverse(T,2*e+1);
	if(T[2*e+2]!=Nil) /* ����������*/
		PostTraverse(T,2*e+2);
	visit(T[e]);
}

/* ������ �E��T����*/
/* ���\� ����:T��*/
Status PostOrderTraverse(SqBiTree T)
{ 
	if(!BiTreeEmpty(T)) /* ������*/
		PostTraverse(T,0);
	printf("\n");
	return OK;
}

/* ����:�E�� */
void LevelOrderTraverse(SqBiTree T)
{ 
	int i=MAX_TREE_SIZE-1,j;
	while(T[i]==Nil)
		i--; /* ���k�����桼�������� */
	for(j=0;j<=i;j++)  /* �����P��������������/
		if(T[j]!=Nil)
			visit(T[j]); /* ������������ */
	printf("\n");
}

/* ���������������E�� */
void Print(SqBiTree T)
{ 
	int j,k;
	Position p;
	TElemType e;
	for(j=1;j<=BiTreeDepth(T);j++)
	{
		printf("�`d�� ",j);
		for(k=1;k<=powl(2,j-1);k++)
		{
			p.level=j;
			p.order=k;
			e=Value(T,p);
			if(e!=Nil)
				printf("%d:%d ",k,e);
		}
		printf("\n");
	}
}


int main()
{
	Status i;
	Position p;
	TElemType e;
	SqBiTree T;
	InitBiTree(T);
	CreateBiTree(T);
	printf("��������,���@��%d(1:�� 0:�� �����J=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T,&e);
	if(i)
		printf("�E�����\��d\n",e);
	else
		printf("���롼��n");
	printf("����:�E��:\n");
	LevelOrderTraverse(T);
	printf("�����������ln");
	PreOrderTraverse(T);
	printf("�����������ln");
	InOrderTraverse(T);
	printf("����:�E��:\n");
	PostOrderTraverse(T);
	printf("���O���x��3��������);
	p.level=3;
	p.order=2;
	e=Value(T,p);
	printf("��������������%d����������:50 ",e);
	e=50;
	Assign(T,p,e);
	printf("�����������ln");
	PreOrderTraverse(T);
	printf("�������%d,������������",e,Parent(T,e));
	printf("%d,%d,������������",LeftChild(T,e),RightChild(T,e));
	printf("%d,%d\n",LeftSibling(T,e),RightSibling(T,e));
	ClearBiTree(T);
	printf("�����ġ������@��%d(1:�� 0:�� �����J=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T,&e);
	if(i)
		printf("�E�����\��d\n",e);
	else
		printf("���롼��n");
	
	return 0;
}

