#include<iostream>
#include<vector>
using namespace std;
vector<int> x;					//������,ȫ�ֱ��� 
void disp(vector<int>&a)		//���һ����
{
	printf("   {");
	for (int i=0;i<x.size();i++)
		if (x[i]==1)
			printf("%d",a[i]);
	printf("}");
}
void dfs(vector<int>&a,int i)	//�ݹ�����㷨
{
	if (i>=a.size())
		disp(a);
	else
	{
		x[i]=1;
		dfs(a,i+1);				//ѡ��a[i]
		x[i]=0;
		dfs(a,i+1);				//��ѡ��a[i]
	}
}
void subsets(vector<int>&a)		//��a���ݼ�
{
	int n=a.size();
	x.resize(n);				//ָ��x�ĳ���Ϊn
	dfs(a,0);
} 
int main()
{
	vector<int> a{1,2,3};
	vector<int> x(a.size(),0);		//����������ʼ��Ϊ0 
	printf("�����\n");
	subsets(a);
	printf("\n");
	return 0; 
}
