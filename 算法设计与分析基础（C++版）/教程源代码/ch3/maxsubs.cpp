#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxSubSum1(vector<int>& a)			//�ⷨ1
{
	int n=a.size();
	int maxsum=0,cursum;
	for (int i=0;i<n;i++)				//����ѭ��������е�����������
	{	for (int j=i;j<n;j++)
		{	cursum=0;
			for (int k=i;k<=j;k++)
				cursum+=a[k];
			maxsum=max(maxsum,cursum);	//ͨ���Ƚ������maxsum
		}
	}
	return maxsum;
}
int maxSubSum2(vector<int>& a)			//�ⷨ2
{
	int n=a.size();
	int maxsum=0,cursum;
	for (int i=0;i<n;i++)  
	{	cursum=0;
		for (int j=i;j<n;j++)
		{	cursum+=a[j];
			maxsum=max(maxsum,cursum);	//ͨ���Ƚ������maxsum
		}
	}
	return maxsum;
}

int maxSubSum3(vector<int>& a)			//�ⷨ3
{
	int n=a.size();
	int maxsum=0,cursum=0;
	for (int i=0;i<n;i++)  
	{
		cursum+=a[i];
		maxsum=max(maxsum,cursum);		//ͨ���Ƚ������maxsum
		if(cursum<0)					//��cursum<0��������������д���һ��λ�ÿ�ʼ 
			cursum=0;
	}
	return maxsum;
}

int main()
{	vector<int> a={-2,11,-4,13,-5,-2};
	vector<int> b={-6,2,4,-7,5,3,2,-1,6,-9,10,-2};
	printf("a: ");
	for(int i=0;i<a.size();i++)
		printf("%d ",a[i]);
	printf("\n"); 
	printf("  �ⷨ1��������������еĺ�: %d\n",maxSubSum1(a));
	printf("  �ⷨ2��������������еĺ�: %d\n",maxSubSum2(a));
	printf("  �ⷨ3��������������еĺ�: %d\n",maxSubSum3(a));

	printf("b: ");
	for(int i=0;i<b.size();i++)
		printf("%d ",b[i]);
	printf("\n"); 
	printf("  �ⷨ1��������������еĺ�: %d\n",maxSubSum1(b));
	printf("  �ⷨ2��������������еĺ�: %d\n",maxSubSum2(b));
	printf("  �ⷨ3��������������еĺ�: %d\n",maxSubSum3(b));

	return 0;
	
}

