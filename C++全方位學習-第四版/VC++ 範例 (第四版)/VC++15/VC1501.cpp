//�ɮצW�١Gd:\VC++15\VC1501\VC1501.cpp
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
	ofstream filePtr;	//�إ��ɮת���(�N��)
	filePtr.open("d:\\VC++15\\VC1501.txt", ios::out);	//�}�ҿ�X��VC1501.txt
	if (!filePtr.is_open()) {	//�Y�}���ɮץN�����~
		cout << "�}���ɮ׿��~�I\n";
		system("PAUSE");
		exit(1);	//�D���`�����{��
	}
	else {		//�_�h
		filePtr << "Life is not easy, but in the long run \n";
		filePtr << "it's easier than going to elaborate ends \n";
		filePtr << "to deny it.\n";	//�g�J�r����ɮ�
	}
	filePtr.close();	//�����ɮת���(�N��)
	return 0;
}
