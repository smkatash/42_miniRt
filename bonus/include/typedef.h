/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:01:29 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/12 14:44:13 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

# include "minirt_bonus.h"

typedef struct s_vec3	t_vector;
typedef struct s_vec3	t_point;
typedef struct s_vec3	t_color;
typedef double			t_matrix[3];

// enum definitions
typedef enum e_form
{
	NA = -1,
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
	CONE,
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
	KD,
	KS,
	KSN,
}			t_type_data;

typedef enum e_etexture
{
	UNDEF = -1,
	COLOR,
	CHECKBOARD,
	BUMPMAP,
	CAM,
}	t_etexture;

// Universal param
struct s_vec3
{
	double		x;
	double		y;
	double		z;
};

// Quadratic eq
typedef struct s_equation
{
	double		a;
	double		half_b;
	double		c;
}				t_equation;

// Parser
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
	char		*kd;
	char		*ks;
	char		*ksn;
	t_etexture	text_type;
	char		*rgb;
	char		*texture_ident;
	char		*texture_img;
	char		*bump_img;
	char		*xcolor;
	char		*xwidth;
	char		*xheight;
}				t_parse;

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
}				t_camera;

// Ray
typedef struct s_ray
{
	t_point		origin;
	t_vector	direction;
}				t_ray;

// Lights
typedef struct s_ambient
{
	t_color		light_color;
	double		light_ratio;
}				t_ambient;

typedef struct s_light
{
	t_point		origin;
	double		bright_ratio;
}				t_light;

// Objects
typedef struct s_cone
{
	t_point		center;
	double		radius;
	double		radius2;
	t_vector	normal;
	double		height;
	double		kd;
	double		ks;
	double		ksn;
}				t_cone;

typedef struct s_sphere
{
	t_point		center;
	double		radius;
	double		radius2;
	double		kd;
	double		ks;
	double		ksn;
}				t_sphere;

typedef struct s_plane
{
	t_point		point;
	t_vector	normal;
	double		radius;
	double		kd;
	double		ks;
	double		ksn;
}				t_plane;

typedef struct s_cylinder
{
	t_point		center;
	t_vector	normal;
	double		radius;
	double		radius2;
	double		height;
	double		kd;
	double		ks;
	double		ksn;
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

// Textures
typedef struct s_checkboard
{
	t_color		xcolor;
	int			xwidth;
	int			xheight;
}	t_checkboard;

typedef struct s_bumpmap
{
	t_xpm_image	*surface;
	t_xpm_image	*map;
}	t_bumpmap;

typedef struct s_texture
{
	t_color			color;
	t_checkboard	*checkboard;
	t_bumpmap		*map;
}	t_texture;

// Record info
typedef struct s_record
{
	t_point		point;
	t_vector	normal;
	t_vector	u_dir;
	t_vector	v_dir;
	t_color		color;
	void		*objects;
	bool		front_face;
	double		tmin;
	double		tmax;
	double		t;
	double		u;
	double		v;
	double		kd;
	double		ks;
	double		ksn;
}	t_record;

// Objects list
typedef struct s_objlist
{
	t_form		type;
	t_texture	texture;
	void		*object;
	void		*next;
}	t_objlst;

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

typedef bool			(*t_hittable) \
	(t_objlst *objects, t_ray *ray, t_record *record);

#endif
