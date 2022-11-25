// 标识号类IdNo（第2版：源文件）

#include "IdNo.h"

int IdNo::counter = 0;

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

//--- 返回标识号的最大值 ---//
int IdNo::get_max_id()
{
	return counter;			// 返回标识号的最大值
}
