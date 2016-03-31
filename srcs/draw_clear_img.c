/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_clear_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 13:42:28 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/31 16:01:40 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

void	draw_clear_img(t_img *img, int color)
{
	t_px	cur;

	cur.x = 0;
	cur.y = 0;
	while (cur.y < img->height)
	{
		cur.x = 0;
		while (cur.x < img->width)
		{
			*((int*)(unsigned long)(img->data + ((img->size_line * (cur.y))
							+ ((cur.x) * (img->bpp / 8))))) = color;
			cur.x++;
		}
		cur.y++;
	}
}
