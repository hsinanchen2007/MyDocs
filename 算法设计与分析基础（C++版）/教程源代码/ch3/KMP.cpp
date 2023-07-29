#include<iostream>
#include<vector>
#include<string>
using namespace std;
void getnext(string& t,vector<int>& next)
{	int j,k;
	j=0;k=-1;							//j����t��k��¼t[j]֮ǰ��t��ͷ��ͬ���ַ�����
	next[0]=k;							//����next[0]ֵ
	while (j<t.size()-1)				//��t����λ�õ�nextֵ
	{	if (k==-1 || t[j]==t[k]) 		//kΪ-1��Ƚϵ��ַ����ʱ
		{	j++;k++;					//j��k�����Ƶ���һ���ַ�
			next[j]=k;					//����next[j]Ϊk
		}
		else  k=next[k];					//k����
	}
}
int cnt=0;
int KMP(string s,string t)					//�ַ���ƥ��
{
	int n=s.size();
	int m=t.size();
	vector<int> next(m,-1);
	getnext(t,next);
	int i=0,j=0;
	while(i<n && j<m)
	{
		cnt++;
		if (j==-1 || s[i]==t[j])			//ƥ�䣬i��jͬʱ����ƶ�
		{
			i++;
			j++;
		}
		else								//��ƥ��
			j=next[j];						//jѰ��֮ǰƥ���λ��
    }
	if (j>=m)								//j����˵��t��s���Ӵ�
		return i-t.size();
    else									//����˵��t����s���Ӵ�
		return -1;
}

int main()
{
	string s="aaaabc";
	string t="aab";
	//string s="mississippi";
	//string t="issip";
	printf("%d\n",KMP(s,t));
	printf("cnt=%d\n",cnt);
	return 0;
}
