//檔案名稱：d:\C++08\C0819.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int num = 100;	//宣告並起始變數
	int *ptr1 = &num;	//定義變數指標
	cout << "*ptr1 = " << *ptr1 << endl;

	int *ptr2;	//宣告指標
	ptr2 = new int(200);	//配置並起始指標內值
	cout << "*ptr2 = " << *ptr2 << endl;
	delete ptr2;	//釋放ptr2指標

	int *ptr3 = new int(300);	//宣告並起始指標內值
	cout << "*ptr3 = " << *ptr3 << endl;
	delete ptr3; 	//釋放ptr3指標
	return 0;
}
