//儲存檔名：d:\C++05\C0514.cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv)
{
	int count = 1, factor = 1;	//while 迴圈初值
	cout << "計數\t" << setw(8) << "階乘\n";	//輸出字串
	do				//do 迴圈
	{
		factor *= count;	//計算階乘
		cout << setw(3) << count << '\t';	//輸出計數值
		cout << setw(7) << factor << endl;	//輸出階乘
	} while (++count <= 10);	//count<=10迴圈繼續
	return 0;
}
