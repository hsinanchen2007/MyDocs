//�ɮצW�١Gd:\VC++07\VC0718\VC0718.cpp
#include <iostream>
using namespace std;

double calArray(int[][2]);	//�ŧi��ƭ쫬
void ansArray(double, double, double);	//�ŧi��ƭ쫬

int main(int argc, char** argv)
{
	int a1, a2, b1, b2, c1, c2;
	cout << "�D�p�ߤ�{�� a1x + b1y = c1" << endl;	//����D��
	cout << "�@�@�@�@�@�@ a2x + b2y = c2 ���ѡH" << endl;
	cout << "��J a1 = "; cin >> a1;	//��J��{�իY��
	cout << "��J b1 = "; cin >> b1;
	cout << "��J c1 = "; cin >> c1;
	cout << "��J a2 = "; cin >> a2;
	cout << "��J b2 = "; cin >> b2;
	cout << "��J c2 = "; cin >> c2;
	int dd[2][2] = { { a1, b1 },
	{ a2, b2 } };	//�ŧi�ð_�l�G���}�C
	int dx[2][2] = { { c1, b1 },
	{ c2, b2 } };	//�ŧi�ð_�l�G���}�C
	int dy[2][2] = { { a1, c1 },
	{ a2, c2 } };	//�ŧi�ð_�l�G���}�C
	double delta = calArray(dd);	//delta=�I�scalArray���
	double deltax = calArray(dx);	//deltax=�I�scalArray���
	double deltay = calArray(dy);	//deltay=�I�scalArray���
	ansArray(delta, deltax, deltay);	//�I�sansArray���
	cout << endl;
	return 0;
}

double calArray(int array[][2])	//�p���C����
{
	return array[0][0] * array[1][1] - array[1][0] * array[0][1];	//��C����
}

void ansArray(double del, double delx, double dely)	//�P�_�èD��{�դ���
{
	if (del != 0)	//�Y���� del != 0
	{
		double x = delx / del;
		double y = dely / del;
		cout << "���@�ѡGx = " << x << ", y = " << y;	//�h��ܦ��@��
	}
	else if (del == 0)	//�Y���� del == 0
	{
		if (delx == 0 && dely == 0)	//�B�G���l�Ҭ�0
			cout << "���L���h��";	//��ܦ��L���h��
		else if (delx != 0 || dely != 0)	//�B���@���l�D0
			cout << "�L��";	//��ܵL��
	}
}
