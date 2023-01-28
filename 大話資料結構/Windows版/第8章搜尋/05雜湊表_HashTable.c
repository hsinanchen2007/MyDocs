#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* ��������æ�� */

#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12 /* ����P���������_�� */
#define NULLKEY -32768 

typedef int Status;	/* Status������ ��,���������������á���OK�R*/ 

typedef struct
{
   int *elem; /* ���������������iæ���� */
   int count; /*  �Z�������V��/
}HashTable;

int m=0; /* ��P������������/

/* ������P��*/
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

/* ��P����/
int Hash(int key)
{
	return key % m; /* �������Y*/
}

/* ����������P��*/
void InsertHash(HashTable *H,int key)
{
	int addr = Hash(key); /* ����P����/
	while (H->elem[addr] != NULLKEY) /* ���v���롼����/
	{
		addr = (addr+1) % m; /* �������������� */
	}
	H->elem[addr] = key; /* ����������������*/
}

/* ��P�����ڡ� */
Status SearchHash(HashTable H,int key,int *addr)
{
	*addr = Hash(key);  /* ����P����/
	while(H.elem[*addr] != key) /* ���v���롼����/
	{
		*addr = (*addr+1) % m; /* �������������� */
		if (H.elem[*addr] == NULLKEY || *addr == Hash(key)) /* ���¡������b*/
			return UNSUCCESS;	/* �������ڡ����� */
	}
	return SUCCESS;
}

int main()
{
	int arr[HASHSIZE]={12,67,56,16,25,37,22,29,15,47,48,34};
	int i,p,key,result;
	HashTable H;

	key=39;

	InitHashTable(&H);
	for(i=0;i<m;i++)
		 InsertHash(&H,arr[i]);
	
	result=SearchHash(H,key,&p);
	if (result)
		printf("����%d �졼����d \n",key,p);
	else
		printf("����%d ������",key);

	for(i=0;i<m;i++)
	{
		key=arr[i];
		SearchHash(H,key,&p);
		printf("����%d �졼����d \n",key,p);
	}

	return 0;
}
