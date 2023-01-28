#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 40 /* 儲存空間起始分配量 */

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

/* 由串S複製得串T */
Status StrCopy(String T,String S)
{ 
	int i;
	for(i=0;i<=S[0];i++)
		T[i]=S[i];
	return OK;
}

/* 若S為空字串,則傳回TRUE,否則傳回FALSE */
Status StrEmpty(String S)
{ 
	if(S[0]==0)
		return TRUE;
	else
		return FALSE;
}

/*  起始條件: 串S和T存在 */
/*  動作結果: 若S>T,則傳回值>0;若S=T,則傳回值=0;若S<T,則傳回值<0 */
int StrCompare(String S,String T)
{ 
	int i;
	for(i=1;i<=S[0]&&i<=T[0];++i)
		if(S[i]!=T[i])
			return S[i]-T[i];
	return S[0]-T[0];
}

/* 傳回串的元素個數 */
int StrLength(String S)
{ 
	return S[0];
}

/* 起始條件:串S存在。動作結果:將S清為空字串 */
Status ClearString(String S)
{ 
	S[0]=0;/*  令串長為零 */
	return OK;
}

/* 用T傳回S1和S2聯接而成的新串。若未裁斷，則傳回TRUE，否則FALSE */
Status Concat(String T,String S1,String S2)
{
	int i;
	if(S1[0]+S2[0]<=MAXSIZE)
	{ /*  未裁斷 */
		for(i=1;i<=S1[0];i++)
			T[i]=S1[i];
		for(i=1;i<=S2[0];i++)
			T[S1[0]+i]=S2[i];
		T[0]=S1[0]+S2[0];
		return TRUE;
	}
	else
	{ /*  裁斷S2 */
		for(i=1;i<=S1[0];i++)
			T[i]=S1[i];
		for(i=1;i<=MAXSIZE-S1[0];i++)
			T[S1[0]+i]=S2[i];
		T[0]=MAXSIZE;
		return FALSE;
	}
}

/* 用Sub傳回串S的第pos個字元起長度為len的子字串。 */
Status SubString(String Sub,String S,int pos,int len)
{
	int i;
	if(pos<1||pos>S[0]||len<0||len>S[0]-pos+1)
		return ERROR;
	for(i=1;i<=len;i++)
		Sub[i]=S[pos+i-1];
	Sub[0]=len;
	return OK;
}

/* 傳回子字串T在主串S中第pos個字元之後的位置。若不存在,則函數傳回值為0。 */
/* 其中,T非空,1□pos□StrLength(S)。 */
int Index(String S, String T, int pos) 
{
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
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}


/*  T為非空字串。若主串S中第pos個字元之後存在與T相等的子字串， */
/*  則傳回第一個這樣的子字串在S中的位置，否則傳回0 */
int Index2(String S, String T, int pos) 
{
	int n,m,i;
	String sub;
	if (pos > 0) 
	{
		n = StrLength(S);	/* 得到主串S的長度 */
		m = StrLength(T);	/* 得到子字串T的長度 */
		i = pos;
		while (i <= n-m+1) 
		{
			SubString (sub, S, i, m);	/* 取主串中第i個位置長度與T相等的子字串給sub */
			if (StrCompare(sub,T) != 0)    /* 若果兩串不相等 */
				++i;
			else 				/* 若果兩串相等 */
				return i;		/* 則傳回i值 */
		}
	}
	return 0;	/* 若無子字串與T相等，傳回0 */
}


/*  起始條件: 串S和T存在,1□pos□StrLength(S)+1 */
/*  動作結果: 在串S的第pos個字元之前插入串T。完全插入傳回TRUE,部分插入傳回FALSE */
Status StrInsert(String S,int pos,String T)
{ 
	int i;
	if(pos<1||pos>S[0]+1)
		return ERROR;
	if(S[0]+T[0]<=MAXSIZE)
	{ /*  完全插入 */
		for(i=S[0];i>=pos;i--)
			S[i+T[0]]=S[i];
		for(i=pos;i<pos+T[0];i++)
			S[i]=T[i-pos+1];
		S[0]=S[0]+T[0];
		return TRUE;
	}
	else
	{ /*  部分插入 */
		for(i=MAXSIZE;i<=pos;i--)
			S[i]=S[i-T[0]];
		for(i=pos;i<pos+T[0];i++)
			S[i]=T[i-pos+1];
		S[0]=MAXSIZE;
		return FALSE;
	}
}

/*  起始條件: 串S存在,1□pos□StrLength(S)-len+1 */
/*  動作結果: 從串S中移除第pos個字元起長度為len的子字串 */
Status StrDelete(String S,int pos,int len)
{ 
	int i;
	if(pos<1||pos>S[0]-len+1||len<0)
		return ERROR;
	for(i=pos+len;i<=S[0];i++)
		S[i-len]=S[i];
	S[0]-=len;
	return OK;
}

/*  起始條件: 串S,T和V存在,T是非空字串（此函數與串的儲存結構無關） */
/*  動作結果: 用V置換主串S中出現的所有與T相等的不重疊的子字串 */
Status Replace(String S,String T,String V)
{ 
	int i=1; /*  從串S的第一個字元起查詢串T */
	if(StrEmpty(T)) /*  T是空字串 */
		return ERROR;
	do
	{
		i=Index(S,T,i); /*  結果i為從上一個i之後找到的子字串T的位置 */
		if(i) /*  串S中存在串T */
		{
			StrDelete(S,i,StrLength(T)); /*  移除該串T */
			StrInsert(S,i,V); /*  在原串T的位置插入串V */
			i+=StrLength(V); /*  在插入的串V後面繼續查詢串T */
		}
	}while(i);
	return OK;
}

/*  輸出字串T */
void StrPrint(String T)
{ 
	int i;
	for(i=1;i<=T[0];i++)
		printf("%c",T[i]);
	printf("\n");
}


int main()
{
	
	int i,j;
	Status k;
	char s;
	String t,s1,s2;
	printf("請輸入串s1: ");
	
	k=StrAssign(s1,"abcd");
	if(!k)
	{
		printf("串長超過MAXSIZE(=%d)\n",MAXSIZE);
		exit(0);
	}
	printf("串長為%d 串空否？%d(1:是 0:否)\n",StrLength(s1),StrEmpty(s1));
	StrCopy(s2,s1);
	printf("覆制s1產生的串為: ");
	StrPrint(s2);
	printf("請輸入串s2: ");
	
	k=StrAssign(s2,"efghijk");
	if(!k)
	{
		printf("串長超過MAXSIZE(%d)\n",MAXSIZE);
		exit(0);
	}
	i=StrCompare(s1,s2);
	if(i<0)
		s='<';
	else if(i==0)
		s='=';
	else
		s='>';
	printf("串s1%c串s2\n",s);
	k=Concat(t,s1,s2);
	printf("串s1聯接串s2得到的串t為: ");
	StrPrint(t);
	if(k==FALSE)
		printf("串t有裁斷\n");
	ClearString(s1);
	printf("清為空字串後,串s1為: ");
	StrPrint(s1);
	printf("串長為%d 串空否？%d(1:是 0:否)\n",StrLength(s1),StrEmpty(s1));
	printf("求串t的子字串,請輸入子字串的起始位置,子字串長度: ");

	i=2;
	j=3;
	printf("%d,%d \n",i,j);

	k=SubString(s2,t,i,j);
	if(k)
	{
		printf("子字串s2為: ");
		StrPrint(s2);
	}
	printf("從串t的第pos個字元起,移除len個字元，請輸入pos,len: ");
	
	i=4;
	j=2;
	printf("%d,%d \n",i,j);


	StrDelete(t,i,j);
	printf("移除後的串t為: ");
	StrPrint(t);
	i=StrLength(s2)/2;
	StrInsert(s2,i,t);
	printf("在串s2的第%d個字元之前插入串t後,串s2為:\n",i);
	StrPrint(s2);
	i=Index(s2,t,1);
	printf("s2的第%d個字母起和t第一次比對\n",i);
	SubString(t,s2,1,1);
	printf("串t為：");
	StrPrint(t);
	Concat(s1,t,t);
	printf("串s1為：");
	StrPrint(s1);
	Replace(s2,t,s1);
	printf("用串s1取代串s2中和串t相同的不重疊的串後,串s2為: ");
	StrPrint(s2);


	return 0;
}

