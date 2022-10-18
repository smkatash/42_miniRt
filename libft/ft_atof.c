/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:14:46 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/18 02:02:45 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void define_fpoint(double *fl, int fpoint)
{
    while (fpoint > 0)
    {
        *fl *= 10.0;
        fpoint--;
    }
    while (fpoint < 0)
    {
        *fl *= 0.1;
        fpoint++;
    }
}

void    define_sign(int ch, char *str, int *fpoint)
{
    int sign;
    int i;

    sign = 1;
    i = 0;
    if (ch == 'e' || ch == 'E')
    {
        ch = *str++;
        if (ch == '+')
            ch = *str++;
        else if (ch == '-')
        {
            ch = *str++;
            sign = -1;
        }
        while (ft_isdigit(ch))
        {
            i = i * 10 + (ch - '0');
            ch = *str++;
        }
        *fpoint = i * sign;
    }
}

double ft_atof(const char *str)
{
    int     ch;
    double  fl = 0.0;
    int     fpoint = 0;

    while ((ch = *str++) != '\0' && ft_isdigit(ch))
    {
        fl = fl * 10.0 + (ch - '0');
    }
    if (ch == '.')
    {
        while ((ch = *str++) != '\0' && ft_isdigit(ch))
        {
            fl = fl * 10.0 + (ch - '0');
            fpoint = fpoint - 1;
        }
    }
    define_sign(ch, (char*)str, &fpoint);
    define_fpoint(&fl, fpoint);
    return (fl);
}