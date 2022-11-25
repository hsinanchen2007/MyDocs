//檔案名稱：d:\VC++09\VC0913\VC0913.cpp
#include <iostream>
#include <string>	//C++型態string標題檔
using namespace std;

int main(int argc, char** argv)
{
	string s1("Hello world!"), s2, s3;	//宣告s1, s2, s3字串
	s2.assign(s1);	// s2 = "Hello world!"

	s3.assign(s1, 6, 5);	// s3 = "world"
	s3[2] = 'u';	// s3 = "would"

	cout << "s1 = " << s1 << endl;	//輸出s1
	cout << "s2 = " << s2 << endl;	//輸出s2
	cout << "s3 = " << s3 << endl;	//輸出s3
	return 0;
}
