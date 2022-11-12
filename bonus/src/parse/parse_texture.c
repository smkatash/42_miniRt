/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:49:58 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/12 15:28:29 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

/**
 * @brief sets texture type based on key word
 * @return texture type
 */
static t_etexture	object_texture(char **str, int len, int i)
{
	if (ft_strcmp(str[i], "-rgb") == 0)
	{
		if (len == i + 5)
			return (COLOR);
	}
	else if (ft_strcmp(str[i], "-ck") == 0)
	{
		if (len == i + 8)
			return (CHECKBOARD);
	}
	else if (ft_strcmp(str[i], "-bmp") == 0)
	{
		if (len == i + 6 || len == i + 5)
			return (BUMPMAP);
	}
	return (UNDEF);
}

/**
 * @brief sets RGB if 1 parameter after index
 * @return texture type
 */
static t_etexture	color_texture(int len, int i)
{
	if (len == i + 1)
		return (COLOR);
	return (UNDEF);
}

/**
 * @brief defines texture type based on object types
 * @return texture type
 */
static t_etexture	get_texture_type(t_parse *lst, char **str, int i)
{
	int		line_len;

	line_len = 0;
	while (str[line_len] != NULL)
		++line_len;
	if (line_len <= i)
		return (UNDEF);
	if (lst->type == SPHERE || lst->type == PLANE \
		|| lst->type == CYLINDER || lst->type == CONE)
	{
		return (object_texture(str, line_len, i));
	}
	else if (lst->type == AMBIENT || lst->type == LIGHT)
		return (color_texture(line_len, i));
	return (COLOR);
}

/**
 * @brief sets texture into parse list according to type
 */
static void	set_texture_type(t_parse *lst, char **str, int i)
{
	lst->texture_ident = str[i++];
	if (lst->text_type == COLOR)
		lst->rgb = str[i++];
	else if (lst->text_type == CHECKBOARD)
	{
		lst->rgb = str[i++];
		lst->xcolor = str[i++];
		lst->xwidth = str[i++];
		lst->xheight = str[i++];
	}
	if (lst->text_type == BUMPMAP)
		lst->texture_img = str[i++];
	else
		lst->texture_img = NULL;
	if (lst->text_type == BUMPMAP && str[i + 3] != NULL)
		lst->bump_img = str[i++];
	else
		lst->bump_img = NULL;
	lst->kd = str[i++];
	lst->ks = str[i++];
	lst->ksn = str[i++];
}

/**
 * @brief gets texture from parse list,
 * sets textures according to object type
 */
void	parse_texture(t_parse *lst, char **str, int i)
{
	if (lst->type == CAMERA)
		lst->text_type = CAM;
	else
		lst->text_type = get_texture_type(lst, str, i);
	if (lst->text_type == -1)
		error_message("Invalid texture.\n");
	if (lst->type == AMBIENT || lst->type == LIGHT)
		lst->rgb = str[i++];
	else if (lst->type == SPHERE || lst->type == CYLINDER \
		|| lst->type == PLANE || lst->type == CONE)
		set_texture_type(lst, str, i);
}
