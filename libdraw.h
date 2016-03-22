/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdraw.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 23:18:43 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/23 00:38:36 by nmougino         ###   ########.fr       */
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

typedef struct	s_img
{
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	void		*img;
}				t_img;

typedef	struct	s_px
{
	int			x;
	double		y;
	float		color;
}				t_px;

//chaecker que le point est dans l'image.
void			draw_pixel(t_img *img, t_pix pt);


#endif
