/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:20:15 by ysushkov          #+#    #+#             */
/*   Updated: 2018/07/23 20:48:45 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		colors(int q)
{
	int		c;

	c = 0;
	if (q == 0)
		c = 0x800080;
	else if (q == 1)
		c = 0xD2F700;
	else if (q == 2)
		c = 0xFF00FF;
	else if (q == 3)
		c = 0x00FF00;
	else if (q == 4)
		c = 0x7FFFD4;
	else if (q == 5)
		c = 0xFF0000;
	else if (q == 6)
		c = 0x00FFFF;
	else if (q == 7)
		c = 0xFF4500;
	else if (q == 8)
		c = 0xFFFF00;
	return (c);
}

void	happy_colors(t_map *map, int key)
{
	static int	q = 0;
	int			y;
	int			x;
	int			color;

	y = -1;
	if (key == 49)
	{
		if (q == 9)
			q = 0;
		color = colors(q);
		while (++y < map->y)
		{
			x = -1;
			while (++x < map->x)
			{
				map->col[y][x] = color;
			}
		}
		q++;
	}
	else if (key == 35)
		physics(map);
}

void	physics(t_map *map)
{
	int y;
	int x;

	y = -1;
	while (++y < map->y)
	{
		x = -1;
		while (++x < map->x)
		{
			if (map->pos[y][x] < 30)
				map->col[y][x] = 0x0000FF;
			if (map->pos[y][x] >= 30 && map->pos[y][x] <= 0)
				map->col[y][x] = 0x0000FF;
			if (map->pos[y][x] > 0 && map->pos[y][x] <= 5)
				map->col[y][x] = 0xFFFACD;
			if (map->pos[y][x] > 5 && map->pos[y][x] < 35)
				map->col[y][x] = 0x228B22;
			if (map->pos[y][x] >= 35 && map->pos[y][x] < 50)
				map->col[y][x] = 0x800000;
			if (map->pos[y][x] >= 50)
				map->col[y][x] = 0xFFE4E1;
		}
	}
}

void	key_enlarge(int key, t_map *param)
{
	if (key == 13 && param->scale < 10000)
	{
		param->scale++;
		param->startx -= (param->x / 2);
		param->starty -= (param->y / 2);
	}
	if (key == 1 && param->scale > 1)
	{
		param->scale--;
		param->startx = param->startx + (param->x / 2);
		param->starty = param->starty + (param->y / 2);
	}
	if (key == 24)
		param->height += 2;
	if (key == 27)
		param->height -= 2;
	if (key == 126)
		param->starty -= 20;
	if (key == 125)
		param->starty += 20;
	if (key == 123 || key == 0)
		param->startx -= 20;
	if (key == 124 || key == 2)
		param->startx += 20;
}

int		deal_key(int key, t_map *param)
{
	if (key == 53 || key == 36)
	{
		param = NULL;
		exit(1);
		return (0);
	}
	else if (key == 17)
		param->a = param->a + 0.1;
	else if (key == 5)
		param->a = param->a - 0.1;
	else if (key == 16)
		param->b = param->b + 0.1;
	else if (key == 4)
		param->b = param->b - 0.1;
	else if (key == 32 || key == 14)
		param->c = param->c + 0.1;
	else if (key == 38 || key == 12)
		param->c = param->c - 0.1;
	else if (key == 35 || key == 49)
		happy_colors(param, key);
	else
		key_enlarge(key, param);
	ft_memset(param->addr, 0, ((2000 * 1200) * 4));
	build2(param);
	return (0);
}
