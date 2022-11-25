//儲存檔名：d:\C++05\C0512.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int count = 1;	//宣告迴圈計數初值
	do
	{ 
		cout << count << ' ';	//迴圈敘述
	} while (count++ < 9);	//設定while條件運算式
	cout << endl;    //跳行 
	return 0;
}
