#include "../libft.h"

extern char *ft_strstr(const char *haystack, const char *needle)
{
    if (*needle == '\0')
    {  
        return (char *)haystack;
    }

    while (*haystack != '\0')
    {
        if (*haystack == *needle) {
            const char *haystack_ptr = haystack;
            const char *needle_ptr = needle;
            while (1) {
                if (*needle_ptr == '\0') {
                    return (char *)haystack;
                }

                if (*needle_ptr != *haystack_ptr) {
                    break;
                }

                needle_ptr++;
                haystack_ptr++;
            }
        }
        haystack++;
    }

    return NULL;
}