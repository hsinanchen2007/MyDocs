// CharConv.cpp
// --------------------------------------
#include <iostream>
#include <cctype> 
using namespace std;

// ---�D�{��------------------------
int main()
{
	const int SLength = 60;
	char S1[SLength], Ch;

	cout << "�п�J�@�y�^��G" << endl;
	cin.getline(S1,SLength);
	for (int i=0; S1[i]!='\0';i++)
		S1[i] = toupper(S1[i]);
	cout << "���y�^���ন�j�g��O�G"  << endl;
	cout << S1 << endl;

	cout << "�п�J�@�Ӧr���G" << endl;
	Ch = cin.get();

	if (isalpha (Ch))
		cout << "�z��J�F�@�ӭ^��r��" << endl;
	else
		cout << "�z��J�����O�^��r��" << endl;
	system ("pause");
	return 0;
}

