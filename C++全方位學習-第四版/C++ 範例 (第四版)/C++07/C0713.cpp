//檔案名稱：d:\C++07\C0713.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int count, max = 0;	//宣告整數變數
	int number[5] = {5, 9, 3, 4, 7};	//宣告並起始number陣列
	for (count = 0; count <= 4; count++)	//找尋最大值迴圈
	{
		if (number[count] > max)	//若數值>緩衝器值
			max = number[count];	//則取代緩衝器值
	}
	cout << "5, 9, 3, 4, 7 五數的最大值 = " << max;	//顯示最大值
	cout << endl;
	return 0;
}
