// string类的使用例程

#include <string>
#include <iostream>

using namespace std;

int main()
{
	string s1 = "ABC";
	string s2 = "HIJKLMN";
	string digits = "0123456789";

	s1 += "DEF";							// 在s1的末尾拼接"DEF"
	s1 += 'G';								// 在s1的末尾拼接'G'
	s1 += s2;								// 在s1的末尾拼接"HIJKLMN"
	s1.insert(6, digits.substr(5, 3));		// 向s1[6]插入"567"

	s2.replace(3, 2, "kl");					// 把s2[3]~s2[4]替换为"kl"
	s2.erase(6);							// 删除s2[6]

	cout << "s1 = ";
	for (int i = 0; i < s1.length(); i++)
		cout << s1[i];
	cout << '\n';
	cout << "s2 = " << s2 << '\n';
}
