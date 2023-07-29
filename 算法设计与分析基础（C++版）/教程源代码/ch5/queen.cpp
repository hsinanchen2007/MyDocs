#include<iostream>
using namespace std;
#define MAXN 20					//最多皇后个数
int q[MAXN];					//存放各皇后所在的列号,为全局变量
int cnt=0;						//累计解个数
void disp(int n)   				//输出一个解
{
	printf("  第%d个解:",++cnt);
	for (int i=1;i<=n;i++)
		printf("(%d,%d) ",i,q[i]);
	printf("\n");
}
bool place(int i,int j)				//测试(i,j)位置能否摆放皇后
{	if (i==1) return true;			//第一个皇后总是可以放置
	int k=1;
	while (k<i)						//k=1～i-1是已放置了皇后的行
	{	if ((q[k]==j) || (abs(q[k]-j)==abs(i-k)))
			return false;
		k++;
	}
	return true;
}
//-----------递归解法------------------------ 
void queen11(int n,int i)			//回溯算法 
{	if (i>n) 
		disp(n);					//所有皇后放置结束
	else
	{	for (int j=1;j<=n;j++)		//在第i行上试探每一个列j
			if (place(i,j))			//在第i行上找到一个合适位置(i,j)
			{	q[i]=j;
				queen11(n,i+1);
				q[i]=0;				//回溯 
			}
	}
}
void queen1(int n)				//递归法求解n皇后问题
{
	queen11(n,1);
} 

//-----------迭代解法------------------------ 
void queen2(int n)						//迭代法求解n皇后问题
{
	int i=1;							//i表示当前行,也表示放置第i个皇后
	q[i]=0;								//q[i]是当前列,从0列即开头试探
	while (i>=1)						//重复试探
	{
		q[i]++;
		while (q[i]<=n && !place(i,q[i]))	//试探一个位置(i,q[i])
			q[i]++;
		if (q[i]<=n)					//为第i个皇后找到了一个合适位置(i,q[i])
		{
			if (i==n)					//若放置了所有皇后,输出一个解
				disp(n);
			else						//皇后没有放置完
			{
				i++;					//转向下一行,即开始下一个皇后的放置
				q[i]=0;					//每次放一个新皇后,都从该行的列头进行试探
			}
		}
		else i--;						//若第i个皇后找不到合适的位置,则回溯到上一个皇后
	}
}

int main()
{	int n=6;								//n存放实际皇后个数
	printf("%d皇后问题求解如下:\n",n);
	queen1(n);
	return 0;
}
