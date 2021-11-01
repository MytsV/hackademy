#include "../libft.h"

void ft_bzero(void *s, size_t n) 
{
    for (unsigned int i = 0; i < n; i++)
    {
        *((char *)(s + i)) = '\0';
    }
}
