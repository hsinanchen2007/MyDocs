//�x�s�ɦW�Gd:\VC++05\VC0506\VC0506.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	unsigned int year;
	cout << "�п�J�褸�~���A�Y��J 0 �h�����G";
	cin >> year;
	while (year != '\0')	//�Y��J���O0�h�j�馨��
	{
		if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
			//�Y(year�O400����)��(year�O4�����ƥB���O100������) 
			cout << year << "�~�O�|�~";	//�h���year���O�|�~
		else
			cout << year << "���~�O�|�~";	//�h���year���O�|�~

		cout << "\n�п�J�褸�~���A�Y��J 0 �h�����G";
		cin >> year;
	}
	return 0;
}
