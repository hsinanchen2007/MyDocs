//檔案名稱：d:\C++09\C0906.cpp
#include <iostream>
#include <iomanip>
#include <cstdlib>	//轉換數值標題檔
using namespace std;

int main(int argc, char** argv)
{
	char *s; double x; int i; long l;
	setiosflags(ios::fixed|ios::right);	//設定輸出格式
	cout << setw(7) << "字串\t" << setw(23) << "    數值" << endl;

	s = "-1998.12E-25  ";	//定義字串
	x = atof( s );	//轉換成浮點數
	cout << setw(15) << s << "\t" << setw(15) << x << endl;

	s = " 686 pigs     ";	//定義字串
	i = atoi( s );	//轉換成短整數
	cout << setw(15) << s << "\t" << setw(15) << i << endl;

	s = " 98686 dollars";	//定義字串
	l = atol( s );	//轉換成長整數
	cout << setw(15) << s << "\t" << setw(15) << l << endl;
	return 0;
}
