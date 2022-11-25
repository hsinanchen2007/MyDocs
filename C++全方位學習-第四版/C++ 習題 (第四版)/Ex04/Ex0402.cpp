//d:\Ex04\Ex0407.cpp
#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char** argv) {
	float weight, fee;
	cout << "請輸入包裹重量 (單位：公克)：";
	cin >> weight;
	if(weight >= 1001 && weight <= 2000)
		fee = 160;
	else if(weight >= 501 && weight <= 1000)
		fee = 112;
	else if(weight >= 251 && weight <= 500)
		fee = 72;
	else if(weight >= 101 && weight <= 250)
		fee = 40;
	else if(weight >= 51 && weight <= 100)
		fee = 24;
	else if(weight >= 21 && weight <= 50)
		fee = 16;
	else if(weight <= 20)
		fee = 8;
	cout << "包裹郵費 = " << fee << " 元\n";
	system("PAUSE");
	return 0;
}
