//--- strlen的实现例程A ---//

#include <cstddef>

size_t strlen(const char* s)
{
	size_t len = 0;		// 长度

	while (*s++)
		len++;
	return len;
}
