//檔案名稱：d:\C++07\C0717.cpp
#include <iostream>
#include <iomanip>
using namespace std;

void showArray(int [][3], int, char []);	//宣告函數原型
int calArray(int [][3]); 	//宣告函數原型

int main(int argc, char** argv)
{
	int eq[3][4] = { {7, 1, 3, 6}, 
				          {4, -1, 1, 1},
				          {5, 3, -2, 8} };	//宣告並起始二維陣列
	int dd[3][3] = {0};	//宣告並起始二維陣列
	int d, dx, dy, dz, y;	//宣告整數變數

	//輸出方程組
	cout << "三元一次聯立方程組\n";
	for(y=0; y<3; y++)
	{
		cout << eq[y][0] << (eq[y][1]>0 ? "x +" : "x ");	//輸出ax
		cout << eq[y][1] << (eq[y][2]>0 ? "y +" : "y ");	//輸出by
		cout << eq[y][2] << "z= ";			//輸出cz
		cout << eq[y][3] << "\n";			//輸出d
	}
	//計算與輸出 d 值
	for(y=0; y<3; y++)	//複製陣列元素
	{
		dd[y][0] = eq[y][0];	//複製eq第0到dd第0列
		dd[y][1] = eq[y][1];	//複製eq第1到dd第1列
		dd[y][2] = eq[y][2];	//複製eq第2到dd第2列
	}
	d = calArray(dd);	//計算行列式值
	showArray(dd, d, "d  = | ");	//輸出行列式與值
	//計算與輸出 dx 值
	for(y=0; y<3; y++)	//複製陣列元素
	{
		dd[y][0] = eq[y][3];	//複製eq第3到dd第0列
		dd[y][1] = eq[y][1];	//複製eq第1到dd第1列
		dd[y][2] = eq[y][2];	//複製eq第2到dd第2列
	}
	dx = calArray(dd);	//計算行列式值
	showArray(dd, dx, "dx = | ");	//輸出行列式與值
	//計算與輸出 dy 值
	for(y=0; y<3; y++)	//複製陣列元素
	{
		dd[y][0] = eq[y][0];	//複製eq第0到dd第0列
		dd[y][1] = eq[y][3];	//複製eq第3到dd第1列
		dd[y][2] = eq[y][2];	//複製eq第2到dd第2列
	}
	dy = calArray(dd);	//計算行列式值
	showArray(dd, dy, "dy = | ");	//輸出行列式與值
	//計算與輸出 dz 值
	for(y=0; y<3; y++)	//複製陣列元素
	{
		dd[y][0] = eq[y][0];	//複製eq第0到dd第0列
		dd[y][1] = eq[y][1];	//複製eq第1到dd第1列
		dd[y][2] = eq[y][3];	//複製eq第3到dd第2列
	}
	dz = calArray(dd);	//計算行列式值
	showArray(dd, dz, "dz = | ");	//輸出行列式與值
	//輸出行列式的解
	cout << endl;
	cout << "x = " << dx << '/' << d << endl;	//輸出 x 值
	cout << "y = " << dy << '/' << d << endl;	//輸出 y 值
	cout << "z = " << dz << '/' << d << endl;	//輸出 z 值
	return 0;
}

int calArray(int array[][3])	//計算行列式值函數
{
	int a = 0;
	for(int i=0; i<3; i++)	//計算行列式值迴圈
	{
		a += array[0][i]*array[1][(i+1)%3]*array[2][(i+2)%3];
		a -= array[0][i]*array[1][(i+2)%3]*array[2][(i+1)%3];
	}
	return a;	//傳回計算值
}

void showArray(int array[][3], int d, char s[])	//顯示行列式函數
{
	cout << endl;
	for(int y=0; y<3; y++)	//外層迴圈,改變索引值y
	{
		if(y==1)
			cout << s;
		else
			cout << "     | ";
		for(int x=0; x<3; x++)	//內層迴圈,改變索引值x
			cout << setw(2) << array[y][x] << ' ';	//輸出陣列元素
		if(y==1)
			cout << "| = " << d << endl;	//輸出行列式值
		else
			cout << "|\n";
	}
}
