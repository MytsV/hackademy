#include "../libft.h"

void *ft_memset(void *destination, int c, size_t n)
{
    for (unsigned int i = 0; i < n; i++, destination++)
    {
        *((char *)destination) = (char)c;
    }
    return destination;
}