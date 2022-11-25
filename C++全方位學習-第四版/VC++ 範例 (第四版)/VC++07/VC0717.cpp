//�ɮצW�١Gd:\VC++07\VC0717\VC0717.cpp
#include <iostream>
#include <iomanip>
using namespace std;

void showArray(int[][3], int, char []);	//�ŧi��ƭ쫬
int calArray(int[][3]); 	//�ŧi��ƭ쫬

int main(int argc, char** argv)
{
	int eq[3][4] = { { 7, 1, 3, 6 },
	{ 4, -1, 1, 1 },
	{ 5, 3, -2, 8 } };	//�ŧi�ð_�l�G���}�C
	int dd[3][3] = { 0 };	//�ŧi�ð_�l�G���}�C
	int d, dx, dy, dz, y;	//�ŧi����ܼ�
	char tt[] = "d  = | ";	//�ŧi�r���ܼ�
	//��X��{��
	cout << "�T���@���p�ߤ�{��\n";
	for (y = 0; y<3; y++)
	{
		cout << eq[y][0] << (eq[y][1]>0 ? "x +" : "x ");	//��Xax
		cout << eq[y][1] << (eq[y][2]>0 ? "y +" : "y ");	//��Xby
		cout << eq[y][2] << "z= ";			//��Xcz
		cout << eq[y][3] << "\n";			//��Xd
	}
	//�p��P��X d ��
	for (y = 0; y<3; y++)	//�ƻs�}�C����
	{
		dd[y][0] = eq[y][0];	//�ƻseq��0��dd��0�C
		dd[y][1] = eq[y][1];	//�ƻseq��1��dd��1�C
		dd[y][2] = eq[y][2];	//�ƻseq��2��dd��2�C
	}
	d = calArray(dd);	//�p���C����
	showArray(dd, d, tt);	//��X��C���P��
									//�p��P��X dx ��
	for (y = 0; y<3; y++)	//�ƻs�}�C����
	{
		dd[y][0] = eq[y][3];	//�ƻseq��3��dd��0�C
		dd[y][1] = eq[y][1];	//�ƻseq��1��dd��1�C
		dd[y][2] = eq[y][2];	//�ƻseq��2��dd��2�C
	}
	dx = calArray(dd);	//�p���C����
	showArray(dd, dx, tt);	//��X��C���P��
									//�p��P��X dy ��
	for (y = 0; y<3; y++)	//�ƻs�}�C����
	{
		dd[y][0] = eq[y][0];	//�ƻseq��0��dd��0�C
		dd[y][1] = eq[y][3];	//�ƻseq��3��dd��1�C
		dd[y][2] = eq[y][2];	//�ƻseq��2��dd��2�C
	}
	dy = calArray(dd);	//�p���C����
	showArray(dd, dy, tt);	//��X��C���P��
									//�p��P��X dz ��
	for (y = 0; y<3; y++)	//�ƻs�}�C����
	{
		dd[y][0] = eq[y][0];	//�ƻseq��0��dd��0�C
		dd[y][1] = eq[y][1];	//�ƻseq��1��dd��1�C
		dd[y][2] = eq[y][3];	//�ƻseq��3��dd��2�C
	}
	dz = calArray(dd);	//�p���C����
	showArray(dd, dz, tt);	//��X��C���P��
									//��X��C������
	cout << endl;
	cout << "x = " << dx << '/' << d << endl;	//��X x ��
	cout << "y = " << dy << '/' << d << endl;	//��X y ��
	cout << "z = " << dz << '/' << d << endl;	//��X z ��
	return 0;
}

int calArray(int array[][3])	//�p���C���Ȩ��
{
	int a = 0;
	for (int i = 0; i<3; i++)	//�p���C���Ȱj��
	{
		a += array[0][i] * array[1][(i + 1) % 3] * array[2][(i + 2) % 3];
		a -= array[0][i] * array[1][(i + 2) % 3] * array[2][(i + 1) % 3];
	}
	return a;	//�Ǧ^�p���
}

void showArray(int array[][3], int d, char s[])	//��ܦ�C�����
{
	cout << endl;
	for (int y = 0; y<3; y++)	//�~�h�j��,���ܯ��ޭ�y
	{
		if (y == 1)
			cout << s;
		else
			cout << "     | ";
		for (int x = 0; x<3; x++)	//���h�j��,���ܯ��ޭ�x
			cout << setw(2) << array[y][x] << ' ';	//��X�}�C����
		if (y == 1)
			cout << "| = " << d << endl;	//��X��C����
		else
			cout << "|\n";
	}
}
