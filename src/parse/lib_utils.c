/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:16:56 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/17 15:51:09 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse.h"

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
        while (isdigit(ch))
        {
            i = i * 10 + (ch - '0');
            ch = *str++;
        }
        *fpoint = i * sign;
    }
}

double atof(const char *str)
{
    int     ch;
    double  fl = 0.0;
    int     fpoint = 0;

    while ((ch = *str++) != '\0' && isdigit(ch))
    {
        fl = fl * 10.0 + (ch - '0');
    }
    if (ch == '.')
    {
        while ((ch = *str++) != '\0' && isdigit(ch))
        {
            fl = fl * 10.0 + (ch - '0');
            fpoint = fpoint - 1;
        }
    }
    define_sign(ch, (char*)str, &fpoint);
    define_fpoint(&fl, fpoint);
    return (fl);
}
