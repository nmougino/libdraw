/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 10:51:11 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/31 10:51:14 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

static int	draw_torgb(float vh)
{
	if (vh < 0)
		vh += 1.0;
	if (vh > 1)
		vh -= 1.0;
	if (vh * 6.0 < 1)
		return (6.0 * vh * 255);
	if (vh * 2.0 < 1)
		return (255);
	if (vh * 3.0 < 2)
		return ((4.0 - (6.0 * vh)) * 255);
	return (0);
}

void		draw_pixel(t_img *img, t_px pt)
{
	int	col;

	col = 0;
	if ((pt.x < img->width && pt.x >= 0) && (pt.y < img->height && pt.y >= 0))
	{
		col = ((draw_torgb(pt.color + (1.0 / 3.0))) * 65536)
			+ ((draw_torgb(pt.color)) * 256)
			+ (draw_torgb(pt.color - (1.0 / 3.0)));
		*((int*)(unsigned long)(img->data + ((img->size_line * (pt.y))
						+ ((pt.x) * (img->bpp / 8))))) = col;
	}
}
