// Bubble.cpp
// --------------------------------------
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;
// --- �w�q�˪���� Exchange() ---------------------
template <class T>
void Exchange(T& A, T& B)
{ 
	T Temp;
	Temp = A; A=B; B=Temp;
}
// --- �w�q�˪���� Bubble() -----------------------
template <class T>
void Bubble(T *V, int N )
{
	for (int i=0; i<N; i++)
		for (int j=N-1; j>i; j--)
			if (V[j]<V[j-1])
				Exchange(V[j],V[j-1]); 
	return;
}
// �w�q inline ��� Rand()
inline double Rand()
{return double(rand())/RAND_MAX;}
// ---- �D�{�� -------------------------------------
int main()
{
	srand(int(time(0))); 
	const int Size = 20;
	double Data[Size];
	for (int i=0; i<20; i++)
		Data[i]= 10.0*Rand()-5.0;
	cout << setiosflags(ios::right)
		<< setiosflags(ios::fixed)
		<< setiosflags(ios::showpoint)
		<< setprecision(4);
	cout << "\n���� Bubble() ���e, Data ���ȬO:" 
		<< endl;
	for (int i=0; i<Size; i++)
	{
		cout << setw(10) << Data[i];
		if (i%5 == 4) cout << endl;
	}
	Bubble(Data, Size);
	cout << "\n���� Bubble() ����, Data ���ȬO:" 
		<< endl;
	for (int i=0; i<Size; i++)
	{
		cout << setw(10) << Data[i];
		if (i%5 == 4) cout << endl;
	}
	system("PAUSE");
	return 0;
}
