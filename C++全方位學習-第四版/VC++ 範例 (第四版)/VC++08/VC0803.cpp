//�ɮצW�١Gd:\VC++08\VC0803\VC0803.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	bool boolVar = true;	//�ŧi�P�_�l���L���ܼ�
	int intVar = 65536;	//�ŧi�P�_�l����ܼ�
	float floatVar = 123.45f;	//�ŧi�P�_�l�����ܼ�
	double doubleVar = 98765.43;	//�ŧi�P�_�l������ܼ�

	bool* boolPtr = &boolVar;	//�]�wboolVar����
	int* intPtr = &intVar;	//�]�wintVar����
	float* floatPtr = &floatVar;	//�]�wfloatVar����
	double* doublePtr = &doubleVar;	//�]�wdoubleVar����

	cout << "�ܼƦW�� \t�ܼƦ�}\t�ܼƫ���\n";	//��X���Y
	cout << "---------\t--------\t--------\n";	//��X���j�u
												//��X�ܼƦW�١B��}�B�P����
	cout << "bool     \t" << &boolVar << '\t' << boolPtr << endl;
	cout << "intVar   \t" << &intVar << '\t' << intPtr << endl;
	cout << "floatVar \t" << &floatVar << '\t' << floatPtr << endl;
	cout << "doubleVar\t" << &doubleVar << '\t' << doublePtr << endl;
	return 0;
}
