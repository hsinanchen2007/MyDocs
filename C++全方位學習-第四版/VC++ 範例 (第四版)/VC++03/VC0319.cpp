//�x�s�ɦW�Gd:\VC++03\VC0319\VC0319.cpp
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv)
{
	unsigned seed;	//unsigned int seed;
	cout << "�п�J�ؤl�ơG";
	cin >> seed;	//��J�ؤl��
	srand(seed);	//�]�w�üƺؤl��
	cout << rand() << endl;	//��X�ü�
	cout << rand() << endl;	//��X�ü�
	cout << rand() << endl;	//��X�ü�
	return 0;
}
