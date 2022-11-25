//檔案名稱：d:\VC++09\VC0915\VC0915.cpp
#include <iostream>
#include <string>	//C++型態string標題檔
using namespace std;

int main(int argc, char** argv)
{
	string s1("Dev/Visual C++");	//宣告並起始字串s1
	string s2("Visual C++");	//宣告並起始字串s2

	if (s1.compare(s2) == 0)	//比較s1與s2
		cout << s1 << " == " << s2;	//輸出字串
	else
		cout << s1 << " != " << s2;	//輸出字串
	cout << endl;

	if (s1.compare(11, 3, s2, 7, 3) == 0)	//比較s1與s2的子字串
		cout << s1.substr(11, 3) << " == " << s2.substr(7, 3);	//輸出子字串
	else
		cout << s1.substr(11, 3) << " != " << s2.substr(7, 3);	//輸出子字串
	cout << endl;
	return 0;
}
