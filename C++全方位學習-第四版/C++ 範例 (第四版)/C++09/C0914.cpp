//檔案名稱：d:\C++09\C0914.cpp
#include <iostream>
#include <string>	//C++型態string標題檔
using namespace std;

int main(int argc, char** argv)
{
	string s1("Hello"), s2("wi"), s3("world!");
	cout << "串接前\n";
	cout << "s1 = " << s1 << endl;	//輸出s1
	cout << "s2 = " << s2 << endl;	//輸出s2
	cout << "s3 = " << s3 << endl;	//輸出s3

	s1.append(' ' + s3);	// s1 = "Hello world!"
	s2.append(s3, 3, 2);	// s2 = "wild"

	cout << "串接後\n";
	cout << "s1 = " << s1 << endl;	//輸出s1
	cout << "s2 = " << s2 << endl;	//輸出s2
	cout << "s3 = " << s3 << endl;	//輸出s3
	return 0;
}
