#include <stdarg.h>
#include "../include/libft.h"
#include "../include/linked_list.h"
#include "../include/my_puts.h"
#include "../include/atoi_itoa.h"
//using functions i wrote in the previous exercises

typedef struct modification
{
    char modifier;
    int padding;
    char padding_char;
} modification_t;

static char *get_new_char_between(char *beginning, char *end)
{
    char *token = malloc(end - beginning + 1);
    char *token_start = token;
    while (beginning < end)
    {
        *token = *beginning;
        token++;
        beginning++;
    }
    *token = '\0';
    return token_start;
}

static char *char_to_str(char c)
{
    char *str = malloc(sizeof(char) * 2);
    *str = c;
    *(str + 1) = '\0';
    return str;
}

static char *get_str_from_char(va_list args)
{
    char c = va_arg(args, int);
    return char_to_str(c);
}

static char *to_mem_from_literal(char *str)
{
    int str_len = ft_strlen(str);
    char *str_mem = malloc(sizeof(char) * (str_len + 1));
    return ft_memcpy(str_mem, str, str_len + 1);
}

static const char *get_str_from_str(va_list args)
{
    char const *str = va_arg(args, const char *);
    if (str == NULL)
    {
        return to_mem_from_literal("(null)");
    }
    else
    {
        return to_mem_from_literal(str);
    }
}

static const char *get_int_modified(char *converted, char modifier)
{
    char *str = char_to_str(modifier);
    return ft_strjoin(str, converted);
}

static const char *get_int_from_str(va_list args, char modifier)
{
    int number = va_arg(args, int);
    char *converted = my_itoa(number);
    if (modifier && (number >= 0))
    {
        char const *modified = get_int_modified(converted, modifier);
        free(converted);
        return modified;
    } 
    else
    {
        return converted;
    }
}

static const char *get_specifier_value(char *specifier, va_list args, char modifier)
{
    switch (*specifier)
    {
        case 'c':
        {
            return get_str_from_char(args);
            break;
        }
        case 'd':
        {
            return get_int_from_str(args, modifier);
            break;
        }
        case 'i':
        {
            return get_int_from_str(args, modifier);
            break;
        }
        case 's':
        {
            return get_str_from_str(args);
            break;
        }
        case '%':
        {
            return to_mem_from_literal("%");
            break;
        }
        default:
        {
            return to_mem_from_literal("");
            break;
        }            
    }
}

static int is_sign(char ch)
{
    return ch == ' ' || ch == '+' || ch == '-'; 
}

static char const *get_str_padded(char const *str, int padding, char padding_char)
{
    int str_len = ft_strlen(str);

    if (str_len >= padding)
    {
        return str;
    }

    char *str_padded = malloc(sizeof(char) * (padding + 1));
    char *str_padded_start = str_padded;

    if (padding_char == '0' && is_sign(*str))
    {
        *str_padded = *str;
        str++, str_padded++;
    }

    for (int i = 0; i < padding - str_len; i++, str_padded++)
    {
        *str_padded = padding_char;
    }

    while (*str != '\0')
    {
        *str_padded = *str;
        str++, str_padded++;
    }
    *str_padded = '\0';

    return str_padded_start;
}

static int ismodifier(char str)
{
    return str == ' ' || str == '+';
}

static int previous_is_digit(char *specifier_start)
{
    return ft_isdigit(*(specifier_start - 1));
}

static int is_zero_pad(char *specifier_start)
{
    return *specifier_start == '0' && !previous_is_digit(specifier_start);
}

static modification_t get_modification(char *specifier_start, char *specifier_end)
{
    modification_t mod;
    mod.modifier = '\0';
    mod.padding_char = ' ';
    mod.padding = 0;

    char *number_start = NULL;
    char *number_end = NULL;

    int previous_zero = 0;

    while (specifier_start <= specifier_end) 
    {
        if (number_start != NULL && !ft_isdigit(*specifier_start))
        {
            number_end = specifier_start;
        }

        if (*specifier_start == '+' && mod.modifier != ' ')
        {
            mod.modifier = '+';
        } 
        else if (*specifier_start == ' ')
        {
            mod.modifier = ' ';
        }
        else if (is_zero_pad(specifier_start))
        {
            mod.padding_char = '0';
            previous_zero = 1;
        }
        else if (!previous_is_digit(specifier_start) || previous_zero)
        {
            number_start = specifier_start;
        }

        if (!is_zero_pad(specifier_start))
        {
            previous_zero = 0;
        }
        specifier_start++;
    }

    if (number_end != NULL && number_start != NULL && number_end >= number_start)
    {
        char *number_str = get_new_char_between(number_start, number_end);
        mod.padding = my_atoi(number_str);
        free(number_str);
    }

    return mod;
}

static char *get_specifier_end(char *specifier_start)
{
    //incrementing to omit %
    specifier_start++;
    while (ft_isdigit(*specifier_start) || ismodifier(*specifier_start))
    {
        specifier_start++;
    }
    return specifier_start;
}

static char *get_processed_specifier(char *specifier, va_list args)
{
    char *specifier_end = get_specifier_end(specifier);
    modification_t mod = get_modification(specifier, specifier_end);
    char const *value = get_specifier_value(specifier_end, args, mod.modifier);
    value = get_str_padded(value, mod.padding, mod.padding_char);
    return (char *)value;
}

static node_t *add_token(node_t *tokens, char *token)
{
    if (tokens == NULL)
    {
        return list_create(token);
    }
    else
    {
        list_push(tokens, token);
        return tokens;
    }
}

static char *get_tokens_joined(node_t *tokens)
{
    char *str = "";
    while (tokens != NULL)
    {
        str = ft_strjoin(str, (char *)tokens->data);
        tokens = tokens->next;
    }
    return str;
}

static node_t *get_token_list(char *format, va_list args)
{
    char *regular_start = format;
    node_t *tokens = NULL;

    while (*format != '\0')
    {
        if (*format == '%')
        {
            tokens = add_token(tokens, 
                               get_new_char_between(regular_start, format));
            tokens = add_token(tokens, get_processed_specifier(format, args));

            regular_start = get_specifier_end(format) + 1;
            format = regular_start;
        } 
        else
        {
            format++;
        }
    }
    tokens = add_token(tokens, 
                       get_new_char_between(regular_start, format));

    return tokens;
}

static void free_token(void *data)
{
    free((char *)data);
}

int ft_printf(char *format, ...)
{
    va_list args;

    va_start(args, format);
    node_t *tokens = get_token_list(format, args);
    char *str = get_tokens_joined(tokens);
    
    list_destroy(&tokens, free_token);

    my_puts(str);
    free(str);

    va_end(args);

    return 1;
}