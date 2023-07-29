#include<iostream>
#include<vector>
using namespace std;
void delodd1(vector<int>&v)		//解法1的算法
{	int k=0;					//k记录结果v中的元素个数 
	int i=0;
	while(i<v.size())
	{	if(v[i]%2==0)						//v[i]是偶数
		{	v[k]=v[i];						//将v[i]重新插入到结果v中
			k++;								//结果v的长度增1
		}
		i++;
	}
	v.resize(k);								//设置v的长度为k
}
void delodd2(vector<int>&v)		//解法2的算法
{	int k=0;						//k记录删除的元素个数 
	int i=0;
	while(i<v.size())
	{	if(v[i]%2==0)						//v[i]是偶数
			v[i-k]=v[i];						//将v[i]前移k个位置
		else								//v[i]是奇数
			k++;							//奇数元素个数增1
		i++;
	}
	v.resize(v.size()-k);					//设置v的长度为n-k
}

void delodd3(vector<int>&v)				//解法3的算法
{	int k=-1;								//v[0..k]表示偶数元素的区间 
	int i=0;
	while(i<v.size())
	{	if(v[i]%2==0)						//v[i]是偶数
		{	k++;							//扩大偶数区间 
			swap(v[k],v[i]);				//v[k]和v[i]交换
		}
		i++;
	}
	v.resize(k+1);							//设置v的长度为k+1
}

void disp(vector<int> &v)	//输出v的所有元素 
{
	for(auto e:v)
		printf("%d ",e);
	printf("\n");
}
int main()
{
	vector<int> v={2,1,4,5,1,2};
	printf("v: "); disp(v);
	printf("删除所有奇数\n"); 
	delodd3(v);
	printf("v: "); disp(v);		
	return 0;
}
