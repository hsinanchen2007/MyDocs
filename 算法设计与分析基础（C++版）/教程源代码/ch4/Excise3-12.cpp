#include<iostream>
#include<vector>
using namespace std;
bool exist1(vector<int>& a,int x)						//�����㷨
{	int low=0,high=a.size()-1;
	while(low<high)
	{	int c=a[low]+a[high];
		if(c==x)
			return true;
		else if(c<x)
			low++;
		else
			high++;
	}
	return false;
}
bool exist21(vector<int>& a,int low,int high,int x)
{	if (low>=high)
		return false;
	int c=a[low]+a[high];
	if(c==x)
		return true;
	else if(c<x)
		return exist21(a,low+1,high,x);
	else
		return exist21(a,low,high-1,x);
}
bool exist2(vector<int>& a,int x)					//�ݹ��㷨
{
	return exist21(a,0,a.size()-1,x);
}
int main()
{
	vector<int> a={1,3,5,5,8,9};
	int x=10;
	printf("�ⷨ1:\n");
	printf("    ���=%d\n",exist1(a,x)); 
	printf("�ⷨ2:\n");
	printf("    ���=%d\n",exist2(a,x));
	return 0;
}
