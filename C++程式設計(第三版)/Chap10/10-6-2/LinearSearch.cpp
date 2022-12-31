// LinearSearch.cpp
// --------------------------------------
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;
// --- �w�q�˪���� LinSearch() -----------------------
template <class T>
int LinSearch(T *V, int N , T Key)
{
	for (int i=0; i<N; i++)
	{ 
		if (V[i] == Key) 
			return i; 
	}
	return -1;
}
// -- �w�q inline ��� RandI() ���� 1~N �������ü� ------
inline int RandI(int N)
{
	return rand()%N+1;
}
// ---- �D�{�� -------------------------------------
int main()
{
	int Index;
	int Key = 32;
	srand(int(time(0))); 
	const int Size = 20;
	int Data[Size];
	for (int i=0; i<20; i++)
		Data[i]= RandI(85);
	cout << "\nData ���ȬO:" 
		<< endl;
	for (int i=0; i<Size; i++)
	{
		cout << setw(10) << Data[i];
		if (i%5 == 4) cout << endl;
	}
	Index = LinSearch(Data, Size, Key);
	if (Index > -1)
		cout << Key << " �b�� " << Index+1 
		<< " �Ӥ������a��." << endl;
	else
		cout << "�䤣�� " << Key << endl;
	system("PAUSE");
	return 0;
}
