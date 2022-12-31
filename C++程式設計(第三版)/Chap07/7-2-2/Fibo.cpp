// Fibo.cpp
// Fibonacci number generation
// --------------------------------------
#include <iostream>
using namespace std;
// --- ㄧ计 Fibonacci()  -------------
int Fibonacci(int n);
const int MaxSize = 100;
// ------ 祘Α --------------------------
int main()
{
	int InputN;
	cout  << "叫块Fibonacci 计";
	cin   >> InputN;
	if (InputN > MaxSize)
	{ 
		cerr << "Maximun size exceeded!" << endl;
		system("PAUSE");
		return 0;
	}
	cout  << "琌眤┮﹚ " << InputN
		  << "  Fibonacci 计\n";
	for (int i=0; i < InputN; i++)
		cout << Fibonacci(i) << " ";
	
	cout << endl;

	system("PAUSE");
	return 0;
}

// --- ㄧ计 Fibonacci() ﹚竡 -------------
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
