#include<iostream>
#include<string>
using namespace std;
void Replaceall(string&str,string&s,string&t)
{
	int m=s.size();
	int pos=str.find(s,0);
	while(pos!=string::npos)
	{
		str.replace(pos,m,t);
		pos=str.find(s,pos+t.size());
	}
}		
	
int main()
{
	string str="aababcabcd";
	string s="ab";
	string t="1234";
	cout << "str: " << str << endl;
	cout << "s:   " << s << endl;
	cout << "t:   " << t << endl;
	cout << "Ìæ»»" << endl;
	Replaceall(str,s,t);
	cout << "str: " << str << endl;
	return 0;
}
