//d:\Ex09\Ex0902.cpp
//�p��^���r�Ӽ�
#include <iostream>
#include <cctype>
#include <cstring> 
using namespace std;

int wordCount(char []);

int main(int argc, char** argv) {
	char str[80];
	cout << "�п�J�r�� (�i�t�ť�)�G";
	cin.getline(str, 81);

	cout << "�r��G" << str << endl;
	cout << "�r�ꤤ�t�� " << wordCount(str) << " �ӳ�r" << endl;
	system("PAUSE");
	return 0;
}

int wordCount(char array[])
{
	int len = strlen(array);
	bool aflag = false;
	int n = 0;

	for (int i=0; i<=len; i++) {
		if (isalpha(array[i]) != 0) {
			if(aflag == false) {
				n++;
				aflag = true;
			}
		} else {
			aflag = false;
		}
	}
	return n;
}
