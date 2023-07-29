#include<iostream>
#include<vector>
#include<stack> 
using namespace std;
void disp(vector<int> &R,int low,int high)
{
	for (int i=low;i<=high;i++)
		printf("%d ",R[i]);
	printf("\n");
}

int Partition1(vector<int> &R,int s,int t)  	//划分算法1
{	int i=s,j=t;
 	int base=R[s];							//以表首元素为基准
 	while (i<j)								//从表两端交替向中间遍历,直至i=j为止
  	{	while (j>i && R[j]>=base)
      		j--;							//从后向前遍历,找一个小于等于基准的R[j]
    	if (j>i)
      	{	R[i]=R[j];						//R[j]前移覆盖R[i]
        	i++;
    	}
     	while (i<j && R[i]<=base)
      		i++;						//从前向后遍历,找一个大于基准的R[i]
     	if (i<j)
      	{	R[j]=R[i];					//R[i]后移覆盖R[j]
        	j--;
    	}
	}
 	R[i]=base;								//基准归位
 	return i;								//返回归位的位置
}

int Partition2(vector<int> &R,int s,int t)		//划分算法2
{	int i=s,j=s+1;
 	int base=R[s];							//以表首元素为基准
 	while (j<=t)							//j从s+1开始遍历其他元素
  	{	if (R[j]<=base)						//找到小于等于基准的元素R[j]
      	{	i++;							//扩大小于等于base的元素区间
        	if (i!=j)
         		swap(R[i],R[j]); 			//将R[i]与R[j]交换
    	}
    	j++;								//继续扫描
	}
	swap(R[s],R[i]);             			//将基准R[s]和R[i]进行交换
 	return i;
}
//---------递归算法--------------------
void QuickSort11(vector<int> &R,int s,int t)	//对R[s..t]的元素进行快速排序
{	if (s<t) 				 				//表中至少存在两个元素的情况
  	{	int i=Partition1(R,s,t);			//可以使用前面2种划分算法中的任意一种
  		printf("划分结果:"); disp(R,s,t); 
    	QuickSort11(R,s,i-1);			//对左子表递归排序
     	QuickSort11(R,i+1,t);			//对右子表递归排序
	}
}

void QuickSort1(vector<int> &R)				//递归算法：快速排序
{
	int n=R.size();
	QuickSort11(R,0,n-1);
}
//---------非递归算法--------------------
struct SNode					//栈元素类型
{
	int low;
	int high;
	SNode() {}								//构造函数 
	SNode(int l,int h):low(l),high(h) {} 	//重载构造函数 
};
void QuickSort2(vector<int> &R)				//非递归算法：快速排序
{
	stack<SNode> st;						//定义一个栈
	int n=R.size();
	st.push(SNode(0,n-1));
	while(!st.empty())						//栈不空循环
	{
		SNode e=st.top(); st.pop();			//出栈元素e
		if(e.low<e.high)
		{
			int i=Partition1(R,e.low,e.high);	//可以使用前面2种划分算法中的任意一种
			st.push(SNode(e.low,i-1));			//子问题1进栈 
			st.push(SNode(i+1,e.high));		//子问题2进栈
		}
	} 
} 
 
int main() 
{
    vector<int> a={2,5,1,7,10,6,9,4,3,8};
	//vector<int> a={9,8,7,6,5,4,3,2,1,0};
	int n=a.size();
	printf("排序前: "); disp(a,0,n-1); 
	QuickSort2(a);
	printf("排序后: "); disp(a,0,n-1); 
	return 0;
}
	

