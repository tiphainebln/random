/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 02:32:57 by tbouline          #+#    #+#             */
/*   Updated: 2017/09/30 03:12:00 by tbouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int 		expose_hook(t_wolf *w)
{
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	return (0);
}

int 		exit_red(t_wolf *w)
{
	exit_wolf(w, 0);
	return (0);
}

int			main(void)
{
	t_wolf w;

	srand(time(NULL));
	w.flag = 0;
	w = wolf_map(w);
	w = init(w);
	w.mlx = mlx_init();
	w.win = mlx_new_window(w.mlx, WIN_X, WIN_Y, "Wolf3D");
	w.img = mlx_new_image(w.mlx, WIN_X, WIN_Y);
	w.data = (int *)mlx_get_data_addr(w.img, &(w.bpp),
			&(w.size_line), &(w.endian));
	draw_loop(&w);
	mlx_expose_hook(w.win, expose_hook, &w);
	mlx_hook(w.win, 2, (1L << 0), key_hook, &w);
	mlx_hook(w.win, 17, 0, exit_red, &w);
	mlx_key_hook(w.win, key_hook, &w);
	mlx_do_key_autorepeaton(w.mlx);
	mlx_loop(w.mlx);
	return (0);
}
