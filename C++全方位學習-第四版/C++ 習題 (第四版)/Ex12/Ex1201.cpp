//d:\Ex12\Ex1201.cpp
//だ计玥笲衡
#include <iostream>
#include <cmath>
using namespace std;

class Fracpri
{
	int whole;
	int numer;
	int denom;
public:
	int getgcd();
	Fracpri operator += (Fracpri);
	Fracpri operator -= (Fracpri);
	Fracpri operator *= (Fracpri);
	Fracpri operator /= (Fracpri);
	friend istream &operator>> (istream &in, Fracpri &obj);
	friend ostream &operator<< (ostream &out, Fracpri &obj);
};

int Fracpri::getgcd()
{
	int n = numer<denom ? numer : denom;
	for( ; n>=1; n--)
		if(denom%n==0 && numer%n==0)	//计埃n单0
			break;	//い耞癹伴
	return n;
}

Fracpri Fracpri::operator += (Fracpri obj)
{
	Fracpri temp;
	int numer1, numer2;
	numer1 = whole * denom + numer;
	numer2 = obj.whole * obj.denom + obj.numer;
	temp.denom = denom * obj.denom;
	temp.numer = (numer1 * obj.denom + numer2 * denom) % temp.denom;
	temp.whole = (numer1 * obj.denom + numer2 * denom) / temp.denom;
	denom = temp.denom;
	numer = temp.numer;
	whole = temp.whole;
}

Fracpri Fracpri::operator -= (Fracpri obj)
{
	Fracpri temp;
	int numer1, numer2;
	numer1 = whole * denom + numer;
	numer2 = obj.whole * obj.denom + obj.numer;
	temp.denom = denom * obj.denom;
	temp.numer = (numer1 * obj.denom - numer2 * denom) % temp.denom;
	temp.whole = (numer1 * obj.denom - numer2 * denom) / temp.denom;
	denom = temp.denom;
	numer = temp.numer;
	whole = temp.whole;
}

Fracpri Fracpri::operator *= (Fracpri obj)
{
	Fracpri temp;
	int numer1, numer2;
	numer1 = whole * denom + numer;
	numer2 = obj.whole * obj.denom + obj.numer;
	temp.denom = denom * obj.denom;
	temp.numer = (numer1 * numer2) % temp.denom;
	temp.whole = (numer1 * numer2) / temp.denom;
	denom = temp.denom;
	numer = temp.numer;
	whole = temp.whole;
}

Fracpri Fracpri::operator /= (Fracpri obj)
{
	Fracpri temp;
	int numer1, numer2;
	numer1 = whole * denom + numer;
	numer2 = obj.whole * obj.denom + obj.numer;
	temp.numer = numer1 * obj.denom;
	temp.denom = numer2 * denom;
	temp.whole = (temp.numer) / temp.denom;
	temp.numer = (temp.numer) % temp.denom;
	denom = temp.denom;
	numer = temp.numer;
	whole = temp.whole;
}

istream & operator >> (istream & in, Fracpri & obj)
{
	in >> obj.whole >> obj.numer >> obj.denom;
	obj.whole = abs(obj.whole);
	obj.numer = abs(obj.numer);
	obj.denom = abs(obj.denom);
	return in;
}

ostream & operator << (ostream& out, Fracpri& obj)
{
	int gcd = obj.getgcd();
	obj.numer = obj.numer / gcd;
	obj.denom = obj.denom / gcd;
	if (obj.whole)
		out << obj.whole << ' ';
	out << obj.numer << '/' << obj.denom;
	return out;
}

int main(int argc, char** argv) {
	Fracpri S1, S2, S3;
	cout << "叫块盿だ计1 (俱计-だ-だダ): ";
	cin >> S1;
	cout << "叫块盿だ计2 (俱计-だ-だダ): ";
	cin >> S2;
	S3 = S1;
	S3 += S2;
	cout << "盿だ计1 += 盿だ计2 => " << S1 << " += " 
		 << S2 << " = " << S3 << endl;
	S3 = S1;
	S3 -= S2;
	cout << "盿だ计1 -= 盿だ计2 => " << S1 << " -= " 
		 << S2 << " = " << S3 << endl;
	S3 = S1;
	S3 *= S2;
	cout << "盿だ计1 *= 盿だ计2 => " << S1 << " *= " 
		 << S2 << " = " << S3 << endl;
	S3 = S1;
	S3 /= S2;
	cout << "盿だ计1 /= 盿だ计2 => " << S1 << " /= " 
		 << S2 << " = " << S3 << endl;
	system("PAUSE");
	return 0;
}
