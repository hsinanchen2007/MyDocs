//檔案名稱：d:\VC++09\VC0918\VC0918.cpp
#include <iostream>
#include <string>	//C++型態string標題檔
using namespace std;

int main(int argc, char** argv)
{
	string s("call by reference");	//宣告並起始字串s

	cout << "取代前的字串：" << s << endl;

	unsigned int p = s.find(" ");	//找尋第一個空白
	while (p<string::npos)	// 若不等於字串結尾則繼續
	{
		s.replace(p, 1, "-");	//找到後以"–"取代" "
		p = s.find(" ", ++p);	//找尋下一個空白
	}
	cout << "取代後的字串：" << s << endl;
	return 0;
}
