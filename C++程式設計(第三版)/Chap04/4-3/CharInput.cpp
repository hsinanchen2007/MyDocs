// CharInput.cpp
// --------------------------------------
#include <iostream>
using namespace std;
// ------ 主程式 --------------------
int main()
{	
	char ch;
	cout << "請輸入一個字元 (Y/N):" << endl;
	cin >> ch;
	if ( ch == 'Y' ||ch == 'y' )
		cout << "您輸入了 yes." << endl;
	else
		cout << "您輸入了 No."  << endl;
	system("pause");
	return 0;
}


