//�x�s�ɦW�Gd:\VC++05\VC0522\VC0522.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	char string[25] = "ANSI/ISO C++";	//�ŧi�P�ҩl�r��
	char letter;	//�ŧi�r���ܼ�
	int count;	//�ŧi����ܼ�
	for (count = 0; count <= 24; count++)	//�Q�ΰj����ܦr���ܼ�
	{
		cout << string[count];
	}
	cout << "\n�п�J�n�j�M���r���G";	//��ܦr��`��
	cin >> letter;	//��J�r��
	for (count = 0; count <= 24; count++)	//�w�q�j��
	{
		if (string[count] == letter)	//���۲Ŧr��
			break;	//���_�j��
	}
	if (count <= 24)	//�Y�p�ƭ�<=�r�����
		cout << "�� " << ++count << " �Ӧr���� "	//�h��ܦr���m
		<< letter << '\n';
	else
		cout << "�䤣��۲Ŧr��\n";	//�_�h��ܧ䤣��
	return 0;
}
