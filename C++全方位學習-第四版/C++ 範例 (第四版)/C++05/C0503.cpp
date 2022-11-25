//儲存檔名：d:\C++05\C0503.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int c = 3;	//宣告變數
	cout << --c << endl;	//c=3-1=2後輸出c值
	cout << --c << endl; 	//c=2-1=1後輸出c值
	cout << --c << endl; 	//c=1-1=0後輸出c值
	return 0;
}
