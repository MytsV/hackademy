#include "../libft.h"

static int has_transition(char const *s, char c)
{
    return (*s == c) && (*(s + 1) != c && *(s + 1) != '\0');
}

static int is_first_not_delimiter(char const *s, char const *str_start, char c)
{
    return (s == str_start) && (*s != c);
}

static int get_parts_count(char const *s, char c)
{
    int count = 0;
    char const *str_start = s;
    while (*s != '\0')
    {
        if (has_transition(s, c) || is_first_not_delimiter(s, str_start, c))
        {
            count++;
        }
        s++;
    }
    return count;
}

static char *get_part(char const *ptr, char c)
{
    char const *end_ptr = ptr;
    
    while (*(end_ptr + 1) != c && *(end_ptr + 1) != '\0')
    {
        end_ptr++;
    } 

    char *part = malloc(sizeof(char) * (end_ptr - ptr + 2));
    char *part_ptr = part;

    while (ptr <= end_ptr)
    {
        *part_ptr = *ptr;
        ptr++, part_ptr++;
    }

    *part_ptr = '\0';
    return part;
}

char **get_emptpy_array()
{
    char **p = malloc(sizeof(char *));
    *p = NULL;
    return p;
}

char **ft_strsplit(char const *s, char c)
{
    int parts_count = get_parts_count(s, c);

    if (parts_count == 0)
    {
        return get_emptpy_array();
    }

    char **parts = malloc(sizeof(char *) * (parts_count + 1));
    char **parts_start = parts;
    char const *str_start = s;

    while (*s != '\0')
    {
        int first_not_del = is_first_not_delimiter(s, str_start, c);
        if (has_transition(s, c) || first_not_del)
        {
            const char *part_ptr = first_not_del ? s : s + 1;
            *parts = get_part(part_ptr, c);
            parts++;
        }
        s++;
    }

    *parts = NULL;
    return parts_start;
}