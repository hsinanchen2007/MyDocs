//儲存檔名：d:\VC++05\VC0509\VC0509.cpp
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(int argc, char** argv)
{
	double count = 0;	//while迴圈初值
	double power;	//宣告power變數
	cout << "計數\t" << "2的n次方\n";	//輸出字串
	while (count++ < 10)	//判斷count<10後再加1
	{
		power = pow(2, count);	//計算2的n次方
		cout << setw(3) << count << '\t';	//輸出計數值
		cout << setw(6) << power << endl;	//輸出2的n次方值
	}
	return 0;
}
