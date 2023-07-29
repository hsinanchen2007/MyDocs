#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int topk1(vector<int> &v,int k)		//�ⷨ1���㷨 
{
	sort(v.begin(),v.end());		//��v������Ԫ�ص������� 
	return v[v.size()-k];
}
int topk2(vector<int> &v,int k)		//�ⷨ2���㷨 
{
	sort(v.begin(),v.end(),greater<int>());		//��v������Ԫ�صݼ�����
	return v[k-1];
}
void disp(vector<int> &v)	//���v������Ԫ�� 
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
		printf("��%d�������:%d\n",k,topk2(v,k)); 
	return 0;
}
