//儲存檔名：d:\C++03\C0310.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	char sentence[81];	//宣告字串變數
	cout << "請輸入字串：";	//輸出訊息字串
	cin.getline(sentence, 81);	//取得輸入句子
	cout << "輸入字串是：" << sentence << endl;	//顯示訊息與輸入句子
	return 0;
}
