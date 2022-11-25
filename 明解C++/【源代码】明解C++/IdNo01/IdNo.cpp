// 标识号类IdNo（第1版：源文件）

#include "IdNo.h"

int IdNo::counter = 0;		// 已经赋予的标识号数量

//--- 构造函数 ---//
IdNo::IdNo()
{
	id_no = ++counter;		// 赋予标识号
}

//--- 返回标识号 ---//
int IdNo::id() const
{
	return id_no;			// 返回标识号
}
