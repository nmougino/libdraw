/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 22:48:04 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/23 01:49:25 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

static int	ft_toRgb(float vh)
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

void	ft_img_pixel_put(t_img *img, int x, int y, float color)
{
	int 	col;

	col = ((ft_toRgb(color + (1.0 / 3.0))) * 65536)
		+ ((ft_toRgb(color)) * 256)
		+ (ft_toRgb(color - (1.0 / 3.0)));
	*((int*)(unsigned long)(img->data + ((img->size_line * y)
					+ (x * (img->bpp / 8))))) = col;
}

float	ft_curcolor(t_pix *src, t_pix *dst, t_pix delta, t_pix tmp)
{
	float	ans;

	ans = (float)(((((dst->x - tmp.x) + (dst->y - tmp.y)) * src->color)
		+ (((src->x - tmp.x) + (src->y - tmp.y)) * dst->color)))
		/ (float)(delta.x - delta.y);
	printf("couleur courante: %f", ans);
	return (ans);
}

void segment(t_img *img, t_pix *pix1, t_pix *pix2)
{
	t_pix	cur;
	t_pix	delta;
	double	m;
	float	color;

	delta.x = pix2->x - pix1->x;
	delta.y = pix2->y - pix1->y;
	cur.x = pix1->x;
	cur.y = pix1->y;
	m = (pix2->y - pix1->y) / (pix2->x - pix1->x);
	while (cur.x <= pix2->x)
	{
		color = ft_curcolor(pix1, pix2, delta, cur);
		ft_img_pixel_put(img, cur.x, (int)(cur.y + 0.5), color);
		cur.y += m;
		(cur.x)++;
	}
}

/*
**	Il reste a solutionner le probleme de l'affichage en pointille des lignes...
*/

void	ft_putline(t_img *img, t_pix *src, t_pix *dst)
{
	if (src->x < dst->x)
		segment(img, src, dst);
	else
		segment(img, dst, src);

}

t_img	*ft_new_img(void *mlx, int param, int x, int y)
{
	t_img	*ans;

	ans = (t_img*)malloc(sizeof(t_img));
	if (!ans)
		return (NULL);
	if (param == 0)
		ans->img = mlx_new_image(mlx, WINX, WINY);
	else
		ans->img = mlx_new_image(mlx, x, y);
	ans->data = mlx_get_data_addr(ans->img, &(ans->bpp), &(ans->size_line), &(ans->endian));
	return (ans);
}
