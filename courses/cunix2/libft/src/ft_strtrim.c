#include "../libft.h"

static int is_whitespace(char s)
{
    return s == ' ' || s == '\t' || s == '\n';
}

static const char *get_str_end(char const *s) 
{
    while (*s != '\0')
    {
        s++;
    }
    return s - 1;
}

static const char *get_real_start(char const *s)
{
    while (is_whitespace(*s) && (*s != '\0')) 
    {
        s++;
    }
    return s;
}

static const char *get_real_end(char const *s)
{
    char const *str_end = get_str_end(s);
    while (is_whitespace(*str_end) && s != str_end) 
    {
        str_end--;
    }
    return str_end;
}

char *ft_strtrim(char const *s)
{
    char const *real_start = get_real_start(s);
    char const *real_end = get_real_end(s);

    if (real_end < real_start) 
    {
        char *trim_str = malloc(1);
        *trim_str = '\0';
        return trim_str;
    }

    char *trim_str = malloc(sizeof(char) * (real_end - real_start + 2));
    char *trim_str_ptr = trim_str;

    while (real_start <= real_end) 
    {
        *trim_str_ptr = *real_start;
        real_start++;
        trim_str_ptr++;
    }
    *trim_str_ptr = '\0';

    return trim_str;
}