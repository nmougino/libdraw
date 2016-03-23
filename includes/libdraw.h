/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdraw.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 02:00:06 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/23 13:46:30 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Cette librairie a pour objet d'offrir un certain nombre
** de fonctions compatibles mlx.
**
** Elle sera utilisee pour la premiere fois par le programme fdf.
*/

#ifndef LIBDRAW_H
# define LIBDRAW_H

#include "mlx.h"

typedef struct	s_img
{
	char		*data;
	int			width;
	int			height;
	int			bpp;
	int			size_line;
	int			endian;
	void		*img;
}				t_img;

typedef	struct	s_px
{
	int			x;
	int			y;
	float		color;
}				t_px;

void			draw_pixel(t_img *img, t_px pt);

void			draw_ver_line(t_img *img, t_px *src, t_px *dst, t_px d);
void			draw_hor_line(t_img *img, t_px *src, t_px *dst, t_px d);
void			draw_line(t_img *img, t_px *src, t_px *dst);

t_img			*draw_new_img(void *mlx, int width, int height);

void			draw_square(t_img *img, t_px p1, t_px p2, float color);
void			draw_empty_square(t_img *img, t_px p1, t_px p2, float color);

void			draw_clear_img(t_img *img);
#endif
