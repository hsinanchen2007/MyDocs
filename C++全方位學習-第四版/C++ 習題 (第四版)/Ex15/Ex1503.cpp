//d:\Ex15\Ex1503.cpp
//Ū����r��
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
	char inData;
	ifstream filePtr;
	filePtr.open("d:\\Ex15\\Ex15_1.dat", ios::in);
	if(!filePtr.is_open()) {
		cout << "�}���ɮ׿��~�I\n";
        exit(0);
	} else {
		for (int i=1; i<=4; i++) {
			while(filePtr.get(inData)) {
				cout << inData;
			}
		}
		filePtr.close();
	}
	system("PAUSE");
	return 0;
}
