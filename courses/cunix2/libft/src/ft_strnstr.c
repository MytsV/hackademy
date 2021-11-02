#include "../libft.h"

int can_continue(const char *haystack_start, const char *haystack, size_t len) {
    return (unsigned int)(haystack - haystack_start) <= len;
}

extern char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    const char *haystack_start = haystack;

    if (*needle == '\0')
    {  
        return (char *)haystack;
    }

    while (*haystack != '\0' && can_continue(haystack_start, haystack, len))
    {
        if (*haystack == *needle) {
            const char *haystack_ptr = haystack;
            const char *needle_ptr = needle;
            while (can_continue(haystack_start, haystack_ptr, len)) {
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