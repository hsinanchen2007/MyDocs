//檔案名稱：d:\VC++07\VC0705\VC0705.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int eq[2][2] = { { 3, 8 },
	{ 4, 9 } };	//宣告並起始二維陣列
	cout << "求行列式x的值\n";
	//計算行列式值
	int d = eq[0][0] * eq[1][1] - eq[1][0] * eq[0][1];
	//輸出陣列元素
	cout << "x = |" << eq[0][0] << " " << eq[0][1] << "| = ";
	cout << d << endl;	//輸出行列式值
	cout << "    |" << eq[1][0] << " " << eq[1][1] << "|\n";
	return 0;
}
