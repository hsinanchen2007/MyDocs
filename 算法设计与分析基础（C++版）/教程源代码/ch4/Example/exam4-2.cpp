#include<iostream>
#include<vector>
using namespace std;
int insertpoint(vector<int>& R,int k)
{	int n=R.size();
	int low=0,high=n;
	while (low<high)							//�����������ٺ�����Ԫ�� 
	{
		printf("[%d..%d]\n",low,high);
		int mid=(low+high)/2;
		if (k<=R[mid])							//k<=R[mid]
			high=mid;							//���������в���(��R[mid]) 
		else
			low=mid+1;							//���������в���
	}
	
	printf("end:[%d..%d]\n",low,high);
	return low;									//����low
}
int main()
{
	vector<int> a={1,2,2,4};
	int k=5;
	int i=insertpoint(a,k);
	printf("%d�Ĳ����=%d\n",k,i);
	return 0;
}
