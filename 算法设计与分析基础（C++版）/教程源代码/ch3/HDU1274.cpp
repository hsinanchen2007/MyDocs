#include<iostream>
#include<string>
using namespace std;
int i;
string unfold(string s)				//�ݹ��㷨 
{
    string ans="";
    int n=0;
    for(;s[i];i++)
	{
        if(isdigit(s[i]))			//�������� 
			n=n*10+s[i]-'0';
        else if(isalpha(s[i]))		//������ĸ 
		{
            if(n>0)
            {
				while(n--)			//չ��s[k]�ַ�n�� 
					ans+=s[i];
			}
            else ans+=s[i];			//չ��s[k]�ַ�1��
            n=0;
        }
        else if(s[i]=='(')			//����'('
		{
            i++;
            string tmp=unfold(s);
            if(n>0)
			{ 
            	while(n--)
					ans+=tmp;
			}
			else ans+=tmp;
            n=0;
        }
		else 						//����')'
			return ans;				//����������ans
    }
    return ans;						//s������Ϸ���ans 
}
int main()
{
    int t;
    cin >> t;
    while(t--)
	{
        string s;
        cin >> s;       
        i=0;
        cout << unfold(s) << endl;
    }
    return 0;
}


/*
#include <iostream>
#include <string>
using namespace std;
int fun(string s,int i,int num)
{
    int k,e;
    char c;
    for(c=s[i++]; i<s.size() && c!=')'; c=s[i++]) //�ݹ�������������ַ�������������������
    {
        for(int k=0;isdigit(c);c=s[i++])	//������ 
            k=k*10+c-'0';
        if(k==0) k=1;
        if(c=='(')							//����'(' 
        {
            while(k--)
                e=fun(s,i,num+1);
            i=e;							//����i��ֵ�����²�ݹ������λ��
        }
        else
        {
            while(k--)
                putchar(c);
        }
    }
    if(c==')') return i;			//���ر��ζ�����β��λ��
}
int main()
{
    int i,j,k,T;
    string s;
    cin >> T;
    while(T--)
    {
        s.clear();
        cin >> s;
        fun(s,0,0);			//����ݹ�
        cout<<endl;
    }
    return 0;
}
*/
