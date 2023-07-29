#include<iostream>
#include<vector>
using namespace std;
int candidate(vector<int> &R)	//求候选多数元素 
{
	int c=R[0],cnt=1;
	int i=1;
	while(i<R.size())
	{
		if(R[i]==c)				//选择两个元素(R[i],c) 
			cnt++;				//相同时累加 
		else
			cnt--;				//不相同时递cnt，相当于删除这两个元素 
		if(cnt==0)				//cnt为0时对剩余元素从头开始查找 
		{
			i++;
			c=R[i];
			cnt++;
		}
		i++;
	}
	return c;
}
int majority(vector<int>& R)		//求多数元素
{
	if(R.size()==0 || R.size()==1)
		return -1;
	int c=candidate(R);
	int cnt=0;
	for(int i=0;i<R.size();i++)
		if(R[i]==c) cnt++;
	if(cnt>R.size()/2)
		return c;
	else
		return -1;
}
int main()
{
	vector<int> a={1,2,2};
	int c=majority(a);
	if(c!=-1)
		printf(" 多数元素=%d\n",majority(a));
	else
		printf(" 不存在多数元素\n");
	return 0;
}
