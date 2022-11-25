//儲存檔名：d:\C++06\C0616.cpp
#include <iostream>
#include <iomanip>
#include "C0616.h"	//插入自建標題檔
using namespace std;

double c;		//宣告公用變數

int main(int argc, char** argv)
{
	cout << "攝氏\t 華氏\n";	//顯示字串
	cout << setprecision(2);	//設定2位有效位數
	cout << setiosflags(ios::fixed|ios::right);	//改為2位小數有效位數
	for (c = 36; c <= 40; c++)	//攝氏溫度=計數
	{
		cout << setw(5) << c << '\t';	//顯示英尺值
		cout << setw(6) << degree() << '\n';	//顯示函數傳回公尺值
	}
	return 0;
}
