//�ɮצW�١Gd:\VC++07\VC0708\VC0709.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int eq[3][4] = { { 7, 1, 3, 6 },
	{ 4, -1, 1, 1 },
	{ 5, 3, -2, 8 } };	//�ŧi�ð_�l�G���}�C
	cout << "�T���@����{��\n";
	for (int i = 0; i<3; i++)	//��X��{�հj��
	{
		cout << eq[i][0] << (eq[i][1]>0 ? "x +" : "x ");	//��Xax + ��ax
		cout << eq[i][1] << (eq[i][2]>0 ? "y +" : "y ");	//��Xby + ��by
		cout << eq[i][2] << "z= ";	//��Xcz
		cout << eq[i][3] << "\n";	//��Xd
	}
	return 0;
}
