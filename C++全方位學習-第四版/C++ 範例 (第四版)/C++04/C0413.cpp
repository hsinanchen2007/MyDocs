//儲存檔名：d:\C++04\C0413.cpp
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	char inChar;
	cout << "a. 新增資料\tb. 插入資料\tc. 刪除資料\t其他. 結束程式：";
	cin >> inChar;	//inChar=輸入字元
	switch (inChar)
	{
		case 'A':	//若inChar為A字元
		case 'a':	//或inChar為a字元
			cout << "新增資料\n";
			break;
		case 'B':	//若inChar為B字元
		case 'b':	//或inChar為b字元
			cout << "插入資料\n";
			break;
		case 'C':	//若inChar為C字元
		case 'c':	//或inChar為c字元
			cout << "刪除資料\n";
			break;
		default:	//inChar為其他字元
			cout << "結束程式\n";
	}
	return 0;
}
