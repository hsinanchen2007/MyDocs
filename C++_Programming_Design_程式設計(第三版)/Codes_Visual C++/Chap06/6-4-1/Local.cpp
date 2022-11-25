// Local.cpp
// --------------------------------------
#include <iostream>
using namespace std;
// ---函數 TestLocal () 的宣告 -------------------
void TestLocal();
// ------ 主程式 --------------------------------
int main()
{
	for (int i=1; i<=3; i++)
	{ 
		cout << "第(" << i << ")次:" << endl;
		TestLocal();
		cout << endl;
	}

	system("PAUSE");
	return 0;
}

void TestLocal()
{
	int          A = 1; 
	static int   S = 1;
	register int R = 1;   

	cout << " A 的值是 " << A << endl;
	cout << " S 的值是 " << S << endl;
	cout << " R 的值是 " << R << endl;

	for (register int i=0; i<1000; i++)
		R += 2;
	cout << " 計算後 R 的值是 " << R << endl;

	A++;  S++; R++;
	return;							// 此指令可以省略
}
