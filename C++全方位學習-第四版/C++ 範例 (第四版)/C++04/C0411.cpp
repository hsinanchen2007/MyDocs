//�x�s�ɦW�Gd:\C++04\C0411.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int year;
	cout << "�п�J�褸�~���G";
	cin >> year;
	if((year%400 == 0) || ((year%4 == 0) && (year%100 != 0))) 
		cout << year << "�O�|�~\n";	//�h���year�O�|�~
	else			//�_
		cout << year << "���O�|�~\n";	//�h���year���O�|�~
	return 0;
}
