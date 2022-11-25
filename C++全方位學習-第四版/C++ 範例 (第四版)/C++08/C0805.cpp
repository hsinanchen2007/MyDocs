//檔案名稱：d:\C++08\C0805.cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv)
{
	bool boolVar = true;	//宣告與起始布林值變數
	int intVar = 65536;	//宣告與起始整數變數
	float floatVar = 123.45f;	//宣告與起始單精度變數
	double doubleVar = 98765.43;	//宣告與起始倍精度變數
	
	bool* boolPtr = &boolVar;	//設定boolVar指標
	int* intPtr = &intVar;	//設定intVar指標
	float* floatPtr = &floatVar;	//設定floatVar指標
	double* doublePtr = &doubleVar;	//設定doubleVar指標

	cout << "變數名稱 \t變數指標\t變數長度\n";	//輸出表頭
	cout << "---------\t--------\t--------\n";	//輸出分隔線
	//輸出變數名稱、指標、與長度
	cout << "bool     \t" << boolPtr << '\t' 	//輸出boolVar指標
	     << setw(5) << sizeof(boolVar) << endl; 	//輸出boolVar長度
	cout << "intVar   \t" << intPtr << '\t'  	//輸出intVar指標
	     << setw(5) << sizeof(intVar) << endl;	//輸出intVar長度
	cout << "floatVar \t" << floatPtr << '\t'  	//輸出floatVar指標
	     << setw(5) << sizeof(floatVar) << endl;	//輸出floatVar長度
	cout << "doubleVar\t" << doublePtr << '\t'  	//輸出doubleVar指標
	     << setw(5) << sizeof(doubleVar) << endl;	//輸出doubleVar長度
	return 0;
}
