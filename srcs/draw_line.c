/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 23:41:15 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/23 19:27:00 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

/*
 ** Tracer une ligne en degrade
 */

void			draw_ver_line(t_img *img, t_line line)
{
	t_px	p1;

	p1 = line.src;
	if (line.src.y > line.dst.y)
		p1 = line.dst;
	while (p1.y <= line.dst.y)
	{
		p1.color = draw_line_curcolor(line, p1);
		draw_pixel(img, p1);
		p1.y++;
	}
}

void			draw_hor_line(t_img *img, t_line line)
{
	t_px	p1;

	p1 = line.src;
	if (line.src.x > line.dst.x)
		p1 = line.dst;
	while (p1.x <= line.dst.x)
	{
		p1.color = draw_line_curcolor(line, p1);
		draw_pixel(img, p1);
		p1.x++;
	}
}

void			draw_bresenham(t_img *img, t_line line)
{
	int		e;
	t_px	inc;
	t_px	cur;

	inc.x = (line.dst.x - line.src.x < 0) ? -1 : 1;
	inc.y = (line.dst.y - line.src.y < 0) ? -1 : 1;
	e = -line.dx >> 1;
	cur = line.src;
	while (cur.x != line.dst.x)
	{
		cur.color = draw_line_curcolor(line, cur);
		draw_pixel(img, cur);
		e += line.dy;
		while (e > 0)
		{
			draw_pixel(img, cur);
			cur.color = draw_line_curcolor(line, cur);
			e -= line.dx;
			cur.y += inc.y;
		}
		cur.x += inc.x;
	}

}

void			draw_line(t_img *img, t_px *src, t_px *dst)
{
	t_line	line;

	line = draw_new_line(src, dst);

	if (line.dx <= 1 && line.dy <= 1)
	{
		draw_pixel(img, *src);
		draw_pixel(img, *dst);
		ft_putendl("prout");
	}
	else if (line.dx == 0)
		draw_ver_line(img, line);
	else if (line.dy == 0)
		draw_hor_line(img, line);
	else
		draw_bresenham(img, line);
}
