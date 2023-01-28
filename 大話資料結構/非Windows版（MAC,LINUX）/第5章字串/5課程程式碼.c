/*  T為非空字串。若主串S中第pos個字元之後存在與T相等的子字串， */
/*  則傳回第一個這樣的子字串在S中的位置，否則傳回0 */
int Index(String S, String T, int pos) 
{
	int n,m,i;
	String sub;
	if (pos > 0) 
	{
		n = StrLength(S);				/* 得到主串S的長度 */
		m = StrLength(T);				/* 得到子字串T的長度 */
		i = pos;
		while (i <= n-m+1) 
		{
			SubString(sub, S, i, m);	/* 取主串中第i個位置長度與T相等的子字串給sub */
			if (StrCompare(sub,T) != 0) /* 若果兩串不相等 */
				++i;
			else 						/* 若果兩串相等 */
				return i;				/* 則傳回i值 */
		}
	}
	return 0;							/* 若無子字串與T相等，傳回0 */
}

/* 傳回子字串T在主串S中第pos個字元之後的位置。若不存在,則函數傳回值為0。 */
/* 其中,T非空,1□pos□StrLength(S)。 */
int Index(String S, String T, int pos) 
{
	int i = pos;					/* i用於主串S中目前位置索引值，從pos位置開始比對 */
	int j = 1;						/* j用於子字串T中目前位置索引值 */
	while (i <= S[0] && j <= T[0]) 	/* 若i小於S的長度並且j小於T的長度時，循環繼續 */
	{
		if (S[i] == T[j]) 			/* 兩字母相等則繼續 */
      	{
			++i;
         	++j; 
      	} 
      	else 						/* 指標後退重新開始比對 */
      	{  
         	i = i-j+2;				/* i退回到上次比對首位的下一位 */
         	j = 1; 					/* j退回到子字串T的首位 */
      	}      
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
	int i = pos;					/* i用於主串S中目前位置索引值，從pos位置開始比對 */
	int j = 1;						/* j用於子字串T中目前位置索引值 */
	int next[255];					/* 定義一next陣列 */
	get_next(T, next);				/* 對串T作分析，得到next陣列 */
	while (i <= S[0] && j <= T[0]) 	/* 若i小於S的長度並且j小於T的長度時，循環繼續 */
	{
		if (j==0 || S[i] == T[j]) 	/* 兩字母相等則繼續，與樸素算法增加了j=0判斷 */
      	{
         	++i;
         	++j; 
      	} 
      	else						/* 指標後退重新開始比對 */
      	{ 						
      	 	j = next[j];			/* j退回合適的位置，i值不變 */
      	}
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
  	while (i<T[0])  				/* 此處T[0]表示串T的長度 */
 	{
    	if(k==0 || T[i]== T[k]) 	/* T[i]表示副檔名的單一字元，T[k]表示前綴的單一字元 */
		{
      		++i;  
			++k;  
			if (T[i]!=T[k])      	/* 若目前字元與前綴字元不同 */
				nextval[i] = k;		/* 則目前的k為nextval在i位置的值 */
      		else 
				nextval[i] = nextval[k];	/* 若果與前綴字元相同，則將前綴字元的 */
											/* nextval值給予值給nextval在i位置的值 */
    	} 
		else 
			k= nextval[k];			/* 若字元不相同，則k值回溯 */
  	}
}

