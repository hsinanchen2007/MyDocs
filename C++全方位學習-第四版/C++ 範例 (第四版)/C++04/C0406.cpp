//儲存檔名：d:\C++04\C0406.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	short num1, num2, sum;

	cout << "請輸入短整數 1：";
	cin >> num1;	//輸入短整數並存入num1
	cout << "請輸入短整數 2：";
	cin >> num2;	//輸入短整數並存入num2
	if ((num1 + num2) > 32767) {	//若num1+num2 > 32767
		cout << num1 << " + " << num2 << " = 上限溢位\n";	//  顯示錯誤訊息
	} else {			//若num1+num2 <= 32767
		sum = num1 + num2;
		cout << num1 << " + " << num2 << " = " << sum << endl;	//  顯示運算值
	}
	return 0;
}
