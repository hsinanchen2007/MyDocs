//�ɮצW�١Gd:\VC++09\VC0916\VC0916.cpp
#include <iostream>
#include <string>	//C++���Astring���D��
using namespace std;

int main(int argc, char** argv)
{
	string s1("Visual C++"), s2("ANSI/ISO C++");
	cout << "��իe�G\n";
	cout << "s1 = " << s1 << endl;	//s1 = "Visual C++"
	cout << "s2 = " << s2 << endl;	//s2 = "ANSI/ISO C++"

	s1.swap(s2);	//s1�Ps2���
	cout << "��ի�G\n";
	cout << "s1 = " << s1 << endl;	//s1 = "ANSI/ISO C++"
	cout << "s2 = " << s2 << endl;	//s2 = "Visual C++"
	return 0;
}
