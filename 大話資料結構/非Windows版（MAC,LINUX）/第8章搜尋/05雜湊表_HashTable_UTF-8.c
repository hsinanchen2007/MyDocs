#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* �x�s�Ŷ��_�l���t�q */

#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12 /* �w�q���������}�C������ */
#define NULLKEY -32768 

typedef int Status;	/* Status�O��ƪ����A,��ȬO��Ƶ��G���A�{���X�A�pOK�� */ 

typedef struct
{
   int *elem; /* ��Ƥ����x�s��}�A�ʺA���t�}�C */
   int count; /*  �ثe��Ƥ����Ӽ� */
}HashTable;

int m=0; /* ��������A�����ܼ� */

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
	int addr = Hash(key); /* �D�����} */
	while (H->elem[addr] != NULLKEY) /* �Y�G�����šA�h�R�� */
	{
		addr = (addr+1) % m; /* �}��w�}�k���u�ʱ��� */
	}
	H->elem[addr] = key; /* ���즳�Ŧ�ᴡ�J����r */
}

/* �����d������r */
Status SearchHash(HashTable H,int key,int *addr)
{
	*addr = Hash(key);  /* �D�����} */
	while(H.elem[*addr] != key) /* �Y�G�����šA�h�R�� */
	{
		*addr = (*addr+1) % m; /* �}��w�}�k���u�ʱ��� */
		if (H.elem[*addr] == NULLKEY || *addr == Hash(key)) /* �Y�G�`���^����I */
			return UNSUCCESS;	/* �h��������r���s�b */
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
		printf("�d�� %d ����}���G%d \n",key,p);
	else
		printf("�d�� %d ���ѡC\n",key);

	for(i=0;i<m;i++)
	{
		key=arr[i];
		SearchHash(H,key,&p);
		printf("�d�� %d ����}���G%d \n",key,p);
	}

	return 0;
}
