#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int Count(vector<int>&v)		//����㷨 
{
	unordered_set<int> s;
	for(auto e:v)
		s.insert(e);
	return s.size();
}
	
int main()
{
	vector<int> v={1,4,6,2,5,6,3,2,1,5,4};
	printf("v: ");
	for(int i=0;i<v.size();i++)
		printf("%d ",v[i]);
	printf("\n");		
	printf("v�в�ͬ��Ԫ�ظ����� %d",Count(v));
	return 0;
}
