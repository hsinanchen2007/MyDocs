//儲存檔名：d:\VC++05\VC0511\VC0511.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	char inkey;
	short num;
	short  plus = 0, minus = 0, zero = 0;
	do
	{
		cout << "請輸入 -32768 到 32767 的數值：";
		cin >> num;	//輸入有號整數
		if (num != 0)	//若 num 不等於 0
			(num > 0) ? plus++ : minus++;	//執行條件運算敘述
		else		//否則
			zero++;	//zero = zero + 1
		cout << "是否輸入下一筆數值 (y/n)：";
		cin >> inkey;	//輸入字元
	} while (inkey == 'Y' || inkey == 'y');	//若字元='Y'則重複迴圈
	cout << "\n正數有" << plus << "個";	//顯示正數個數
	cout << "\n負數有" << minus << "個";	//顯示負數個數
	cout << "\n零有" << zero << "個\n";	//顯示零的個數
	return 0;
}
