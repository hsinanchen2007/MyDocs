//d:\Ex17\Ex1702.cpp
// �p��r�����
#include <iostream>
using namespace std;

struct link
{
	char data;
	link *next;
};

class Linklist
{
	link *pointer;
	int counter;
public:
	Linklist() { pointer = NULL; }
	void push(char letter);
	void reset();
	int length(char* string);
};

void Linklist::push (char letter)
{
	link *newPtr = new link;
	newPtr->data = letter;
	newPtr->next = pointer;
	pointer = newPtr;
	counter++;
}

void Linklist::reset()
{
	counter = 0;
}

int Linklist::length(char* s1)
{
	reset();
	int i = 0;
	while(s1[i] != NULL)
	{
		push(s1[i]);
		i++;
	}
	return counter;
}

int main(int argc, char** argv) {
	Linklist ls;
	char str1[80];

	cout << "��J���t�ťժ��r��A�B���פ��i�W�L 80 �ӭ^��r�C\n";
	cout << "�п�J�r��G";
	cin >> str1;
	cout << "�r���`���סF" << ls.length(str1);
	cout << endl;
	system("PAUSE");
	return 0;
}
