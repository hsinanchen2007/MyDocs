//�x�s�ɦW�Gd:\Ex18\Ex1808.cpp
//�C�X�E�E���k���^���
#include <iostream>
#include <iomanip>
using namespace std;

void mulTable(int, int);
void mulInner(int, int);
int multiplier = 2, faciend = 1;

int main(int argc, char** argv) {
	mulTable(faciend, multiplier);
	system("PAUSE");
	return 0;
}

void mulTable(int faciend, int multiplier)
{
	if(faciend <= 9)
	{
		mulInner(faciend, multiplier);
		cout << endl;	//��X����
		mulTable(++faciend, multiplier);
	}
}

void mulInner(int faciend, int multiplier)
{
	if(multiplier <= 9)
	{
		cout << multiplier << '*'; 	//��Xmultiplier *
		cout << faciend << '=';	//��Xfaciend =
		cout << setw(2);	//�]�w��X�G���
		cout << multiplier*faciend << '\t';	//��X�B��ȫ���U�@�w��
		mulInner(faciend, ++multiplier);
	}
}
