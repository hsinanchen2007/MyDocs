// TestDice.cpp
// --------------------------------------
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;
// ﹚竡 inline ㄧ计 RandI()
inline int RandI(int N)
{return rand()%N+1;}
//------- ㄧ计 TestDice() ---------
void TestDice();
const int TestNum = 6000;
//------- 祘Α ----------------------
int main()
{
	cout << right << fixed << showpoint << setprecision(4);
	cout << "RAND_MAX  (0x7FFFU) 琌 :"
		<< setw(7) << RAND_MAX  << endl;
	TestDice();
	system("PAUSE");
	return 0;
}
//------- ﹚竡ㄧ计 TestDice() ---------
void TestDice()
{
	int Freq[6], Face, i;
	for (i=0; i<6; i++) Freq[i]=0;
	// (1) ﹍て  
	srand(int(time(0))); 
	// (2) 硈耏 20 Ω
	cout << "硈耏 20 Ω挡狦: " << endl;
	for (i=1; i<=20; i++)
	{
		cout << setw(5) << RandI(6);
		if (i%5 == 0) cout << endl;
	}
	cout << endl;
	// (3) 参璸硈耏 TestNum Ω挡狦
	for (int Roll=0; Roll< TestNum; Roll++)
	{
		Face = RandI(6);
		Freq[Face-1]++;
	}
	cout << "   翴计    Ω计   "  << endl;
	cout << "------------------ " << endl;
	for (i=0; i<6; i++)
		cout << setw(5)  << (i+1)
		<< setw(10) << Freq[i] << endl;
	cout << "------------------ " << endl;
	return;
}