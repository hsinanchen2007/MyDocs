//檔案名稱：d:\VC++08\VC0810\VC0810.cpp
#include <iostream>
using namespace std;

const int SIZE = 6;

int main(int argc, char** argv)
{
	int array[SIZE];	//宣告字串變數
	int *arrayPtr = &array[0];	//宣告並起始陣列指標
	int i;		//宣告整數變數
	cout << "請輸入 " << SIZE << " 筆整數資料：";
	for (i = 0; i<SIZE; i++)	//輸入陣列元素迴圈
	{
		cin >> *arrayPtr++;	//輸入資料存入指標位置
	}
	for (i = SIZE - 1; i >= 0; i--)	//輸出陣列元素迴圈
	{
		cout << "array 的第 " << i << " 個元素是：";
		cout << *--arrayPtr << endl;	//輸出陣列指標位置資料
	}
	return 0;
}
