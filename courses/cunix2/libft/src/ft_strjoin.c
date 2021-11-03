#include "../libft.h"
#include "ft_strlen.c"

char *ft_strjoin(char const *s1, char const *s2)
{
    char *str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    char *str_pointer = str;
    while (*s1 != '\0')
    {
        *str_pointer = *s1;
        str_pointer++, s1++;
    }
    while (*s2 != '\0')
    {
        *str_pointer = *s2;
        str_pointer++, s2++;
    }
    *str_pointer = '\0';
    return str;
}