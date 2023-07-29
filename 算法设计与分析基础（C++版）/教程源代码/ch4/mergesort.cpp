#include<iostream>
#include<vector>
using namespace std;
void disp(vector<int>&R)			//���a������Ԫ��
{
	for (int i=0;i<R.size();i++)
		printf("%d ",R[i]);
	printf("\n");
}

void Merge(vector<int>&R,int low,int mid,int high)
//��R[low..mid]��R[mid+1..high]�������ڵ����������й鲢Ϊ����������R[low..high]
{	vector<int> R1;
	int i=low,j=mid+1;			//i��j�ֱ�Ϊ�����ӱ���±�
	while (i<=mid && j<=high)	//���ӱ�1���ӱ�2��δ������ʱѭ��
		if (R[i]<=R[j])			//���ӱ�1�е�Ԫ�ع鲢��R1
		{	R1.push_back(R[i]);
			i++; 
		}
		else					//���ӱ�2�е�Ԫ�ع鲢��R1
		{	R1.push_back(R[j]);
			j++; 
		}
	while (i<=mid)					//���ӱ�1����Ԫ�ظı䵽R1
	{	R1.push_back(R[i]);
		i++; 
	}
	while (j<=high)					//���ӱ�2����Ԫ�ظı䵽R1
	{	R1.push_back(R[j]);
		j++;;
	}
	for (int k=0,i=low;i<=high;k++,i++) 	//��R1���ƻ�R��
		R[i]=R1[k];
}
//****�Ե����ϵĶ�·�鲢�����㷨***************
void MergePass(vector<int>&R,int length)	//һ�˶�·�鲢����
{	int i,n=R.size();
	for (i=0;i+2*length-1<n;i=i+2*length)	//�鲢length�����������ӱ�
		Merge(R,i,i+length-1,i+2*length-1);
	if (i+length-1<n)						//���������ӱ�,���߳���С��length
		Merge(R,i,i+length-1,n-1);			//�鲢�������ӱ�
}
void MergeSort1(vector<int>&R)				//�Ե����ϵĶ�·�鲢�㷨
{	for (int length=1;length<R.size();length=2*length)
		MergePass(R,length);
}
//****�Զ����µĶ�·�鲢�����㷨***************
void MergeSort21(vector<int>&R,int low,int high)	//��MergeSort2����
{
	if (low<high)					//������������������Ԫ��
	{	int mid=(low+high)/2;			//ȡ�м�λ��
		MergeSort21(R,low,mid);		//��a[low..mid]����������
		MergeSort21(R,mid+1,high);	//��a[mid+1..high]����������
		Merge(R,low,mid,high);		//���������кϲ�,��ǰ����㷨
	}
}
void MergeSort2(vector<int>&R)				//��·�鲢�㷨
{	int n=R.size();
	MergeSort21(R,0,n-1);
} 
int main()
{
	vector<int> a={2,5,1,7,10,6,9,4,3,8};
	//vector<int> a={6,2,1,4,5,3};
	printf("����ǰ:"); disp(a);
	MergeSort2(a);
	printf("�����:"); disp(a);
	return 0;
}

