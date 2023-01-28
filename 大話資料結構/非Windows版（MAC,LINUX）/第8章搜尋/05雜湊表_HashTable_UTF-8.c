#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* 儲存空間起始分配量 */

#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12 /* 定義雜湊表長為陣列的長度 */
#define NULLKEY -32768 

typedef int Status;	/* Status是函數的型態,其值是函數結果狀態程式碼，如OK等 */ 

typedef struct
{
   int *elem; /* 資料元素儲存基址，動態分配陣列 */
   int count; /*  目前資料元素個數 */
}HashTable;

int m=0; /* 雜湊表表長，全局變數 */

/* 起始化雜湊表 */
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

/* 雜湊函數 */
int Hash(int key)
{
	return key % m; /* 除留余數法 */
}

/* 插入關鍵字進雜湊表 */
void InsertHash(HashTable *H,int key)
{
	int addr = Hash(key); /* 求雜湊位址 */
	while (H->elem[addr] != NULLKEY) /* 若果不為空，則沖突 */
	{
		addr = (addr+1) % m; /* 開放定址法的線性探測 */
	}
	H->elem[addr] = key; /* 直到有空位後插入關鍵字 */
}

/* 雜湊表查詢關鍵字 */
Status SearchHash(HashTable H,int key,int *addr)
{
	*addr = Hash(key);  /* 求雜湊位址 */
	while(H.elem[*addr] != key) /* 若果不為空，則沖突 */
	{
		*addr = (*addr+1) % m; /* 開放定址法的線性探測 */
		if (H.elem[*addr] == NULLKEY || *addr == Hash(key)) /* 若果循環回到原點 */
			return UNSUCCESS;	/* 則說明關鍵字不存在 */
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
		printf("查詢 %d 的位址為：%d \n",key,p);
	else
		printf("查詢 %d 失敗。\n",key);

	for(i=0;i<m;i++)
	{
		key=arr[i];
		SearchHash(H,key,&p);
		printf("查詢 %d 的位址為：%d \n",key,p);
	}

	return 0;
}
