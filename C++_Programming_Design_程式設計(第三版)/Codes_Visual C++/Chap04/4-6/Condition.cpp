// Condition.cpp
// --------------------------------------
#include <iostream>
using namespace std;
// ------ 主程式 --------------------
int main()
{	
	float a, b;
	int N;

	// (1)
	cout << "(1) 請輸入兩個數" << endl;
	cout << "請輸入第一個數 a:" << endl;
	cin  >> a;
	cout << "請輸入第二個數 b:" << endl;
	cin  >> b;
	cout << "a , b 兩者中較大的是 "
		<<  ( a > b ? 'a' : 'b' )  <<  endl ;
	cout << endl;

	// (2)
	cout << "(2) 請輸入一個整數 N:" << endl;
	cin  >>  N;
	cout <<  "N 是"
		<< ( N % 2  ?  "奇數" : "偶數") 
		<<  endl ;
	system("pause");
	return 0;
}
