/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_curcolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 16:23:51 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/23 17:47:32 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

float	draw_line_curcolor(t_line line, t_px cur)
{
	float	ans;

	ans = (float)(((((line.dst.x - cur.x)
		+ (line.dst.y - cur.y)) * line.src.color)
		+ (((line.src.x - cur.x)
		+ (line.src.y - cur.y)) * line.dst.color)))
		/ (float)(line.dx - line.dy);
	return (ans);
}
