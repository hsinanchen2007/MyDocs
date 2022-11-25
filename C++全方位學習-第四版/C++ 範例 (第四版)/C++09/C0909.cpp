//檔案名稱：d:\C++09\C0909.cpp
#include <iostream>
#include <string>	//C++型態string標題檔
using namespace std;

int main(int argc, char** argv)
{
	string s1, s2;	//宣告s1, s2
	cout << "請輸入 s1 字串：";
	getline(cin, s1);	//輸入字串到s1
	cout << "請輸入 s2 字串：";
	cin >> s2;	//輸入字串到s2
	cout << "s1 = " << s1 << endl;	//輸出s1
	cout << "s2 = " << s2 << endl;	//輸出s2
	return 0;
}
