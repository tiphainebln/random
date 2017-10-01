#ifndef WOLF_H
# define WOLF_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"

# define WIN_X 800
# define WIN_Y 600
# define X_CENTER WIN_X/2
# define Y_CENTER WIN_Y/2
# define ARGUMENT 1
# define ERROR 2
# define MALLOC_ERROR 3

# define ESCAPE 53
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126

typedef struct		s_wolf
{
	int 			flag;
	int 			random;
	int 			seed;
	void			*mlx;
	void			*win;
	int 			*data;
	void			*img;
	int				bpp;
	int				size_line;
	int				endian;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			cam_x;
	double			cam_y;
	double			ray_posx;
	double			ray_posy;
	double			ray_dirx;
	double			ray_diry;
	double			frame;
	double			oldframe;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			ray_length;
	int 			x;
	int 			y;
	int 			map_x;
	int 			map_y;
	int 			step_x;
	int 			step_y;
	int 			hit;
	int 			side;
	int				map[15][15];
	double 			angle;
	double 			beam;
	double 			vision;
}					t_wolf;

t_wolf				init(t_wolf w);
t_wolf 				wolf_map(t_wolf w);
t_wolf 				wolf_map_rand(t_wolf w);
int					key_hook(int keycode, t_wolf *w);
void 				exit_wolf(t_wolf *w, int error);
void 				draw_loop(t_wolf *w);
t_wolf 				*architect_of_destruction(t_wolf *w);

#endif