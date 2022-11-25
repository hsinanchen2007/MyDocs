//儲存檔名：d:\C++05\C0524.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int a, b, n;	//宣告變數
	cout << "請輸入二個整數 (a b)：";	//輸出訊息
	cin >> a >> b;	//輸入a, b二數
	for(n=a; n>=1; n--)
		if(a%n==0 && b%n==0)	//二數除以n皆等於0
			break;		//中斷迴圈
	cout << "GCD = " << n << endl;		//輸出GCD
	return 0;
}
