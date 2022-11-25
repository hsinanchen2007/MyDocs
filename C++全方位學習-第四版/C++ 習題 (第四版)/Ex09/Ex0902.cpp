//d:\Ex09\Ex0906.cpp
//西式日期轉成中式日期
#include <iostream>
using namespace std;

void convertDate(string [], char []);

int main(int argc, char** argv) {
	string c[12] = {"○", "一", "二", "三", "四", "五",
		        "六", "七", "八", "九", "十"};
	char date[11];
	cout << "請輸入日期 (mm/dd/yyyy)：";
	cin >> date;
	for(int i=0; i<10; i++) {
		date[i] -= 48;
	}
	cout << "中文日期格式：";
	convertDate(c, date);
	system("PAUSE");
	return 0;
}

void convertDate(string c[], char date[])
{
	cout << c[date[6]] << c[date[7]] << c[date[8]] << c[date[9]] << "年";
	if(date[0] != 0)
		cout << c[10] << c[date[1]] << "月";
	else
		cout << c[date[1]] << "月";
	if(date[3] != 0)
		cout << c[date[3]] << c[date[4]] << "日\n";
	else
		cout << c[date[4]] << "日\n";
}
