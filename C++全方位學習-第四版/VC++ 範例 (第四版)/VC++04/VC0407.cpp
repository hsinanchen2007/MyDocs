//�x�s�ɦW�Gd:\VC++04\VC0407\VC0407.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int number;

	cout << "�п�J�@�Ӿ�ơG";
	cin >> number;	//��J��ƨæs�Jnumber
	if (number > 0) {	//�Ynumber >= 0
		cout << number << " �j�� 0\n";	//  ��ܰT��
	}				//if�϶������I
	else if (number < 0) {	//�Ynumber < 0
		cout << number << " �p�� 0\n";	//  ��ܰT��
	}				//else if�϶������I
	else {		//�H�W�ҫD
		cout << number << " ���� 0\n";	//  ��ܰT��
	}				//else�϶������I
	return 0;
}
