//�x�s�ɦW�Gd:\C++02\C0214.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	double dType;

	cout << "long int ���A���줸�ռ� = " 
		   << sizeof(long int) << "bytes\n";	//���olong int���A�j�p
	cout << "int ���A���줸�ռ� = " 
		   << sizeof(int) << "bytes\n";	//���oint���A�j�p
	cout << "short ���A���줸�ռ� = " 
		   << sizeof(short) << "bytes\n";	//���oshort���A�j�p
	cout << "bool ���A���줸�ռ� = " 
		   << sizeof(bool) << "bytes\n";	//���obool���A�j�p
	cout << "�ܼ�dType���줸�ռ� = " 
		   << sizeof(dType) << "bytes\n";	//���o�ܼ�dType���j�p
	return 0;
}
