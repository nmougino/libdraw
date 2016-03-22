/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 23:41:15 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/23 00:38:14 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	draw_ver_line(t_img *img, t_px *src, t_px *dst, t_px d)
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
		p1
		draw_px(img, p1);
		p1.y++;
	}
}

void	draw_line(t_img *img, t_px *src, t_px *dst)
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
		draw_ver_line(img, src, dst);
	else if (d.y == 0)
		draw_hor_line(img, src, dst);
}
