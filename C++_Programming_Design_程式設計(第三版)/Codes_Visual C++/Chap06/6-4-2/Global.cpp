// Global.cpp
// --------------------------------------
#include <iostream>
using namespace std;

int GLOBAL = 1, GLOBAL_2 = 7; //办跑计
// -----  ㄧ计 TestFnc ()  ------
void TestFnc();

// ------ 祘Α -------------------- 
int main()
{
	int Local = 3;                // Ы场跑计

	GLOBAL = 9;   
	cout  << "GLOBAL ㄓ琌"
		<< GLOBAL << endl;
	cout  << "Local  ㄓ琌"
		<< Local  << endl;
	cout  << endl;

	TestFnc(); 

	cout  << "㊣ TestFnc()ぇ."<< endl;
	cout  << "GLOBAL ヘ玡琌"
		<< GLOBAL << endl;
	cout  << "Local  ヘ玡琌"
		<< Local  << endl;    

	system("PAUSE");
	return 0;
}
//------------------------------------
void TestFnc()
{
	int Local = 2;                // 籔祘Αず跑计Ы场跑计
	int GLOBAL_2 = 20;   // 籔办跑计Ы场跑计

	Local  += 10;
	GLOBAL += 10;
	cout << "GLOBAL_2   琌"
		<< GLOBAL_2    << endl;
	cout << "::GLOBAL_2 琌"
		<< ::GLOBAL_2  << endl;
	cout  << endl;
}

