//儲存檔名：d:\VC++05\VC0520\VC0520.cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv)
{
	int multiplier, faciend;
	for (faciend = 1; faciend <= 9; faciend++)	//定義被乘數迴圈由1到9
	{
		for (multiplier = 2; multiplier <= 9; multiplier++)	//乘數由2數到9
		{
			cout << multiplier << '*'; 	//輸出multiplier *
			cout << faciend << '=';	//輸出faciend =
			cout << setw(2);	//設定輸出二位數
			cout << multiplier * faciend << '\t';	//輸出運算值後跳下一定位
		}
		cout << endl;	//輸出跳行
	}
	return 0;
}
