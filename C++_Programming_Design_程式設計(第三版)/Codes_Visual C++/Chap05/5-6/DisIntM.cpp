// DisIntM.cpp
// --------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;
// ------ �D�{�� --------------------
int main()
{	
	int M=3, N=5, i, j;
	cout << M <<" �C " << N << " ��x�}:" << endl;
	for (i = 1; i <= M; i++)
	{
		for(j = 1; j <= N ; j++)
			cout << setw(5)
			<< i << j ;
		cout << endl;
	}
	system("pause");
	return 0;
}
