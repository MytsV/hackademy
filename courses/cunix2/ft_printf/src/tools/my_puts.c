#include <unistd.h>

//the function determines the length of a string
unsigned int get_str_len(const char *s)
{
    int len = 0;
    for (; *s != '\0'; s++)
    {
        len++;
    }
    return len;
}

//writes a string to standard output
int my_puts(const char *s)
{
    int result = write(STDOUT_FILENO, s, get_str_len(s));
    return result;
}