//儲存檔名：d:\VC++04\VC0404\VC0404.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int number;

	cout << "請輸入一個整數：";
	cin >> number;	//輸入整數並存入number
	if (number >= 0) {	//若number >= 0
		cout << number << " 是零或正整數。\n";	//  顯示訊息
	}				//if區塊結束點
	else {		//若number < 0
		cout << number << " 是負整數。\n";	//  顯示訊息
	}				//else區塊結束點
	return 0;
}
