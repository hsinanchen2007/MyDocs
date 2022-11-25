//檔案名稱：d:\C++08\C0812.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	char *array[] = {"床前明月光，",
				         "疑似地上霜；",
				         "舉頭望明月，",
				         "低頭思故鄉。"};	//宣告陣列指標
	int size = (sizeof array)/(sizeof array[0]);	//計算陣列個數
	for (int i=0; i<size; i++)	//顯示陣列元素
	{
		cout << *(array+i) << endl;
	}
	return 0;
}
