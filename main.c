/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 15:34:49 by ysushkov          #+#    #+#             */
/*   Updated: 2018/06/04 15:27:54 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

void	ft_error(void)
{
	ft_putendl("Error");
	exit(1);
}

int		counter(char *b)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (b[i] != 0)
	{
		if (b[i] > 43 && b[i] < 121 && (b[i + 1] == 32 || b[i + 1] == 0))
			a++;
		i++;
	}
	return (a);
}

int		ft_processing(char *name)
{
	int		fd;
	int		i;
	int		a;
	char	*b;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		ft_error();
	i = 0;
	while (get_next_line(fd, &b) == 1)
	{
		if (i == 0)
			a = counter(b);
		if (i > 0 && counter(b) != a)
			ft_error();
		ft_strdel(&b);
		i++;
	}
	if (i == 0 || a == 0)
		ft_error();
	if (close(fd) == -1)
		ft_error();
	structures(name, a, i);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_processing(argv[1]);
	else
		ft_putendl("usage: ./fdf [file.fdf]");
	return (0);
}
