#include<iostream>
#include<queue>
#include<string>
using namespace std;
int popk(queue<int>&qu,int k)
{
	int n=qu.size(),x;
	for(int i=1;i<k;i++)				//�������1��k-1��Ԫ�� 
	{
		x=qu.front(); qu.pop();			//����Ԫ��x 
		qu.push(x);						//��x����
	}
	int e=qu.front(); qu.pop();			//�������Ϊk��Ԫ��e
	for(int i=k+1;i<=n;i++)				//�������k+1��n��Ԫ�� 
	{
		x=qu.front(); qu.pop();			//����Ԫ��x 
		qu.push(x);						//��x����
	}
	return e;	 
}		
void disp(queue<int> qu)
{
	printf("��ͷ����β: ");
	while(!qu.empty())
	{
		printf("%d ",qu.front());
		qu.pop();
	}
	printf("\n");
}
	
int main()
{
	queue<int> qu;
	qu.push(1);
	qu.push(2);
	qu.push(3);
	qu.push(4);
	printf(" qu: "); disp(qu);
	int k=3;
	printf(" �������%d��Ԫ��:%d\n",k,popk(qu,k));
	printf(" qu: "); disp(qu);
	 
	return 0;
}
