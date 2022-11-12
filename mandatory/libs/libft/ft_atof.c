/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:14:46 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/12 19:24:46 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	define_fpoint(double *fl, int fpoint)
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

void	define_sign(int ch, char *str, int *fpoint)
{
	int	sign;
	int	i;

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

static double	convert(const char *str, double fl, int fpoint, int neg)
{
	if (str[0] == '-')
	{
		neg = -1;
		str++;
	}
	while (*str != '\0' && ft_isdigit(*str))
	{
		fl = fl * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (*str != '\0' && ft_isdigit(*str))
		{
			fl = fl * 10.0 + (*str - '0');
			fpoint = fpoint - 1;
			str++;
		}
	}
	define_sign(*str, (char *)str, &fpoint);
	define_fpoint(&fl, fpoint);
	return (fl * neg);
}

double	ft_atof(const char *str)
{
	double	fl;
	int		fpoint;
	int		neg;

	fl = 0.0;
	fpoint = 0;
	neg = 1;
	return (convert(str, fl, fpoint, neg));
}
