#include <stdio.h>
#include <string>
#include<iostream>
#include <malloc.h>
using namespace std;

typedef struct
{
	int a;
	string b;
	int c;
	int d;
}Car;

typedef struct
{	
	Car elem[2];
	int top;
}SeqStack;

typedef struct Node
{
	Car d;    
	int n;	  
	struct Node  *next;
}LQNode;

typedef struct
{
	LQNode * front;
	LQNode * rear;
}LinkQueue;

//------------------------------------------

void initstack(SeqStack *S)
{
	S->top=-1;
}

int push(SeqStack *S,Car x)
{
	if(S->top==1)return (0);
	S->top++;
	S->elem[S->top]=x;
	return (1);
}

int pop(SeqStack *S,Car *x)
{
	if(S->top==-1)return(0);
	else
	{
		*x=S->elem[S->top];
		S->top--;
		return(1);
	}
}
//------------------------------------------
int initQueue(LinkQueue *Q)
{
	Q->front=(LQNode *)malloc(sizeof(LQNode));
	if(Q->front!=NULL)
	{
		Q->rear=Q->front;
		Q->front->next=NULL;
		Q->rear->n=0;
		return (1);	
	}
	else return(0);
}

int enterQueue(LinkQueue *Q,Car X)
{
	LQNode * NewNode=new LQNode;
	//NewNode=(LQNode *)malloc(sizeof(LQNode));  //��֪��Ϊʲô����malloc�����
	if(NewNode!=NULL)
	{
		NewNode->d=X;
		NewNode->next=NULL;
		Q->rear->next=NewNode;
		Q->rear->next->n=Q->rear->n+1; //�õ�ǰ��Q->rear->n����űർ������Ŀ��Ϣ��
		Q->rear=NewNode;
		return (1);
	}
	else return (0);
}

int deletQueue(LinkQueue *Q,Car *X)
{
	LQNode *p;
	if(Q->front==Q->rear)
	{
		return (0);
	}
	p=Q->front->next;
	Q->front->next=p->next;
	Q->rear->n--;
	if(Q->rear==p)
	{
		Q->rear=Q->front;
		Q->rear->n=0;
	}
	*X=p->d;
	delete p;
	return (1);
}

int in(SeqStack *S,LinkQueue *Q,Car X)
{
	if(S->top<1)
	{
		push(S,X);
	cout<<"����"<<X.b<<"�Ѿ�����ͣ����"<<S->top<<"�ų�λ���泵ʱ��Ϊ"<<X.c<<":"<<X.d<<"��\n";
	}
	else
	{
		enterQueue(Q,X);
		cout<<"����"<<X.b<<"�Ѿ����ڱ��"<<Q->rear->n<<"�ų�λ���泵ʱ��Ϊ"<<X.c<<":"<<X.d<<"\n";
	}
	return (1);
}

int out(SeqStack *S,SeqStack *L,LinkQueue *Q,Car A)
{
	Car X;
	float money;
	if(S->top==-1) 
	{
		cout<<"�����ѿգ�û�����ĳ���\n";
		return(0);
	}
	else
	{	pop(S,&X);
		if(X.b!=A.b&&S->top==-1) push(L,X);
		while(X.b!=A.b&&S->top!=-1)
		{
			pop(S,&X);
			push(L,X);	
		}
	}
	if(X.b==A.b)
	{	
		if(A.c<X.c)cout<<"ʱ���������\n";
		else money=(A.c-X.c)*6+(A.d-X.d)*0.1;
		cout<<"����"<<A.b<<"�泵ʱ��Ϊ"<<X.c<<":"<<X.d<<"���뿪ʱ��Ϊ"<<A.c<<":"<<A.d<<"��";
		cout<<"ͣ������Ϊ"<<money<<"Ԫ��ף��һ·˳�磡\n";
		while(L->top!=-1)
		{
			pop(L,&X);
			push(S,X);
		}
		if(Q->rear->n!=0)
		{
			deletQueue(Q,&X);
			X.c=A.c; X.d=A.d;      //���뿪������ʱ�丳���ӱ�����복��������ʱ�䡣
			if(push(S,X)==1)
			{cout<<"����"<<X.b<<"���ɱ����������"<<S->top<<"�ų�λ��";
			cout<<"�泵ʱ���"<<X.c<<":"<<X.d<<""<<"����\n";}
		}
		return(1);
	}
	else 
	{
		int l=Q->rear->n;//�����������ҳ��Σ������бർ������Ŀ��Ϣ��Q->rear->n���ݡ�
		LinkQueue E; //������ʱ���������������ϳ�����
		initQueue(&E);
		while(deletQueue(Q,&X)!=0&&X.b!=A.b)
		{enterQueue(&E,X);}
		if(X.b!=A.b)
			printf("�������û�����ĳ���\n\n");
		if(X.b==A.b)
		{
			l--;  //�г��뿪����l=l-1��
			cout<<"����"<<X.b<<"�Ѵӱ���뿪��ͣ������Ϊ0Ԫ��\n";
		}
		while(deletQueue(&E,&X)!=0)
		{
			enterQueue(Q,X);
		}
		Q->rear->n=l; //��l��ֵ�����������Ŀ��Ϣ�����µ�Q->rear->n��
	}
}



int main()
{
	cout<<"************************��ӭ����ͣ����***************************\n";
	cout<<"                       ͣ������ÿСʱ6Ԫ                         \n\n";
	Car A;
	SeqStack S,L;
	initstack(&S);
	initstack(&L);
	LinkQueue Q;
	initQueue(&Q);
	while(1)
	{
		cout<<"����1ͣ��������0�뿪,����-1�ɻ�ȡ��ǰͣ����Ϣ��"; 
		cin>>A.a;
		if(A.a!=1&&A.a!=0&&A.a!=-1)
		{	cout<<"����������������롣\n";
		    continue;
		}
		if(A.a!=-1)
		{
			cout<<"�����복�ƺţ�";cin>>A.b;
			cout<<"������Ŀǰ��ʱ�䣨���磺3:50 ��(ע��ΪӢ�ĸ�ʽ������";
			scanf("%d:%d",&A.c,&A.d);
			if(A.c<=24&&A.c>=0&&A.d<60&&A.d>=0) ;
			else 
			{
				cout<<"�����������������Ŀǰ��ʱ�䣨���磺3:50 ��(ע��ΪӢ�ĸ�ʽ������";
				scanf("%d:%d",&A.c,&A.d);
			}
			cout<<"\n"<<"��˶���Ϣ�� [ "<<A.a<<" "<<A.b<<" "<<A.c<<":"<<A.d<<" ]   ��ȷ�밴 y�������밴 n��";
			char sure;cin>>sure;
			if(sure=='n'||sure=='N')continue;
			printf("\n");
		}
		
		switch(A.a)
		{
			case 1 : in(&S,&Q,A);break;
			case 0 : out(&S,&L,&Q,A);break;
			case -1:cout<<"��ǰ�����г���"<<S.top+1<<"��������г���"<<Q.rear->n<<"����\n\n";break;
		}
		cout<<"-------------------------------------------------------------------------------\n";
	}
}

