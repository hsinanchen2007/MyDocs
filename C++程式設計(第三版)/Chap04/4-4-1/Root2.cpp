// Root2.cpp
// --------------------------------------
#include <iostream>
#include <cmath>
using namespace std;
// ------ �D�{�� --------------------
int main()
{	
	float a, b, c, D;
	cout << "�п�J a:" << endl;
	cin >> a;
	cout << "�п�J b:" << endl;
	cin >> b;
	cout << "�п�J c:" << endl;
	cin >> c;
	if ( a == 0.0 )
		if (b==0.0)
			cout << "�L��! " << endl;
		else
			cout << "�u���@�ո�: " << -c/b << endl;
	else
	{
		D= b*b-4.0*a*c;
		if (D==0.0)
			cout << "����: "  
			<< -b/(2.0*a) << endl;
		else if (D>0.0)
		{
			cout << "����չ�Ƹ�"      << endl;
			cout << "�Ĥ@��:"  
				<< (-b+sqrt(D))/(2.0*a) << endl;
			cout << "�ĤG��:"  
				<< (-b-sqrt(D))/(2.0*a) << endl;
		}
		else
		{
			cout << "�Ѭ���զ@�m�Ƽ�"      << endl;  	
			cout << "�Ĥ@��:"   
				<< (-b)/(2.0*a)
				<< " + i " << sqrt(-D)/(2.0*a) 
				<< endl;
			cout << "�ĤG��:"   
				<< (-b)/(2.0*a)
				<< " - i " << sqrt(-D)/(2.0*a) 
				<< endl;
		}
	}
	system("pause");
	return 0;
}

