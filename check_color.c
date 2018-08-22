/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 21:05:40 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/22 21:05:42 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int				ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

unsigned int	get_color(char *str)
{
	int				i;
	int				j;
	unsigned int	num;
	const char		*arr = "0123456789ABCDEF";

	i = 0;
	num = 0;
	j = -1;
	while (str[i] != ' ' && str[i] != '\0')
	{
		while (arr[++j] != '\0')
		{
			if (ft_toupper(str[i]) == arr[j])
			{
				num = num * 16 + j;
				j = -1;
				break ;
			}
		}
		i++;
	}
	return (num);
}
