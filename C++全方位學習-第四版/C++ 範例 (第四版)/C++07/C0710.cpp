//檔案名稱：d:\C++07\C0710.cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv)
{
	int i, x, y;
	int eq[3][4] = { {7, 1, 3, 6}, 
			 {4, -1, 1, 1},
			 {5, 3, -2, 8} };	//宣告並起始二維陣列
	int dd[3][3] = {0};	//宣告並起始二維陣列
	//輸出方程組
	cout << "三元一次方程組\n";
	for(i=0; i<3; i++)
	{
		cout << eq[i][0] << (eq[i][1]>0 ? "x +" : "x ");	//輸出ax
		cout << eq[i][1] << (eq[i][2]>0 ? "y +" : "y ");	//輸出by
		cout << eq[i][2] << "z= ";			//輸出cz
		cout << eq[i][3] << "\n";			//輸出d
	}
	//複製陣列元素
	for(y=0; y<3; y++)	//外層迴圈,改變索引值y
	{
		for(x=0; x<3; x++)	//內層迴圈,改變索引值x
			dd[y][x] = eq[y][x];	//複製陣列元素
	}
	//輸出陣列元素
	cout << "\nd = ";
	for(y=0; y<3; y++)	//外層迴圈,改變索引值y
	{
		cout << ((y == 0) ? "| " : "    | ");
		for(x=0; x<3; x++)	//內層迴圈,改變索引值x
			cout << setw(2) << dd[y][x] << ' ';	//輸出陣列元素
		cout << "|\n";
	}
	return 0;
}
