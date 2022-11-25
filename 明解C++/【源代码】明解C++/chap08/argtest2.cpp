// 显示程序名和程序形参（其二）

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int i = 0;
	while (argc-- > 0)
		cout << "argv[" << i++ << "] = " << *argv++ << '\n';
}
