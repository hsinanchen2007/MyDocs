//d:\Ex09\Ex0906.cpp
//�覡����ন�������
#include <iostream>
using namespace std;

void convertDate(string [], char []);

int main(int argc, char** argv) {
	string c[12] = {"��", "�@", "�G", "�T", "�|", "��",
		        "��", "�C", "�K", "�E", "�Q"};
	char date[11];
	cout << "�п�J��� (mm/dd/yyyy)�G";
	cin >> date;
	for(int i=0; i<10; i++) {
		date[i] -= 48;
	}
	cout << "�������榡�G";
	convertDate(c, date);
	system("PAUSE");
	return 0;
}

void convertDate(string c[], char date[])
{
	cout << c[date[6]] << c[date[7]] << c[date[8]] << c[date[9]] << "�~";
	if(date[0] != 0)
		cout << c[10] << c[date[1]] << "��";
	else
		cout << c[date[1]] << "��";
	if(date[3] != 0)
		cout << c[date[3]] << c[date[4]] << "��\n";
	else
		cout << c[date[4]] << "��\n";
}
