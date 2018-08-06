/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tablecolors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:21:59 by ysushkov          #+#    #+#             */
/*   Updated: 2018/06/04 11:33:11 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

int		ft_atoi2(const char *str)
{
	unsigned int	i;
	long long		total;

	i = 0;
	total = 0;
	while (str[i] != 'x')
		i++;
	i++;
	while (str[i] != 0)
	{
		if (str[i] >= '0' && str[i] <= '9')
			total = total * 16 + (str[i] - '0');
		else if (str[i] >= 'A' && str[i] <= 'F')
			total = total * 16 + (str[i] - '7');
		else if (str[i] >= 'a' && str[i] <= 'f')
			total = total * 16 + (str[i] - 'W');
		i++;
	}
	return ((int)total);
}

int		tablecolors(char *str)
{
	int i;
	int res;

	i = 0;
	while (str[i] != ',' && str[i] != 0)
		i++;
	if (str[i] == 0)
		res = 16777215;
	else
		res = ft_atoi2(str);
	return (res);
}
