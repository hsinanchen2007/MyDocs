//檔案名稱：d:\VC++07\VC0703\VC0703.cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv)
{
	char ascii[10] = { '0', '1', '2', '3', '4',
		'5', '6', '7', '8', '9' };	//宣告並起始字元陣列

	cout << "字元\tASCII碼\n";	//輸出表頭
	cout << "----\t-------\n";	//輸出表頭
	for (int count = 0; count <= 9; count++)	//for count = 0 to 9
	{
		cout << setw(3) << ascii[count] << '\t';	//輸出數字
		cout << setw(5) << int(ascii[count]);	//輸出對應的ASCII碼
		cout << endl;
	}
	return 0;
}
