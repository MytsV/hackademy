#include "../libft.h"

void *ft_memset(void *destination, int c, size_t n)
{
    char *dest_char = (char *)destination;
    for (unsigned int i = 0; i < n; i++, dest_char++)
    {
        *dest_char = (char)c;
    }
    return destination;
}