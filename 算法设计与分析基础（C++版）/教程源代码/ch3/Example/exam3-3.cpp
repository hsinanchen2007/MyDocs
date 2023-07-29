#include<iostream>
#include<string>
#include<vector>
using namespace std;
int Count1(string s,string t)	//解法1
{	int cnt=0;				//累计出现次数
	int n=s.size(),m=t.size();
	int i=0,j=0;
	while (i<n && j<m)
	{	if (s[i]==t[j])		//比较的两个字符相同时
		{	i++; 
			j++;
		}
		else					//比较的两个字符不相同时
		{	i=i-j+1;			//i回退
			j=0;				//j从0开始
		}
		if(j>=m)
		{	cnt++;			//出现次数增1
			j=0;				//j从0开始继续
		}
	}
	return cnt;
}
void getnext(string& t,vector<int>& next)		//求t的next数组 
{	int j,k;
	j=0;k=-1;									//j遍历t，k记录t[j]之前与t开头相同的字符个数
	next[0]=k;									//设置next[0]值
	while (j<t.size()-1)						//求t所有位置的next值
	{	if (k==-1 || t[j]==t[k]) 				//k为-1或比较的字符相等时
		{	j++;k++;							//j、k依次移到下一个字符
			next[j]=k;							//设置next[j]为k
		}
		else  k=next[k];						//k回退
	}
}
int Count2(string s,string t)			//解法2
{	int cnt=0;							//累计出现次数
	int n=s.size(),m=t.size();
	vector<int> next(m,-1);
	getnext(t,next);
	int i=0,j=0;
	while(i<n)
	{	if (j==-1 || s[i]==t[j])		//匹配，i和j同时向后移动
		{	i++;
			j++;
		}
		else							//不匹配
			j=next[j];					//j寻找之前匹配的位置
		if (j>=m)						//成功匹配一次
		{
			cnt++;
			j=0;						//匹配成功后t从头开始比较 
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
	printf("解法1\n"); 
	cout << "  " << t << "在" << s << "中出现次数=" << Count1(s,t) << endl;
	printf("解法2\n"); 
	cout << "  " << t << "在" << s << "中出现次数=" << Count2(s,t) << endl;
	return 0;
}
