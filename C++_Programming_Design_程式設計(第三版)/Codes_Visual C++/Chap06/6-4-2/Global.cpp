// Global.cpp
// --------------------------------------
#include <iostream>
using namespace std;

int GLOBAL = 1, GLOBAL_2 = 7; //�����ܼ�
// -----  ��� TestFnc () ���ŧi ------
void TestFnc();

// ------ �D�{�� -------------------- 
int main()
{
	int Local = 3;                // �����ܼ�

	GLOBAL = 9;   
	cout  << "GLOBAL ���ȭ�ӬO�G"
		<< GLOBAL << endl;
	cout  << "Local  ���ȭ�ӬO�G"
		<< Local  << endl;
	cout  << endl;

	TestFnc(); 

	cout  << "�I�s TestFnc()����."<< endl;
	cout  << "GLOBAL ���ȥثe�O�G"
		<< GLOBAL << endl;
	cout  << "Local  ���ȥثe�O�G"
		<< Local  << endl;    

	system("PAUSE");
	return 0;
}
//------------------------------------
void TestFnc()
{
	int Local = 2;                // �P�D�{�����ܼƦP�W�������ܼ�
	int GLOBAL_2 = 20;   // �P�����ܼƦP�W�������ܼ�

	Local  += 10;
	GLOBAL += 10;
	cout << "GLOBAL_2   ���ȬO�G"
		<< GLOBAL_2    << endl;
	cout << "::GLOBAL_2 ���ȬO�G"
		<< ::GLOBAL_2  << endl;
	cout  << endl;
}

