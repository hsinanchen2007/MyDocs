//�ɮצW�١Gd:\VC++07\VC0706\VC0706.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int eq[2][3] = { { 3, 8, 7 },
	{ 4, 9, 2 } };	//�ŧi�ð_�l�G���}�C
	cout << "�D�G���@���p�ߤ�{�դ���\n";
	cout << eq[0][0] << "x + " << eq[0][1];	//��X�}�C����
	cout << "y = " << eq[0][2] << endl;	//��X�}�C����
	cout << eq[1][0] << "x + " << eq[1][1];	//��X�}�C����
	cout << "y = " << eq[1][2] << endl;	//��X�}�C����
										//�p��delta��
	int d = eq[0][0] * eq[1][1] - eq[1][0] * eq[0][1];
	//�p��delta x��
	int dx = eq[0][2] * eq[1][1] - eq[1][2] * eq[0][1];
	//�p��delta y��
	int dy = eq[0][0] * eq[1][2] - eq[1][0] * eq[0][2];
	cout << "�h x = " << float(dx) / float(d);	//��Xdx/d��
	cout << "\ty = " << float(dy) / float(d) << endl;	//��Xdy/d��
	return 0;
}
