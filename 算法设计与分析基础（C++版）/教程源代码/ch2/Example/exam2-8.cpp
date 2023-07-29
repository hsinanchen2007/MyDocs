#include<iostream>
#include<stack>
#include<string>
using namespace std;
string Reversewords(string& s)
{
	stack<string> st;
	int i=0;
	while(i<s.length())
	{
		while(i<s.length() && s[i]==' ')
			i++;						//Ìø¹ý¿Õ×Ö·û
		string tmp="";
		while(i<s.length() && s[i]!=' ')
		{
			tmp+=s[i];
			i++;
		}
		st.push(tmp);
	}
	string ans="";
	while(!st.empty())
	{
		if(ans.length()==0)
			ans+=st.top();
		else
			ans+=" "+st.top();
		st.pop();
	}
	return ans;
}

int main()
{
	string s="  the sky is blue    ";
	cout << "s: " << s << endl;
	string t=Reversewords(s);
	cout << "µ¥´Ê·­×ª" << endl;
	cout << "t: " << t << endl;
	return 0;
}
