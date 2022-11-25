//檔案名稱：d:\VC++07\VC0708\VC0709.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int eq[3][4] = { { 7, 1, 3, 6 },
	{ 4, -1, 1, 1 },
	{ 5, 3, -2, 8 } };	//宣告並起始二維陣列
	cout << "三元一次方程組\n";
	for (int i = 0; i<3; i++)	//輸出方程組迴圈
	{
		cout << eq[i][0] << (eq[i][1]>0 ? "x +" : "x ");	//輸出ax + 或ax
		cout << eq[i][1] << (eq[i][2]>0 ? "y +" : "y ");	//輸出by + 或by
		cout << eq[i][2] << "z= ";	//輸出cz
		cout << eq[i][3] << "\n";	//輸出d
	}
	return 0;
}
