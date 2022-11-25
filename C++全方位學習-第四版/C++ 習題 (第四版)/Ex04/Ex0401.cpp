//d:\Ex04\Ex0401.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	float chi, eng, mat;
	cout << "請輸入國-英-數三科成績，使用空白間隔：";
	cin >> chi >> eng >> mat;
	float sum = chi + eng + mat;
	float avg = sum /3;
	if(avg >= 90)
		cout << "哇，帥！\n";
	else
		cout << "喔，遜！\n";
	system("PAUSE");
	return 0;
}
