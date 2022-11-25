//檔案名稱：d:\VC++07\VC0704\VC0704.cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv)
{
	int a[2][3] = { { 87, 93, 85 },	//起始a[0][0]~a[0][2]
	{ 95, 85, 90 } };	//起始a[1][0]~a[1][2]
	int sum[2] = { 0, 0 };		//定義與起始sum陣列

	cout << "學號\t國文\t英文\t數學\t總分\n";
	cout << "----\t----\t----\t----\t----\n";
	for (int i = 0; i<2; i++)
	{
		cout << " a" << i << '\t';	//輸出學號
		for (int j = 0; j<3; j++)
		{
			cout << setw(3) << a[i][j] << '\t';	//輸出個人成績
			sum[i] += a[i][j];		//計算個人總和
		}
		cout << setw(4) << sum[i] << endl;	//輸出總和
	}
	return 0;
}
