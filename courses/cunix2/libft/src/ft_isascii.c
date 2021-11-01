#include "../libft.h"

int ft_isascii(int ch)
{
    return ch >= 0 && ch <= 0x7F;
}
