//檔案名稱：d:\C++08\C0807.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	double array[] = {3.0, 4.7, 2.6, 1.7, 2.2, 2.3};	//宣告字串變數

	const int SIZE = (sizeof array)/(sizeof array[0]);	//計算陣列個數
	cout.precision(1);	//設定有效位數1位
	cout.setf(ios::fixed);	//改為小數有效位數1位
	for(int i=0; i<SIZE; i++)	//輸出陣列元素迴圈
	{
		cout << "array 的第 " << i << " 個元素是：";
		cout << *(array+i) << endl;	//輸出陣列指標位置資料
	}
	return 0;
}
