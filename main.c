/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 23:19:05 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/23 13:50:28 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"
#include "mlx.h"


void	tourne(void *mlx, void *win, t_img *img)
{
	t_px p1;
	t_px p2;

	p1.x = 400;
	p1.y = 400;
	p2.x = 450;
	p2.y = 450;

	while (1)
	{
		draw_clear_img(img);
		draw_square(img, p1, p2, 0);
		mlx_put_image_to_window(mlx, win, img->img, 0, 0);
		if (p2.y < 750)
		{
			p1.y++;
			p2.y++;
		}
	}
	

}

int		main(void)
{
	void	*mlx = mlx_init();
	void	*win = mlx_new_window(mlx, 800, 800, "fenetre");

	t_img	*img = draw_new_img(mlx, 800, 800);

	tourne(mlx, win, img);
	mlx_loop(mlx);
	return (0);
}
