//檔案名稱：d:\C++07\C0707.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int source[3] = {5, 9, 3};	//宣告一維陣列變數
	cout << "輸出陣列元素\n";
	for (int i=0; i<=2; i++)	//輸出陣列元素迴圈
	{
		cout << "source[" << i << "] = ";	//輸出陣列索引值
		cout << source[i] << '\t';	//輸出陣列元素
	}
	cout << endl;         //跳行 
	return 0;
}
