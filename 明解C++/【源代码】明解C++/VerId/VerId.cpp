// 用于验证的标识号类VerId（源文件）

#include "VerId.h"

int VerId::counter = 0;		// 已经赋予的标识号数量

//--- 构造函数 ---//
VerId::VerId()
{
	id_no = ++counter;		// 赋予标识号
}

//--- 返回标识号 ---//
int VerId::id() const
{
	return id_no;			// 返回标识号
}
