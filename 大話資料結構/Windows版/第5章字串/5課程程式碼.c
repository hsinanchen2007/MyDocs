/*  T¡¼ïú¡¼–Ì¡¼¡¼¡¼¡¼¿ios¡¼¡¼¡¼¡¼¡¼¡¼T¡¼ËÐ¡¼¡¼—¸ */
/*  ¡¼ß_¡¼¡¼¡¼¡¼¡¼èö¡¼‘rS¡¼¸ü¡¼¡¼¡¼ß_¡¼ */
int Index(String S, String T, int pos) 
{
	int n,m,i;
	String sub;
	if (pos > 0) 
	{
		n = StrLength(S);				/* »ø¡¼¡¼Ã_¡¼ */
		m = StrLength(T);				/* »ø¡¼¡¼Ã_¡¼ */
		i = pos;
		while (i <= n-m+1) 
		{
			SubString(sub, S, i, m);	/* ¡¼¡¼¡¼¡¼¡¼à`¡¼¡¼¡¼¡¼¡¼èö¡¼ ]sub */
			if (StrCompare(sub,T) != 0) /* ¡¼¡¼¡¼¡¼¡¼ */
				++i;
			else 						/* ¡¼¡¼¡¼¡¼§R*/
				return i;				/* ¡¼ß_¡¼¡¼ */
		}
	}
	return 0;							/* ¡¼£Q¡¼¡¼¡¼¡¼¡¼áµ0 */
}

/* ß_¡¼¡¼‘l¡¼²ÏS¡¼¿ios¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼á¶0¡¼*/
/* ¡¼¡¼,Tïú¡¼1¡¼os¡¼trLength(S)¡¼*/
int Index(String S, String T, int pos) 
{
	int i = pos;					/* i¡¼¡¼¡¼¡¼¡¼ÌZ£f¡¼¡¼¡¼¤Ð¡¼os£f¡¼¡¼¡¼¡¼ */
	int j = 1;						/* j¡¼¡¼¡¼¡¼¡¼ÌZ£f¡¼¡¼¡¼³ô/
	while (i <= S[0] && j <= T[0]) 	/* ¡¼i¡¼¡¼SÃ_¡¼¡¼¡¼¡¼¡¼TÃ_¡¼¡¼¡¼¡¼¡¼÷P/
	{
		if (S[i] == T[j]) 			/* }¡¼¡¼¡¼­ç¡¼¡¼ */
      	{
			++i;
         	++j; 
      	} 
      	else 						/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */
      	{  
         	i = i-j+2;				/* i¡¼¡¼¡¼¡¼®Ì¡¼£fßT¡¼¡¼ */
         	j = 1; 					/* j¡¼¡¼¡¼¡¼äñ¡¼¡¼/
      	}      
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}

/* ¡¼¡¼¡¼¡¼¡¼¡¼‘¯¡¼ext¡¼¡¼¡¼*/
void get_next(String T, int *next) 
{
	int i,k;
  	i=1;
  	k=0;
  	next[1]=0;
  	while (i<T[0])  /* ¡¼õÍ0]¡¼ž¯TÃ_¡¼ */
 	{
    	if(k==0 || T[i]== T[k]) 
		{
      		++i;  
			++k;  
			next[i] = k;
    	} 
		else 
			k= next[k];	/* ¡¼¡¼ãl¡¼¡¼¡¼¡¼áµ¡¼ */
  	}
}

/* ß_¡¼¡¼‘l¡¼²ÏS¡¼¿ios¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼á¶0¡¼*/
/*  Tïú¡¼¡¼¡¼os¡¼trLength(S)¡¼*/
int Index_KMP(String S, String T, int pos) 
{
	int i = pos;					/* i¡¼¡¼¡¼¡¼¡¼ÌZ£f¡¼¡¼¡¼¤Ð¡¼os£f¡¼¡¼¡¼¡¼ */
	int j = 1;						/* j¡¼¡¼¡¼¡¼¡¼ÌZ£f¡¼¡¼¡¼³ô/
	int next[255];					/* ¡¼«¦next¡¼¡¼ */
	get_next(T, next);				/* ¡¼‘oºü£a¡¼o¡¼xt¡¼¡¼ */
	while (i <= S[0] && j <= T[0]) 	/* ¡¼i¡¼¡¼SÃ_¡¼¡¼¡¼¡¼¡¼TÃ_¡¼¡¼¡¼¡¼¡¼÷P/
	{
		if (j==0 || S[i] == T[j]) 	/* }¡¼¡¼¡¼­ç¡¼¡¼¡¼¡¼¡¼¡¼¸ZºvKj=0¡¼Ù]*/
      	{
         	++i;
         	++j; 
      	} 
      	else						/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */
      	{ 						
      	 	j = next[j];			/* j¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼/
      	}
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}

/* ¡¼¡¼¡¼¡¼ï¹ext¡¼¡¼¡¼¡¼¡¼áØ¡¼¡¼nextval */
void get_nextval(String T, int *nextval) 
{
  	int i,k;
  	i=1;
  	k=0;
  	nextval[1]=0;
  	while (i<T[0])  				/* ¡¼õÍ0]¡¼ž¯TÃ_¡¼ */
 	{
    	if(k==0 || T[i]== T[k]) 	/* T[i]¡¼ ú¡¼ñì±a¡¼Â¸¡¼k]¡¼ýY¡¼ñì±a¡¼ßX*/
		{
      		++i;  
			++k;  
			if (T[i]!=T[k])      	/* ¡¼ÌZ¡¼µ²¡¼¡¼¡¼ãl¡¼ */
				nextval[i] = k;		/* ¡¼ÌZ¡¼k¡¼nextval¡¼i£f¡¼ºÊ³ô/
      		else 
				nextval[i] = nextval[k];	/* ¡¼èñ¡¼¡¼¡¼¸g¡¼¡¼¡¼¡¼¡¼¡¼ºø¡¼*/
											/* nextval¡¼»­±`nextval¡¼i£f¡¼ºÊ³ô/
    	} 
		else 
			k= nextval[k];			/* ¡¼¡¼ãl¡¼¡¼¡¼¡¼áµ¡¼ */
  	}
}

