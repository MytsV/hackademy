#include "../libft.h"

extern char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    const char *substr = NULL;
    const char *needle_ptr = needle;
    unsigned int count = 0;

    if (*needle == '\0')
    {  
        return (char *)haystack;
    }

    while (*haystack != '\0' && *needle_ptr != '\0' && count < len)
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
        count++;
    }

    if (*needle_ptr != '\0') 
    { 
        return NULL;
    }

    return (char *)substr;
}

