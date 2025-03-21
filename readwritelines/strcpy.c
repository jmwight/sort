#include "strcpy.h"

void strcpy(char *dst, char *src)
{
	while((*dst = *src) != '\0')
		++src, ++dst;
}
