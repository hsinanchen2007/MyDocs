//檔案名稱：d:\VC++08\VC0817\VC0817.cpp
#include <iostream>
using namespace std;

void capital(char *);	//宣告函數原型

int main(int argc, char** argv)
{
	char str[] = "You will never win, if you never begin.\n";
	char *strPtr = &str[0];	//宣告並起始C字串指標
	cout << "資料列：" << str;
	capital(strPtr);	//傳遞字串指標給capital
	cout << "更改後：" << str;
	return 0;
}

void capital(char *s)	//第一個字母改大寫函數
{
	while (*s != NULL)	//若不是字串結尾則繼續
		if (*s++ == ' ') {	//若*s == ' '
			*s -= 32;	//則*s++ -= 32
		}
}
