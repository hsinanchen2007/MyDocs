// Guess2.cpp
// --------------------------------------
#include <iostream>
using namespace std;
// ------ 主程式 --------------------
int main() 
{
	char Secret1 = 'D', Secret2 = 'd';
	char Guess   = 'z';

	while((Guess != Secret1) &&(Guess != Secret2))
	{ 
		cout << "請輸入一個從A至E的字母：" << endl ;
		cin >> Guess;	
	}

	cout << "你猜對了，就是" << Secret1 << endl ;
	system("PAUSE");
	return 0;
}