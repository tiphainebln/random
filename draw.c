/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 04:15:39 by tbouline          #+#    #+#             */
/*   Updated: 2017/09/30 04:15:42 by tbouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void  backdrop(t_wolf *w)
{
  int i;

  i = 0;
  while (i < (w->size_line * WIN_Y / 2))
  {
    w->data[i / 4] = 0xA1FFFF - ((i * 2.2) / 10000);
    i++;
  }
  while (i < (w->size_line * WIN_Y))
  {
    w->data[i / 4] = 0x664F47 + ((i * 0.01) / 10000);
    i++;
  }
}

void  bottom_nightmares(t_wolf *w, int step, int color)
{
  int   h;
  int   y;
  int   c;
  int   i;
  int   z;

  h = (WIN_Y / (2 * w->beam));
  y = ((WIN_Y / 2) * w->size_line) + (step * w->bpp / 8);
  i = 0;
  while (i < h)
  {
    c = 0;
    while (c < (w->bpp / 8))
    {
      z = y + (i * w->size_line);
      if (c % 2)
        w->data[(c + z) / 4] = color;
      else
        w->data[(c + z) / 4] = color / 2;
      c++;
    }
    i++;
  }
}

void  high_end(t_wolf *w, int step, int color)
{
  int i;
  int h;
  int c;
  int y;
  int z;

  h = (WIN_Y / (2 * w->beam));
  y = ((WIN_Y / 2) * w->size_line) + (step * w->bpp / 8);
  i = 0;
  while (i < h)
  {
    c = 0;
    while (c < (w->bpp / 8))
    {
      z = y - (i * w->size_line);
      if (c % 2)
        w->data[(c + z) / 4] = color;
      else
        w->data[(c + z) / 4] = color / 2;
      c++;
    }
    i++;
  }
  bottom_nightmares(w, step, color);
}

double   shine(t_wolf *w, double dir_x, double dir_y, int *color)
{
  int   x;
  int   y;
  double beam;

  beam = 1;
  x = w->pos_x + (beam * (dir_x - w->pos_x));
  y = w->pos_y + (beam * (dir_y - w->pos_y));
  while (w->map[x][y] == 0)
  {
    x = w->pos_x + (beam * (dir_x - w->pos_x));
    y = w->pos_y + (beam * (dir_y - w->pos_y));
    beam += 0.001;
  }
  *color = rand() - w->angle * 10;
  return (beam);
}

void    draw_loop(t_wolf *w)
{
  double  i;
  int     color;

  backdrop(w);
  w->vision = ((w->angle / 180) * M_PI);
  i = 0;
  color = 0;
  while (i <= WIN_X)
  {
    w->dir_y = (WIN_X / 2 - i) / WIN_X;
    w->dir_x = cos(w->vision) - (w->dir_y * sin(w->vision)) + w->pos_x;
    w->dir_y = sin(w->vision) + (w->dir_y * cos(w->vision)) + w->pos_y;
    w->beam = shine(w, w->dir_x, w->dir_y, &color);
    high_end(w, i++, color);
  }
  mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
}