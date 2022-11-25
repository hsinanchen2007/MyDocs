//--- 会员类的使用例程 ---//

#include <iostream>
#include "Member.h"

using namespace std;

void print(Member* p)
{
	p->print();			// 调用成员函数print
}

int main()
{
	Member wangming("王明", 15, 4);			// 调用构造函数
	wangming.set_rank(wangming.get_rank() + 1);		// 等级增加1
	print(&wangming);								// 显示
}
