/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:29:37 by aiarinov          #+#    #+#             */
/*   Updated: 2022/03/27 14:24:02 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

// int main()
// {
//     char c;

//     c = 'a';
//     printf ("%c -> %c", c, ft_toupper(c));
//     c = 'D';
//     printf("\n%c -> %c", c, ft_toupper(c));

//     c = '9';
//     printf("\n%c -> %c", c, ft_toupper(c));
//     return 0;
// }
