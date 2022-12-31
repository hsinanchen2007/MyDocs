// St2Num.cpp
// --------------------------------------
#include <iostream>
#include <cstdlib> 
using namespace std;

// ---主程式------------------------
int main()
{
	const int SLength = 20;
	char S1[SLength] = " 320";
	char S2[SLength] = " 60.5";
	char *pS1, *pS2;
	int Num = 365;
	pS1=S1;
	pS2=S2;

	cout << "\n"
		<< "320 + 5 的值為 :  " 
		<<  atoi(pS1)+5  << endl;

	cout << "\n"
		<< "60.5 + 5 的值為:  " 
		<< atof(pS2)+5  << endl;

	itoa(Num, S2, 10);
	cout << "\n"
		<< "S2 的值 (十進位) 為:  " 
		<< S2  << endl;

	itoa(Num, S2, 16);
	cout << "\n"
		<< "S2 的值 (十六進位) 為:  0x" 
		<< S2  << endl;

	itoa(Num, S2, 2);
	cout << "\n"
		<< "S2 的值 (二進位) 為:  " 
		<< S2  << endl;
	system ("pause");    
	return 0;
}
