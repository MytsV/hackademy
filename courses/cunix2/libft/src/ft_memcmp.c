#include "../libft.h"

int ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
    for (unsigned int i = 0; i < count; i++, buf1++, buf2++)
    {
        if (*((unsigned char *)buf1) < * ((unsigned char *)buf2))
        {
            return -1;
        }
        else if (*((unsigned char *)buf1) > *((unsigned char *)buf2))
        {
            return 1;
        }
    }
    return 0;  
}