//the function returns 1 if a char is a digit, 0 if it isn't
int is_digit(char ch)
{
    return ch >= '0' && ch <= '9';
}

//the function converts an ASCII string to an integer
int my_atoi(const char *nptr)
{
    int n = 0;
    int sign = 1;
    
    if (*nptr == '-')
    {
        sign = -1;
        nptr++;
    }
    
    for (; *nptr != '\0'; nptr++)
    {
        if (!is_digit(*nptr))
        {
            break;
        }
        n = 10 * n + *nptr - '0';
    }

    return sign * n;
}
