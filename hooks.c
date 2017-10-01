/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 04:19:45 by tbouline          #+#    #+#             */
/*   Updated: 2017/09/30 04:19:47 by tbouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void 		refresh(t_wolf *w, int keycode)
{
	draw_loop(w);

	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	if (keycode == 40)
	{
		w->flag = 1;
		mlx_string_put(w->mlx, w->win, 25, 550, 0x000000,\
			"YOU'RE VERY POWERFUL.");
	}
	if (keycode == 15 && w->flag)
	{
		w->flag = -1;
		mlx_string_put(w->mlx, w->win, 350, 550, 0x000000,\
			"NOPE. CONSIDER THIS YOUR PUNISHMENT.");
	}
	else if (w->flag == -1)
	{
		mlx_string_put(w->mlx, w->win, 350, 550, 0x000000,\
			"YOU MUST FEEL PRETTY LONELY RIGHT ABOUT NOW.");
	}
}

int 		check_position(t_wolf *w, int direction)
{
	double x;
	double y;

	if (direction == UP)
	{
		x = w->pos_x + (cos((w->angle / 180) * M_PI) * 0.2);
		y = w->pos_y + (sin((w->angle / 180) * M_PI) * 0.2);
	}
	else
	{
		x = w->pos_x - (cos((w->angle / 180) * M_PI) * 0.2);
		y = w->pos_y - (sin((w->angle / 180) * M_PI) * 0.2);
	}
	if (x >= 0 && x <= 14 && y >= 0 && y <= 14 && w->map[(int)x][(int)y] == 0)
		return (1);
	return (0);
}

void 		print_everything(t_wolf *w)
{
	ft_putstr("ANGLE ");
	ft_putnbr(w->angle);
	ft_putchar('\n');
	ft_putstr("VISION ");
	ft_putnbr(w->vision);
	ft_putchar('\n');
	ft_putstr("POSX ");
	ft_putnbr(w->pos_x);
	ft_putchar('\n');
	ft_putstr("POSY ");
	ft_putnbr(w->pos_y);
	ft_putchar('\n');
	ft_putstr("DIRX ");
	ft_putnbr(w->dir_x);
	ft_putchar('\n');
	ft_putstr("DIRY ");
	ft_putnbr(w->dir_y);
	ft_putchar('\n');
	ft_putstr("BEAM ");
	ft_putnbr(w->beam);
	ft_putchar('\n');
}

t_wolf 		*init_again(t_wolf *w)
{
	w->pos_x = 14;
	w->pos_y = 1;
	w->angle = 180;
	w->dir_x = -1;
	w->dir_y = 0;
	w->plane_x = 0;
	w->plane_y = 0.66;
	w->cam_x = 0;
	w->cam_y = 0;
	return (w);
}

int			key_hook(int keycode, t_wolf *w)
{
	if (keycode == 15)
		w = init_again(w);
	if (keycode == 40)
		w = architect_of_destruction(w);
	if (keycode == 34)
	{
		mlx_string_put(w->mlx, w->win, 350, 470, 0x000000, "PRESS R TO RESET");
		mlx_string_put(w->mlx, w->win, 350, 550, 0x000000, "PRESS K TO DESTROY EVERYTHING");
	}
	if (keycode == ESCAPE)
		exit_wolf(w, 0);
	else if (keycode == UP)
	{
		if (check_position(w, UP))
		{
			w->pos_x = w->pos_x + (cos((w->angle / 180) * M_PI) * 0.2);
			w->pos_y = w->pos_y + (sin((w->angle / 180) * M_PI) * 0.2);
		}
	}
	else if (keycode == DOWN)
	{
		if (check_position(w, DOWN))
		{
			w->pos_x = w->pos_x - (cos((w->angle / 180) * M_PI) * 0.2);
			w->pos_y = w->pos_y - (sin((w->angle / 180) * M_PI) * 0.2);
		}
	}
	else if (keycode == LEFT)
		w->angle = w->angle + 15;
	else if (keycode == RIGHT)
		w->angle = w->angle - 15;
	refresh(w, keycode);
	return (0);
}