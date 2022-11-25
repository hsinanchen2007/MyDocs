//儲存檔名：d:\C++04\C0411.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int year;
	cout << "請輸入西元年份：";
	cin >> year;
	if((year%400 == 0) || ((year%4 == 0) && (year%100 != 0))) 
		cout << year << "是閏年\n";	//則顯示year是閏年
	else			//否
		cout << year << "不是閏年\n";	//則顯示year不是閏年
	return 0;
}
