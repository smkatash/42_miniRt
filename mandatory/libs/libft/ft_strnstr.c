/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 09:26:45 by aiarinov          #+#    #+#             */
/*   Updated: 2022/04/06 17:23:02 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*bigstr;
	char	*littlestr;

	i = 0;
	j = 0;
	bigstr = (char *)big;
	littlestr = (char *)little;
	if (ft_strlen(little) == 0)
		return (bigstr);
	while (i < len && bigstr[i] != '\0')
	{
		while (bigstr[i + j] == littlestr[j] && len > i + j)
		{
			j++;
			if (littlestr[j] == '\0')
				return (bigstr + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}

//The strstr function locates the first occurrence of
// the null-terminated string \c little in the null-terminated string \c big.
//line 26 if some charachter equal the first character of littlestr
//line 28 compare big and little only strlen of little and if equal 0,
// that means that they are similar

// int main () {
//    const char haystack[20] = "TutorialsPoint";
//    const char needle[10] = "rial";
//    char *ret;

//    ret = strnstr(haystack, needle,4);

//    printf("The substring in    strnstr is: %s\n", ret);
//    //ft_strnstr(haystack, needle,6);
//    printf("The substring in ft_strnstr is: %s\n",
//	ft_strnstr(haystack, needle,4));

//    return(0);
// }
