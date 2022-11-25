//儲存檔名：d:\C++03\C0308.cpp
#include <iostream>
#include <iomanip>	//包含setw()的標題檔
using namespace std;

int main(int argc, char** argv)
{
	char string[4];	//宣告字串變數string
	cout << "請輸入字串：";	//輸出訊息字串
	cin >> setw(4) >> string;	//設定輸入字數並取得輸入
	cout << "輸入字串是：" << string << endl;	//顯示訊息與輸入字串
}
