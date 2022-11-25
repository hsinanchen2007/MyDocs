//d:\Ex15\Ex1502.cpp
//附加文字檔
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
		cout << "開啟附加檔案錯誤！\n";
        exit(0);
	} else {
		for (int i=4; i<=4; i++) {
			cout << "\n請輸入第 " << i << " 筆姓名：";
			cin >> name;
			cout << "請輸入第 " << i << " 筆電話：";
			cin >> phone;
			cout << "請輸入第 " << i << " 筆Email：";
			cin >> email;
			filePtr << setw(15) << name << setw(15) << phone << setw(25) << email << endl;
		}
		filePtr.close();
	}
	system("PAUSE");
	return 0;
}
