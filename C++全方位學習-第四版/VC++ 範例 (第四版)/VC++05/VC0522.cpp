//儲存檔名：d:\VC++05\VC0522\VC0522.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	char string[25] = "ANSI/ISO C++";	//宣告與啟始字串
	char letter;	//宣告字元變數
	int count;	//宣告整數變數
	for (count = 0; count <= 24; count++)	//利用迴圈顯示字串變數
	{
		cout << string[count];
	}
	cout << "\n請輸入要搜尋的字元：";	//顯示字串常數
	cin >> letter;	//輸入字元
	for (count = 0; count <= 24; count++)	//定義迴圈
	{
		if (string[count] == letter)	//找到相符字元
			break;	//中斷迴圈
	}
	if (count <= 24)	//若計數值<=字串長度
		cout << "第 " << ++count << " 個字元為 "	//則顯示字串位置
		<< letter << '\n';
	else
		cout << "找不到相符字元\n";	//否則顯示找不到
	return 0;
}
