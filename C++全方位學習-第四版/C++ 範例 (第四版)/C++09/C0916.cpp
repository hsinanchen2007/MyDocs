//檔案名稱：d:\C++09\C0916.cpp
#include <iostream>
#include <string>	//C++型態string標題檔
using namespace std;

int main(int argc, char** argv)
{
	string s1("Visual C++"), s2("ANSI/ISO C++");
	cout << "對調前：\n";
	cout << "s1 = " << s1 << endl;	//s1 = "Visual C++"
	cout << "s2 = " << s2 << endl;	//s2 = "ANSI/ISO C++"

	s1.swap(s2);	//s1與s2對調
	cout << "對調後：\n";
	cout << "s1 = " << s1 << endl;	//s1 = "ANSI/ISO C++"
	cout << "s2 = " << s2 << endl;	//s2 = "Visual C++"
	return 0;
}
