//�ɮצW�١Gd:\VC++15\VC1502\VC1502.cpp
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
	ofstream filePtr;	//�إ��ɮת���(�N��)
	filePtr.open("d:\\VC++15\\VC1501.txt", ios::app);	//�}��d:\VC++15\VC1501.txt

	if (!filePtr.is_open()) {	//�Y�}���ɮץN�����~
		cout << "�}���ɮ׿��~�I\n";
		system("PAUSE");
		exit(1);	//�D���`�����{��
	}
	else {	//�_�h
		filePtr << "�H�ͪ��T���O²�檺�A�i�O�Ѧѹ��a���ۡA\n";	//���[�r����ɮ�
		filePtr << "�`�n��Q�X�d��ʭp���k�פH�ͨӱo²��ǡC\n";	//���[�r����ɮ�
	}
	filePtr.close();	//�����ɮת���(�N��)
	return 0;
}
