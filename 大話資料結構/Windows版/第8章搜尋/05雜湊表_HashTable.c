#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* ¡¼¡¼¡¼ËÕÃ¦¡¼ */

#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12 /* ¡¼ÐìP¡¼¡¼¡¼¡¼Ã_¡¼ */
#define NULLKEY -32768 

typedef int Status;	/* Status¡¼¡¼¡¼ ¡¼,¡¼¡¼¡¼¡¼¡¼¡¼¡¼¶Ã¡¼¡¼OK§R*/ 

typedef struct
{
   int *elem; /* ¡¼”÷¡¼¡¼¡¼¡¼¡¼ˆiÃ¦¡¼¡¼ */
   int count; /*  ÌZ¡¼”÷¡¼¶V¡¼/
}HashTable;

int m=0; /* ¡¼P¡¼¡¼¡¼¡¼¡¼Èà/

/* ¡¼¡¼¡¼P¡¼*/
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

/* ¡¼P¡¼¡¼/
int Hash(int key)
{
	return key % m; /* ¡¼¡¼¡¼¸Y*/
}

/* ¡¼¡¼¡¼¡¼ÀÎP¡¼*/
void InsertHash(HashTable *H,int key)
{
	int addr = Hash(key); /* ¡¼¡¼P¹ÉÒä/
	while (H->elem[addr] != NULLKEY) /* ¡¼øv¡¼‹ë¡¼¡¼¡¼/
	{
		addr = (addr+1) % m; /* ¡¼¡¼ð¸´þ¡¼¡¼¡¼¡¼ */
	}
	H->elem[addr] = key; /* ¡¼·í¡¼¡¼¡¼¡¼¡¼¡¼¡¼*/
}

/* ¡¼P¡¼ÂïÍÚ¡¼ */
Status SearchHash(HashTable H,int key,int *addr)
{
	*addr = Hash(key);  /* ¡¼¡¼P¹ÉÒä/
	while(H.elem[*addr] != key) /* ¡¼øv¡¼‹ë¡¼¡¼¡¼/
	{
		*addr = (*addr+1) % m; /* ¡¼¡¼ð¸´þ¡¼¡¼¡¼¡¼ */
		if (H.elem[*addr] == NULLKEY || *addr == Hash(key)) /* ¡¼¶Â¡¼¡¼¡¼Ãb*/
			return UNSUCCESS;	/* ¡¼¡¼¡ÒÍÚ¡¼¡¼¡¼ */
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
		printf("¡¼¡¼%d ñì¡¼¡¼¡¼d \n",key,p);
	else
		printf("¡¼¡¼%d ¡¼¡¼¡¼",key);

	for(i=0;i<m;i++)
	{
		key=arr[i];
		SearchHash(H,key,&p);
		printf("¡¼¡¼%d ñì¡¼¡¼¡¼d \n",key,p);
	}

	return 0;
}
