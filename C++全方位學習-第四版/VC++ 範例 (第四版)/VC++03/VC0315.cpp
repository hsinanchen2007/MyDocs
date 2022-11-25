//¿x¶s¿…¶W°Gd:\VC++03\VC0315\VC0315.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int n;

	short n1 = 32767;	//n1=32767
	n = int(n1 + 1);	//n=32767+1=32768
	cout << n1 << " + 1 = " << n << endl;

	unsigned short n2 = 65535;	//n2=65535
	n = int(n2 + 1);	//n=65535+1=65536
	cout << n2 << " + 1 = " << n << endl;

	short n3 = -32768;	//n3=-32768
	n = int(n3 - 1);	//n=-32768-1=-32769
	cout << n3 << " - 1 = " << n << endl;

	unsigned short n4 = 0;	//n4=0
	n = int(n4 - 1);	//n=0-1=-1
	cout << n4 << " - 1 = " << n << endl;
	return 0;
}
