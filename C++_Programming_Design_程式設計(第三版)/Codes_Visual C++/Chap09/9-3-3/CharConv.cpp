// CharConv.cpp
// --------------------------------------
#include <iostream>
#include <cctype> 
using namespace std;

// ---主程式------------------------
int main()
{
	const int SLength = 60;
	char S1[SLength], Ch;

	cout << "請輸入一句英文：" << endl;
	cin.getline(S1,SLength);
	for (int i=0; S1[i]!='\0';i++)
		S1[i] = toupper(S1[i]);
	cout << "此句英文轉成大寫後是："  << endl;
	cout << S1 << endl;

	cout << "請輸入一個字元：" << endl;
	Ch = cin.get();

	if (isalpha (Ch))
		cout << "您輸入了一個英文字母" << endl;
	else
		cout << "您輸入的不是英文字母" << endl;
	system ("pause");
	return 0;
}

