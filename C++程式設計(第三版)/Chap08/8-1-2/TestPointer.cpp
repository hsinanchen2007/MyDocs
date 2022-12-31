// TestP.cpp
// --------------------------------------
#include <iomanip>
#include <iostream>
using namespace std;

// ----- ¥Dµ{¦¡ ------------------------
int main()
{

	float V[3]={0,1,2};
	float* pV = V;
	cout << "*V     "   << *V     << endl;
	cout << "*(V+1) "   << *(V+1) << endl;
	cout << " V     "   <<  V     << endl;
	cout << "&V     "   << &V     << endl;
	cout << "pV     "   <<  pV    << endl;
	cout << "pV[0]  "   <<  pV[0] << endl;
	cout << "pV[1]  "   <<  pV[1] << endl;
	cout << endl;

	float(* p)[3] = &V;
	cout << " p     "   <<  p     << endl;
	cout << "*p     "   << *p     << endl;
	cout << "*p[0]  "   << *p[0]  << endl;
	cout << "*p[1]  "   << *p[1]  << endl;
	cout << " p[0]  "   <<  p[0]  << endl;
	cout << " p[1]  "   <<  p[1]  << endl;
	system ("pause");
	return 0 ;
}

