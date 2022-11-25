//檔案名稱：d:\VC++08\VC0820\VC0820.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int *p = new int[10];	//等於int p[10];
	int i;
	for (i = 0; i<10; i++)
		p[i] = i;	//起始陣列初值

	cout << "輸出陣列元素值：";
	for (i = 0; i<10; i++)
		cout << p[i] << ' ';	//輸出陣列元素值
	delete[] p;	//釋放陣列記憶體
	cout << endl; //跳行 
	return 0;
}
