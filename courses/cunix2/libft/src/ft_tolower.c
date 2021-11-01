#include "../libft.h"

const int upper_lower_gap = 32;

int ft_tolower(int ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        return ch + upper_lower_gap;
    }
    else
    {
        return ch;
    }
}
