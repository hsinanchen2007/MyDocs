// Alias.cpp
// --------------------------------------
#include <iostream>
using namespace std;
//------ �D�{�� -------------------------------
int main()
{
	int N = 10;
	int& M = N;

	cout<< "M ���ȭ�ӬO�G"<< M << endl;
	cout<< "N ���ȭ�ӬO�G"<< N << endl;
	N = 5;
	cout<< "���� �uN = 5;�v ����" << endl;
	cout<< "M ���ȥثe�O�G"  << M <<endl;
	M = 2;
	cout<< "���� �uM = 2;�v ����" << endl;
	cout<< "N ���ȥثe�O�G"  << N <<endl; 

	system("PAUSE");
	return 0;
}

