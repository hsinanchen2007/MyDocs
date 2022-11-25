//儲存檔名：d:\Ex18\Ex1801.cpp
//利用遞回函數求三數GCD
#include <iostream>
using namespace std;

int gcd(int, int, int, int);

int main(int argc, char** argv) {
	int a, b, c, n;	//宣告變數
	cout << "請輸入三個整數 (a b c)：";	//輸出訊息
	cin >> a >> b >> c;	//輸入a, b, c三數
	n = a;
	cout << "GCD = " << gcd(a, b, c, n) << endl;		//輸出GCD
	system("PAUSE");
	return 0;
}

int gcd(int a, int b, int c, int n)
{
	if(a%n==0 && b%n==0 && c%n==0)	//三數除以n皆等於0
		return n;
	else
		return gcd(a, b, c, n-1);
}
