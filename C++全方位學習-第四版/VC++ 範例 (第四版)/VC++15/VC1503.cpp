//�ɮצW�١Gd:\VC++15\VC1503\VC1503.cpp
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
	ifstream filePtr;	//�إ��ɮת���(�N��)
	char inData;	//�s���ƽw�İ�

	filePtr.open("d:\\VC++15\\VC1501.txt", ios::in);	//�}��d:\VC++15\VC1501.txt

	if (!filePtr) {	//�Y�}���ɮץN�����~
		cout << "�}���ɮ׿��~�I\n";
		system("PAUSE");
		exit(1);	//�D���`�����{��
	}
	else {		//�Y�}���ɮץN�����T
		while (filePtr.get(inData)) {	//���o��ƨæs�J�w�İ�
			cout << inData;	//��ܸ��
		}
	}
	filePtr.close();	//�����ɮת���(�N��)
	return 0;
}
