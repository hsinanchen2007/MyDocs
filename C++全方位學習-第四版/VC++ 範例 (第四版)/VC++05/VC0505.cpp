//儲存檔名：d:\VC++05\VC0505\VC0505.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int year;
	cout << "請輸入整數，若輸入 0 則結束：";
	cin >> year;			//讀取鍵盤輸入
	while (year != 0)	//若輸入不是0則迴圈成立
	{
		cout << "請輸入整數，若輸入 0 則結束：";
		cin >> year;		//讀取鍵盤輸入
	}
	return 0;
}
