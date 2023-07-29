#include<iostream>
#include<vector>
#include<string>
using namespace std;
void getnext(string& t,vector<int>& next)
{	int j,k;
	j=0;k=-1;							//j遍历t，k记录t[j]之前与t开头相同的字符个数
	next[0]=k;							//设置next[0]值
	while (j<t.size()-1)				//求t所有位置的next值
	{	if (k==-1 || t[j]==t[k]) 		//k为-1或比较的字符相等时
		{	j++;k++;					//j、k依次移到下一个字符
			next[j]=k;					//设置next[j]为k
		}
		else  k=next[k];					//k回退
	}
}
int cnt=0;
int KMP(string s,string t)					//字符串匹配
{
	int n=s.size();
	int m=t.size();
	vector<int> next(m,-1);
	getnext(t,next);
	int i=0,j=0;
	while(i<n && j<m)
	{
		cnt++;
		if (j==-1 || s[i]==t[j])			//匹配，i和j同时向后移动
		{
			i++;
			j++;
		}
		else								//不匹配
			j=next[j];						//j寻找之前匹配的位置
    }
	if (j>=m)								//j超界说明t是s的子串
		return i-t.size();
    else									//否则说明t不是s的子串
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
