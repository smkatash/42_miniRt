/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:36:06 by ktashbae          #+#    #+#             */
/*   Updated: 2022/10/04 12:59:11 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef enum	e_type {
	CAMERA,
	AMB_LIGHT,
	LIGHT,
	SPHERE,
	PLANE,
	SQUARE,
	CYLINDER,
	TRIANGLE
}				t_type;

typedef struct		s_img
{
	void			*ptr;
	char			*addr;
	int				bpp;
	int				size;
	int				endian;
}					t_img;

typedef struct		s_resolution
{
	int				x;
	int				y;
}					t_resolution;

typedef struct		s_coordinate
{
	double			x;
	double			y;
	double			z;
}					t_coordinate;

typedef struct		s_shape
{
	t_coordinate	point;
	t_coordinate	basic;
	t_coordinate	*vertex;
	short int		qtd_vertex;
	int				colour;
	double			ratio;
	double			diam;
	double			height;
	struct s_shape	*next;
}					t_shape;

typedef struct		s_base
{
	char			*line;
	char			**map;
	t_resolution	resolution;
	//  		amb_light;
	//			cam;
	//			light;
	t_shape			*pl;
	t_shape			*sp;
	t_shape			*sq;
}					t_base;

# endif