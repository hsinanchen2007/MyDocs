//�ݹ�ͷǵݹ��۰�����㷨
#include<iostream>
#include<vector>
using namespace std;
int BinSearch11(vector<int>&R,int low,int high,int k) //��BinSearch1����
{	if (low<=high)				//��ǰ�������Ԫ��ʱ
	{	int mid=(low+high)/2;		//�����������м�λ��
		if (k==R[mid])			//�ҵ��󷵻��±�mid
			return mid;
		if (k<R[mid])			//��k<R[mid]ʱ,���������еݹ����
			return BinSearch11(R,low,mid-1,k);
		else					//��k>R[mid]ʱ,���������еݹ����
			return BinSearch11(R,mid+1,high,k);
	}
	else return -1;			//����ǰ��������Ϊ��ʱ����-1
}
int BinSearch1(vector<int>&R,int k) 	//�ݹ���ֲ����㷨
{
	int n=R.size();
	return BinSearch11(R,0,n-1,k); 
} 

int BinSearch2(vector<int>&R,int k)	//�����㷨�����ֲ���
{	int low=0,high=R.size()-1;
	while (low<=high)			//��ǰ�������Ԫ��ʱѭ��
	{	int mid=(low+high)/2;		//�����������м�λ��
		if (k==R[mid])			//�ҵ��󷵻����±�mid
			return mid;
		if (k<R[mid])			//��k<R[mid]ʱ,���������еݹ����
			high=mid-1;
		else					//��k>R[mid]ʱ,���������еݹ����
			low=mid+1;
	}
	return -1;					//����ǰ��������û��Ԫ��ʱ����-1
}
int main()
{
	vector<int> a={1,2,3,4,5,6,7,8,9,10};
	int k=6;
	int i=BinSearch2(a,k);
	if (i>=0)
		printf("a[%d]=%d\n",i,k);
	else
		printf("δ�ҵ�%dԪ��\n",k);
	return 0;
}
