//檔案名稱：d:\VC++08\VC0803\VC0803.cpp
#include <iostream>
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

	cout << "變數名稱 \t變數位址\t變數指標\n";	//輸出表頭
	cout << "---------\t--------\t--------\n";	//輸出分隔線
												//輸出變數名稱、位址、與指標
	cout << "bool     \t" << &boolVar << '\t' << boolPtr << endl;
	cout << "intVar   \t" << &intVar << '\t' << intPtr << endl;
	cout << "floatVar \t" << &floatVar << '\t' << floatPtr << endl;
	cout << "doubleVar\t" << &doubleVar << '\t' << doublePtr << endl;
	return 0;
}
