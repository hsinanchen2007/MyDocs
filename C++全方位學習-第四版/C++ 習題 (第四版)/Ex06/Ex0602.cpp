//d:\Ex06\Ex0604.cpp
//�D GCD �P LCM
#include <iostream>
using namespace std;

void GCD(int a, int b);
void LCM(int a, int b);

int main(int argc, char** argv) {
	int a, b;
	int sel;
	while (1)
	{
		cout << "1. �D GCD  2. �D LCM  3. �����G";
		cin >> sel;
		if(sel == 1) {
			cout << "�п�J�G�Ӿ�� (a b)�G";
			cin >> a >> b;
			GCD(a, b);
		} else if(sel == 2) {
			cout << "�п�J�G�Ӿ�� (a b)�G";
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
