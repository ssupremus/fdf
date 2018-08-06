/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 12:32:21 by ysushkov          #+#    #+#             */
/*   Updated: 2018/06/02 13:07:51 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

static int		is_format(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') ||
		(c >= 'a' && c <= 'f'))
		return (1);
	return (0);
}

void			format(char *str)
{
	int i;

	i = 0;
	while (str[i] != ',' && str[i] != 0)
	{
		if (i == 0 && str[i] != '-' && ft_isdigit(str[i]) == 0)
			ft_error();
		else if (i > 0 && ft_isdigit(str[i]) == 0)
			ft_error();
		i++;
	}
	if (str[i] == ',')
	{
		if (((int)ft_strlen(str) - i) > 9)
			ft_error();
		if (str[i + 1] != '0' || str[i + 2] != 'x')
			ft_error();
		i += 3;
		while (str[i] != 0)
		{
			if (is_format(str[i]) == 0)
				ft_error();
			i++;
		}
	}
}
