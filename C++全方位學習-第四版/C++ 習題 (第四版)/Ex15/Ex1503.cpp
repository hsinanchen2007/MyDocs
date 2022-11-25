//d:\Ex15\Ex1503.cpp
//讀取文字檔
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
	char inData;
	ifstream filePtr;
	filePtr.open("d:\\Ex15\\Ex15_1.dat", ios::in);
	if(!filePtr.is_open()) {
		cout << "開啟檔案錯誤！\n";
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
