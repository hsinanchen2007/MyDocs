// CString.cpp
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

// ---�D�{��------------------------
int main()
{
	string S1("012345678");
	string S2("abcdefghi");
	string  S3, S4;
	cout << " (1) S1 ��Ӫ����e�O:" << endl;
	cout << "     " << S1 << endl;
	cout << "     S1.c_str() �i�H�����H cout ��X:" << endl;
	cout << "     " << S1.c_str() << endl;
	char CS[10];
	char* pS = new char[S1.length()+1];
	cout << " (2) pS �O�@�ӥ� strcpy(pS, S1.c_str()) ���ͪ�";
	cout << "  C-style string:" << endl;
	strcpy(pS, S1.c_str());
	cout << "     " << pS << endl;
	cout << " (3) CS �O�@�ӥ� strcpy() �ƻs�ӨӪ��r��}�C:" << endl;
	strcpy(CS, S1.c_str());
	cout << "     " << CS << endl;
	S1.resize(4);
	cout << " (4) S1 �b���H S1.resize(4) ���." << endl;
	cout << "     pS �O (�S������):" << endl;
	cout << "     " << pS << endl;
	const char* pSc;
	cout << " (5) pSc = S1.c_str():" << endl;
	pSc = S1.c_str();
	cout << "     pSc �O:" << endl;
	cout << "     " << pSc << endl;
	S1[2]='A';
	cout << " (6) S1[2] �b���H S1[2]='A' ���." << endl;
	cout << "     pSc �O:" << endl;
	cout << "     " << pSc << endl;
	cout << " (7) S2 ��Ӫ����e�O:" << endl;
	cout << "     " << S2 << endl;
	cout << "     pSc = S2.data():" << endl;
	pSc=S2.data();
	cout << "     pSc �O:" << endl;
	cout << "     " << pSc << endl;
	S2.resize(4);
	cout << " (8) S2 �b���H S2.resize(4) ���." << endl;
	cout << "     pSc �O:" << endl;
	cout << "     " << pSc << endl;

	system("PAUSE");
	return 0;
}

