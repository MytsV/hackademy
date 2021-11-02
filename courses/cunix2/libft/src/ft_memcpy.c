#include "../libft.h"
#include <assert.h>
#include <string.h>

void *ft_memcpy(void *dest, const void *source, size_t count)
{
    for (unsigned int i = 0; i < count; i++, dest++, source++)
    {
        *((char *)dest) = *((char *)source);
    }
    return dest;
}