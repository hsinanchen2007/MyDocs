#include<iostream>
#include<string>
using namespace std;
int cnt=0;
int BF(string s,string t)						//�ַ���ƥ��
{	int i=0,j=0;
	while (i<s.length() && j<t.length())
	{	cnt++;
		if (s[i]==t[j])							//�Ƚϵ������ַ���ͬʱ
		{	i++;
			j++;
		}
		else										//�Ƚϵ������ַ�����ͬʱ
		{	i=i-j+1;								//i���˵�ԭi����һ��λ��
			j=0;									//j��0��ʼ
		}
	}
	if (j==t.length())							//t���ַ��Ƚ����
		return i-j;								//t��s���Ӵ�,����λ��
	else											//t����s���Ӵ�
		return -1;								//����-1
}
int main()
{
	string s="aaaabc";
	string t="aab";
	//string s="mississippi";
	//string t="issip";
	printf("%d\n",BF(s,t));
	printf("cnt=%d\n",cnt);
	return 0;
}
