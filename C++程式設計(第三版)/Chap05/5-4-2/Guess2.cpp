// Guess2.cpp
// --------------------------------------
#include <iostream>
using namespace std;
// ------ �D�{�� --------------------
int main() 
{
	char Secret1 = 'D', Secret2 = 'd';
	char Guess   = 'z';

	while((Guess != Secret1) &&(Guess != Secret2))
	{ 
		cout << "�п�J�@�ӱqA��E���r���G" << endl ;
		cin >> Guess;	
	}

	cout << "�A�q��F�A�N�O" << Secret1 << endl ;
	system("PAUSE");
	return 0;
}