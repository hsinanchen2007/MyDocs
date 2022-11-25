//儲存檔名：d:\VC++03\VC0309\VC0309.cpp
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	char string[5];	//宣告字串變數string
	cout << "請輸入字串：";	//輸出訊息字串
	cin.width(5);	//設定輸入字元數
	cin >> string;	//取得輸入字串
	cout << "輸入字串是：" << string << endl;	//顯示訊息與輸入字串
	return 0;
}
