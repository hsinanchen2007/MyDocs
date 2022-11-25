//儲存檔名：d:\C++03\C0319.cpp
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv)
{
	unsigned seed;	//unsigned int seed;
	cout << "請輸入種子數：";
	cin >> seed;	//輸入種子數
	srand(seed);	//設定亂數種子數
	cout << rand() << endl;	//輸出亂數
	cout << rand() << endl;	//輸出亂數
	cout << rand() << endl;	//輸出亂數
	return 0;
}
