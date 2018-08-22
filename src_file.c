/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 21:07:33 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/22 21:07:35 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	print_error(char *str)
{
	ft_putstr_fd("\033[01;38;05;226mError : \033[01;38;05;196m", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\033[01m\n", 1);
	exit(1);
}

char	**ft_freestrarr(char **arr)
{
	int	i;

	if (arr == NULL)
		return (NULL);
	i = -1;
	while (arr[++i])
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
	arr = NULL;
	return (NULL);
}
