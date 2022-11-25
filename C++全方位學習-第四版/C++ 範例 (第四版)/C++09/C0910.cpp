//檔案名稱：d:\C++09\C0910.cpp
#include <iostream>
#include <string>	//C++型態string標題檔
using namespace std;

int main(int argc, char** argv)
{
	string s1("Hello"), s2(" world"), s3;
	s3 = s1 + s2;	//s3="Hello world"
	string s4(s3 + "!");	//s4="Hello world!"
	s1 += "!";	//s1="Hello!"
	cout << "s1 = " << s1 << endl;	//輸出s1
	cout << "s2 = " << s2 << endl;	//輸出s2
	cout << "s3 = " << s3 << endl;	//輸出s3
	cout << "s4 = " << s4 << endl;	//輸出s4
	return 0;
}
