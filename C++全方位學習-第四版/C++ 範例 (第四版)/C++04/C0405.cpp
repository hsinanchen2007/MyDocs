//儲存檔名：d:\C++04\C0405.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	cout << "請輸入一整數：";
	int number;	//宣告整數變數
	cin >> number;	//輸入number資料
	if (number % 2 == 0)	//若number/2餘數為0
		cout << number << " 是偶數\n";	//則顯示訊息1
	else			//否則
		cout << number << " 是奇數\n";	//則顯示訊息2
	return 0;
}
