//儲存檔名：d:\VC++06\VC0601\VC0601.cpp
#include <iostream>
using namespace std;

void womain(void)	//使用者函數
{
	cout << "Womain: I'm doing good. How about you?";
	cout << endl;
}

int main(int argc, char** argv)
{
	cout << "Main: Hi! How are you doing?" << endl;
	womain();	//呼叫使用者函數womain
	cout << "Main: Very well! Thank you!" << endl;
	return 0;
}
