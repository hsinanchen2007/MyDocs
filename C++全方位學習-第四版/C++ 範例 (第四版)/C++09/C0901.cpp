//�ɮצW�١Gd:\C++09\C0901.cpp
#include <iostream>
#include <cstring>	//���J�r����D��
using namespace std;

int main(int argc, char** argv)
{
	char instr[80];
	cout << "�п�J�r��G";	//��ܰT���r��
	cin.getline (instr, 80, '\n');	//���o��J�r��C
	cout << "�r����׬��G" << strlen(instr);	//��ܦr�����
	cout << endl;
	return 0;
}
