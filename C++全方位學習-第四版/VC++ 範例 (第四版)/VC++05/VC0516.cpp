//�x�s�ɦW�Gd:\VC++05\VC0516\VC0516.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int count, sum;
	for (count = 11, sum = 0; count > 1; count--, sum += count);
	cout << "10 + 9 + 8 + ... + 1 = " << sum	//��X�r��P�`�M
		<< endl;	//����
	return 0;
}
