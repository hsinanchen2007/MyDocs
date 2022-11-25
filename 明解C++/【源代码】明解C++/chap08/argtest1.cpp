// 显示程序名和程序形参（其一）

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	for (int i = 0; i < argc; i++)
		cout << "argv[" << i << "] = " << argv[i] << '\n';
}
