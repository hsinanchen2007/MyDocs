#include<iostream>
#include<string>
#include<vector>
using namespace std;
int Count1(string s,string t)	//�ⷨ1
{	int cnt=0;				//�ۼƳ��ִ���
	int n=s.size(),m=t.size();
	int i=0,j=0;
	while (i<n && j<m)
	{	if (s[i]==t[j])		//�Ƚϵ������ַ���ͬʱ
		{	i++; 
			j++;
		}
		else					//�Ƚϵ������ַ�����ͬʱ
		{	i=i-j+1;			//i����
			j=0;				//j��0��ʼ
		}
		if(j>=m)
		{	cnt++;			//���ִ�����1
			j=0;				//j��0��ʼ����
		}
	}
	return cnt;
}
void getnext(string& t,vector<int>& next)		//��t��next���� 
{	int j,k;
	j=0;k=-1;									//j����t��k��¼t[j]֮ǰ��t��ͷ��ͬ���ַ�����
	next[0]=k;									//����next[0]ֵ
	while (j<t.size()-1)						//��t����λ�õ�nextֵ
	{	if (k==-1 || t[j]==t[k]) 				//kΪ-1��Ƚϵ��ַ����ʱ
		{	j++;k++;							//j��k�����Ƶ���һ���ַ�
			next[j]=k;							//����next[j]Ϊk
		}
		else  k=next[k];						//k����
	}
}
int Count2(string s,string t)			//�ⷨ2
{	int cnt=0;							//�ۼƳ��ִ���
	int n=s.size(),m=t.size();
	vector<int> next(m,-1);
	getnext(t,next);
	int i=0,j=0;
	while(i<n)
	{	if (j==-1 || s[i]==t[j])		//ƥ�䣬i��jͬʱ����ƶ�
		{	i++;
			j++;
		}
		else							//��ƥ��
			j=next[j];					//jѰ��֮ǰƥ���λ��
		if (j>=m)						//�ɹ�ƥ��һ��
		{
			cnt++;
			j=0;						//ƥ��ɹ���t��ͷ��ʼ�Ƚ� 
		}
 	}
	return cnt;
}

int main()
{
	//string s="abababa";
	//string t="aba";
	string s="aaaaa";
	string t="aa";
	printf("�ⷨ1\n"); 
	cout << "  " << t << "��" << s << "�г��ִ���=" << Count1(s,t) << endl;
	printf("�ⷨ2\n"); 
	cout << "  " << t << "��" << s << "�г��ִ���=" << Count2(s,t) << endl;
	return 0;
}
