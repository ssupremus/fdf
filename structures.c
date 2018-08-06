/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:55:13 by ysushkov          #+#    #+#             */
/*   Updated: 2018/06/04 13:37:14 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

void	strtoclrs(int *c, int x, char **arr)
{
	int i;

	i = 0;
	while (i < x)
	{
		c[i] = tablecolors(arr[i]);
		i++;
	}
}

void	strtoints(int *p, int x, char **arr)
{
	int i;

	i = 0;
	while (i < x)
	{
		format(arr[i]);
		p[i] = ft_atoi(arr[i]);
		i++;
	}
}

void	entrypoint(char *name, t_map *map)
{
	int		i;
	int		fd;
	char	*b;
	char	**arr;
	int		j;

	i = -1;
	fd = open(name, O_RDONLY);
	map->pos = (int **)malloc(sizeof(int *) * map->y);
	map->col = (int **)malloc(sizeof(int *) * (map->y));
	while (get_next_line(fd, &b) == 1 && ++i < map->y)
	{
		arr = ft_strsplit(b, 32);
		ft_strdel(&b);
		map->pos[i] = (int *)malloc(sizeof(int) * (map->x));
		strtoints(map->pos[i], map->x, arr);
		map->col[i] = (int *)malloc(sizeof(int) * (map->x));
		strtoclrs(map->col[i], map->x, arr);
		j = -1;
		while (j < map->x)
			ft_strdel(&arr[++j]);
		free(arr);
	}
	close(fd);
	build(map);
}

void	structures(char *name, int a, int n)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (map)
	{
		map->name = name;
		map->y = n;
		map->x = a;
		map->a = 0;
		map->b = 0;
		map->c = 0;
		if (map->x >= map->y)
			map->scale = 1200 / map->x * 0.6;
		else
			map->scale = 1200 / map->y * 0.6;
		map->startx = (2000 - (map->x * map->scale)) / 2;
		map->starty = (1200 - (map->y * map->scale)) / 2;
		map->mlx = 0;
		map->win = 0;
		map->height = 0;
		map->by = 5;
		map->s = 1;
		entrypoint(name, map);
	}
}
