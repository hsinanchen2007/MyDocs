//檔案名稱：d:\C++09\C0917.cpp
#include <iostream>
#include <string>	//C++型態string標題檔
using namespace std;

int main(int argc, char** argv)
{
	string s1("Dev/Visual C++"), s2("C++");
	int p1, p2;

	p1 = s1.find(s2);	// p1 = 7 (找到再位置7)
	if(p1!=-1)	//判斷在s1中是否找到s2
		cout << s1 << " 的第 " << p1 << " 字元位置找到 " << s2;	//輸出位置
	else
		cout << s1 << " 中找不到 " << s2;	//輸出字串
	cout << endl;

	p2 = s1.find("C#");	// p2 = -1 (找不到)
	if(p2!=-1)	//判斷在s1中是否找到Visual
		cout << s1 << " 的第 " << p2 << " 字元位置找到 C#";	//輸出位置
	else
		cout << s1 << " 中找不到 C#";	//輸出字串
	cout << endl;
	return 0;
}
