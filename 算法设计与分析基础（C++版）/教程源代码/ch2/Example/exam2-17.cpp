#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm> 
using namespace std;
void Apposition(vector<string>&words)
{
	string s;
	unordered_map<string,vector<string>> mp;
	for(int i=0;i<words.size();i++)
	{
		s=words[i];
		sort(s.begin(),s.end());
		mp[s].push_back(words[i]);
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		for(int j=0;j<it->second.size();j++)
			cout << it->second[j] << " ";
		cout << endl;
	}
}
int main()
{
	vector<string> words={"abcd","xyz","dabc","cdab","yzx"};
	Apposition(words);
	return 0;
}
