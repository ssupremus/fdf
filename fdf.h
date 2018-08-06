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
