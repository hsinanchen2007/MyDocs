//檔案名稱：d:\VC++07\VC0722\VC0722.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	bool flag = false;	//宣告布林值旗號
	int i, search;	//宣告整數變數
	int number[5] = { 57, 19, 33, 92, 6 };	//宣告並起始number陣列
	cout << "顯示資料：";
	for (i = 0; i <= 4; i++)	//輸出陣列資料迴圈
		cout << number[i] << ' ';
	cout << "\n輸入資料：";
	cin >> search;		//讀取鍵盤輸入
	for (i = 0; i <= 4; i++)	//找尋資料迴圈
	{
		if (number[i] == search)	//若資料==緩衝器值
			flag = 1;
	}
	if (flag)	//若找到資料
		cout << "找到資料：" << search << endl;
	else
		cout << "找不到資料：" << search << endl;
	return 0;
}
