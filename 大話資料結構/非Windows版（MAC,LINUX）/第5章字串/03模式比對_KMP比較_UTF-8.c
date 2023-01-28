#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* �x�s�Ŷ��_�l���t�q */

typedef int Status;		/* Status�O��ƪ����A,��ȬO��Ƶ��G���A�{���X�A�pOK�� */
typedef int ElemType;	/* ElemType���A�ھڹ�ڱ��p�өw�A�o�̰��]��int */

typedef char String[MAXSIZE+1]; /*  0���椸�s��ꪺ���� */

/* ���ͤ@�Ө�ȵ���chars����T */
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
	S[0]=0;/*  �O������s */
	return OK;
}

/*  ��X�r��T�C */
void StrPrint(String T)
{ 
	int i;
	for(i=1;i<=T[0];i++)
		printf("%c",T[i]);
	printf("\n");
}

/*  ��XNext�}�C�ȡC */
void NextPrint(int next[],int length)
{ 
	int i;
	for(i=1;i<=length;i++)
		printf("%d",next[i]);
	printf("\n");
}

/* �Ǧ^�ꪺ�����Ӽ� */
int StrLength(String S)
{ 
	return S[0];
}

/* ������Ҧ����k */
int Index(String S, String T, int pos) 
{
	int n = 0;
	int i = pos;	/* i�Ω�D��S���ثe��m���ޭȡA�Ypos����1�A�h�qpos��m�}�l��� */
	int j = 1;				/* j�Ω�l�r��T���ثe��m���ޭ� */
	while (i <= S[0] && j <= T[0]) /* �Yi�p��S�����רåBj�p��T�����׮ɡA�`���~�� */
	{
		if (S[i] == T[j]) 	/* ��r���۵��h�~�� */
      	{
			++i;
         	++j; 
      	} 
      	else 				/* ���Ы�h���s�}�l��� */
      	{  
         	i = i-j+2;		/* i�h�^��W����ﭺ�쪺�U�@�� */
         	j = 1; 			/* j�h�^��l�r��T������ */
      	} 
      	
		printf("n=%d i=%d j=%d\n",++n,i,j); 
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
	int n = 0;
	int i = pos;		/* i�Ω�D��S���ثe��m���ޭȡA�Ypos����1�A�h�qpos��m�}�l��� */
	int j = 1;			/* j�Ω�l�r��T���ثe��m���ޭ� */
	int next[255];		/* �w�q�@next�}�C */
	get_next(T, next);	/* ���T�@���R�A�o��next�}�C */
	while (i <= S[0] && j <= T[0]) /* �Yi�p��S�����רåBj�p��T�����׮ɡA�`���~�� */
	{
		if (j==0 || S[i] == T[j]) 	/* ��r���۵��h�~��A�P�����k�W�[�Fj=0�P�_ */
      	{
         	++i;
         	++j; 
      	} 
      	else 			/* ���Ы�h���s�}�l��� */
      	 	j = next[j];/* j�h�^�X�A����m�Ai�Ȥ��� */
      
	  	printf("n=%d i=%d j=%d\n",++n,i,j);  
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
  	while (i<T[0])  /* ���BT[0]��ܦ�T������ */
 	{
    	if(k==0 || T[i]== T[k]) 	/* T[i]��ܰ��ɦW����@�r���AT[k]��ܫe�󪺳�@�r�� */
		{
      		++i;  
			++k;  
			if (T[i]!=T[k])      /* �Y�ثe�r���P�e��r�����P */
				nextval[i] = k;	/* �h�ثe��j��nextval�bi��m���� */
      		else 
				nextval[i] = nextval[k];	/* �Y�G�P�e��r���ۦP�A�h�N�e��r���� */
											/* nextval�ȵ����ȵ�nextval�bi��m���� */
    	} 
		else 
			k= nextval[k];			/* �Y�r�����ۦP�A�hk�Ȧ^�� */
		
  	}
}

int Index_KMP1(String S, String T, int pos) 
{
	int n=0;
	int i = pos;		/* i�Ω�D��S���ثe��m���ޭȡA�Ypos����1�A�h�qpos��m�}�l��� */
	int j = 1;			/* j�Ω�l�r��T���ثe��m���ޭ� */
	int next[255];		/* �w�q�@next�}�C */
	get_nextval(T, next);	/* ���T�@���R�A�o��next�}�C */
	while (i <= S[0] && j <= T[0]) /* �Yi�p��S�����רåBj�p��T�����׮ɡA�`���~�� */
	{
		if (j==0 || S[i] == T[j]) 	/* ��r���۵��h�~��A�P�����k�W�[�Fj=0�P�_ */
      	{
         	++i;
         	++j; 
      	} 
      	else 			/* ���Ы�h���s�}�l��� */
      	 	j = next[j];/* j�h�^�X�A����m�Ai�Ȥ��� */
      	
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
	printf("�D�ꬰ: ");
	StrPrint(s1);
	StrAssign(s2,"0000000001");
	printf("�l�r�ꬰ: ");
	StrPrint(s2);
	printf("\n");
	
	printf("\n");
	printf("�D��M�l�r��b��%d�Ӧr���B�Ĥ@�����]����Ҧ�����k�^\n",Index(s1,s2,1));
	printf("�D��M�l�r��b��%d�Ӧr���B�Ĥ@�����]KMP��k�^ \n",Index_KMP(s1,s2,1));
	printf("�D��M�l�r��b��%d�Ӧr���B�Ĥ@�����]KMP��}��k�^ \n",Index_KMP1(s1,s2,1));

	return 0;
}
