//d:\Ex06\Ex0604.cpp
//求 GCD 與 LCM
#include <iostream>
using namespace std;

void GCD(int a, int b);
void LCM(int a, int b);

int main(int argc, char** argv) {
	int a, b;
	int sel;
	while (1)
	{
		cout << "1. 求 GCD  2. 求 LCM  3. 結束：";
		cin >> sel;
		if(sel == 1) {
			cout << "請輸入二個整數 (a b)：";
			cin >> a >> b;
			GCD(a, b);
		} else if(sel == 2) {
			cout << "請輸入二個整數 (a b)：";
			cin >> a >> b;
			LCM(a, b);
		} else if(sel == 3) {
			exit(0);
		}
	}
	system("PAUSE");
	return 0;
}

void GCD(int a, int b)
{
	int n;
	for(n=a; n>=1; n--)
		if(a%n==0 && b%n==0)
			break;
	cout << "GCD = " << n << "\n\n";
}

void LCM(int a, int b)
{
	int n;
	for(n=a; n<=a*b; n+=a)
		if(n%b==0)
			break;
	cout << "LCM = " << n << "\n\n";
}
