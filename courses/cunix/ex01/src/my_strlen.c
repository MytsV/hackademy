//the function determines the length of a string
unsigned int my_strlen(char *str)
{
    int len = 0;
    for (; *str != '\0'; str++)
    {
        len++;
    }
    return len;
}
