// StringPArray.cpp
// --------------------------------------
#include <iostream>
using namespace std;

// ---���FindSeason()���ŧi--------
char* FindSeason(int);

// ---�D�{��------------------------
int main()
{
	int N;
	cout << "\n" 
		<< "�п�J�@�Ӥ��  :  " << endl;
	cin  >> N;
	cout << "\n" 
		<< N << "��O" 
		<< FindSeason(N)<< endl;
	system ("pause");
	return 0;
}

// ---��� FindSeason() ���w�q-----
char* FindSeason(int Month)
{
	int N;
	char* Seasons[]={"�V�u","�K�u","�L�u","��u"};
	if (Month < 1 || Month >12) 
		return "(�z��J������S���N�q)";
	N=(Month%12)/3;
	return Seasons[N];	
}
