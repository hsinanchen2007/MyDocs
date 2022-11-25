// 显示所选动物的叫声

#include <iostream>

using namespace std;

int main()
{
	enum animal { Dog, Cat, Monkey, Invalid };
	int type;

	do {
		cout << "0...狗 1...猫 2...猴 3...结束：";
		cin >> type;
	} while (type < Dog || type > Invalid);

	if (type != Invalid) {
		animal selected = static_cast<animal>(type);
		switch (selected) {
		 case Dog	 : cout << "汪汪!!\n";	break;
		 case Cat	 : cout << "喵喵!!\n";	break;
		 case Monkey : cout << "唧唧!!\n";	break;
		}
	}
}
