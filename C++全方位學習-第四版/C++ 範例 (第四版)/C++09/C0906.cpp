//�ɮצW�١Gd:\C++09\C0906.cpp
#include <iostream>
#include <iomanip>
#include <cstdlib>	//�ഫ�ƭȼ��D��
using namespace std;

int main(int argc, char** argv)
{
	char *s; double x; int i; long l;
	setiosflags(ios::fixed|ios::right);	//�]�w��X�榡
	cout << setw(7) << "�r��\t" << setw(23) << "    �ƭ�" << endl;

	s = "-1998.12E-25  ";	//�w�q�r��
	x = atof( s );	//�ഫ���B�I��
	cout << setw(15) << s << "\t" << setw(15) << x << endl;

	s = " 686 pigs     ";	//�w�q�r��
	i = atoi( s );	//�ഫ���u���
	cout << setw(15) << s << "\t" << setw(15) << i << endl;

	s = " 98686 dollars";	//�w�q�r��
	l = atol( s );	//�ഫ�������
	cout << setw(15) << s << "\t" << setw(15) << l << endl;
	return 0;
}
