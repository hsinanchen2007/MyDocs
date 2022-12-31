// TestDice.cpp
// --------------------------------------
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;
// �w�q inline ��� RandI()
inline int RandI(int N)
{return rand()%N+1;}
//------- �ŧi��� TestDice() ---------
void TestDice();
const int TestNum = 6000;
//------- �D�{�� ----------------------
int main()
{
	cout << right << fixed << showpoint << setprecision(4);
	cout << "RAND_MAX  (0x7FFFU) ���ȬO :"
		<< setw(7) << RAND_MAX  << endl;
	TestDice();
	system("PAUSE");
	return 0;
}
//------- �w�q��� TestDice() ---------
void TestDice()
{
	int Freq[6], Face, i;
	for (i=0; i<6; i++) Freq[i]=0;
	// (1) ��l��  
	srand(int(time(0))); 
	// (2) �s�Y 20 ��
	cout << "�s�Y 20 �������G: " << endl;
	for (i=1; i<=20; i++)
	{
		cout << setw(5) << RandI(6);
		if (i%5 == 0) cout << endl;
	}
	cout << endl;
	// (3) �έp�s�Y TestNum �������G
	for (int Roll=0; Roll< TestNum; Roll++)
	{
		Face = RandI(6);
		Freq[Face-1]++;
	}
	cout << "   �I��    ����   "  << endl;
	cout << "------------------ " << endl;
	for (i=0; i<6; i++)
		cout << setw(5)  << (i+1)
		<< setw(10) << Freq[i] << endl;
	cout << "------------------ " << endl;
	return;
}