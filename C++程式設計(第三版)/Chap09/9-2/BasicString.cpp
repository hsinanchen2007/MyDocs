// BasicString..cpp
// --------------------------------------
#include <iostream>
using namespace std;

// ---�D�{��------------------------
int main()
{
	const int SLength = 20;
	char S1[SLength] = "Hello, �z�n!";
	int I[5]={1, 2, 4, 5, 6};
	char *pS;
	int *pI=I;
	pS=S1;
	cout << "S1     is: " << S1 << endl;
	cout << "pS     is: " << pS << endl;
	cout << "I      is: " << I << endl;
	cout << "pI     is: " << pI << endl;
	cout << "*S1    is: " << *S1 << endl;
	cout << "&S1[0] is: " << &S1[0] << endl;
	cout << "S1[0]  is: " << S1[0] << endl;
	cout << "(void*)S1[0] is: " << (void*)S1[0] << endl;
	cout << "(void*)S1    is: " << (void*)S1    << endl;

	cout << "\n�п�J S1 ���s��:\n";
	cin.getline(S1,SLength); 
	cout << "��J�s�ȫ�, S1 ���Ȭ�:  \n" 
		<< S1 <<  endl;
	system ("pause");
	return 0;
}
