//儲存檔名：d:\C++04\C0409.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	short number;
	cout << "請輸入成績 (0 - 100)：";
	cin >> number;	//輸入數值並存入number
	if (number >= 90 && number <= 100)	//若90<=number<=100則
		cout << "成績甲等\n";	//   輸出字串並結束 if
	else if (number >= 80 && number <= 89)	//若80<=number<=89則
		cout << "成績乙等\n";	//  輸出字串並結束 if
	else if (number >= 70 && number <= 79)	//若70<=number<=79則
		cout << "成績丙等\n";	//  輸出字串並結束 if
	else if (number >= 60 && number <= 69)	//若60<=number<=69則
		cout << "成績丁等\n";	//  輸出字串並結束 if
	else if (number <= 59)	//若number<=59則
		cout << "成績戊等\n";	//  輸出字串並結束 if
	return 0;
}
