/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:45:32 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/12 19:02:24 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_update_text(char *src)
{
	int		len;
	int		i;
	char	*text;

	len = 0;
	while (src[len] != '\n' && src[len])
		len++;
	if (!src[len])
	{
		free(src);
		return (NULL);
	}
	text = malloc(sizeof(char) * (ft_strlen(src) - len + 1));
	if (!text)
		return (NULL);
	len++;
	i = 0;
	while (src[len])
	{
		text[i++] = src[len++];
	}
	text[i] = '\0';
	free(src);
	return (text);
}

static char	*ft_get_line(char *src)
{
	char	*line;
	int		len;

	len = 0;
	if (src[len] == '\0')
		return (NULL);
	while (src[len] != '\n' && src[len])
		len++;
	line = malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	len = 0;
	while (src[len] != '\n' && src[len])
	{
		line[len] = src[len];
		len++;
	}
	if (src[len] == '\n')
	{
		line[len] = src[len];
		len++;
	}
	line[len] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	int			n;
	char		*buff;
	char		*line;
	static char	*text;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	n = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (n != 0 && !(ft_strchr_gnl(text, '\n')))
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[n] = '\0';
		text = ft_strjoin_gnl(text, buff);
	}
	free(buff);
	line = ft_get_line(text);
	text = ft_update_text(text);
	return (line);
}
