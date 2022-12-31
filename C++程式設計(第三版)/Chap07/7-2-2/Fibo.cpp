// Fibo.cpp
// Fibonacci number generation
// --------------------------------------
#include <iostream>
using namespace std;
// --- ��� Fibonacci() ���ŧi -------------
int Fibonacci(int n);
const int MaxSize = 100;
// ------ �D�{�� --------------------------
int main()
{
	int InputN;
	cout  << "�п�JFibonacci �ƦC�����סG";
	cin   >> InputN;
	if (InputN > MaxSize)
	{ 
		cerr << "Maximun size exceeded!" << endl;
		system("PAUSE");
		return 0;
	}
	cout  << "�U�C�O�z�ҫ��w���׬� " << InputN
		  << " �� Fibonacci �ƦC�G\n";
	for (int i=0; i < InputN; i++)
		cout << Fibonacci(i) << " ";
	
	cout << endl;

	system("PAUSE");
	return 0;
}

// --- ��� Fibonacci() ���w�q -------------
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
