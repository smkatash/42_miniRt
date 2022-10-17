/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:10:52 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/17 15:11:36 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse.h"

int	get_input_file(int argv, char **argc)
{
	char	*format;
	int		fd;
	int		filename_len;
	int		end_len;

	format = ".rt";
	if (argv != 2)
		error_message("Wrong number of arguments...\n");
	filename_len = ft_strlen(argc[1]);
	if (filename_len < 3)
		error_message("The file format should be: [filename].rt\n");
	end_len = ft_strncmp(&argc[1][filename_len - 3], format, 3);
	if (end_len != 0)
		error_message("The file format should be: [filename].rt\n");
	fd = open(argc[1], O_RDONLY);
	if (fd < 0)
		error();
	return (fd);
}

