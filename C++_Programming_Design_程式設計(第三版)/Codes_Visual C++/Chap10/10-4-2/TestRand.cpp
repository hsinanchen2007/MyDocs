// TestRand.cpp
// --------------------------------------
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;
// �w�q inline ��� Rand() ���� 0 ~ 1  �������ü�
inline double Rand()
{return double(rand())/RAND_MAX;}
//------- �ŧi��� TestRand() ---------
void TestRand();
const int TestNum = 6000;
//------- �D�{�� ----------------------
int main()
{
	cout << setiosflags(ios::right)
		 << setiosflags(ios::fixed)
		 << setiosflags(ios::showpoint)
		 << std::setprecision(4);
	TestRand();

	system("PAUSE");
	return 0;
}
//------- �w�q��� TestRand() ---------
void TestRand()
{
	int Freq[10];
	double Sum, Temp;
	// (1) ��l��
	srand(int(time(0))); 
	for (int i=0; i<10; i++) Freq[i]=0;
	// (2) �s�� 20 �� Rand()
	cout << "�s�� 20 �� Rand(): " << endl;
	for (int i=1; i<=20; i++)
	{
		cout << setw(10) << Rand();
		if (i%5 == 0) cout << endl;
	}
	cout << endl;
	// (3) �έp�s�� TestNum �������G
	Sum = 0.0;
	for (int Roll=0; Roll< TestNum; Roll++)
	{
		Temp = Rand();
		for (int i=1; i<=10; i++)
			if ((Temp<=i*0.1) && (Temp>(i-1)*0.1))
				Freq[i-1]++;
		Sum += Temp;
	}
	cout << "   �d��                    ����   " << endl;
	cout << "--------------------------------- " << endl;
	for (int i=1; i<=10; i++)
	{
		cout << ((i-1)*0.1) << " < Rand() <= "
		<< (i*0.1)
		<< setw(6)    << Freq[i-1] << endl;
	}
	cout << "--------------------------------- " << endl;
	cout << "����: "  << Sum/double(TestNum) << endl;
	return;
}