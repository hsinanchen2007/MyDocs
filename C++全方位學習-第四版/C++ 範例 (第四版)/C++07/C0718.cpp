//檔案名稱：d:\C++07\C0718.cpp
#include <iostream>
using namespace std;

double calArray(int [][2]);	//宣告函數原型
void ansArray(double, double, double);	//宣告函數原型

int main(int argc, char** argv)
{
	int a1, a2, b1, b2, c1, c2;
	cout << "求聯立方程組 a1x + b1y = c1" << endl;	//顯示題目
	cout << "　　　　　　 a2x + b2y = c2 之解？" << endl;
	cout << "輸入 a1 = "; cin >> a1;	//輸入方程組係數
	cout << "輸入 b1 = "; cin >> b1;
	cout << "輸入 c1 = "; cin >> c1;
	cout << "輸入 a2 = "; cin >> a2;
	cout << "輸入 b2 = "; cin >> b2;
	cout << "輸入 c2 = "; cin >> c2;
	int dd[2][2] = {{a1, b1},
				{a2, b2}};	//宣告並起始二維陣列
	int dx[2][2] = {{c1, b1},
				{c2, b2}};	//宣告並起始二維陣列
	int dy[2][2] = {{a1, c1},
				{a2, c2}};	//宣告並起始二維陣列
	double delta = calArray(dd);	//delta=呼叫calArray函數
	double deltax = calArray(dx);	//deltax=呼叫calArray函數
	double deltay = calArray(dy);	//deltay=呼叫calArray函數
	ansArray(delta, deltax, deltay);	//呼叫ansArray函數
	cout << endl;
	return 0;
}

double calArray(int array[][2])	//計算行列式值
{
	return array[0][0]*array[1][1]-array[1][0]*array[0][1];	//行列式值
}

void ansArray(double del, double delx, double dely)	//判斷並求方程組之解
{
	if (del != 0)	//若分母 del != 0
	{
		double x = delx / del;
		double y = dely / del;
		cout << "有一解：x = " << x << ", y = " << y;	//則顯示有一解
	}
	else if (del == 0)	//若分母 del == 0
	{
		if (delx == 0 && dely == 0)	//且二分子皆為0
			cout << "有無限多解";	//顯示有無限多解
		else if (delx != 0 || dely != 0)	//且有一分子非0
			cout << "無解";	//顯示無解
	}
}
