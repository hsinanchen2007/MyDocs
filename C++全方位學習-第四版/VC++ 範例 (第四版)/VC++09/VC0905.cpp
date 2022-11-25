//檔案名稱：d:\VC++09\VC0905\VC0905.cpp
#include <iostream>
#include <cstring>	//插入字串標題檔
#include <cctype>	//插入轉換字元檔
using namespace std;

int main(int argc, char** argv)
{
	char flexStr[] = "Success is never ending. Failure is never final.";
	cout << "字串轉換前：" << flexStr << endl;	//顯示轉換前字串
	int len = strlen(flexStr);	//取得字串長度

	for (int i = 0; i <= len; i++)	//轉成小寫迴圈
		flexStr[i] = tolower(flexStr[i]);	//轉成小寫字元
	cout << "轉換小寫後：" << flexStr << endl;	//顯示轉換後字串

	for (int i = 0; i <= len; i++)	//轉成大寫迴圈
		flexStr[i] = toupper(flexStr[i]);	//轉成大寫字元
	cout << "轉換大寫後：" << flexStr << endl;	//顯示轉換後字串
	return 0;
}
