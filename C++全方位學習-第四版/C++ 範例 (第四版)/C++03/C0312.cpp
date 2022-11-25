//儲存檔名：d:\C++03\C0312.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int num;	//宣告整數變數
	char key;	//宣告字元變數
	cout << "請輸入一整數：";	//輸出訊息字串
	cin >> num;	//讀取數值並存入num
	cin.ignore();	//忽略前一輸入字元Enter
	cout << "請按Enter結束：";	//輸出訊息字串
	cin.get(key);	//取得鍵盤按鍵
	cout << "謝謝！\n";	//顯示訊息
	return 0;
}
