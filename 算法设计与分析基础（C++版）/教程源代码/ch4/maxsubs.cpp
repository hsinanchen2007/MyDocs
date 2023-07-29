//���������������к͵��㷨
#include<iostream>
#include<vector>
using namespace std;
int max3(int a,int b,int c)				//���3��int�����е����ֵ
{
	return max(max(a,b),c);
} 
int maxSubSum31(vector<int>&a,int low,int high)	//��maxSubSum3����
{
	if (low==high)						//������ֻ��һ��Ԫ��ʱ
	{	if (a[low]>0) 					//��Ԫ�ش���0ʱ������
			return a[low];
		else								//��Ԫ��С�ڻ����0ʱ����0
			return 0; 
	} 
	int mid=(low+high)/2;					//���м�λ��
	int maxLeftSum=maxSubSum31(a,low,mid);		//����ߵ��������������֮��
	int maxRightSum=maxSubSum31(a,mid+1,high);	//���ұߵ��������������֮��

	int maxLeftBorderSum=0,lowBorderSum=0;
	for (int i=mid;i>=low;i--)				//�������߼���a[mid]���ɵ��������е�����
	{	lowBorderSum+=a[i];
		if (lowBorderSum>maxLeftBorderSum)
			maxLeftBorderSum=lowBorderSum;
	}
	int maxRightBorderSum=0,highBorderSum=0;
	for (int j=mid+1;j<=high;j++)			//���a[mid]�ұ�Ԫ�ع��ɵ��������е�����
	{	highBorderSum+=a[j];
		if (highBorderSum>maxRightBorderSum)
			maxRightBorderSum=highBorderSum;
	}
	int ans=max3(maxLeftSum,maxRightSum,maxLeftBorderSum+maxRightBorderSum); 
	return max(ans,0);
}
int maxSubSum3(vector<int>&a)		//�ݹ��㷨����a������������������к�
{
	int n=a.size();
	return maxSubSum31(a,0,n-1);
}

int main()
{	vector<int> a{-2,11,-4,13,-5,-2};
	vector<int> b={-6,2,4,-7,5,3,2,-1,6,-9,10,-2};
	printf("a���е�������������еĺ�: %d\n",maxSubSum3(a));
	printf("b���е�������������еĺ�: %d\n",maxSubSum3(b));
	return 0;
}
