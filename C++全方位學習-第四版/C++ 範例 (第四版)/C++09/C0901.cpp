//檔案名稱：d:\C++09\C0901.cpp
#include <iostream>
#include <cstring>	//插入字串標題檔
using namespace std;

int main(int argc, char** argv)
{
	char instr[80];
	cout << "請輸入字串：";	//顯示訊息字串
	cin.getline (instr, 80, '\n');	//取得輸入字串列
	cout << "字串長度為：" << strlen(instr);	//顯示字串長度
	cout << endl;
	return 0;
}
