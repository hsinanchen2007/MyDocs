//儲存檔名：d:\Ex18\Ex1803.cpp
//利用遞回函數計算陣列元素總和
#include <iostream>
using namespace std;

int sum(int[], int);

int main(int argc, char** argv) {
	int a[6] = {1, 4, 5, 6, 9, 4};
	int n = 5;
	cout << sum(a, n) << endl;
	system("PAUSE");
	return 0;
}

int sum(int a[], int n)
{
	if(n>=0) {
		cout << a[n];
		if (n!=0) 
			cout << " + ";
		return a[n] + sum(a, n-1);
	} else {
		cout << " = ";
		return 0;
	}
}
