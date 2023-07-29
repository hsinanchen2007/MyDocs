#include<iostream>
#include<malloc.h>
using namespace std;
#define m 2
struct List
{
	int *data;				//动态数组 
	int length;				//长度 
	int capacity;			//容量 
};
void Init(List& L)			//初始化 
{
	L.capacity=m;
	L.data=new int[L.capacity];
	L.length=0;
}
void Expand(List& L)		//按长度两倍扩大容量 
{
	int *p=L.data;
	L.capacity=2*L.length;		//设置新容量 
	L.data=new int[L.capacity];
	for(int i=0;i<L.length;i++)		//复制全部元素 
		L.data[i]=p[i];
	delete p;
}
void Add(List& L,int e)
{
	if(L.length==L.capacity)
		Expand(L);
	L.data[L.length]=e;
	L.length++;
}
void disp(List& L)
{
	printf("L: ");
	for(int i=0;i<L.length;i++)
		printf("%d ",L.data[i]);
	printf("\n");
}
int main ()
{
	List L;
	Init(L);
	printf("长度=%d,容量=%d\n",L.length,L.capacity);
	for(int i=1;i<=10;i++)
	{
		printf("插入%d ",i); 
		Add(L,i);
		printf("长度=%d,容量=%d  ",L.length,L.capacity);
		disp(L);
	}

	return 0;
}
