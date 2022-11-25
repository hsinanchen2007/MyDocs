//儲存檔名：d:\VC++04\VC0412\VC0412.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	char letter;
	int num1 = 75, num2 = 15;
	cout << "num1 = 75, num2 = 15 \n";
	cout << "請選擇 +,-,*,/ ：";
	cin >> letter;	//輸入字元並存入letter
	switch (letter)
	{
	case '+':	//若 letter = '+'
		cout << "num1 + num2 = " << num1 + num2;
		cout << endl; break;	//跳行、並跳出switch
	case '-':	//若 letter = '-'
		cout << "num1 - num2 = " << num1 - num2;
		cout << endl; break;	//跳行、並跳出switch
	case '*':	//若 letter = '*'
		cout << "num1 * num2 = " << num1 * num2;
		cout << endl; break;	//跳行、並跳出switch
	case '/':	//若 letter = '/'
		cout << "num1 / num2 = " << num1 / num2;
		cout << endl; break;	//跳行、並跳出switch
	}
	return 0;
}
