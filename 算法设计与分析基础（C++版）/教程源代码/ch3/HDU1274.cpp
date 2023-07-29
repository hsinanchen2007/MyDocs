#include<iostream>
#include<string>
using namespace std;
int i;
string unfold(string s)				//递归算法 
{
    string ans="";
    int n=0;
    for(;s[i];i++)
	{
        if(isdigit(s[i]))			//遇到数字 
			n=n*10+s[i]-'0';
        else if(isalpha(s[i]))		//遇到字母 
		{
            if(n>0)
            {
				while(n--)			//展开s[k]字符n次 
					ans+=s[i];
			}
            else ans+=s[i];			//展开s[k]字符1次
            n=0;
        }
        else if(s[i]=='(')			//遇到'('
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
		else 						//遇到')'
			return ans;				//结束并返回ans
    }
    return ans;						//s处理完毕返回ans 
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
    for(c=s[i++]; i<s.size() && c!=')'; c=s[i++]) //递归结束的条件是字符串结束或遇到右括号
    {
        for(int k=0;isdigit(c);c=s[i++])	//求数字 
            k=k*10+c-'0';
        if(k==0) k=1;
        if(c=='(')							//遇到'(' 
        {
            while(k--)
                e=fun(s,i,num+1);
            i=e;							//重置i的值，到下层递归结束的位置
        }
        else
        {
            while(k--)
                putchar(c);
        }
    }
    if(c==')') return i;			//返回本次读到结尾的位置
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
        fun(s,0,0);			//进入递归
        cout<<endl;
    }
    return 0;
}
*/
