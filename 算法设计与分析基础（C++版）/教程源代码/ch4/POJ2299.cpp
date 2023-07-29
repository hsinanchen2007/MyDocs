#include<iostream>
#include<vector>
using namespace std; 
long long ans; 											//���������
void Merge(vector<int> &R,int low,int mid,int high)
//��R[low..mid]��R[mid+1..high]��������ζ�·�鲢Ϊһ�������R[low..high]
{	vector<int> R1;
	R1.resize(high-low+1);							//����R1�ĳ���Ϊhigh-low+1
	int i=low,j=mid+1,k=0;							//k��R1���±�,i��j�ֱ�Ϊ��1��2�ε��±�
	while (i<=mid && j<=high)						//�ڵ�1�κ͵�2�ξ�δɨ����ʱѭ��
	{	if (R[i]>R[j])										//����2���е�Ԫ�ط���R1��
		{	R1[k]=R[j];
			ans+=mid-i+1;								//�ۼ�������
			j++; k++;
		}
		else													//����1���е�Ԫ�ط���R1��
		{	R1[k]=R[i];
			i++; k++;
		}
	}
	while (i<=mid)										//����1�����²��ָ��Ƶ�R1
	{	R1[k]=R[i];
		i++; k++;
	}
	while (j<=high)										//����2�����²��ָ��Ƶ�R1
	{	R1[k]=R[j];
		j++; k++;
	}
	for (k=0,i=low;i<=high;k++,i++)				//��R1���ƻ�R��
		R[i]=R1[k];
}
void MergeSort21(vector<int> &R,int s,int t)	//��MergeSort2����
{	if (s>=t) return;										//R[s..t]�ĳ���Ϊ0����1ʱ����
	int m=(s+t)/2;											//ȡ�м�λ��m
	MergeSort21(R,s,m);								//��ǰ�ӱ�����
	MergeSort21(R,m+1,t);							//�Ժ��ӱ�����
	Merge(R,s,m,t);										//�����������ӱ�ϲ���һ�������
}
void MergeSort2(vector<int> &R,int n)		//�Զ����µĶ�·�鲢����
{
	MergeSort21(R,0,n-1);
}
int main()
{	int n,x;
	while(scanf("%d",&n)!=EOF)
	{	if (n==0) break;
		vector<int> R;
		for (int i=0;i<n;i++)
		{	scanf("%d",&x);
			R.push_back(x);
		}
		ans=0;		
		MergeSort2(R,n);
		printf("%lld\n",ans);
	}
	return 0;
}

