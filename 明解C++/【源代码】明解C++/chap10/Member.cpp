//--- 会员类（源文件）---//

#include <iostream>
#include "Member.h"

using namespace std;

// 构造函数【定义】
Member::Member(string name, int number, int grade)
{
	full_name = name;  no = number;  rank = grade;
}

// 显示【定义】
void Member::print()
{
	cout << "No." << no << "：" << full_name << "[等级：" << rank << "]\n";
}
