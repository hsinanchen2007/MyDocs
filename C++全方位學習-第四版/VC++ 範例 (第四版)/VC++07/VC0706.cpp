//檔案名稱：d:\VC++07\VC0706\VC0706.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int eq[2][3] = { { 3, 8, 7 },
	{ 4, 9, 2 } };	//宣告並起始二維陣列
	cout << "求二元一次聯立方程組之解\n";
	cout << eq[0][0] << "x + " << eq[0][1];	//輸出陣列元素
	cout << "y = " << eq[0][2] << endl;	//輸出陣列元素
	cout << eq[1][0] << "x + " << eq[1][1];	//輸出陣列元素
	cout << "y = " << eq[1][2] << endl;	//輸出陣列元素
										//計算delta值
	int d = eq[0][0] * eq[1][1] - eq[1][0] * eq[0][1];
	//計算delta x值
	int dx = eq[0][2] * eq[1][1] - eq[1][2] * eq[0][1];
	//計算delta y值
	int dy = eq[0][0] * eq[1][2] - eq[1][0] * eq[0][2];
	cout << "則 x = " << float(dx) / float(d);	//輸出dx/d值
	cout << "\ty = " << float(dy) / float(d) << endl;	//輸出dy/d值
	return 0;
}
