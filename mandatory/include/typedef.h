/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:01:29 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/13 23:02:00 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

# include "minirt.h"

typedef struct s_vec3	t_vector;
typedef struct s_vec3	t_point;
typedef struct s_vec3	t_color;

typedef enum e_form
{
	NA = -1,
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
}			t_form;

typedef enum e_type_data
{
	POINT = 0,
	BRI_RATIO,
	NORM_VEC,
	DIAMETER,
	HEIGHT,
	FOV,
	RGB,
}			t_type_data;

struct s_vec3
{
	double		x;
	double		y;
	double		z;
};

typedef struct s_equation
{
	double		a;
	double		half_b;
	double		c;
}				t_equation;

typedef struct s_parse
{
	t_form		type;
	char		*ident;
	char		*bri_ratio;
	char		*point;
	char		*nor_vec;
	char		*diameter;
	char		*height;
	char		*fov;
	char		*rgb;
}	t_parse;

typedef struct s_objlist
{
	t_form		type;
	t_color		color;
	void		*object;
	void		*next;
}	t_objlst;

// Camera
typedef struct s_screen
{
	int			width;
	int			height;
	double		aspect_ratio;
}				t_screen;

typedef struct s_camera
{
	t_point		origin;
	t_vector	w_dir;
	t_vector	u_dir;
	t_vector	v_dir;
	t_vector	horizontal;
	t_vector	vertical;
	t_point		left_bottom;
	double		viewport_height;
	double		viewport_width;
}	t_camera;

// Record info
typedef struct s_record
{
	t_point		point;
	t_vector	normal;
	t_color		color;
	double		tmin;
	double		tmax;
	double		t;
	bool		front_face;
}	t_record;

// Ray
typedef struct s_ray
{
	t_point		origin;
	t_vector	direction;
}	t_ray;

// Lights
typedef struct s_ambient
{
	t_color		light_color;
	double		light_ratio;
}	t_ambient;

typedef struct s_light
{
	t_point		origin;
	double		bright_ratio;
}	t_light;

// Scene
typedef struct s_scene
{
	t_screen	screen;
	t_camera	camera;
	t_objlst	*objects;
	t_objlst	*lights;
	t_ambient	ambient;
	t_ray		ray;
	t_record	record;
}				t_scene;

// Objects
typedef struct s_sphere
{
	t_point		center;
	double		radius;
	double		radius2;
}				t_sphere;

typedef struct s_plane
{
	t_point		point;
	t_vector	normal;
	double		radius;
}				t_plane;

typedef struct s_cylinder
{
	t_point		center;
	t_vector	normal;
	double		radius;
	double		radius2;
	double		height;
}				t_cylinder;

// MLX
typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line;
	int			endian;
}				t_image;

typedef struct s_xpm_image
{
	t_image		data;
	int			height;
	int			width;
}				t_xpm_image;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_image		img;
}				t_mlx;

typedef bool			(*t_hittable) \
	(t_objlst *objects, t_ray *ray, t_record *record);

#endif
