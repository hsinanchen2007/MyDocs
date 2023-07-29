#include<iostream>
#include<string>
using namespace std;
int cnt=0;
int BF(string s,string t)						//字符串匹配
{	int i=0,j=0;
	while (i<s.length() && j<t.length())
	{	cnt++;
		if (s[i]==t[j])							//比较的两个字符相同时
		{	i++;
			j++;
		}
		else										//比较的两个字符不相同时
		{	i=i-j+1;								//i回退到原i的下一个位置
			j=0;									//j从0开始
		}
	}
	if (j==t.length())							//t的字符比较完毕
		return i-j;								//t是s的子串,返回位置
	else											//t不是s的子串
		return -1;								//返回-1
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
