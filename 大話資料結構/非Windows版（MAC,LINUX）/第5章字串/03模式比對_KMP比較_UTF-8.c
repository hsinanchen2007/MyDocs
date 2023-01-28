#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* 儲存空間起始分配量 */

typedef int Status;		/* Status是函數的型態,其值是函數結果狀態程式碼，如OK等 */
typedef int ElemType;	/* ElemType型態根據實際情況而定，這裡假設為int */

typedef char String[MAXSIZE+1]; /*  0號單元存放串的長度 */

/* 產生一個其值等於chars的串T */
Status StrAssign(String T,char *chars)
{ 
	int i;
	if(strlen(chars)>MAXSIZE)
		return ERROR;
	else
	{
		T[0]=strlen(chars);
		for(i=1;i<=T[0];i++)
			T[i]=*(chars+i-1);
		return OK;
	}
}

Status ClearString(String S)
{ 
	S[0]=0;/*  令串長為零 */
	return OK;
}

/*  輸出字串T。 */
void StrPrint(String T)
{ 
	int i;
	for(i=1;i<=T[0];i++)
		printf("%c",T[i]);
	printf("\n");
}

/*  輸出Next陣列值。 */
void NextPrint(int next[],int length)
{ 
	int i;
	for(i=1;i<=length;i++)
		printf("%d",next[i]);
	printf("\n");
}

/* 傳回串的元素個數 */
int StrLength(String S)
{ 
	return S[0];
}

/* 樸素的模式比對法 */
int Index(String S, String T, int pos) 
{
	int n = 0;
	int i = pos;	/* i用於主串S中目前位置索引值，若pos不為1，則從pos位置開始比對 */
	int j = 1;				/* j用於子字串T中目前位置索引值 */
	while (i <= S[0] && j <= T[0]) /* 若i小於S的長度並且j小於T的長度時，循環繼續 */
	{
		if (S[i] == T[j]) 	/* 兩字母相等則繼續 */
      	{
			++i;
         	++j; 
      	} 
      	else 				/* 指標後退重新開始比對 */
      	{  
         	i = i-j+2;		/* i退回到上次比對首位的下一位 */
         	j = 1; 			/* j退回到子字串T的首位 */
      	} 
      	
		printf("n=%d i=%d j=%d\n",++n,i,j); 
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}

/* 透過計算傳回子字串T的next陣列。 */
void get_next(String T, int *next) 
{
	int i,k;
  	i=1;
  	k=0;
  	next[1]=0;
  	while (i<T[0])  /* 此處T[0]表示串T的長度 */
 	{
    	if(k==0 || T[i]== T[k]) 
		{
      		++i;  
			++k;  
			next[i] = k;
    	} 
		else 
			k= next[k];	/* 若字元不相同，則k值回溯 */
  	}
}

/* 傳回子字串T在主串S中第pos個字元之後的位置。若不存在，則函數傳回值為0。 */
/*  T非空，1□pos□StrLength(S)。 */
int Index_KMP(String S, String T, int pos) 
{
	int n = 0;
	int i = pos;		/* i用於主串S中目前位置索引值，若pos不為1，則從pos位置開始比對 */
	int j = 1;			/* j用於子字串T中目前位置索引值 */
	int next[255];		/* 定義一next陣列 */
	get_next(T, next);	/* 對串T作分析，得到next陣列 */
	while (i <= S[0] && j <= T[0]) /* 若i小於S的長度並且j小於T的長度時，循環繼續 */
	{
		if (j==0 || S[i] == T[j]) 	/* 兩字母相等則繼續，與樸素算法增加了j=0判斷 */
      	{
         	++i;
         	++j; 
      	} 
      	else 			/* 指標後退重新開始比對 */
      	 	j = next[j];/* j退回合適的位置，i值不變 */
      
	  	printf("n=%d i=%d j=%d\n",++n,i,j);  
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}

/* 求模式串T的next函數修正值並存入陣列nextval */
void get_nextval(String T, int *nextval) 
{
  	int i,k;
  	i=1;
  	k=0;
  	nextval[1]=0;
  	while (i<T[0])  /* 此處T[0]表示串T的長度 */
 	{
    	if(k==0 || T[i]== T[k]) 	/* T[i]表示副檔名的單一字元，T[k]表示前綴的單一字元 */
		{
      		++i;  
			++k;  
			if (T[i]!=T[k])      /* 若目前字元與前綴字元不同 */
				nextval[i] = k;	/* 則目前的j為nextval在i位置的值 */
      		else 
				nextval[i] = nextval[k];	/* 若果與前綴字元相同，則將前綴字元的 */
											/* nextval值給予值給nextval在i位置的值 */
    	} 
		else 
			k= nextval[k];			/* 若字元不相同，則k值回溯 */
		
  	}
}

int Index_KMP1(String S, String T, int pos) 
{
	int n=0;
	int i = pos;		/* i用於主串S中目前位置索引值，若pos不為1，則從pos位置開始比對 */
	int j = 1;			/* j用於子字串T中目前位置索引值 */
	int next[255];		/* 定義一next陣列 */
	get_nextval(T, next);	/* 對串T作分析，得到next陣列 */
	while (i <= S[0] && j <= T[0]) /* 若i小於S的長度並且j小於T的長度時，循環繼續 */
	{
		if (j==0 || S[i] == T[j]) 	/* 兩字母相等則繼續，與樸素算法增加了j=0判斷 */
      	{
         	++i;
         	++j; 
      	} 
      	else 			/* 指標後退重新開始比對 */
      	 	j = next[j];/* j退回合適的位置，i值不變 */
      	
      	printf("n=%d i=%d j=%d\n",++n,i,j);
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}

int main()
{
	int i,*p;
	String s1,s2;
	
	StrAssign(s1,"000000000200000000020000000002000000000200000000020000000001");
	printf("主串為: ");
	StrPrint(s1);
	StrAssign(s2,"0000000001");
	printf("子字串為: ");
	StrPrint(s2);
	printf("\n");
	
	printf("\n");
	printf("主串和子字串在第%d個字元處第一次比對（樸素模式比對算法）\n",Index(s1,s2,1));
	printf("主串和子字串在第%d個字元處第一次比對（KMP算法） \n",Index_KMP(s1,s2,1));
	printf("主串和子字串在第%d個字元處第一次比對（KMP改良算法） \n",Index_KMP1(s1,s2,1));

	return 0;
}
