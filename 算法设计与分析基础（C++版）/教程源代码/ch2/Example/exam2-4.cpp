#include<iostream>
#include<string>
using namespace std;
int Count(string&s,string&t)
{
	int cnt=0;
	int pos=s.find(t,0);
	while(pos!=string::npos)
	{
		cnt++;
		pos=s.find(t,pos+t.size());
	}
	return cnt;
}		
	
int main()
{
	string s="aababcabcd";
	string t="abc";
	int cnt=Count(s,t);
	cout << "s: " << s << endl;
	cout << "t: " << t << endl;
	printf("t��s�в��ص����ֵĴ���=%d\n",cnt);
	return 0;
}
