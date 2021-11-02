#include "../libft.h"

div_t ft_div(int numerator, int denominator)
{
    div_t item;
    item.quot = numerator / denominator;
    item.rem = numerator % denominator;
    return item; 
}
