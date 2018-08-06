/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 16:59:29 by ysushkov          #+#    #+#             */
/*   Updated: 2018/06/04 16:33:49 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

int		exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

int		ft_max(int a, int b)
{
	int max;

	if (a >= b)
		max = a;
	else
		max = b;
	return (max);
}

void	ft_printer(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
	mlx_string_put(map->mlx, map->win, 1750, 20, 0xFFFFFF, "Controls");
	mlx_string_put(map->mlx, map->win, 1750, 40, 0xFFFFFF,
				"[W] - Zoom In");
	mlx_string_put(map->mlx, map->win, 1750, 60, 0xFFFFFF, "[S] - Zoom Out");
	mlx_string_put(map->mlx, map->win, 1750, 80, 0xFFFFFF, "[A] - Left");
	mlx_string_put(map->mlx, map->win, 1750, 100, 0xFFFFFF, "[D] - Right");
	mlx_string_put(map->mlx, map->win, 1750, 120, 0xFFFFFF, "[T][G] - x-axis");
	mlx_string_put(map->mlx, map->win, 1750, 140, 0xFFFFFF, "[Y][H] - y-axis");
	mlx_string_put(map->mlx, map->win, 1750, 160, 0xFFFFFF, "[U][J] - z-axis");
	mlx_string_put(map->mlx, map->win, 1750, 180, 0xFFFFFF,
				"[+][-] - Change Height");
	mlx_string_put(map->mlx, map->win, 1750, 200, 0xFFFFFF, "[Up] - Move Up");
	mlx_string_put(map->mlx, map->win, 1750, 220, 0xFFFFFF,
				"[Down] - Move Down");
	mlx_string_put(map->mlx, map->win, 1750, 240, 0xFFFFFF,
				"[Space] - Change Colors");
	mlx_string_put(map->mlx, map->win, 1750, 260, 0xFFFFFF,
				"[P] - Physic Map");
}

void	build2(t_map *map)
{
	int		y;
	int		x;
	t_draw	g[2];

	y = -1;
	while (++y < map->y)
	{
		x = -1;
		while (++x < map->x)
		{
			g[0] = ft_flash(map, y, x);
			if (x < map->x - 1)
				g[1] = ft_flash(map, y, x + 1);
			else if (x == map->x - 1)
				g[1] = ft_flash(map, y, x);
			drawning(map, g[0], g[1], map->col[y][x]);
			if (y < map->y - 1)
				g[1] = ft_flash(map, y + 1, x);
			else if (y == map->y - 1)
				g[1] = ft_flash(map, y, x);
			drawning(map, g[0], g[1], map->col[y][x]);
		}
	}
	ft_printer(map);
	mlx_loop(map->mlx);
}

void	build(t_map *map)
{
	int		end;

	end = 2000 * 1200;
	ft_putendl("Press ESC to escape");
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, 2000, 1200, map->name);
	map->img = mlx_new_image(map->mlx, 2000, 1200);
	map->addr = mlx_get_data_addr(map->img, &map->by, &map->s, &end);
	mlx_hook(map->win, 2, 5, deal_key, map);
	mlx_hook(map->win, 17, 1L << 17, exit_x, 0);
	build2(map);
}
