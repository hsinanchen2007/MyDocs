// ModifyString.cpp
#include <string>
#include <iostream>
using namespace std;

// ---�D�{��------------------------
int main()
{
	string S1("0123456789");
	string S2("abcdefghi");
	string S3("���� do it");
	string S4;
	string S5 ("���׬O 123");
	string S6(1,'A');
	string S7(S3,1,3);
	string S8 (S3, 2, 5);
	cout << "(1)  S3 ��Ӫ����e�O: " << endl;
	cout << "     " << S3 << endl;
	cout << "     ���� string S8 (S3, 2, 5); ��\n" 
		<< "     S8 = " << S8 << endl;
	cout << "(2)  S1 ��Ӫ����e�O: " << endl;
	cout << "     " << S1 << endl;
	S1.resize(7);
	cout << "     ���� S1.resize(7); ��\n " 
		<< "    S1 = " << S1 << endl;
	cout << "(3)  S5 ��Ӫ����e�O: " << endl;
	cout << "     " << S5 << endl;
	S5='A';
	cout << "     ���� S5 ='A'; ��\n " 
		<< "     S5 = " << S5 << endl;
	cout << "(4)  S1 ��Ӫ����e�O:" << endl;
	cout << "     " << S1 << endl;
	cout << "     S3 ��Ӫ����e�O:" << endl;
	cout << "     " << S3 << endl;
	S3=S1.substr(2,5);
	cout << "     ���� S3=S1.substr(2,5); ��." << endl;
	cout << "     S3 �����e�O:" << endl;
	cout << "     " << S3 << endl;
	cout << "(5)  S1 ��Ӫ����e�O:" << endl;
	cout << "     " << S1 << endl;
	S1.erase(1,3);
	cout << "     ���� S1.erase(1,3); ��." << endl;
	cout << "     S1 �����e�O:" << endl;
	cout << "     " << S1 << endl;
	cout << "(6)  ���� S4=S1+S3; ��." << endl;
	S4=S1+S3;
	cout << "     S4 �����e�O:" << endl;
	cout << "     " << S4 << endl;
	system("PAUSE");
	return 0;
}

