//the function determines the length of a string
unsigned int my_strlen(char *str)
{
    int len = 0;
    while (*(str + len) != '\0')
    {
        len++;
    }
    return len;
}
