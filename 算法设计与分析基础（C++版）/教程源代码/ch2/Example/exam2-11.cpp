#include<iostream>
#include<vector>
#include<set>
using namespace std;
int topk(vector<int>&v,int k)			//����㷨 
{
	set<int,greater<int>> s;
	for(auto e:v)
		s.insert(e);
	auto it=s.begin();					//����s�ĵ����� 
	for(int i=1;i<k;i++)				//it����ƶ�k-1�� 
		it++;
	return *it;
}
	
int main()
{
	vector<int> v={1,4,6,2,5,6,3,2,1};
	printf("v: ");
	for(int i=0;i<v.size();i++)
		printf("%d ",v[i]);
	printf("\n");	
	for(int k=1;k<=6;k++)
		printf("��%d�������=%d\n",k,topk(v,k));
	return 0;
}
