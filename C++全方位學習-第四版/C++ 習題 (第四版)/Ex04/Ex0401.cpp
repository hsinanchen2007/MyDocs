//d:\Ex04\Ex0401.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	float chi, eng, mat;
	cout << "�п�J��-�^-�ƤT�즨�Z�A�ϥΪťն��j�G";
	cin >> chi >> eng >> mat;
	float sum = chi + eng + mat;
	float avg = sum /3;
	if(avg >= 90)
		cout << "�z�A�ӡI\n";
	else
		cout << "��A���I\n";
	system("PAUSE");
	return 0;
}
