/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 23:19:05 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/23 19:38:15 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"
#include "mlx.h"
#include "libft.h"

int		main(void)
{
	void	*mlx = mlx_init();
	void	*win = mlx_new_window(mlx, 800, 800, "fenetre");

	t_img	*img = draw_new_img(mlx, 800, 800);

	t_px	p1;
	t_px	p2;

	p1.x = 400;
	p1.y = 400;
	p1.color = 0;
	p2.x = 400;
	p2.y = 300;
	p2.color = 0.7;



	draw_line(img, &p1, &p2);



	mlx_put_image_to_window(mlx, win, img->img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
