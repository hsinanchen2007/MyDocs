// 求两个值中的较大值的函数模板和显式特例化

#include <cstring>

//--- 求a和b中的较大值 ---//	 
template <class Type> Type maxof(Type a, Type b)
{
	return a > b ? a : b;
}

//--- 求a和b中的较大值（const char*型的特例化）---//
template <> const char* maxof<const char*>(const char* a, const char* b)
{
	return std::strcmp(a, b) > 0 ? a : b;
}
