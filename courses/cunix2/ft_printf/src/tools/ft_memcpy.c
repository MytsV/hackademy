#include <string.h>

void *ft_memcpy(void *dest, const void *source, size_t count)
{
    char *dest_char = (char *)dest;
    char *source_char = (char *)source; 
    for (unsigned int i = 0; i < count; i++, dest_char++, source_char++)
    {
        *dest_char = *source_char;
    }
    return dest;
}