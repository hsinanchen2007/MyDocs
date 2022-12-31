// Guess.cpp
// --------------------------------------
#include <iostream>
using namespace std;
// ------ 主程式 --------------------
int main() 
{
	char Secret1 = 'D', Secret2 = 'd';
	char Guess;

	do
	{
		cout << "請輸入一個從A至E的字母：" << endl ;
		cin >> Guess;	
	} while ((Guess != Secret1) &&(Guess != Secret2)); 

	cout << "你猜對了，就是" << Secret1 << endl ;
	system("pause");
	return 0;
} 
