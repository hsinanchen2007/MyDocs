//�ɮצW�١Gd:\VC++09\VC0918\VC0918.cpp
#include <iostream>
#include <string>	//C++���Astring���D��
using namespace std;

int main(int argc, char** argv)
{
	string s("call by reference");	//�ŧi�ð_�l�r��s

	cout << "���N�e���r��G" << s << endl;

	unsigned int p = s.find(" ");	//��M�Ĥ@�Ӫť�
	while (p<string::npos)	// �Y������r�굲���h�~��
	{
		s.replace(p, 1, "-");	//����H"�V"���N" "
		p = s.find(" ", ++p);	//��M�U�@�Ӫť�
	}
	cout << "���N�᪺�r��G" << s << endl;
	return 0;
}
