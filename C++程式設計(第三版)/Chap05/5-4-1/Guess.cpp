// Guess.cpp
// --------------------------------------
#include <iostream>
using namespace std;
// ------ �D�{�� --------------------
int main() 
{
	char Secret1 = 'D', Secret2 = 'd';
	char Guess;

	do
	{
		cout << "�п�J�@�ӱqA��E���r���G" << endl ;
		cin >> Guess;	
	} while ((Guess != Secret1) &&(Guess != Secret2)); 

	cout << "�A�q��F�A�N�O" << Secret1 << endl ;
	system("pause");
	return 0;
} 
