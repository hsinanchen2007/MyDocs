//d:\Ex15\Ex1502.cpp
//���[��r��
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {
	char name[15];
	char phone[15];
	char email[80];
	ofstream filePtr;
	filePtr.open("d:\\Ex15\\Ex15_1.dat", ios::app);
	if(!filePtr.is_open()) {
		cout << "�}�Ҫ��[�ɮ׿��~�I\n";
        exit(0);
	} else {
		for (int i=4; i<=4; i++) {
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
