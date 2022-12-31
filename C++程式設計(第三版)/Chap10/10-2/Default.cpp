// Default.cpp
// --------------------------------------
#include <iostream>
using namespace std;

// --- ㄧ计Area() --------------------
double Area(double Width, double Length = 12.0);

// --- 祘Α ----------------------------
int main()
{
	double A;
	A = Area(6.5);				// ノ把计㊣
	cout << "A is : " << A << endl;
	system("PAUSE");
	return 0;
}

// --- ﹚竡ㄧ计Area() --------------------
double Area(double Width, double Length)
{ 
	return Width*Length; 
}
