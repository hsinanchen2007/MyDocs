// Condition.cpp
// --------------------------------------
#include <iostream>
using namespace std;
// ------ �D�{�� --------------------
int main()
{	
	float a, b;
	int N;

	// (1)
	cout << "(1) �п�J��Ӽ�" << endl;
	cout << "�п�J�Ĥ@�Ӽ� a:" << endl;
	cin  >> a;
	cout << "�п�J�ĤG�Ӽ� b:" << endl;
	cin  >> b;
	cout << "a , b ��̤����j���O "
		<<  ( a > b ? 'a' : 'b' )  <<  endl ;
	cout << endl;

	// (2)
	cout << "(2) �п�J�@�Ӿ�� N:" << endl;
	cin  >>  N;
	cout <<  "N �O"
		<< ( N % 2  ?  "�_��" : "����") 
		<<  endl ;
	system("pause");
	return 0;
}
