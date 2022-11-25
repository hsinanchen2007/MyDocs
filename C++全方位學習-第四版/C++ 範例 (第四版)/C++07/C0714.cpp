//檔案名稱：d:\C++07\C0714.cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv)
{
	int eq[3][3] = { {7, 1, 3}, 
			 {4, -1, 1},
			 {5, 3, -2} };	//宣告並起始二維陣列
	long d = 0;	//宣告並起始變數d
	cout << "計算行列式 a 值\n";
	//計算行列式值
	for(int i=0; i<3; i++)	//計算行列式值迴圈
	{
		d += eq[0][i]*eq[1][(i+1)%3]*eq[2][(i+2)%3];
		d -= eq[0][i]*eq[1][(i+2)%3]*eq[2][(i+1)%3];
	}
	//輸出陣列元素
	for(int y=0; y<3; y++)	//外層迴圈,改變索引值y
	{
		if(y==1)
			cout << "a = | ";
		else
			cout << "    | ";
		for(int x=0; x<3; x++)	//內層迴圈,改變索引值x
			cout << setw(2) << eq[y][x] << ' ';	//輸出陣列元素
		if(y==1)
			cout << "| = " << d << endl;	//輸出行列式值
		else
			cout << "|\n";
	}
	return 0;
}
