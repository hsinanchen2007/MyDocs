//�x�s�ɦW�Gd:\VC++04\VC0404\VC0404.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int number;

	cout << "�п�J�@�Ӿ�ơG";
	cin >> number;	//��J��ƨæs�Jnumber
	if (number >= 0) {	//�Ynumber >= 0
		cout << number << " �O�s�Υ���ơC\n";	//  ��ܰT��
	}				//if�϶������I
	else {		//�Ynumber < 0
		cout << number << " �O�t��ơC\n";	//  ��ܰT��
	}				//else�϶������I
	return 0;
}
