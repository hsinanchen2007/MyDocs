//儲存檔名：d:\VC++03\VC0302\VC0302.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int n11 = 14, n12 = 21474836, n13 = 44;
	int n21 = -889162, n22 = 9, n23 = 524;
	cout << n11 << '\t' 	//輸出n11後跳至下一定位
		<< n12 << '\t' 	//輸出n12後跳至下一定位
		<< n13 << endl;	//輸出n13後跳至下一行
	cout << n21 << '\t' 	//輸出n21後跳至下一定位
		<< n22 << '\t' 	//輸出n22後跳至下一定位
		<< n23 << endl;	//輸出n23後跳至下一行
	return 0;
}
