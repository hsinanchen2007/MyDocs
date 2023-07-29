#include<iostream>
#include<vector>
using namespace std;
void Insert(vector<int>&R,int i)		//��R[i]������뵽R[0..i-1]��
{
	int tmp=R[i];
	int j=i-1; 
	do									//��R[i]�Ĳ���λ��
	{	R[j+1]=R[j];   					//���ؼ��ִ���R[i]��Ԫ�غ���
		j--;
	} while(j>=0 && R[j]>tmp);			//ֱ��R[j]<=tmpΪֹ 
	R[j+1]=tmp;      					//��j+1������R[i]
}
/********************************************/
/***�����㷨*****************************/
/********************************************/
void InsertSort1(vector<int> &R) 		//�����㷨��ֱ�Ӳ�������
{	int n=R.size();
	for (int i=1;i<n;i++) 
	{	if (R[i]<R[i-1])				//����ʱ
			Insert(R,i);
	}
}

/********************************************/
/***�ȵݺ���㷨*****************************/
/********************************************/

void InsertSort21(vector<int> &R,int i) //�ݹ�ֱ�Ӳ�������
{
	if(i==0) return;
	InsertSort21(R,i-1);
	if (R[i]<R[i-1])					//����ʱ
		Insert(R,i);
}
void InsertSort2(vector<int> &R) 		//�ݹ��㷨��ֱ�Ӳ�������
{
	int n=R.size();
	InsertSort21(R,n-1);
}

/*
/********************************************/
/***�ȺϺ���㷨*****************************/
/********************************************/

void InsertSort31(vector<int> &R,int i) //�ݹ�ֱ�Ӳ�������
{
	int n=R.size();
	if(i<1 || i>n-1) return;
	if (R[i]<R[i-1])					//����ʱ
		Insert(R,i);
	InsertSort31(R,i+1);
}
void InsertSort3(vector<int> &R) 		//�ݹ��㷨��ֱ�Ӳ�������
{
	InsertSort31(R,1);
}

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
	InsertSort2(a);
	printf("a: "); disp(a);
	return 0;
}
