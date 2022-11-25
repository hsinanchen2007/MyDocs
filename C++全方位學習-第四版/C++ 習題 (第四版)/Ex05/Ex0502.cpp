//d:\Ex05\Ex0509.cpp
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

int main(int argc, char** argv) {
	srand(time(NULL));
	int head=0, tail=0;
	for(int i=0; i<10000; i++) {
		int r = (0 + rand() % (1 - 0 + 1));
		if(r == 0) {
			head++;
		} else {
			tail++;
		}
	}
	cout << "出現正面次數：" << head << endl;
	cout << "出現反面次數：" << tail << endl;
	system("PAUSE");
	return 0;
}
