#include<iostream> 
#include<cstring> 
using namespace std;
#define MAXN 55
#define MAXM 105 
struct SNode								//元素类型
{	char str[MAXN];							//字符串
	int inv;									//逆序数
} a[MAXM];
void BubbleSort(SNode a[],int m) 			//冒泡排序:按inv递增排序
{	for (int i=0;i<m-1;i++) 
	{	bool exchange=false;					//本趟前将exchange置为false
		for (int j=m-1;j>i;j--)				//一趟中找出最小关键字的元素
			if (a[j].inv<a[j-1].inv)			//反序时交换
			{	swap(a[j],a[j-1]);
				exchange=true;				//本趟发生交换置exchange为true
			}
		if (!exchange)						//本趟没有发生交换，中途结束算法
			return;
	}
}
int main()
{	int n,m;
	char s[MAXN]; 
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{	scanf("%s",s);
		int cnt=0; 
		for(int j=0;j<n;j++)							//求字符串s的逆序数
			for(int k=0;k<j;k++)
				if(s[j]<s[k])
					cnt++;  							//累计逆序数
		strcpy(a[i].str,s);
		a[i].inv=cnt;
	}
	BubbleSort(a,m);									//排序
	for(int i=0;i<m;i++)								//输出结果
		printf("%s\n",a[i].str);
	return 0;
}

