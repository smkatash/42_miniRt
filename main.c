/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:31:46 by aiarinov          #+#    #+#             */
/*   Updated: 2022/10/04 13:35:08 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void err (char *str)
{
	write(1, &str, ft_strlen(str));
	exit(0);
}

void	parse_color(t_color *result, char *field)
{
	char	**color;
	color = ft_split(field, ',');
	if (ft_strlen(color) != 3)
		err("wrong number of colors");
	result->red = ft_atoi(color[0]);
	result->green = ft_atoi(color[1]);
	result->blue = ft_atoi(color[2]);
	if (result->red < 0 || result->red > 255 || result->green < 0 || result->green > 255 || result->blue < 0 || result->blue > 255)
		err("not existing color");
}

void	parse_coords(t_v3 *point, char *field)
{
	char	**coords;

	coords = ft_split(field, ',');
	if (ft_strlen(coords) != 3)
		err("Wrong number of coordinate arg");
	point->x = ft_atoi(coords[0]);//ft_atoi change for double numbers
	point->y = ft_atoi(coords[1]);
	point->z = ft_atoi(coords[2]);
}

void	parse_sphere(char **splitted)
{
	t_sph	*sphere;
	t_color	*color;

	if (ft_strlen(splitted) != 4)
		err("Invalid argument length");
	sphere = malloc(sizeof(t_sph));
	parse_coords(&(sphere->center), splitted[1]);
	sphere->diametr = ft_atoi(splitted[2]);
	parse_color(&color, splitted[3]);
}

void parse_line(char **splitted)
{
	if (ft_strncmp(splitted[0], "A", 1) == 0)
		parse_ambient(splitted);
	else if (ft_strncmp(splitted[0], "C", 1) == 0)
		parse_camera(splitted);
	else if (ft_strncmp(splitted[0], "L", 1) == 0)
		parse_light(splitted);
	else if (ft_strncmp(splitted[0], "sp", 2) == 0)
		parse_sphere(splitted);
	else if (ft_strncmp(splitted[0], "pl", 2) == 0)
		parse_plane(splitted);
	else if (ft_strncmp(splitted[0], "cy", 2) == 0)
		parse_cylinder(splitted);
	else
		err("Unknown element in the scene.");

}

void parse ()
{
	char **splitted;

	splitted =
	parse_line(splitted);
}

static t_my_mlx	init_mlx(void)
{
	t_my_mlx	mlx_main;

	mlx_main.win_heigh = IMG_HEIGHT;
	mlx_main.win_width = IMG_WIDTH;
	mlx_main.mlx_ptr = mlx_init();
	mlx_main.mlx_win = mlx_new_window(mlx_main.mlx_ptr, IMG_HEIGHT,
			IMG_WIDTH, "MiniRt");
	mlx_main.mlx_img = mlx_new_image(mlx_main.mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	return (mlx_main);
}

void	minirt(char *filename)
{
	parse();
	init_mlx();
}

int main (int argc, char **argv)
{
	if (argc != 2)
		err("Wrong arguments");
	else
		minirt(argv[1]);
	return(0);

}
