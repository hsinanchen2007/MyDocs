//�ɮצW�١Gd:\VC++09\VC0919\VC0919.cpp
#include <iostream>
#include <string>	//C++���Astring���D��
using namespace std;

int main(int argc, char** argv)
{
	string s1("Dev C++"), s2("Visual");	//�ŧi�ð_�l�r��s1,s2
	cout << "���J���e��s2�r��G" << s2 << endl;
	cout << "���J���e��s1�r��G" << s1 << endl;

	s1.insert(3, s2);	//s1=ANSIISO C++
	cout << "���Js2�᪺s1�r��G" << s1 << endl;

	s1.insert(3, "/");	//s1=ANSI/ISO C++
	cout << "���J/�᪺s1�r�� �G" << s1 << endl;
	return 0;
}
