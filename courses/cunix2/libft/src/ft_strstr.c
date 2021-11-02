#include "../libft.h"

extern char *ft_strstr(const char *haystack, const char *needle)
{
    const char *substr = NULL;
    const char *needle_ptr = needle;

    if (*needle == '\0')
    {  
        return (char *)haystack;
    }

    while (*haystack != '\0' && *needle_ptr != '\0')
    {
        if (substr == NULL && *haystack == *needle)
        {
            substr = haystack;
        }

        if (substr != NULL && *haystack != *needle_ptr)
        {
            needle_ptr = (char *)needle;
            substr = NULL;
        }

        if (substr != NULL)
        {
            needle_ptr++;
        }  
        haystack++;
    }

    if (*needle_ptr != '\0') 
    { 
        return NULL;
    }

    return (char *)substr;
}