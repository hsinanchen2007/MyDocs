//�ɮצW�١Gd:\C++07\C0714.cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv)
{
	int eq[3][3] = { {7, 1, 3}, 
			 {4, -1, 1},
			 {5, 3, -2} };	//�ŧi�ð_�l�G���}�C
	long d = 0;	//�ŧi�ð_�l�ܼ�d
	cout << "�p���C�� a ��\n";
	//�p���C����
	for(int i=0; i<3; i++)	//�p���C���Ȱj��
	{
		d += eq[0][i]*eq[1][(i+1)%3]*eq[2][(i+2)%3];
		d -= eq[0][i]*eq[1][(i+2)%3]*eq[2][(i+1)%3];
	}
	//��X�}�C����
	for(int y=0; y<3; y++)	//�~�h�j��,���ܯ��ޭ�y
	{
		if(y==1)
			cout << "a = | ";
		else
			cout << "    | ";
		for(int x=0; x<3; x++)	//���h�j��,���ܯ��ޭ�x
			cout << setw(2) << eq[y][x] << ' ';	//��X�}�C����
		if(y==1)
			cout << "| = " << d << endl;	//��X��C����
		else
			cout << "|\n";
	}
	return 0;
}
