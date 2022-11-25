//儲存檔名：d:\VC++04\VC0407\VC0407.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int number;

	cout << "請輸入一個整數：";
	cin >> number;	//輸入整數並存入number
	if (number > 0) {	//若number >= 0
		cout << number << " 大於 0\n";	//  顯示訊息
	}				//if區塊結束點
	else if (number < 0) {	//若number < 0
		cout << number << " 小於 0\n";	//  顯示訊息
	}				//else if區塊結束點
	else {		//以上皆非
		cout << number << " 等於 0\n";	//  顯示訊息
	}				//else區塊結束點
	return 0;
}
