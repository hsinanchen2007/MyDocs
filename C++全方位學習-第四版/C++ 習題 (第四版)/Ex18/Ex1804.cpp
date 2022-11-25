//儲存檔名：d:\Ex18\Ex1808.cpp
//列出九九乘法表遞回函數
#include <iostream>
#include <iomanip>
using namespace std;

void mulTable(int, int);
void mulInner(int, int);
int multiplier = 2, faciend = 1;

int main(int argc, char** argv) {
	mulTable(faciend, multiplier);
	system("PAUSE");
	return 0;
}

void mulTable(int faciend, int multiplier)
{
	if(faciend <= 9)
	{
		mulInner(faciend, multiplier);
		cout << endl;	//輸出跳行
		mulTable(++faciend, multiplier);
	}
}

void mulInner(int faciend, int multiplier)
{
	if(multiplier <= 9)
	{
		cout << multiplier << '*'; 	//輸出multiplier *
		cout << faciend << '=';	//輸出faciend =
		cout << setw(2);	//設定輸出二位數
		cout << multiplier*faciend << '\t';	//輸出運算值後跳下一定位
		mulInner(faciend, ++multiplier);
	}
}
