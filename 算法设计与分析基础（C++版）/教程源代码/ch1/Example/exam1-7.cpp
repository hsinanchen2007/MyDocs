#include<iostream>
#include<malloc.h>
using namespace std;
#define m 2
struct List
{
	int *data;				//��̬���� 
	int length;				//���� 
	int capacity;			//���� 
};
void Init(List& L)			//��ʼ�� 
{
	L.capacity=m;
	L.data=new int[L.capacity];
	L.length=0;
}
void Expand(List& L)		//������������������ 
{
	int *p=L.data;
	L.capacity=2*L.length;		//���������� 
	L.data=new int[L.capacity];
	for(int i=0;i<L.length;i++)		//����ȫ��Ԫ�� 
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
	printf("����=%d,����=%d\n",L.length,L.capacity);
	for(int i=1;i<=10;i++)
	{
		printf("����%d ",i); 
		Add(L,i);
		printf("����=%d,����=%d  ",L.length,L.capacity);
		disp(L);
	}

	return 0;
}
