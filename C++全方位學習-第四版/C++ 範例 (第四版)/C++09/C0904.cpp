//�ɮצW�١Gd:\C++09\C0904.cpp
#include <iostream>
#include <cstring>	//���J�r����D��
using namespace std;

int main(int argc, char** argv)
{
	char first[80], last[80], full[160] = "";
	cout << "�п�J�^��W�r (first name)�G";	//��ܰT���r��
	cin.getline (first, 80, '\n');	//���o�W�r�r��
	cout << "�п�J�^��m�� (last name) �G";	//��ܰT���r��
	cin.getline (last, 80, '\n');	//���o�m��r��
	strcat(full, first);	//���[�W�r�r��
	strcat(full, " ");	//���[�ťզr��
	strcat(full, last);	//���[�m��r��
	cout << "�z�����W���G" << full << endl;	//��ܥ��W�r��
	return 0;
}
