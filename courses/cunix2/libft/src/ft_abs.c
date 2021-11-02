#include "../libft.h"

int ft_abs(int x)
{
    if (x < 0)
    {
        return (-1) * x;
    }
    else
    {
        return x;
    }
}
