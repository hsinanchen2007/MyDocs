#include<iostream>
#include<vector>
#include<stack> 
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

int Partition2(vector<int> &R,int s,int t)		//�����㷨2
{	int i=s,j=s+1;
 	int base=R[s];							//�Ա���Ԫ��Ϊ��׼
 	while (j<=t)							//j��s+1��ʼ��������Ԫ��
  	{	if (R[j]<=base)						//�ҵ�С�ڵ��ڻ�׼��Ԫ��R[j]
      	{	i++;							//����С�ڵ���base��Ԫ������
        	if (i!=j)
         		swap(R[i],R[j]); 			//��R[i]��R[j]����
    	}
    	j++;								//����ɨ��
	}
	swap(R[s],R[i]);             			//����׼R[s]��R[i]���н���
 	return i;
}
//---------�ݹ��㷨--------------------
void QuickSort11(vector<int> &R,int s,int t)	//��R[s..t]��Ԫ�ؽ��п�������
{	if (s<t) 				 				//�������ٴ�������Ԫ�ص����
  	{	int i=Partition1(R,s,t);			//����ʹ��ǰ��2�ֻ����㷨�е�����һ��
  		printf("���ֽ��:"); disp(R,s,t); 
    	QuickSort11(R,s,i-1);			//�����ӱ�ݹ�����
     	QuickSort11(R,i+1,t);			//�����ӱ�ݹ�����
	}
}

void QuickSort1(vector<int> &R)				//�ݹ��㷨����������
{
	int n=R.size();
	QuickSort11(R,0,n-1);
}
//---------�ǵݹ��㷨--------------------
struct SNode					//ջԪ������
{
	int low;
	int high;
	SNode() {}								//���캯�� 
	SNode(int l,int h):low(l),high(h) {} 	//���ع��캯�� 
};
void QuickSort2(vector<int> &R)				//�ǵݹ��㷨����������
{
	stack<SNode> st;						//����һ��ջ
	int n=R.size();
	st.push(SNode(0,n-1));
	while(!st.empty())						//ջ����ѭ��
	{
		SNode e=st.top(); st.pop();			//��ջԪ��e
		if(e.low<e.high)
		{
			int i=Partition1(R,e.low,e.high);	//����ʹ��ǰ��2�ֻ����㷨�е�����һ��
			st.push(SNode(e.low,i-1));			//������1��ջ 
			st.push(SNode(i+1,e.high));		//������2��ջ
		}
	} 
} 
 
int main() 
{
    vector<int> a={2,5,1,7,10,6,9,4,3,8};
	//vector<int> a={9,8,7,6,5,4,3,2,1,0};
	int n=a.size();
	printf("����ǰ: "); disp(a,0,n-1); 
	QuickSort2(a);
	printf("�����: "); disp(a,0,n-1); 
	return 0;
}
	

