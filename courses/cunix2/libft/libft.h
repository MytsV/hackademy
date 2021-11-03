#ifndef LIBFT_H_
# define LIBFT_H_
#include <stdlib.h>

typedef unsigned long size_t;

void ft_bzero(void *s, size_t n);
char *ft_strchr(const char *str, int ch);
int ft_isalpha(int ch);
int ft_isdigit(int ch);
int ft_isascii(int ch);
int ft_toupper(int ch);
int ft_tolower(int ch);
int ft_abs(int x);
div_t ft_div(int nominator, int denominator);
extern char *ft_strstr(const char *haystack, const char *needle);
extern char *ft_strnstr(const char *haystack, const char *needle, size_t len); 
void *ft_memset(void *destination, int c, size_t n);
void *ft_memcpy(void *dest, const void *source, size_t count);
int ft_memcmp(const void *buf1, const void *buf2, size_t count);
void ft_striter(char *s, void (*f)(char *));

#endif
