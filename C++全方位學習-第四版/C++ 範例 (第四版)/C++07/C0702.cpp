//檔案名稱：d:\C++07\C0702.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int a[3] ={87, 93, 85};	//定義與起始陣列
	int sum = 0;		//定義與起始變數

	for(int i=0; i<3; i++)
	{
		cout << "a[" << i << "] = " << a[i] << endl;	//輸出陣列內容
		sum += a[i];		//計算總和
	}
	cout << "總和 = " << sum << endl;	//輸出總和
	return 0;
}
