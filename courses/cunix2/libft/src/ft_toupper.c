#include "../libft.h"

static const int lower_upper_gap = -32;

int ft_toupper(int ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return ch + lower_upper_gap; 
    }
    else
    {
        return ch;
    }
}
