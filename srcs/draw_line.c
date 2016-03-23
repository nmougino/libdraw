/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 23:41:15 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/23 01:59:29 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"
#include "libft.h"

/*
** Tracer une ligne en degrade
*/

static float	draw_line_curcolor(t_px *src, t_px *dst, t_px delta, t_px tmp)
{
	float	ans;

	ans = (float)(((((dst->x - tmp.x) + (dst->y - tmp.y)) * src->color)
		+ (((src->x - tmp.x) + (src->y - tmp.y)) * dst->color)))
		/ (float)(delta.x - delta.y);
	return (ans);
}

void			draw_ver_line(t_img *img, t_px *src, t_px *dst, t_px d)
{
	t_px	p1;
	t_px	p2;

	p1 = *src;
	p2 = *dst;
	if (src->y > dst->y)
	{
		p1 = p2;
		p2 = *src;
	}
	while (p1.y <= p2.y)
	{
		p1.color = draw_line_curcolor(src, dst, d, p1);
		draw_pixel(img, p1);
		p1.y++;
	}
}

void			draw_hor_line(t_img *img, t_px *src, t_px *dst, t_px d)
{
	t_px	p1;
	t_px	p2;

	p1 = *src;
	p2 = *dst;
	if (src->x > dst->x)
	{
		p1 = p2;
		p2 = *src;
	}
	while (p1.x <= p2.x)
	{
		p1.color = draw_line_curcolor(src, dst, d, p1);
		draw_pixel(img, p1);
		p1.x++;
	}
}

void			draw_line(t_img *img, t_px *src, t_px *dst)
{
	t_px	d;

	d.x = dst->x - src->x;
	d.y = dst->y - src->y;
	if (ft_abs(d.x) <= 1 && ft_abs(d.y) <= 1)
	{
		draw_pixel(img, *src);
		draw_pixel(img, *dst);
	}
	else if (d.x == 0)
		draw_ver_line(img, src, dst, d);
	else if (d.y == 0)
		draw_hor_line(img, src, dst, d);
	//else
	//	draw_bresenham(src, dst, d);
}
