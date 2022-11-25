//檔案名稱：d:\VC++08\VC0802\VC0802.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int number = 10;	//宣告整數變數
	int *numPtr = 0;	//宣告指標變數
	cout << "number = " << number << endl;	//輸出number值
	cout << "numPtr(未起始) = " << numPtr << endl;	//輸出未起始指標

	numPtr = &number;	//numPtr是number指標
	cout << "*numPtr = " << *numPtr << endl;	//輸出間接取得的資料
	cout << "numPtr = &number = " << numPtr << endl;    //輸出number指標
	return 0;
}
