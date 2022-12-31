// StringBubble.cpp
// ----------------------------------------------
#include <string>
#include <iostream>
using namespace std;
// --- 定義樣版函數 Bubble() -------------------
template <class T>
void Bubble(T * const V, int N )
{
	for (int i=0; i<N; i++)
		for (int j=N-1; j>i; j--)
			if (V[j]<V[j-1])
				swap(V[j],V[j-1]); 
	return;
}
// ---- 主程式 ---------------------------------
int main()
{
	const int Size = 5;
	int i;
	string Students[Size]=
	{"Nancy","Lulu", "Margaret","Stephanie","Monica"};

	cout << "\n執行 Bubble() 之前, Data 的值是:" << endl;
	for (i=0; i<Size; i++)
		cout << "(" << i+1 << ") " << Students[i] << endl;
	Bubble(Students, Size);
	cout << "\n執行 Bubble() 之後, Data 的值是:" << endl;
	for (int i=0; i<Size; i++)
		cout << "(" << i+1 << ") " << Students[i] << endl;
	system("PAUSE");
	return 0;
}
