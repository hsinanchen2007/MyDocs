//儲存檔名：d:\VC++03\VC0321\VC0321.cpp
#include <iostream>	//插入字串標題檔
#include <cstdlib>	//插入亂數函數標題檔
#include <ctime>	//插入時間函數標題檔
using namespace std;

int main(int argc, char** argv)
{
	srand(time(NULL));	//以時間函數為種子數
	cout << 1 + rand() % (10 - 1 + 1) << endl;	//輸出1-10之間的亂數
	cout << 1 + rand() % (10 - 1 + 1) << endl;	//輸出1-10之間的亂數
	cout << 1 + rand() % (10 - 1 + 1) << endl;	//輸出1-10之間的亂數
	return 0;
}
