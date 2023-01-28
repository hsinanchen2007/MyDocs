/*  T�������̡��������ios������������T���С����� */
/*  ���_���������������rS�����������_�� */
int Index(String S, String T, int pos) 
{
	int n,m,i;
	String sub;
	if (pos > 0) 
	{
		n = StrLength(S);				/* �������_�� */
		m = StrLength(T);				/* �������_�� */
		i = pos;
		while (i <= n-m+1) 
		{
			SubString(sub, S, i, m);	/* �����������`���������������]sub */
			if (StrCompare(sub,T) != 0) /* ���������� */
				++i;
			else 						/* ���������R*/
				return i;				/* ���_���� */
		}
	}
	return 0;							/* ���Q�����������0 */
}

/* �_�����l����S���ios�����������������������������0��*/
/* ����,T����1��os��trLength(S)��*/
int Index(String S, String T, int pos) 
{
	int i = pos;					/* i�����������Z�f�������С�os�f�������� */
	int j = 1;						/* j�����������Z�f��������/
	while (i <= S[0] && j <= T[0]) 	/* ��i����S�_����������T�_�����������P/
	{
		if (S[i] == T[j]) 			/* }�������硼�� */
      	{
			++i;
         	++j; 
      	} 
      	else 						/* ������������������ */
      	{  
         	i = i-j+2;				/* i���������̡��f�T���� */
         	j = 1; 					/* j���������񡼡�/
      	}      
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}

/* ����������������ext������*/
void get_next(String T, int *next) 
{
	int i,k;
  	i=1;
  	k=0;
  	next[1]=0;
  	while (i<T[0])  /* ����0]����T�_�� */
 	{
    	if(k==0 || T[i]== T[k]) 
		{
      		++i;  
			++k;  
			next[i] = k;
    	} 
		else 
			k= next[k];	/* �����l��������ᵡ� */
  	}
}

/* �_�����l����S���ios�����������������������������0��*/
/*  T��������os��trLength(S)��*/
int Index_KMP(String S, String T, int pos) 
{
	int i = pos;					/* i�����������Z�f�������С�os�f�������� */
	int j = 1;						/* j�����������Z�f��������/
	int next[255];					/* ����next���� */
	get_next(T, next);				/* ���o���a��o��xt���� */
	while (i <= S[0] && j <= T[0]) 	/* ��i����S�_����������T�_�����������P/
	{
		if (j==0 || S[i] == T[j]) 	/* }�������硼�����������Z�vKj=0���]*/
      	{
         	++i;
         	++j; 
      	} 
      	else						/* ������������������ */
      	{ 						
      	 	j = next[j];			/* j��������������������/
      	}
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}

/* ���������ext�����������ء���nextval */
void get_nextval(String T, int *nextval) 
{
  	int i,k;
  	i=1;
  	k=0;
  	nextval[1]=0;
  	while (i<T[0])  				/* ����0]����T�_�� */
 	{
    	if(k==0 || T[i]== T[k]) 	/* T[i]��������a��¸��k]���Y����a���X*/
		{
      		++i;  
			++k;  
			if (T[i]!=T[k])      	/* ���Z�����������l�� */
				nextval[i] = k;		/* ���Z��k��nextval��i�f���ʳ�/
      		else 
				nextval[i] = nextval[k];	/* ���񡼡����g����������������*/
											/* nextval�����`nextval��i�f���ʳ�/
    	} 
		else 
			k= nextval[k];			/* �����l��������ᵡ� */
  	}
}

