// ExternA.cpp
// --------------------------------------
#include <iostream>
using namespace std;

int Am, An;					//   �����ܼ�
static int ASx, ASy;		//   static�����ܼ�

// --- ��ƪ��ŧi ------------------------
void Func1();
void Func2();
void Func3();

// ------ �D�{�� ------------------------
int main()
{
	cout << "����L Func1()\n";
	Func1();
	cout << "Am   ���ȬO�G"
		 <<  Am    << endl;
	cout << "An   ���ȬO�G"
		 <<  An    << endl;
	cout <<  endl;   

	cout << "����L Func2()\n";
	Func2();
	cout << "Am   ���ȬO�G"
		 <<  Am    << endl;
	cout << "An   ���ȬO�G"
		 <<  An    << endl;

	cout << "����L Func3()\n";
	Func3();

	system("PAUSE");
	return 0;
}
//------------------------------------
extern int Bp;
void Func3()
{
	cout  << "Bp   ���ȬO�G"
		<< Bp    << endl;
	cout  << endl;
}

