//儲存檔名：d:\VC++03\VC0320\VC0320.cpp
#include <iostream>
#include <cstdlib>	//插入亂數函數標題檔
#include <ctime>	//插入時間函數標題檔
using namespace std;

int main(int argc, char** argv)
{
	srand(time(NULL));	//以時間函數為種子數
	cout << rand() << endl;	//輸出亂數
	cout << rand() << endl;	//輸出亂數
	cout << rand() << endl;	//輸出亂數
	return 0;
}
