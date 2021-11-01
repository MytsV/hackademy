#include "../libft.h"

char *ft_strchr(const char *str, int ch)
{
    str--;
    do
    {
        str++;
        if (*str == (char)ch)
        {
            return (char *)str;
        }
    }
    while (*str != '\0');
    
    return 0;
}
