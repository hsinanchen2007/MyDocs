#include<iostream>
#include<vector>
using namespace std;

void disp(vector<vector<int>> ans)			//����ݼ� 
{
	printf("    ");
	for(auto it=ans.begin();it!=ans.end();it++)
	{
		if((*it).size()==0)
			printf("[]  ");
		else
		{
			printf("[");
		   	for(int j=0;j<(*it).size();j++)
		   		if(j==0)
				printf("%d",(*it)[j]);
			else
				printf(" %d",(*it)[j]);
			printf("]  ");
		}
	}
	printf("\n");
}
vector<vector<int>> appendi(vector<vector<int>> Mi_1,int i)	//��Mi_1��ÿ������Ԫ��ĩβ���i
{
	vector<vector<int>> Ai=Mi_1;
	for(int j=0;j<Ai.size();j++)
		Ai[j].push_back(i);
	return Ai;	
}
vector<vector<int>> subsets1(int n)			//�����㷨 
{
	vector<vector<int>> Mi;					//���{1-n}���ݼ�
	vector<vector<int>> Mi_1={{},{1}};		//���M1
	for(int i=2;i<=n;i++)
    {
    	vector<vector<int>> Ai=appendi(Mi_1,i);
    	Mi=Mi_1;
        for(int j=0;j<Ai.size();j++)          //��Ai���м���Ԫ����ӵ�Mi��
        	Mi.push_back(Ai[j]);
        Mi_1=Mi;
	}
	return Mi;
}
/* 
vector<vector<int>> pset(vector<vector<int>> M,int n,int i)		//�ݹ��㷨 
{
	vector<vector<int>> A=appendi(M,i);			//��A 
   	for(int j=0;j<A.size();j++)          		//��A���м���Ԫ����ӵ�M��
   		M.push_back(A[j]);
   	if(i==n)									//�Ѿ�������ʱ����M 
   		return M;
   	else										//����ݹ���� 
		return pset(M,n,i+1);
}
vector<vector<int>> subsets2(int n)			//�ݹ��㷨 
{
	vector<vector<int>> M={{},{1}};			//M���{1-n}���ݼ�,��ʼʱ��ΪM1
	if(n==1)
		return M;
	else
		return pset(M,n,2);
}
*/

vector<vector<int>> pset(int n,int i)				//�ݹ��㷨 
{
	if(i==1)
		return {{},{1}};
	else
	{	vector<vector<int>> Mi_1=pset(n,i-1);		//�ݹ����Mi_1 
		vector<vector<int>> Mi=Mi_1;				//Mi��ΪMi_1 
		vector<vector<int>> Ai=appendi(Mi_1,i);		//��Ai,appendi�㷨�μ�3.3.3��
   		for(int j=0;j<Ai.size();j++)          		//��Ai���м���Ԫ����ӵ�Mi��
   			Mi.push_back(Ai[j]);
   		return Mi;									//����Mi 
   }
}

vector<vector<int>> subsets2(int n)				//�ݹ��㷨 
{
	return pset(n,n);
}

int main()
{
	int n=3;
	vector<vector<int>> ans;
	printf("{1-%d}���ݼ�����:\n",n); 
	printf("�ⷨ1\n"); 
	ans=subsets1(n);
	disp(ans);
	printf("�ⷨ2\n"); 
	ans=subsets2(n);
	disp(ans);
	return 0;
}
