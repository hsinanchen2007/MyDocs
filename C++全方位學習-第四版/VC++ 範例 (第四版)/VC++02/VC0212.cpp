//儲存檔名：d:\VC++02\VC0212\VC0212.cpp
#include <iostream>
#include <cfloat>
using namespace std;

const float PI = 3.14159f;	//宣告常數PI = 3.14159

int main(int argc, char** argv)
{
	char str1[] = "單精數 pi = ";	//宣告字串str1
	char str2[] = "倍精數 val = ";	//宣告字串str2
	double val = 4.5e+101;	//宣告val = 4.5e+101
	cout << str1 << PI << endl	//輸出字串、單精數、跳行
		<< str2 << val << endl;	//輸出字串、倍精數
	return 0;
}
