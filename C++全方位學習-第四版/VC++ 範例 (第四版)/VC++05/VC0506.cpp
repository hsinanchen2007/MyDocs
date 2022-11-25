//儲存檔名：d:\VC++05\VC0506\VC0506.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	unsigned int year;
	cout << "請輸入西元年份，若輸入 0 則結束：";
	cin >> year;
	while (year != '\0')	//若輸入不是0則迴圈成立
	{
		if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
			//若(year是400倍數)或(year是4的倍數且不是100的倍數) 
			cout << year << "年是閏年";	//則顯示year不是閏年
		else
			cout << year << "不年是閏年";	//則顯示year不是閏年

		cout << "\n請輸入西元年份，若輸入 0 則結束：";
		cin >> year;
	}
	return 0;
}
