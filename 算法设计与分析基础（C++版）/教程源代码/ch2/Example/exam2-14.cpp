#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
bool isUnique(string &str)		//���str�е������ַ��Ƿ�Ψһ��
{	unordered_map<char,int> mp;
	for (int i=0;i<str.length();i++)
	{	mp[str[i]]++;
		if (mp[str[i]]>1)
			return false;
	}
	return true;
}
	
int main()
{
	string str="abcdea";
	printf("���: %d",isUnique(str));
	return 0;
}
