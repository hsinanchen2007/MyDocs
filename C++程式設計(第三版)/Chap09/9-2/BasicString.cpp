// BasicString..cpp
// --------------------------------------
#include <iostream>
using namespace std;

// ---主程式------------------------
int main()
{
	const int SLength = 20;
	char S1[SLength] = "Hello, 您好!";
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

	cout << "\n請輸入 S1 的新值:\n";
	cin.getline(S1,SLength); 
	cout << "輸入新值後, S1 的值為:  \n" 
		<< S1 <<  endl;
	system ("pause");
	return 0;
}
