//�x�s�ɦW�Gd:\C++02\C0208.cpp
#include <iostream>
#include <cmath>
using namespace std;

const float PI = 3.14159f;	//�ŧi�B�I�`�ƲŸ�PI

int main(int argc, char** argv)
{
	float area, circu;	//�ŧi�B�I��area,circu
	float radius = 5;	//�ŧi�B�I��radius=5

	area = PI * float(pow(radius, 2));	//area=�ꭱ�n1
	circu = 2 * PI * radius;	//circu=��P��1
	cout << "�ꭱ�n1 = " << area
		   << "\t��P��1 = " << circu;
	radius = 10;	//����radius=10
	area = PI * float(pow(radius, 2));	//area=�ꭱ�n2
	circu = 2 * PI * radius;	//circu=��P��2
	cout << "\n�ꭱ�n2 = " << area
		   << "\t��P��2 = " << circu << endl;
	return 0;
}
