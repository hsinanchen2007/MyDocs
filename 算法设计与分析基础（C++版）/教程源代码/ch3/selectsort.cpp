#include<iostream>
#include<vector>
using namespace std;

/********************************************/
/***�����㷨*****************************/
/********************************************/
void Select(vector<int>& R,int i)				//��R[i..n-1]��ѡ����СԪ�ؽ�����R[i]λ��
{
	int minj=i;									//minj��ʾR[i..n-1]����СԪ�ص��±�
	for (int j=i+1;j<R.size();j++)				//��R[i..n-1]������СԪ��
		if (R[j]<R[minj])
			minj=j;
	if (minj!=i)								//����СԪ�ز���R[i]
		swap(R[minj],R[i]);						//����
}

void SelectSort1(vector<int>& R)				//����������ѡ������
{	int n=R.size();
	for (int i=0;i<n-1;i++)		//����n-1������
		Select(R,i);
}


/********************************************/
/***�ȵݺ���㷨*****************************/
/********************************************/
void SelectSort21(vector<int>& R,int i)			//�ݹ�ļ�ѡ������
{
	if (i==-1) return;							//����ݹ��������
	SelectSort21(R,i-1);
	Select(R,i);
}
void SelectSort2(vector<int>& R)				//�ݹ�ļ�ѡ������
{
	SelectSort21(R,R.size()-2);
}


/********************************************/
/***�ȺϺ���㷨*****************************/
/********************************************/
void SelectSort31(vector<int>& R,int i)			//�ݹ�ļ�ѡ������
{
	int n=R.size();
	if (i==n-1) return;							//����ݹ��������
	Select(R,i);
	SelectSort31(R,i+1);
}

void SelectSort3(vector<int>& R)				//�ݹ�ļ�ѡ������
{
	SelectSort31(R,0);
}
	
/********************************************/

void disp(vector<int>&a)
{
	for(int i=0;i<a.size();i++)
		printf("%d ",a[i]);
	printf("\n");
}


int main()
{
	vector<int> a={2,5,4,1,3};
	printf("a: "); disp(a);
	printf("����\n");
	SelectSort3(a);
	printf("a: "); disp(a);
	return 0;
}
