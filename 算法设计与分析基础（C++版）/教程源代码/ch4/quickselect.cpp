#include<iostream>
#include<vector>
using namespace std;
void disp(vector<int> &R,int low,int high)
{
	for (int i=low;i<=high;i++)
		printf("%d ",R[i]);
	printf("\n");
}
int Partition1(vector<int> &R,int s,int t)  	//�����㷨1
{	int i=s,j=t;
 	int base=R[s];							//�Ա���Ԫ��Ϊ��׼
 	while (i<j)								//�ӱ����˽������м����,ֱ��i=jΪֹ
  	{	while (j>i && R[j]>=base)
      		j--;							//�Ӻ���ǰ����,��һ��С�ڵ��ڻ�׼��R[j]
    	if (j>i)
      	{	R[i]=R[j];						//R[j]ǰ�Ƹ���R[i]
        	i++;
    	}
     	while (i<j && R[i]<=base)
      		i++;						//��ǰ������,��һ�����ڻ�׼��R[i]
     	if (i<j)
      	{	R[j]=R[i];					//R[i]���Ƹ���R[j]
        	j--;
    	}
	}
 	R[i]=base;								//��׼��λ
 	return i;								//���ع�λ��λ��
}
int QuickSelect11(vector<int>&R,int s,int t,int k)	//��QuickSelect1����
{
	if (s<t) 								//���������ٴ���2��Ԫ�ص����
	{
		int i=Partition1(R,s,t);			//����ʹ��ǰ�����ֻ����㷨�е�����һ��

		printf("���ֽ��i=%d: ",i);
		for(int j=0;j<5;j++)
			printf("%3d",R[j]); 
		printf("\n");

		if (k-1==i)
		{
			printf("k=i-1�ҵ�\n"); 
			return R[i];
		}
		else if(k-1<i)
		{
			printf("��R[%d..%d]�в���\n",s,i-1); 
			return QuickSelect11(R,s,i-1,k);			//���������еݹ����
		}
		else
		{
			printf("��R[%d..%d]�в���\n",i+1,t); 
			return QuickSelect11(R,i+1,t,k);			//���������еݹ����
		}
	}
	else if (s==t && s==k-1)					//������ֻ��һ��Ԫ����s=k-1
	{
		printf("һ��Ԫ��\n"); 
		return R[k-1];
	}
}
int QuickSelect1(vector<int>&R,int k)		//�ݹ��㷨����R�ҵ�kС��Ԫ��
{
	int n=R.size();
	return QuickSelect11(R,0,n-1,k);
}

int main()
{
	vector<int> a{2,5,1,4,3};
	int k=3;
	int e=QuickSelect1(a,k);
	printf("��%dС��Ԫ��:%d\n",k,e);
	return 0;
}

/* 
int main()
{
	vector<int> a{2,5,1,7,10,6,9,4,3,8};
	for (int k=1;k<=a.size();k++)
	{	int e=QuickSelect(a,k);
		printf("��%dС��Ԫ��:%d\n",k,e);
	}
	return 0;
}
*/

