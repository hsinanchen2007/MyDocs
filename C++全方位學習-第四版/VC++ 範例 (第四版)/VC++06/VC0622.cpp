//儲存檔名：d:\VC++06\VC0622\VC0622.cpp
#include <iostream>
using namespace std;

#define MAX(x, y) ((x>y) ? x : y)	//判斷較大值函數巨集
#define MIN(x, y) ((x<y) ? x : y)	//判斷較小值函數巨集

int main(int argc, char** argv)
{
	int num1, num2;
	cout << "請輸入二個整數：";
	cin >> num1 >> num2;
	cout << num1 << " 和 " << num2;
	cout << " 的較大值是 " << MAX(num1, num2);	//呼叫巨集函數MAX
	cout << endl;
	cout << num1 << " 和 " << num2;
	cout << " 的較小值是 " << MIN(num1, num2);	//呼叫巨集函數MIN
	cout << endl;
	return 0;
}
