//儲存檔名：d:\C++05\C0525.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int a, b, n;	//宣告變數
	cout << "請輸入二個整數 (a b)：";	//輸出訊息
	cin >> a >> b;	//輸入a, b二數
	for(n=a; n<=a*b; n+=a)
		if(n%b==0)	//a的倍數除以b等於0
			break;		//中斷迴圈
	cout << "LCM = " << n << endl;		//輸出LCM
	return 0;
}
