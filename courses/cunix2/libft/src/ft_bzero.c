#include "../libft.h"

void ft_bzero(void *s, size_t n) 
{
    char *s_char = (char *)s;
    for (unsigned int i = 0; i < n; i++)
    {
        *(s_char + i) = '\0';
    }
}
