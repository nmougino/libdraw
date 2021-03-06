/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdraw.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 02:00:06 by nmougino          #+#    #+#             */
/*   Updated: 2016/05/29 01:39:47 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Cette librairie a pour objet d'offrir un certain nombre
** de fonctions compatibles mlx.
** Elle sera utilisee pour la premiere fois par le programme fdf.
*/

#ifndef LIBDRAW_H
# define LIBDRAW_H

# include "mlx.h"
# include "libft.h"

typedef struct		s_img
{
	char			*data;
	int				width;
	int				height;
	int				bpp;
	int				size_line;
	int				endian;
	void			*img;
}					t_img;

typedef	struct		s_px
{
	int				x;
	int				y;
	float			color;
}					t_px;

typedef	struct		s_upx
{
	unsigned int	x;
	unsigned int	y;
	float			color;
}					t_upx;

typedef	struct		s_line
{
	t_px			src;
	t_px			dst;
	int				dx;
	int				dy;
	int				n;
}					t_line;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

void				draw_clear_img(t_img *img, int color);

float				draw_line_curcolor(t_line line, t_px cur);

void				draw_line(t_img *img, t_px *src, t_px *dst);

void				draw_line_rgb(t_img *img, t_px *src, t_px *dst, int color);

t_img				*draw_new_img(void *mlx, int width, int height);

t_line				draw_new_line(t_px *src, t_px *dst);

void				draw_pixel(t_img *img, t_px pt);

void				draw_pixel_rgb(t_img *img, t_px pt, int color);

void				draw_empty_square(t_img *img, t_px p1, t_px p2, float color);
void				draw_square(t_img *img, t_px p1, t_px p2, float color);

int					draw_hsltorgb(int t, float s, float v);
#endif
