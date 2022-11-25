//d:\EX03\Ex0308.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	float weight;
	cout << "請輸入體重 (單位：公斤)：";
	cin >> weight;
	float cal = 2.2 * weight * 19;
	cout << "體重 " << weight << " 公斤，每天需 " << cal << " 卡熱量\n";
	system("PAUSE");
	return 0;
}
