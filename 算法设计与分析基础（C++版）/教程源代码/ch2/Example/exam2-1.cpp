#include<iostream>
#include<vector>
using namespace std;
void delodd1(vector<int>&v)		//�ⷨ1���㷨
{	int k=0;					//k��¼���v�е�Ԫ�ظ��� 
	int i=0;
	while(i<v.size())
	{	if(v[i]%2==0)						//v[i]��ż��
		{	v[k]=v[i];						//��v[i]���²��뵽���v��
			k++;								//���v�ĳ�����1
		}
		i++;
	}
	v.resize(k);								//����v�ĳ���Ϊk
}
void delodd2(vector<int>&v)		//�ⷨ2���㷨
{	int k=0;						//k��¼ɾ����Ԫ�ظ��� 
	int i=0;
	while(i<v.size())
	{	if(v[i]%2==0)						//v[i]��ż��
			v[i-k]=v[i];						//��v[i]ǰ��k��λ��
		else								//v[i]������
			k++;							//����Ԫ�ظ�����1
		i++;
	}
	v.resize(v.size()-k);					//����v�ĳ���Ϊn-k
}

void delodd3(vector<int>&v)				//�ⷨ3���㷨
{	int k=-1;								//v[0..k]��ʾż��Ԫ�ص����� 
	int i=0;
	while(i<v.size())
	{	if(v[i]%2==0)						//v[i]��ż��
		{	k++;							//����ż������ 
			swap(v[k],v[i]);				//v[k]��v[i]����
		}
		i++;
	}
	v.resize(k+1);							//����v�ĳ���Ϊk+1
}

void disp(vector<int> &v)	//���v������Ԫ�� 
{
	for(auto e:v)
		printf("%d ",e);
	printf("\n");
}
int main()
{
	vector<int> v={2,1,4,5,1,2};
	printf("v: "); disp(v);
	printf("ɾ����������\n"); 
	delodd3(v);
	printf("v: "); disp(v);		
	return 0;
}
