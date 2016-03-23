/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_curcolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 16:23:51 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/23 16:24:23 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

float	draw_line_curcolor(t_px *src, t_px *dst, t_px delta, t_px tmp)
{
	float	ans;

	ans = (float)(((((dst->x - tmp.x) + (dst->y - tmp.y)) * src->color)
		+ (((src->x - tmp.x) + (src->y - tmp.y)) * dst->color)))
		/ (float)(delta.x - delta.y);
	return (ans);
}
