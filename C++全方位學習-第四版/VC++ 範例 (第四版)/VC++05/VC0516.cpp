//儲存檔名：d:\VC++05\VC0516\VC0516.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int count, sum;
	for (count = 11, sum = 0; count > 1; count--, sum += count);
	cout << "10 + 9 + 8 + ... + 1 = " << sum	//輸出字串與總和
		<< endl;	//跳行
	return 0;
}
