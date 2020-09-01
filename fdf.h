/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 15:37:46 by ysushkov          #+#    #+#             */
/*   Updated: 2018/08/06 12:02:18 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# ifdef __APPLE__
#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_A 0
#  define KEY_D 2
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 125
#  define KEY_ENTER 36
#  define KEY_SPACE 49
# define KEY_T 17
# define KEY_G 5
# define KEY_Y 16
# define KEY_H 4
# define KEY_U 32
# define KEY_J 38
# define KEY_P 35
# define KEY_MINUS 27
# define KEY_PLUS 24
# elif __linux__
#  define KEY_ESC 65307
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_ENTER 65293
#  define KEY_SPACE 32
# define KEY_T 116
# define KEY_G 103
# define KEY_Y 121
# define KEY_H 104
# define KEY_U 117
# define KEY_J 106
# define KEY_P 112
# define KEY_MINUS 45
# define KEY_PLUS 61
# endif

typedef struct	s_map
{
	char		*name;
	int			**pos;
	int			**col;
	int			y;
	int			x;
	double		a;
	double		b;
	double		c;
	int			scale;
	int			startx;
	int			starty;
	void		*mlx;
	void		*win;
	int			height;
	int			by;
	int			s;
	void		*img;
	char		*addr;
}				t_map;

typedef struct	s_bras
{
	int			dx;
	int			dy;
	int			lengthx;
	int			lengthy;
	int			length;
	int			x;
	int			y;
	int			d;
}				t_bras;

typedef struct	s_draw
{
	int			x1;
	int			y1;
}				t_draw;

typedef struct	s_flash
{
	double	x0;
	double	y0;
	double	z0;
	double	x1;
	double	y1;
	double	z1;
	double	x2;
	double	y2;
	double	z2;
	double	x3;
	double	y3;
	double	z3;
}				t_flash;

void			physics(t_map *map);
int				deal_key(int key, t_map *param);
int				ft_max(int a, int b);
void			drawning(t_map *map, t_draw g, t_draw h, int c);
t_draw			ft_flash(t_map *map, int y, int x);
void			ft_images(t_map *map, int x, int y, int c);
int				tablecolors(char *str);
void			format(char *str);
void			build2(t_map *map);
void			build(t_map *map);
void			structures(char *name, int a, int n);
void			ft_error();
int				counter(char *b);
int				ft_processing(char *name);

#endif
