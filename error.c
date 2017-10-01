/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 04:18:37 by tbouline          #+#    #+#             */
/*   Updated: 2017/09/30 04:18:39 by tbouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	exit_wolf(t_wolf *w, int error)
{
	int		i;

	i = 0;
	if (error == 0)
		exit(error);
	if (error == 1)
		ft_putendl_fd("Usage: ./wolf3d [-r]", 2);
	if (error == 2)
		ft_putendl_fd("Rand() filled the map with obstacles. Universe hates you.", 2);
	if (w->mlx)
	{
		mlx_clear_window(w->mlx, w->win);
		mlx_destroy_window(w->mlx, w->win);
	}
	exit(error);
}