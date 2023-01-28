#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* �x�s�Ŷ��_�l���t�q */
#define MAX_TREE_SIZE 100 /* �G���𪺳̤j�`�I�� */

typedef int Status;		/* Status�O��ƪ����A,��ȬO��Ƶ��G���A�{���X�A�pOK�� */
typedef int TElemType;  /* ��`�I����ƫ��A�A�ثe�ȩw����� */
typedef TElemType SqBiTree[MAX_TREE_SIZE]; /* 0���椸�x�s�ڸ`�I  */

typedef struct
{
	int level,order; /* �`�I���h,���h�Ǹ�(�����G����p��) */
}Position;

TElemType Nil=0; /*  �]��ƥH0���� */

Status visit(TElemType c)
{
	printf("%d ",c);
	return OK;
}

/* �غc�ŤG����T�C�]��T�O�T�w�}�C�A���|���ܡA�G���ݭn& */
Status InitBiTree(SqBiTree T)
{
	int i;
	for(i=0;i<MAX_TREE_SIZE;i++)
		T[i]=Nil; /* ��Ȭ��� */
	return OK;
}

/* ���h�Ǧ��ǿ�J�G���𤤸`�I����(�r�����ξ��), �غc�s���x�s���G����T */
Status CreateBiTree(SqBiTree T)
{ 
	int i=0;
 	printf("�Ы��h�ǿ�J�`�I����(���)�A0��ܪŸ`�I�A��999�����C�`�I�ơ�%d:\n",MAX_TREE_SIZE);
	while(i<10)
	{
		T[i]=i+1;
		
		if(i!=0&&T[(i+1)/2-1]==Nil&&T[i]!=Nil) /* ���`�I(����)�L���˥B���O�� */
		{
			printf("�X�{�L���˪��D�ڸ`�I%d\n",T[i]);
			exit(ERROR);
		}
		i++;
	}
	while(i<MAX_TREE_SIZE)
	{
		T[i]=Nil; /* �N�ŵ����ȵ�T���᭱���`�I */
		i++;
	}

	return OK;
}

#define ClearBiTree InitBiTree /* �b�s���x�s���c���A���Ƨ����@�� */

/* �_�l����: �G����T�s�b */
/* �ʧ@���G: �YT���ŤG����,�h�Ǧ^TRUE,�_�hFALSE */
Status BiTreeEmpty(SqBiTree T)
{ 
	if(T[0]==Nil) /* �ڸ`�I����,�h��� */
		return TRUE;
	else
		return FALSE;
}

/* �_�l����: �G����T�s�b�C�ʧ@���G: �Ǧ^T���`�� */
int BiTreeDepth(SqBiTree T)
{ 
   int i,j=-1;
   for(i=MAX_TREE_SIZE-1;i>=0;i--) /* ���̫�@�Ӹ`�I */
     if(T[i]!=Nil)
       break;
   i++; 
   do
     j++;
   while(i>=powl(2,j));/* �p��2��j�����C */
   return j;
}

/* �_�l����: �G����T�s�b */
/* �ʧ@���G:  ��T����,��e�Ǧ^T����,�Ǧ^OK;�_�h�Ǧ^ERROR,e�L�w�q */
Status Root(SqBiTree T,TElemType *e)
{ 
	if(BiTreeEmpty(T)) /* T�� */
		return ERROR;
	else
	{	
		*e=T[0];
		return OK;
	}
}

/* �_�l����: �G����T�s�b,e�OT���Y�Ӹ`�I(����m) */
/* �ʧ@���G: �Ǧ^�B���me(�h,���h�Ǹ�)���`�I���� */
TElemType Value(SqBiTree T,Position e)
{ 
	 return T[(int)powl(2,e.level-1)+e.order-2];
}

/* �_�l����: �G����T�s�b,e�OT���Y�Ӹ`�I(����m) */
/* �ʧ@���G: ���B���me(�h,���h�Ǹ�)���`�I��s��value */
Status Assign(SqBiTree T,Position e,TElemType value)
{ 
	int i=(int)powl(2,e.level-1)+e.order-2; /* �N�h�B���h�Ǹ��ର�x�}���Ǹ� */
	if(value!=Nil&&T[(i+1)/2-1]==Nil) /* �����l��D�ŭȦ����ˬ��� */
		return ERROR;
	else if(value==Nil&&(T[i*2+1]!=Nil||T[i*2+2]!=Nil)) /*  �����˽�ŭȦ������l�]���š^ */
		return ERROR;
	T[i]=value;
	return OK;
}

/* �_�l����: �G����T�s�b,e�OT���Y�Ӹ`�I */
/* �ʧ@���G: �Ye�OT���D�ڸ`�I,�h�Ǧ^��������,�_�h�Ǧ^���š� */
TElemType Parent(SqBiTree T,TElemType e)
{ 
	int i;
	if(T[0]==Nil) /* �ž� */
		return Nil;
	for(i=1;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e) /* ���e */
			return T[(i+1)/2-1];
	return Nil; /* �S���e */
}


/* �_�l����: �G����T�s�b,e�OT���Y�Ӹ`�I */
/* �ʧ@���G: �Ǧ^e�����Ĥl�C�Ye�L���Ĥl,�h�Ǧ^���š� */
TElemType LeftChild(SqBiTree T,TElemType e)
{ 
	int i;
	if(T[0]==Nil) /* �ž� */
		return Nil;
	for(i=0;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e) /* ���e */
			return T[i*2+1];
	return Nil; /* �S���e */
}

/* �_�l����: �G����T�s�b,e�OT���Y�Ӹ`�I */
/* �ʧ@���G: �Ǧ^e���k�Ĥl�C�Ye�L�k�Ĥl,�h�Ǧ^���š� */
TElemType RightChild(SqBiTree T,TElemType e)
{ 
	int i;
	if(T[0]==Nil) /* �ž� */
		return Nil;
	for(i=0;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e) /* ���e */
			return T[i*2+2];
	return Nil; /* �S���e */
}

/* �_�l����: �G����T�s�b,e�OT���Y�Ӹ`�I */
/* �ʧ@���G: �Ǧ^e�����S�̡C�Ye�OT�����Ĥl�εL���S��,�h�Ǧ^���š� */
TElemType LeftSibling(SqBiTree T,TElemType e)
{ 
	int i;
	if(T[0]==Nil) /* �ž� */
		return Nil;
	for(i=1;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e&&i%2==0) /* ���e�B��Ǹ�������(�O�k�Ĥl) */
			return T[i-1];
	return Nil; /* �S���e */
}

/* �_�l����: �G����T�s�b,e�OT���Y�Ӹ`�I */
/* �ʧ@���G: �Ǧ^e���k�S�̡C�Ye�OT���k�Ĥl�εL�k�S��,�h�Ǧ^���š� */
TElemType RightSibling(SqBiTree T,TElemType e)
{ 
	int i;
	if(T[0]==Nil) /* �ž� */
		return Nil;
	for(i=1;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e&&i%2) /* ���e�B��Ǹ����_��(�O���Ĥl) */
			return T[i+1];
	return Nil; /* �S���e */
}

/* PreOrderTraverse()�I�s */
void PreTraverse(SqBiTree T,int e)
{ 
	visit(T[e]);
	if(T[2*e+1]!=Nil) /* ���l�𤣪� */
		PreTraverse(T,2*e+1);
	if(T[2*e+2]!=Nil) /* �k�l�𤣪� */
		PreTraverse(T,2*e+2);
}

/* �_�l����: �G����s�b */
/* �ʧ@���G: �����ˬdT�C */
Status PreOrderTraverse(SqBiTree T)
{ 
	if(!BiTreeEmpty(T)) /* �𤣪� */
	 PreTraverse(T,0);
	printf("\n");
	return OK;
}

/* InOrderTraverse()�I�s */
void InTraverse(SqBiTree T,int e)
{ 
	if(T[2*e+1]!=Nil) /* ���l�𤣪� */
		InTraverse(T,2*e+1);
	visit(T[e]);
	if(T[2*e+2]!=Nil) /* �k�l�𤣪� */
		InTraverse(T,2*e+2);
}

/* �_�l����: �G����s�b */
/* �ʧ@���G: �����ˬdT�C */
Status InOrderTraverse(SqBiTree T)
{ 
	if(!BiTreeEmpty(T)) /* �𤣪� */
		InTraverse(T,0);
	printf("\n");
	return OK;
}

/* PostOrderTraverse()�I�s */
void PostTraverse(SqBiTree T,int e)
{ 
	if(T[2*e+1]!=Nil) /* ���l�𤣪� */
		PostTraverse(T,2*e+1);
	if(T[2*e+2]!=Nil) /* �k�l�𤣪� */
		PostTraverse(T,2*e+2);
	visit(T[e]);
}

/* �_�l����: �G����T�s�b */
/* �ʧ@���G: ����ˬdT�C */
Status PostOrderTraverse(SqBiTree T)
{ 
	if(!BiTreeEmpty(T)) /* �𤣪� */
		PostTraverse(T,0);
	printf("\n");
	return OK;
}

/* �h���ˬd�G���� */
void LevelOrderTraverse(SqBiTree T)
{ 
	int i=MAX_TREE_SIZE-1,j;
	while(T[i]==Nil)
		i--; /* ���̫�@�ӫD�Ÿ`�I���Ǹ� */
	for(j=0;j<=i;j++)  /* �q�ڸ`�I�_,���h���ˬd�G���� */
		if(T[j]!=Nil)
			visit(T[j]); /* �u�ˬd�D�Ū��`�I */
	printf("\n");
}

/* �v�h�B�����h�Ǹ���X�G���� */
void Print(SqBiTree T)
{ 
	int j,k;
	Position p;
	TElemType e;
	for(j=1;j<=BiTreeDepth(T);j++)
	{
		printf("��%d�h: ",j);
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
	printf("�إߤG�����,��ŧ_�H%d(1:�O 0:�_) �𪺲`��=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T,&e);
	if(i)
		printf("�G���𪺮ڬ��G%d\n",e);
	else
		printf("��šA�L��\n");
	printf("�h���ˬd�G����:\n");
	LevelOrderTraverse(T);
	printf("�e���ˬd�G����:\n");
	PreOrderTraverse(T);
	printf("�����ˬd�G����:\n");
	InOrderTraverse(T);
	printf("����ˬd�G����:\n");
	PostOrderTraverse(T);
	printf("�ק�`�I���h��3���h�Ǹ�2�C");
	p.level=3;
	p.order=2;
	e=Value(T,p);
	printf("�ݭק�`�I����Ȭ�%d�п�J�s��:50 ",e);
	e=50;
	Assign(T,p,e);
	printf("�e���ˬd�G����:\n");
	PreOrderTraverse(T);
	printf("�`�I%d�����ˬ�%d,���k�Ĥl���O��",e,Parent(T,e));
	printf("%d,%d,���k�S�̤��O��",LeftChild(T,e),RightChild(T,e));
	printf("%d,%d\n",LeftSibling(T,e),RightSibling(T,e));
	ClearBiTree(T);
	printf("�M���G�����,��ŧ_�H%d(1:�O 0:�_) �𪺲`��=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T,&e);
	if(i)
		printf("�G���𪺮ڬ��G%d\n",e);
	else
		printf("��šA�L��\n");
	
	return 0;
}

