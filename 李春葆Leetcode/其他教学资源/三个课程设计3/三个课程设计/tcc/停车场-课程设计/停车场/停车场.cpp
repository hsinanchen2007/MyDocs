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
	//NewNode=(LQNode *)malloc(sizeof(LQNode));  //不知道为什么，用malloc会出错。
	if(NewNode!=NULL)
	{
		NewNode->d=X;
		NewNode->next=NULL;
		Q->rear->next=NewNode;
		Q->rear->next->n=Q->rear->n+1; //用当前的Q->rear->n来存放编导车辆数目信息。
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
	cout<<"车辆"<<X.b<<"已经存在停车场"<<S->top<<"号车位，存车时间为"<<X.c<<":"<<X.d<<"。\n";
	}
	else
	{
		enterQueue(Q,X);
		cout<<"车辆"<<X.b<<"已经存在便道"<<Q->rear->n<<"号车位，存车时间为"<<X.c<<":"<<X.d<<"\n";
	}
	return (1);
}

int out(SeqStack *S,SeqStack *L,LinkQueue *Q,Car A)
{
	Car X;
	float money;
	if(S->top==-1) 
	{
		cout<<"车场已空，没有您的车。\n";
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
		if(A.c<X.c)cout<<"时间输入错误\n";
		else money=(A.c-X.c)*6+(A.d-X.d)*0.1;
		cout<<"车辆"<<A.b<<"存车时间为"<<X.c<<":"<<X.d<<"，离开时间为"<<A.c<<":"<<A.d<<"，";
		cout<<"停车费用为"<<money<<"元，祝您一路顺风！\n";
		while(L->top!=-1)
		{
			pop(L,&X);
			push(S,X);
		}
		if(Q->rear->n!=0)
		{
			deletQueue(Q,&X);
			X.c=A.c; X.d=A.d;      //将离开车辆的时间赋给从便道进入车场车辆的时间。
			if(push(S,X)==1)
			{cout<<"车辆"<<X.b<<"已由便道开进车场"<<S->top<<"号车位，";
			cout<<"存车时间从"<<X.c<<":"<<X.d<<""<<"算起。\n";}
		}
		return(1);
	}
	else 
	{
		int l=Q->rear->n;//便道出车会打乱车次，将存有编导车辆数目信息的Q->rear->n备份。
		LinkQueue E; //定义临时便道帮助遍历便道上车辆。
		initQueue(&E);
		while(deletQueue(Q,&X)!=0&&X.b!=A.b)
		{enterQueue(&E,X);}
		if(X.b!=A.b)
			printf("输入错误，没有您的车。\n\n");
		if(X.b==A.b)
		{
			l--;  //有车离开，则l=l-1。
			cout<<"车辆"<<X.b<<"已从便道离开，停车费用为0元。\n";
		}
		while(deletQueue(&E,&X)!=0)
		{
			enterQueue(Q,X);
		}
		Q->rear->n=l; //将l的值及便道车辆数目信息付给新的Q->rear->n。
	}
}



int main()
{
	cout<<"************************欢迎来到停车场***************************\n";
	cout<<"                       停车费用每小时6元                         \n\n";
	Car A;
	SeqStack S,L;
	initstack(&S);
	initstack(&L);
	LinkQueue Q;
	initQueue(&Q);
	while(1)
	{
		cout<<"输入1停车，输入0离开,输入-1可获取当前停车信息："; 
		cin>>A.a;
		if(A.a!=1&&A.a!=0&&A.a!=-1)
		{	cout<<"输入错误，请重新输入。\n";
		    continue;
		}
		if(A.a!=-1)
		{
			cout<<"请输入车牌号：";cin>>A.b;
			cout<<"请输入目前的时间（例如：3:50 【(注意为英文格式】）：";
			scanf("%d:%d",&A.c,&A.d);
			if(A.c<=24&&A.c>=0&&A.d<60&&A.d>=0) ;
			else 
			{
				cout<<"输入错误，请重新输入目前的时间（例如：3:50 【(注意为英文格式】）：";
				scanf("%d:%d",&A.c,&A.d);
			}
			cout<<"\n"<<"请核对信息： [ "<<A.a<<" "<<A.b<<" "<<A.c<<":"<<A.d<<" ]   正确请按 y，错误请按 n：";
			char sure;cin>>sure;
			if(sure=='n'||sure=='N')continue;
			printf("\n");
		}
		
		switch(A.a)
		{
			case 1 : in(&S,&Q,A);break;
			case 0 : out(&S,&L,&Q,A);break;
			case -1:cout<<"当前车场有车辆"<<S.top+1<<"辆，便道有车辆"<<Q.rear->n<<"辆。\n\n";break;
		}
		cout<<"-------------------------------------------------------------------------------\n";
	}
}

