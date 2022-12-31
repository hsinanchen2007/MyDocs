// ExternA.cpp
// --------------------------------------
#include <iostream>
using namespace std;

int Am, An;					//   办跑计
static int ASx, ASy;		//   static办跑计

// --- ㄧ计 ------------------------
void Func1();
void Func2();
void Func3();

// ------ 祘Α ------------------------
int main()
{
	cout << "磅︽筁 Func1()\n";
	Func1();
	cout << "Am   琌"
		 <<  Am    << endl;
	cout << "An   琌"
		 <<  An    << endl;
	cout <<  endl;   

	cout << "磅︽筁 Func2()\n";
	Func2();
	cout << "Am   琌"
		 <<  Am    << endl;
	cout << "An   琌"
		 <<  An    << endl;

	cout << "磅︽筁 Func3()\n";
	Func3();

	system("PAUSE");
	return 0;
}
//------------------------------------
extern int Bp;
void Func3()
{
	cout  << "Bp   琌"
		<< Bp    << endl;
	cout  << endl;
}

