//儲存檔名：d:\C++05\C0526.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int count;
	cout << "1 至 30 間 3 的倍數為：";
	for (count = 1; count <= 30; count++)	//定義迴圈
	{
		if (count % 3 != 0)	//若不是3的倍數
			continue;	//返回迴圈起點
		cout << count << '\0';	//顯示3的倍數並空格
	}
	cout << endl;	//輸出跳行
	return 0;
}
