//儲存檔名：d:\VC++05\VC0519\VC0519.cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv)
{
	int outer = 1;	//宣告外層迴圈計數值
	do
	{				//外層while迴圈起點
		int inner = 1;	//宣告內層迴圈計數值
		do
		{			//內層while迴圈起點
			cout << setw(3) << inner;	//輸出運算值
		} while (inner++ <= 5 - outer); 	//內層while條件
		cout << endl;
	} while (outer++ <= 4);	//外層while條件
	return 0;
}
