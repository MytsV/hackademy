//the function copies a string from source to destination
char *my_strcpy(char *dest, const char *src)
{
    char *start = dest;
    for (; (*dest = *src) != '\0'; src++, dest++);
    return start;
}
