//檔案名稱：d:\VC++10\VC1003\VC1003.cpp
#include <iostream>
using namespace std;

struct Booklist	//宣告Booklist資料結構
{
	char title[21];	//Booklist第1成員變數
	char auther[7];	//Booklist第2成員變數
	char number[10];	//Booklist第3成員變數
	float price;	//Booklist第4成員變數
};

int main(int argc, char** argv)
{
	//定義並起始CPP資料
	Booklist CPP = { "C++ 物件導向程式設計", "古頤榛", "AEL008900", 520.00 };
	//定義並起始VB資料
	Booklist VB = { "VB 2008 教學範本    ", "古頤榛", "AEL005531", 530.00 };

	cout.precision(2); cout.setf(ios::fixed);
	cout << "書名\t\t\t作者\t\t書號\t\t定價\n";
	cout << CPP.title << '\t';	//輸出CPP第1成員資料
	cout << CPP.auther << "\t\t";	//輸出CPP第2成員資料
	cout << CPP.number << '\t';	//輸出CPP第3成員資料
	cout << CPP.price << '\n';	//輸出CPP第4成員資料

	cout << VB.title << '\t';	//輸出VB第1成員資料
	cout << VB.auther << "\t\t";	//輸出VB第2成員資料
	cout << VB.number << '\t';	//輸出VB第3成員資料
	cout << VB.price << '\n';	//輸出VB第4成員資料
	return 0;
}
