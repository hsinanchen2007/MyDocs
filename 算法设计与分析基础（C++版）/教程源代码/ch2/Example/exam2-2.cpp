#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int topk1(vector<int> &v,int k)		//解法1的算法 
{
	sort(v.begin(),v.end());		//将v中所有元素递增排序 
	return v[v.size()-k];
}
int topk2(vector<int> &v,int k)		//解法2的算法 
{
	sort(v.begin(),v.end(),greater<int>());		//将v中所有元素递减排序
	return v[k-1];
}
void disp(vector<int> &v)	//输出v的所有元素 
{
	for(auto e:v)
		printf("%d ",e);
	printf("\n");
}

int main()
{
	vector<int> v={2,3,2,4,3};
	printf("v: "); disp(v);
	for(int k=1;k<=v.size();k++)
		printf("第%d大的整数:%d\n",k,topk2(v,k)); 
	return 0;
}
