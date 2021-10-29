#include <stdlib.h>

//the function reverses a string
void reverse_str(char *start, char *end)
{
    while (start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++, end--;
    }
}

//the function sets a string to zero and returns it (can't return a literal because tests fail)
char *set_zero(char *str)
{
    *str = '0';
    *(str + 1) = '\0';
    return str;
}

//the function converts an integer to ASCII string
char *my_itoa(int nmb)
{
    char *str = malloc(sizeof(char) * sizeof(int));
    if (nmb == 0)
    {
        return set_zero(str);
    }

    char *ptr = str;
    char *start = str;

    if (nmb < 0) 
    {
        *ptr = '-';
        nmb = (-1) * nmb;
        ptr++, start++;
    }

    while (nmb != 0)
    {
        *ptr = (nmb % 10) + '0';
        ptr++;
        nmb /= 10;
    }
    *ptr = '\0';
    ptr--;

    reverse_str(start, ptr);

    return str;
}
