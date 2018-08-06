/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:12:05 by ysushkov          #+#    #+#             */
/*   Updated: 2018/06/04 11:18:16 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	lenmin(t_draw g, t_bras b, int c, t_map *map)
{
	b.x = g.x1;
	b.y = g.y1;
	b.d = -1 * b.lengthx;
	b.length++;
	while (b.length--)
	{
		ft_images(map, b.x, b.y, c);
		b.x += b.dx;
		b.d += 2 * b.lengthy;
		if (b.d > 0)
		{
			b.d -= 2 * b.lengthx;
			b.y += b.dy;
		}
	}
}

void	lenpl(t_draw g, t_bras b, int c, t_map *map)
{
	b.x = g.x1;
	b.y = g.y1;
	b.d = -1 * b.lengthy;
	b.length++;
	while (b.length--)
	{
		ft_images(map, b.x, b.y, c);
		b.y += b.dy;
		b.d += 2 * b.lengthx;
		if (b.d > 0)
		{
			b.d -= 2 * b.lengthy;
			b.x += b.dx;
		}
	}
}

void	ft_images(t_map *map, int x, int y, int c)
{
	if (x >= 0 && y >= 0 && x < 2000 && y < 1200)
		*(int *)(map->addr + ((x + y * 2000) * 4)) = c;
}

void	drawning(t_map *map, t_draw g, t_draw h, int c)
{
	t_bras b;

	b.dx = (h.x1 - g.x1 >= 0 ? 1 : -1);
	b.dy = (h.y1 - g.y1 >= 0 ? 1 : -1);
	b.lengthx = abs(h.x1 - g.x1);
	b.lengthy = abs(h.y1 - g.y1);
	b.length = ft_max(b.lengthx, b.lengthy);
	b.x = 0;
	b.y = 0;
	b.d = 0;
	if (b.length == 0)
		ft_images(map, g.x1, g.y1, c);
	if (b.lengthy <= b.lengthx)
		lenmin(g, b, c, map);
	else
		lenpl(g, b, c, map);
}

t_draw	ft_flash(t_map *map, int y, int x)
{
	t_flash		f;
	int			z;
	t_draw		g;

	z = map->pos[y][x];
	if (z != 0)
		z = z + map->height;
	f.x0 = map->x / 2;
	f.y0 = map->y / 2;
	f.z0 = z / 2;
	f.x1 = x;
	f.y1 = f.y0 + (y - f.y0) * cos(map->a) + (f.z0 - z) * sin(map->a);
	f.z1 = f.z0 + (y - f.y0) * sin(map->a) + (z - f.z0) * cos(map->a);
	f.x2 = f.x0 + (f.x1 - f.x0) * cos(map->b) + (f.z1 - f.z0) * sin(map->b);
	f.y2 = f.y1;
	f.z2 = f.z0 + (f.x0 - f.x1) * sin(map->b) + (f.z1 - f.z0) * cos(map->b);
	f.x3 = f.x0 + (f.x2 - f.x0) * cos(map->c) + (f.y0 - f.y2) * sin(map->c);
	f.y3 = f.y0 + (f.x2 - f.x0) * sin(map->c) + (f.y2 - f.y0) * cos(map->c);
	f.z3 = f.z2;
	g.x1 = f.x3 * map->scale + map->startx;
	g.y1 = f.y3 * map->scale + map->starty;
	return (g);
}
