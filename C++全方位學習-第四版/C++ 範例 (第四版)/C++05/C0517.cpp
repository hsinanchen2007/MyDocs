//儲存檔名：d:\C++05\C0517.cpp
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const double PI = 3.141592653;

int main(int argc, char** argv)
{
	int x;	//while迴圈初值
	double sine;	//宣告x變數
	cout << " x\t" << "sin(x)\n";	//輸出字串
	for (x=0; x<=90; x+=15)	//判斷x<=90後再加15
	{
		sine = sin(PI * x / 180);	//計算sin(x)
		cout << setprecision(3) << setiosflags(ios::fixed);	//設定輸出格式
		cout << setw(2) << x << '\t';	//輸出計數值
		cout << setw(6) << sine << endl;	//輸出sin值
	}
	return 0;
}
