#include<iostream>
#include<queue>
#include<string>
using namespace std;
int popk(queue<int>&qu,int k)
{
	int n=qu.size(),x;
	for(int i=1;i<k;i++)				//处理序号1到k-1的元素 
	{
		x=qu.front(); qu.pop();			//出队元素x 
		qu.push(x);						//将x进队
	}
	int e=qu.front(); qu.pop();			//出队序号为k的元素e
	for(int i=k+1;i<=n;i++)				//处理序号k+1到n的元素 
	{
		x=qu.front(); qu.pop();			//出队元素x 
		qu.push(x);						//将x进队
	}
	return e;	 
}		
void disp(queue<int> qu)
{
	printf("队头到队尾: ");
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
	printf(" 出队序号%d的元素:%d\n",k,popk(qu,k));
	printf(" qu: "); disp(qu);
	 
	return 0;
}
