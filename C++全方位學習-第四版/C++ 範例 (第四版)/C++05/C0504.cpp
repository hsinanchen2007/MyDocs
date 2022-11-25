//儲存檔名：d:\C++05\C0504.cpp
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int c = 3;	//宣告變數
	cout << c-- << endl;	//輸出c=3後c=3-1=2
	cout << c-- << endl; 	//輸出c=2後c=2-1=1
	cout << c-- << endl; 	//輸出c=1後c=1-1=0
	return 0;
}
