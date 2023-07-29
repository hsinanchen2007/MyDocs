#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Cmp
{	bool operator()(const int& a,const int& b) const
	{
		string s=to_string(a),t=to_string(b);
		return s+t>t+s;
	}
};
string solve(vector<int>& a)
{
	sort(a.begin(),a.end(),Cmp());	//按指定方式排序
	string ans="";
	for(int i=0;i<a.size();i++)
		ans+=to_string(a[i]);
	return ans;	
}
int main()
{
	vector<int> a={50,2,1,9};
	string ans=solve(a);
	cout << ans << endl;
	return 0;
}
