// CharInput.cpp
// --------------------------------------
#include <iostream>
using namespace std;
// ------ �D�{�� --------------------
int main()
{	
	char ch;
	cout << "�п�J�@�Ӧr�� (Y/N):" << endl;
	cin >> ch;
	if ( ch == 'Y' ||ch == 'y' )
		cout << "�z��J�F yes." << endl;
	else
		cout << "�z��J�F No."  << endl;
	system("pause");
	return 0;
}


