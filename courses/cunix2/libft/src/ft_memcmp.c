#include "../libft.h"

int ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
    unsigned char *buf1_char = (unsigned char *)buf1;
    unsigned char *buf2_char = (unsigned char *)buf2;
    for (unsigned int i = 0; i < count; i++, buf1_char++, buf2_char++)
    {
        if (*buf1_char < *buf2_char)
        {
            return -1;
        }
        else if (*buf1_char > *buf2_char)
        {
            return 1;
        }
    }
    return 0;  
}