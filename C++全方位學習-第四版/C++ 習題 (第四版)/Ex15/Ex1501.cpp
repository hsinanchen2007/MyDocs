//d:\Ex15\Ex1501.cpp
//�g�J��r��
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {
	char name[15];
	char phone[15];
	char email[80];
	ofstream filePtr;
	filePtr.open("d:\\Ex15\\Ex15_1.dat", ios::out);
	if(!filePtr.is_open()) {
		cout << "�}�ҿ�X�ɮ׿��~�I\n";
        exit(0);
   	} else {
        filePtr.setf(ios::left);
		filePtr << setw(15) << "�m�W" << setw(15) << "�q��" << setw(25) << "email" << endl;
		for (int i=1; i<=3; i++) {
			cout << "\n�п�J�� " << i << " ���m�W�G";
			cin >> name;
			cout << "�п�J�� " << i << " ���q�ܡG";
			cin >> phone;
			cout << "�п�J�� " << i << " ��Email�G";
			cin >> email;
			filePtr << setw(15) << name << setw(15) << phone << setw(25) << email << endl;
		}
		filePtr.close();
	}
	system("PAUSE");
	return 0;
}
