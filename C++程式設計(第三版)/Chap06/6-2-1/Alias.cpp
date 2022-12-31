// Alias.cpp
// --------------------------------------
#include <iostream>
using namespace std;
//------ 主程式 -------------------------------
int main()
{
	int N = 10;
	int& M = N;

	cout<< "M 的值原來是："<< M << endl;
	cout<< "N 的值原來是："<< N << endl;
	N = 5;
	cout<< "執行 「N = 5;」 之後" << endl;
	cout<< "M 的值目前是："  << M <<endl;
	M = 2;
	cout<< "執行 「M = 2;」 之後" << endl;
	cout<< "N 的值目前是："  << N <<endl; 

	system("PAUSE");
	return 0;
}

