//檔案名稱：d:\C++08\C0806.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	short array[] = {30, 47, 26, 17, 22, 23};	//宣告字串變數
	short *arrayPtr;	//宣告浮點數指標

	const int SIZE = (sizeof array)/(sizeof array[0]);	//計算陣列個數
	for(int i=0; i<SIZE; i++)
	{
		arrayPtr = &array[i];	//更新指標位置
		cout << "array 的第 " << i << " 個元素是：";
		cout << *arrayPtr << endl;	//輸出指標位置資料
	}
	return 0;
}
