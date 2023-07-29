#include<iostream>
#include<vector>
using namespace std;

void disp(vector<int>&a)
{
	for(int i=0;i<a.size();i++)
		printf("%d ",a[i]);
	printf("\n");
}

void Bubble(vector<int>& R,int i,bool& exchange)	//��R[i..n-1]��ð����СԪ�ص�R[i]λ��
{
	int n=R.size();
	for (int j=n-1;j>i;j--)							//������Ԫ�رȽ�,�ҳ���СԪ��
		if (R[j-1]>R[j])							//������Ԫ�ط���ʱ
		{	swap(R[j],R[j-1]);						//a[j]��a[j-1]���н���
			exchange=true;							//����������������exchangeΪtrue
		}
}
/********************************************/
/***�����㷨*****************************/
/********************************************/
void BubbleSort1(vector<int>& R)		//�����㷨��ð������
{
	int n=R.size();
	bool exchange;
	for (int i=0;i<n-1;i++)			//����n-1������
	{	exchange=false;				//��������ǰ��exchangeΪfalse
		Bubble(R,i,exchange);
		if (exchange==false)		//����δ��������ʱ�����㷨
			return;
	}
}


/********************************************/
/***�ȵݺ���㷨*****************************/
/********************************************/

void Bubble1(vector<int>& R,int i)				//��R[i..n-1]��ð����СԪ�ص�R[i]λ��
{
	int n=R.size();
	for (int j=n-1;j>i;j--)						//������Ԫ�رȽ�,�ҳ���СԪ��
		if (R[j-1]>R[j])						//������Ԫ�ط���ʱ
			swap(R[j],R[j-1]);					//R[j]��R[j-1]���н���
}

void BubbleSort21(vector<int>& R,int i)			//�ݹ��ð������
{
	if (i==-1) return;							//����ݹ��������
	BubbleSort21(R,i-1);						//�ݹ���� 
	Bubble1(R,i);
}
void BubbleSort2(vector<int>& R)				//�ݹ�ð������ 
{
	int n=R.size();
	BubbleSort21(R,n-2);
}


/********************************************/
/***�ȺϺ���㷨*****************************/
/********************************************/

void BubbleSort31(vector<int>& R,int i)			//�ݹ�ļ�ѡ������
{
	int n=R.size();
	if (i==n-1) return;							//����ݹ��������
	Bubble1(R,i);								//�ݹ���� 
	BubbleSort31(R,i+1);
}

void BubbleSort3(vector<int>& R)				//�ݹ�ð������
{
	BubbleSort31(R,0);
}
	
/********************************************/



int main()
{
	vector<int> a={2,5,4,1,3};
	printf("a: "); disp(a);
	printf("����\n");
	BubbleSort3(a);
	printf("a: "); disp(a);
	return 0;
}
