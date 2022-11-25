// BinarySearch.cpp
// --------------------------------------
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;
// --- 定義樣版函數 BiSearch() -----------------------
template <class T>
int BiSearch(T *V, int N , T Key)
{
	int Left=0, Right, Mid;
	Right = N-1;
	while (Left <= Right)
	{
		Mid = (int) ((Left+Right)/2);
		if (Key == V[Mid]) return Mid;
		else if (Key > V[Mid]) 
			Left = Mid +1;
		else
			Right = Mid -1;
	}
	return -1;
}

// 定義 inline 函數 RandI(), 產生 1~N 之間的亂數
inline int RandI(int N)
{
	return rand()%N+1;
}

// --- 定義樣版函數 Exchange() ---------------------
template <class T>
void Exchange(T& A, T& B)
{ 
	T Temp;
	Temp = A; A=B; B=Temp;
}
// --- 定義樣版函數 Bubble() -----------------------
template <class T>
void Bubble(T *V, int N )
{
	for (int i=0; i<N; i++)
		for (int j=N-1; j>i; j--)
			if (V[j]<V[j-1])
				Exchange(V[j],V[j-1]); 
	return;
}
// ---- 主程式 -------------------------------------
int main()
{
	int Index;
	int Key = 32;
	srand(int(time(0))); 
	const int Size = 20;
	int Data[Size];
	for (int i=0; i<20; i++)
		Data[i]= RandI(85);
	cout << "\nData 原來的值是:" 
		<< endl;
	for (int i=0; i<Size; i++)
	{
		cout << setw(10) << Data[i];
		if (i%5 == 4) cout << endl;
	}
	Bubble(Data, Size);
	cout << "\n執行 Bubble() 之後, Data 的值是:" 
		<< endl;
	for (int i=0; i<Size; i++)
	{
		cout << setw(10) << Data[i];
		if (i%5 == 4) cout << endl;
	}
	Index = BiSearch(Data, Size, Key);
	if (Index > -1)
		cout << Key << " 在第 " << Index+1 
		<< " 個元素的地方." << endl;
	else
		cout << "找不到 " << Key << endl;
	system("PAUSE");
	return 0;
}
