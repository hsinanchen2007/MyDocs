#include <iostream>
#include "IntStack.h"

using namespace std;

int main()
{
	IntStack s1(5);		// 容量为5的栈
	s1.push(15);		// s1 = {15}
	s1.push(31);		// s1 = {15, 31}

	IntStack s2(1);		// 容量为1的栈
	s2 = s1;			// 把s1复制到s2（s2的容量变为5）
	s2.push(88);		// s2 = {15, 31, 88}

	IntStack s3 = s2;	// s3为s2的副本
	s3.push(99);		// s3 = {15, 31, 88, 99}

	cout << "取出栈s3积压的所有数据。\n";
	while (!s3.empty())					// 不为空期间
		cout << s3.pop() << '\n';		// 出栈并显示
}
