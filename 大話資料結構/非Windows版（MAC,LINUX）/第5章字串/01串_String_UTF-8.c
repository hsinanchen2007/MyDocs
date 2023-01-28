#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 40 /* �x�s�Ŷ��_�l���t�q */

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

/* �Ѧ�S�ƻs�o��T */
Status StrCopy(String T,String S)
{ 
	int i;
	for(i=0;i<=S[0];i++)
		T[i]=S[i];
	return OK;
}

/* �YS���Ŧr��,�h�Ǧ^TRUE,�_�h�Ǧ^FALSE */
Status StrEmpty(String S)
{ 
	if(S[0]==0)
		return TRUE;
	else
		return FALSE;
}

/*  �_�l����: ��S�MT�s�b */
/*  �ʧ@���G: �YS>T,�h�Ǧ^��>0;�YS=T,�h�Ǧ^��=0;�YS<T,�h�Ǧ^��<0 */
int StrCompare(String S,String T)
{ 
	int i;
	for(i=1;i<=S[0]&&i<=T[0];++i)
		if(S[i]!=T[i])
			return S[i]-T[i];
	return S[0]-T[0];
}

/* �Ǧ^�ꪺ�����Ӽ� */
int StrLength(String S)
{ 
	return S[0];
}

/* �_�l����:��S�s�b�C�ʧ@���G:�NS�M���Ŧr�� */
Status ClearString(String S)
{ 
	S[0]=0;/*  �O������s */
	return OK;
}

/* ��T�Ǧ^S1�MS2�p���Ӧ����s��C�Y�����_�A�h�Ǧ^TRUE�A�_�hFALSE */
Status Concat(String T,String S1,String S2)
{
	int i;
	if(S1[0]+S2[0]<=MAXSIZE)
	{ /*  �����_ */
		for(i=1;i<=S1[0];i++)
			T[i]=S1[i];
		for(i=1;i<=S2[0];i++)
			T[S1[0]+i]=S2[i];
		T[0]=S1[0]+S2[0];
		return TRUE;
	}
	else
	{ /*  ���_S2 */
		for(i=1;i<=S1[0];i++)
			T[i]=S1[i];
		for(i=1;i<=MAXSIZE-S1[0];i++)
			T[S1[0]+i]=S2[i];
		T[0]=MAXSIZE;
		return FALSE;
	}
}

/* ��Sub�Ǧ^��S����pos�Ӧr���_���׬�len���l�r��C */
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

/* �Ǧ^�l�r��T�b�D��S����pos�Ӧr�����᪺��m�C�Y���s�b,�h��ƶǦ^�Ȭ�0�C */
/* �䤤,T�D��,1��pos��StrLength(S)�C */
int Index(String S, String T, int pos) 
{
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
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}


/*  T���D�Ŧr��C�Y�D��S����pos�Ӧr������s�b�PT�۵����l�r��A */
/*  �h�Ǧ^�Ĥ@�ӳo�˪��l�r��bS������m�A�_�h�Ǧ^0 */
int Index2(String S, String T, int pos) 
{
	int n,m,i;
	String sub;
	if (pos > 0) 
	{
		n = StrLength(S);	/* �o��D��S������ */
		m = StrLength(T);	/* �o��l�r��T������ */
		i = pos;
		while (i <= n-m+1) 
		{
			SubString (sub, S, i, m);	/* ���D�ꤤ��i�Ӧ�m���׻PT�۵����l�r�굹sub */
			if (StrCompare(sub,T) != 0)    /* �Y�G��ꤣ�۵� */
				++i;
			else 				/* �Y�G���۵� */
				return i;		/* �h�Ǧ^i�� */
		}
	}
	return 0;	/* �Y�L�l�r��PT�۵��A�Ǧ^0 */
}


/*  �_�l����: ��S�MT�s�b,1��pos��StrLength(S)+1 */
/*  �ʧ@���G: �b��S����pos�Ӧr�����e���J��T�C�������J�Ǧ^TRUE,�������J�Ǧ^FALSE */
Status StrInsert(String S,int pos,String T)
{ 
	int i;
	if(pos<1||pos>S[0]+1)
		return ERROR;
	if(S[0]+T[0]<=MAXSIZE)
	{ /*  �������J */
		for(i=S[0];i>=pos;i--)
			S[i+T[0]]=S[i];
		for(i=pos;i<pos+T[0];i++)
			S[i]=T[i-pos+1];
		S[0]=S[0]+T[0];
		return TRUE;
	}
	else
	{ /*  �������J */
		for(i=MAXSIZE;i<=pos;i--)
			S[i]=S[i-T[0]];
		for(i=pos;i<pos+T[0];i++)
			S[i]=T[i-pos+1];
		S[0]=MAXSIZE;
		return FALSE;
	}
}

/*  �_�l����: ��S�s�b,1��pos��StrLength(S)-len+1 */
/*  �ʧ@���G: �q��S��������pos�Ӧr���_���׬�len���l�r�� */
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

/*  �_�l����: ��S,T�MV�s�b,T�O�D�Ŧr��]����ƻP�ꪺ�x�s���c�L���^ */
/*  �ʧ@���G: ��V�m���D��S���X�{���Ҧ��PT�۵��������|���l�r�� */
Status Replace(String S,String T,String V)
{ 
	int i=1; /*  �q��S���Ĥ@�Ӧr���_�d�ߦ�T */
	if(StrEmpty(T)) /*  T�O�Ŧr�� */
		return ERROR;
	do
	{
		i=Index(S,T,i); /*  ���Gi���q�W�@��i�����쪺�l�r��T����m */
		if(i) /*  ��S���s�b��T */
		{
			StrDelete(S,i,StrLength(T)); /*  �����Ӧ�T */
			StrInsert(S,i,V); /*  �b���T����m���J��V */
			i+=StrLength(V); /*  �b���J����V�᭱�~��d�ߦ�T */
		}
	}while(i);
	return OK;
}

/*  ��X�r��T */
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
	printf("�п�J��s1: ");
	
	k=StrAssign(s1,"abcd");
	if(!k)
	{
		printf("����W�LMAXSIZE(=%d)\n",MAXSIZE);
		exit(0);
	}
	printf("�����%d ��ŧ_�H%d(1:�O 0:�_)\n",StrLength(s1),StrEmpty(s1));
	StrCopy(s2,s1);
	printf("�Ш�s1���ͪ��ꬰ: ");
	StrPrint(s2);
	printf("�п�J��s2: ");
	
	k=StrAssign(s2,"efghijk");
	if(!k)
	{
		printf("����W�LMAXSIZE(%d)\n",MAXSIZE);
		exit(0);
	}
	i=StrCompare(s1,s2);
	if(i<0)
		s='<';
	else if(i==0)
		s='=';
	else
		s='>';
	printf("��s1%c��s2\n",s);
	k=Concat(t,s1,s2);
	printf("��s1�p����s2�o�쪺��t��: ");
	StrPrint(t);
	if(k==FALSE)
		printf("��t�����_\n");
	ClearString(s1);
	printf("�M���Ŧr���,��s1��: ");
	StrPrint(s1);
	printf("�����%d ��ŧ_�H%d(1:�O 0:�_)\n",StrLength(s1),StrEmpty(s1));
	printf("�D��t���l�r��,�п�J�l�r�ꪺ�_�l��m,�l�r�����: ");

	i=2;
	j=3;
	printf("%d,%d \n",i,j);

	k=SubString(s2,t,i,j);
	if(k)
	{
		printf("�l�r��s2��: ");
		StrPrint(s2);
	}
	printf("�q��t����pos�Ӧr���_,����len�Ӧr���A�п�Jpos,len: ");
	
	i=4;
	j=2;
	printf("%d,%d \n",i,j);


	StrDelete(t,i,j);
	printf("�����᪺��t��: ");
	StrPrint(t);
	i=StrLength(s2)/2;
	StrInsert(s2,i,t);
	printf("�b��s2����%d�Ӧr�����e���J��t��,��s2��:\n",i);
	StrPrint(s2);
	i=Index(s2,t,1);
	printf("s2����%d�Ӧr���_�Mt�Ĥ@�����\n",i);
	SubString(t,s2,1,1);
	printf("��t���G");
	StrPrint(t);
	Concat(s1,t,t);
	printf("��s1���G");
	StrPrint(s1);
	Replace(s2,t,s1);
	printf("�Φ�s1���N��s2���M��t�ۦP�������|�����,��s2��: ");
	StrPrint(s2);


	return 0;
}

