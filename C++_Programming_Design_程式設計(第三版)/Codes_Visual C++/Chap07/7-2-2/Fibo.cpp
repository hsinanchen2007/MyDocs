// Fibo.cpp
// Fibonacci number generation
// --------------------------------------
#include <iostream>
using namespace std;
// --- 函數 Fibonacci() 的宣告 -------------
int Fibonacci(int n);
const int MaxSize = 100;
// ------ 主程式 --------------------------
int main()
{
	int InputN;
	cout  << "請輸入Fibonacci 數列的長度：";
	cin   >> InputN;
	if (InputN > MaxSize)
	{ 
		cerr << "Maximun size exceeded!" << endl;
		system("PAUSE");
		return 0;
	}
	cout  << "下列是您所指定長度為 " << InputN
		  << " 的 Fibonacci 數列：\n";
	for (int i=0; i < InputN; i++)
		cout << Fibonacci(i) << " ";
	
	cout << endl;

	system("PAUSE");
	return 0;
}

// --- 函數 Fibonacci() 的定義 -------------
int Fibonacci(int N)
{
	static int Fib[MaxSize];
	Fib[0] = Fib[1] = 1;

	int i;
	for(i = 0; i < MaxSize; i++)
		if(Fib[i] == 0) break;
	while(i <= N)
	{
		Fib[i] = Fib[i-1] + Fib[i-2];
		i++;
	}
	return Fib[N];
}
