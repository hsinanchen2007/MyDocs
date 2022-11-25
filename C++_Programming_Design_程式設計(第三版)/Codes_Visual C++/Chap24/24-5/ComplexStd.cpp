// ComplexStd.cpp
#include <iostream>
#include <iomanip>
#include <complex>
using namespace std;

int main()
{
    complex<double>  Z1(2.4,3.7);
    complex<double>  Z2(polar(2.0, 0.8));

    cout << "Z1: " << Z1 << endl;
    cout << "Z2: " << Z2 << endl;
    cout << std::showpoint
			<< std::setprecision(4);
    cout << "Z1 ���곡  = " << setw(10) << Z1.real()
			<< "   "
			<< "Z1 ���곡= "   << setw(10) << Z1.imag()
			<< endl;

    // �H���y�Ъ��
    cout << "Z1 ������  = " << setw(10) << abs(Z1)
			<< "   norm(Z1)= " << setw(10) << norm(Z1)
			<< endl;
    cout << "Z1 ���ۦ쨤= " << setw(10) << arg(Z1)
			 << endl;
    cout << "Z2 ������  = " << setw(10) << abs(Z2)
			<< "   norm(Z2)= " << setw(10) << norm(Z2)
			<< endl;
    cout << "Z2 ���ۦ쨤= " << setw(10)
			 << arg(Z2)  << endl;

    // �@�m�Ƽ�
    cout << "Z1 ���@�m�Ƽ� =  " << conj(Z1) << endl;
    cout << "Z2 ���@�m�Ƽ� =  " << conj(Z2) << endl;

    // �Ƽƪ��N�ƭp��
    cout << "4.4+Z1*1.8/(Z2-2.0)  =  " << setw(20)
			<< 4.4+Z1*1.8/(Z2-2.0) << endl;
    cout << "sin(Z1) * cos(Z2)    = "  << setw(20)
			<< (sin(Z1) * cos(Z2)) << endl;
    cout << "sqrt(Z1)             =  " << setw(20)
			<< (sqrt(Z1)) << endl;
    cout << "log(Z1)              =  "  << setw(20)
			<< (log(Z1)) << endl;
    cout << "pow(Z1, Z2)          =  " << setw(20)
			<< (pow(Z1, Z2)) << endl;
    cout << "Z1 += Z2             =  " << setw(20)
			<< (Z1 += Z2) << endl;
    system("pause");
	return 0;
}
