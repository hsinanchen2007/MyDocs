//檔案名稱：d:\C++09\C0902.cpp
#include <iostream>
#include <cstring>	//插入字串標題檔
using namespace std;

int main(int argc, char** argv)
{
	char source[80], target[80];
	cout << "請輸入來源字串：";	//顯示訊息字串
	cin.getline (source, 80, '\n');	//取得來源字串
	strcpy(target, source);	//複製字串
	cout << "複製後目的字串：" << target;	//顯示目的字串
	cout << endl;
	return 0;
}
