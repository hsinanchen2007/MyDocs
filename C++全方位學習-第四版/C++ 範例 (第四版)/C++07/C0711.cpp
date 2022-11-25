//檔案名稱：d:\C++07\C0711.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int source[3] = {5, 9, 3};	//宣告並起始source陣列
	int target[3];	//宣告target陣列
	int i;
	cout << "複製前\n";
	for (i=0; i<=2; i++)	//輸出迴圈
	{
		cout << "source[" << i << "] = " << source[i] << '\t';
		cout << "target[" << i << "] = " << target[i] << endl;
	}
	for (i=0; i<=2; i++)	//複製迴圈
	{
		target[i] = source[i];	//複製source到target
	}
	cout << "\n複製後\n";
	for (i=0; i<=2; i++)	//輸出迴圈
	{
		cout << "source[" << i << "] = " << source[i] << '\t';
		cout << "target[" << i << "] = " << target[i] << endl;
	}
	for (i=0; i<=2; i++)	//清除迴圈
	{
		target[i] = 0;	//清除target
	}
	cout << "\n清除target後\n";
	for (i=0; i<=2; i++)	//輸出迴圈
	{
		cout << "source[" << i << "] = " << source[i] << '\t';
		cout << "target[" << i << "] = " << target[i] << endl;
	}
	return 0;
}
