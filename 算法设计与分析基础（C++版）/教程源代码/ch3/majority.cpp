#include<iostream>
#include<vector>
using namespace std;
int candidate(vector<int> &R)	//���ѡ����Ԫ�� 
{
	int c=R[0],cnt=1;
	int i=1;
	while(i<R.size())
	{
		if(R[i]==c)				//ѡ������Ԫ��(R[i],c) 
			cnt++;				//��ͬʱ�ۼ� 
		else
			cnt--;				//����ͬʱ��cnt���൱��ɾ��������Ԫ�� 
		if(cnt==0)				//cntΪ0ʱ��ʣ��Ԫ�ش�ͷ��ʼ���� 
		{
			i++;
			c=R[i];
			cnt++;
		}
		i++;
	}
	return c;
}
int majority(vector<int>& R)		//�����Ԫ��
{
	if(R.size()==0 || R.size()==1)
		return -1;
	int c=candidate(R);
	int cnt=0;
	for(int i=0;i<R.size();i++)
		if(R[i]==c) cnt++;
	if(cnt>R.size()/2)
		return c;
	else
		return -1;
}
int main()
{
	vector<int> a={1,2,2};
	int c=majority(a);
	if(c!=-1)
		printf(" ����Ԫ��=%d\n",majority(a));
	else
		printf(" �����ڶ���Ԫ��\n");
	return 0;
}
