#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* ーーー釦脱ー */

#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12 /* ー俾Pーーーー�_ー */
#define NULLKEY -32768 

typedef int Status;	/* Statusーーー ー,ーーーーーーー驚ーーOK�R*/ 

typedef struct
{
   int *elem; /* ー��ーーーーー�i脱ーー */
   int count; /*  �Zー��ー�Vー/
}HashTable;

int m=0; /* ーPーーーーー彼/

/* ーーーPー*/
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

/* ーPーー/
int Hash(int key)
{
	return key % m; /* ーーー�Y*/
}

/* ーーーー昔Pー*/
void InsertHash(HashTable *H,int key)
{
	int addr = Hash(key); /* ーーP紘吮/
	while (H->elem[addr] != NULLKEY) /* ー�vー�襦次次�/
	{
		addr = (addr+1) % m; /* ーー雜棄ーーーー */
	}
	H->elem[addr] = key; /* ー訣ーーーーーーー*/
}

/* ーPー啄遥ー */
Status SearchHash(HashTable H,int key,int *addr)
{
	*addr = Hash(key);  /* ーーP紘吮/
	while(H.elem[*addr] != key) /* ー�vー�襦次次�/
	{
		*addr = (*addr+1) % m; /* ーー雜棄ーーーー */
		if (H.elem[*addr] == NULLKEY || *addr == Hash(key)) /* ー饗ーーー�b*/
			return UNSUCCESS;	/* ーー〈遥ーーー */
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
		printf("ーー%d 骭ーーーd \n",key,p);
	else
		printf("ーー%d ーーー",key);

	for(i=0;i<m;i++)
	{
		key=arr[i];
		SearchHash(H,key,&p);
		printf("ーー%d 骭ーーーd \n",key,p);
	}

	return 0;
}
