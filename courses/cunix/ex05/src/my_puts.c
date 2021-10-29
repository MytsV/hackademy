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

int my_puts_new_line()
{
    char str[] = "\n";
    return write(STDOUT_FILENO, str, sizeof(str) - 1); 
}

//writes a string to standard output
int my_puts(const char *s)
{
    int result = write(STDOUT_FILENO, s, get_str_len(s));
    my_puts_new_line();
    return result;
}

