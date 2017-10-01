/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 04:20:27 by tbouline          #+#    #+#             */
/*   Updated: 2017/09/30 04:20:29 by tbouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_wolf		random_start(t_wolf w)
{
	int 	a;
	int 	b;

	a = 1;
	b = 1;
	while (a < 14)
	{
		b = 1;
		while (b < 14)
		{
			if (w.map[a][b] == 0)
			{
				w.pos_x = a;
				w.pos_y = b;
				return (w);
			}
			b++;
		}
		a++;
	}
	exit_wolf(&w, 2);
	return (w);
}

t_wolf		init(t_wolf w)
{
	if (w.random)
		w = random_start(w);
	else
	{
		w.pos_x = 14;
		w.pos_y = 1;
	}
	w.angle = 180;
	w.dir_x = -1;  //initial direction vector
	w.dir_y = 0;
	w.plane_x = 0; //the 2d raycaster version of camera plane
	w.plane_y = 0.66;
	w.cam_x = 0;
	w.cam_y = 0;
	return (w);
}