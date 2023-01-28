/*  T���D�Ŧr��C�Y�D��S����pos�Ӧr������s�b�PT�۵����l�r��A */
/*  �h�Ǧ^�Ĥ@�ӳo�˪��l�r��bS������m�A�_�h�Ǧ^0 */
int Index(String S, String T, int pos) 
{
	int n,m,i;
	String sub;
	if (pos > 0) 
	{
		n = StrLength(S);				/* �o��D��S������ */
		m = StrLength(T);				/* �o��l�r��T������ */
		i = pos;
		while (i <= n-m+1) 
		{
			SubString(sub, S, i, m);	/* ���D�ꤤ��i�Ӧ�m���׻PT�۵����l�r�굹sub */
			if (StrCompare(sub,T) != 0) /* �Y�G��ꤣ�۵� */
				++i;
			else 						/* �Y�G���۵� */
				return i;				/* �h�Ǧ^i�� */
		}
	}
	return 0;							/* �Y�L�l�r��PT�۵��A�Ǧ^0 */
}

/* �Ǧ^�l�r��T�b�D��S����pos�Ӧr�����᪺��m�C�Y���s�b,�h��ƶǦ^�Ȭ�0�C */
/* �䤤,T�D��,1��pos��StrLength(S)�C */
int Index(String S, String T, int pos) 
{
	int i = pos;					/* i�Ω�D��S���ثe��m���ޭȡA�qpos��m�}�l��� */
	int j = 1;						/* j�Ω�l�r��T���ثe��m���ޭ� */
	while (i <= S[0] && j <= T[0]) 	/* �Yi�p��S�����רåBj�p��T�����׮ɡA�`���~�� */
	{
		if (S[i] == T[j]) 			/* ��r���۵��h�~�� */
      	{
			++i;
         	++j; 
      	} 
      	else 						/* ���Ы�h���s�}�l��� */
      	{  
         	i = i-j+2;				/* i�h�^��W����ﭺ�쪺�U�@�� */
         	j = 1; 					/* j�h�^��l�r��T������ */
      	}      
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}

/* �z�L�p��Ǧ^�l�r��T��next�}�C�C */
void get_next(String T, int *next) 
{
	int i,k;
  	i=1;
  	k=0;
  	next[1]=0;
  	while (i<T[0])  /* ���BT[0]��ܦ�T������ */
 	{
    	if(k==0 || T[i]== T[k]) 
		{
      		++i;  
			++k;  
			next[i] = k;
    	} 
		else 
			k= next[k];	/* �Y�r�����ۦP�A�hk�Ȧ^�� */
  	}
}

/* �Ǧ^�l�r��T�b�D��S����pos�Ӧr�����᪺��m�C�Y���s�b�A�h��ƶǦ^�Ȭ�0�C */
/*  T�D�šA1��pos��StrLength(S)�C */
int Index_KMP(String S, String T, int pos) 
{
	int i = pos;					/* i�Ω�D��S���ثe��m���ޭȡA�qpos��m�}�l��� */
	int j = 1;						/* j�Ω�l�r��T���ثe��m���ޭ� */
	int next[255];					/* �w�q�@next�}�C */
	get_next(T, next);				/* ���T�@���R�A�o��next�}�C */
	while (i <= S[0] && j <= T[0]) 	/* �Yi�p��S�����רåBj�p��T�����׮ɡA�`���~�� */
	{
		if (j==0 || S[i] == T[j]) 	/* ��r���۵��h�~��A�P�����k�W�[�Fj=0�P�_ */
      	{
         	++i;
         	++j; 
      	} 
      	else						/* ���Ы�h���s�}�l��� */
      	{ 						
      	 	j = next[j];			/* j�h�^�X�A����m�Ai�Ȥ��� */
      	}
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}

/* �D�Ҧ���T��next��ƭץ��Ȩæs�J�}�Cnextval */
void get_nextval(String T, int *nextval) 
{
  	int i,k;
  	i=1;
  	k=0;
  	nextval[1]=0;
  	while (i<T[0])  				/* ���BT[0]��ܦ�T������ */
 	{
    	if(k==0 || T[i]== T[k]) 	/* T[i]��ܰ��ɦW����@�r���AT[k]��ܫe�󪺳�@�r�� */
		{
      		++i;  
			++k;  
			if (T[i]!=T[k])      	/* �Y�ثe�r���P�e��r�����P */
				nextval[i] = k;		/* �h�ثe��k��nextval�bi��m���� */
      		else 
				nextval[i] = nextval[k];	/* �Y�G�P�e��r���ۦP�A�h�N�e��r���� */
											/* nextval�ȵ����ȵ�nextval�bi��m���� */
    	} 
		else 
			k= nextval[k];			/* �Y�r�����ۦP�A�hk�Ȧ^�� */
  	}
}

