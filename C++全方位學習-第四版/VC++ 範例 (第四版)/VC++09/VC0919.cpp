//檔案名稱：d:\VC++09\VC0919\VC0919.cpp
#include <iostream>
#include <string>	//C++型態string標題檔
using namespace std;

int main(int argc, char** argv)
{
	string s1("Dev C++"), s2("Visual");	//宣告並起始字串s1,s2
	cout << "插入之前的s2字串：" << s2 << endl;
	cout << "插入之前的s1字串：" << s1 << endl;

	s1.insert(3, s2);	//s1=ANSIISO C++
	cout << "插入s2後的s1字串：" << s1 << endl;

	s1.insert(3, "/");	//s1=ANSI/ISO C++
	cout << "插入/後的s1字串 ：" << s1 << endl;
	return 0;
}
