//d:\Ex11\Ex1104.cpp
//�p�⥻�Q�M
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Interest
{
	double principal;
	double rate;
	int term;
public:
	Interest()
	{
		principal = 0;
		rate = 0;
		term = 0;
	}
	void setInterest(double p, double r, int t)
	{
		principal = p;
		rate = r;
		term = t;
	}
	double amount()
	{
		double total = principal * pow((1 + (rate/12)), term);
		return total;
	}
};

int main(int argc, char** argv) {
	Interest it;
	double pp, rr;
	int tt;
	cout << "��J�����B�Q�v�B���� (�H�Ů�j�})�G";
	cin >> pp >> rr >> tt;

	it.setInterest(pp, rr/100, tt);
	cout << "���Q�M = " << it.amount() << endl;
	system("PAUSE");
	return 0;
}
