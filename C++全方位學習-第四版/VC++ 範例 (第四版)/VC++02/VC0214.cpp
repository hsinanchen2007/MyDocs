//儲存檔名：d:\VC++02\VC0214\VC0214.cpp
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	double dType;

	cout << "int 型態的位元組數 = "
		<< sizeof(int) << "bytes\n";	//取得int型態大小
	cout << "short 型態的位元組數 = "
		<< sizeof(short) << "bytes\n";	//取得short型態大小
	cout << "bool 型態的位元組數 = "
		<< sizeof(bool) << "bytes\n";	//取得bool型態大小
	cout << "變數dType的位元組數 = "
		<< sizeof(dType) << "bytes\n";	//取得變數dType的大小
	return 0;
}
