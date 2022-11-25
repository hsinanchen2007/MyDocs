//檔案名稱：d:\C++09\C0911.cpp
#include <iostream>
#include <string>	//C++型態string標題檔
using namespace std;

int main(int argc, char** argv)
{
	string s1, s2;	//建立s1, s2字串物件
	cout << "請輸入s1：";
	getline(cin, s1);	//輸入s1字串
	cout << "請輸入s2：";
	getline(cin, s2);	//輸入s2字串

	if(s1 == s2)	//比較s1與s2
		cout << "s1 == s2\n";
	else
		cout << "s1 != s2\n";
	return 0;
}
