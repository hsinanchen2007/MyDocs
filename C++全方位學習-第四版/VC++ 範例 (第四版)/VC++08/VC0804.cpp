//檔案名稱：d:\VC++08\VC0804\VC0804.cpp
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

	cout << "變數名稱 \t變數等值\t位址內值\t指標內值\n";	//輸出表頭
	cout << "---------\t--------\t--------\t--------\n";	//輸出分隔線
															//輸出變數名稱、變數值、位址內含值、與指標內含值
	cout << "bool     \t"
		<< setw(8) << boolVar << '\t'	//利用變數取得等值
		<< setw(8) << *(&boolVar) << '\t'	//利用位址取得等值
		<< setw(8) << *boolPtr << endl;	//利用指標取得等值
	cout << "intVar   \t"
		<< setw(8) << intVar << '\t' 	//利用變數取得等值
		<< setw(8) << *(&intVar) << '\t'	//利用位址取得等值
		<< setw(8) << *intPtr << endl;	//利用指標取得等值
	cout << "floatVar \t"
		<< setw(8) << floatVar << '\t' 	//利用變數取得等值
		<< setw(8) << *(&floatVar) << '\t'	//利用位址取得等值
		<< setw(8) << *floatPtr << endl;	//利用指標取得等值
	cout << "doubleVar\t"
		<< setw(8) << doubleVar << '\t' 	//利用變數取得等值
		<< setw(8) << *(&doubleVar) << '\t'	//利用位址取得等值
		<< setw(8) << *doublePtr << endl;	//利用指標取得等值
	return 0;
}
