//儲存檔名：d:\VC++02\VC0210\VC0210.cpp
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	signed int num1 = -12345;	//num1 = -12345
	unsigned short num2 = 65432;	//num2 = 65432
	long num3 = 1234567890;	//num3 = 1234567890

	cout << "有號整數：" << num1 << endl	//輸出字串、數值、跳行
		<< "無號短整數：" << num2 << endl	//輸出字串、數值、跳行
		<< "長整數：" << num3 << endl;	//輸出字串、數值、跳行
	return 0;
}
