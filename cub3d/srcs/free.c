#include "../include/cub3d.h"

// void    ft_free(char **src)
// {
//     char    *tmp;

//     if (*src != NULL)
//     {
//         tmp = *src;
//         src++;
//         free (tmp);
//     }
//     // if (src)
//     //     free (src);
// }
void    ft_free(char **src)
{
    int i;
    int size;
    size = 0;
    while (src[size])
        size++;
    i = 0;
    while (i <= size)
    {
        free(src[i]);
        i++;
    }
    free (src);
}