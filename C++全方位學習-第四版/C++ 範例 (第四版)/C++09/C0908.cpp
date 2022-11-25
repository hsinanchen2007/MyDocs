//檔案名稱：d:\C++09\C0908.cpp
#include <iostream>
#include <string>	//C++型態string標題檔
using namespace std;

int main(int argc, char** argv)
{
	string s1("c++ string class");	//宣告並起始s1
	string s2 = s1;
	string s3(s1);
	string s4(s1, 4, 12); 
	string s5(s1, 0, 3);
	cout << "s1 = " << s1 << endl;	//輸出s1
	cout << "s2 = " << s2 << endl;	//輸出s2
	cout << "s3 = " << s3 << endl;	//輸出s3
	cout << "s4 = " << s4 << endl;	//輸出s4
	cout << "s5 = " << s5 << endl;	//輸出s5
	return 0;
}
