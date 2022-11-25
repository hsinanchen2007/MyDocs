//儲存檔名：d:\VC++06\VC0617\VC0617.cpp
#include <iostream>
#include <iomanip>
using namespace std;

double degree(double);	//宣告函數原型

int main(int argc, char** argv)
{
	register double f;	//宣告暫存器變數
	cout << " 華氏\t  攝氏\n";	//顯示字串
	cout << setprecision(2);	//設定2位有效位數
	cout << setiosflags(ios::fixed | ios::right);	//改為2位小數有效位數
	for (f = 96; f <= 104; f += 2)	//攝氏溫度=計數
	{
		cout << setw(6) << f << '\t';	//顯示華氏值
		cout << setw(6) << degree(f) << '\n';	//顯示函數傳回攝氏值
	}
	return 0;
}

double degree(double fahr)	//溫度轉換函數
{
	register double c;	//宣告暫存器變數
	c = (fahr - 32) * 5 / 9;	//華氏轉成攝氏
	return c;	//返回並傳遞c
}
