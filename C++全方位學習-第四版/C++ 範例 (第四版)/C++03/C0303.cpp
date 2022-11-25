//儲存檔名：d:\C++03\C0303.cpp
#include <iostream>
#include <iomanip>	//包含setw()的標題檔
using namespace std;

int main(int argc, char** argv)
{
	int n11 = 14, n12 = 21474836, n13 = 44;
	int n21 = -889162, n22 = 9, n23 = 524;
	cout << setw(12) << n11 	//設定12空間給n11輸出
		   << setw(12) << n12 	//設定12空間給n12輸出
		   << setw(12) << n13	//設定12空間給n13輸出
		   << endl;	//跳至下一行
	cout << setw(12) << n21 	//設定12空間給n21輸出
		   << setw(12) << n22 	//設定12空間給n22輸出
		   << setw(12) << n23 	//設定12空間給n23輸出
		   << endl;	//跳至下一行
	return 0;
}
