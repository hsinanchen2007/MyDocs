//�ɮצW�١Gd:\C++09\C0905.cpp
#include <iostream>
#include <cstring>	//���J�r����D��
#include <cctype>	//���J�ഫ�r����
using namespace std;

int main(int argc, char** argv)
{
	char flexStr[] = "Success is never ending. Failure is never final.";
	cout << "�r���ഫ�e�G" << flexStr << endl;	//����ഫ�e�r��
	int len = strlen(flexStr);	//���o�r�����

	for (int i = 0; i <= len; i++)	//�ন�p�g�j��
		flexStr[i] = tolower(flexStr[i]);	//�ন�p�g�r��
	cout << "�ഫ�p�g��G" << flexStr << endl;	//����ഫ��r��

	for (int i = 0; i <= len; i++)	//�ন�j�g�j��
		flexStr[i] = toupper(flexStr[i]);	//�ন�j�g�r��
	cout << "�ഫ�j�g��G" << flexStr << endl;	//����ഫ��r��
	return 0;
}
