/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 23:19:05 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/23 15:10:51 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"
#include "mlx.h"
#include "libft.h"

int		main(void)
{
	/*
	void	*mlx = mlx_init();
	void	*win = mlx_new_window(mlx, 800, 800, "fenetre");

	t_img	*img = draw_new_img(mlx, 800, 800);

	tourne(mlx, win, img);
	mlx_loop(mlx);
	*/

	int a = 673;
	int err = -a >> 1;

	ft_putnbrendl(a);
	ft_putnbrendl(err);


	return (0);
}
