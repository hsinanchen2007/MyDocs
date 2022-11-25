//檔案名稱：d:\C++08\C0811.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	char str1[] = "Focus on giving";	//宣告字串變數
	char* pstr2 = "Instead of getting";	//宣告字串指標
	cout << "輸出變數等值：" << str1 << endl;	//顯示字串變數值
	cout << "輸出指標內值：" << pstr2 << endl;	//顯示指標至結束
	cout << "輸出字串元素：" << str1[9] << endl;	//顯示第9元素值
	cout << "輸出元素指標：" << pstr2 + 11 << endl;	//顯示第11至結束
	return 0;
}
