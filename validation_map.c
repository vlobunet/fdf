/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 21:08:25 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/22 21:08:27 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_map	*map_init(void)
{
	t_map *map;

	map = (t_map *)malloc(sizeof(t_map));
	!map ? print_error("Not enough memory") : 0;
	map->x_th = 0;
	map->y_th = 0;
	map->z_th = 0;
	map->map = NULL;
	return (map);
}

char	**check_line(char *line, t_map *map, char **point)
{
	int i;
	int j;

	i = -1;
	point = ft_strsplit(line, 32);
	while (point[++i])
	{
		j = -1;
		while (point[i][++j])
			if (ft_isdigit(point[i][j]) || point[i][j] == ' ' ||
			point[i][j] == ',' || (point[i][j] >= 'A' && point[i][j] <= 'F') ||
			(point[i][j] >= 'a' && point[i][j] <= 'f') || point[i][j] == '-' ||
			point[i][j] == 'x')
				;
			else
				print_error("Maps : Invalid character");
	}
	if (map->x_th != 0 && i != map->x_th)
		print_error("Maps : Invalid line size");
	map->x_th = i;
	map->y_th++;
	ft_strdel(&line);
	return (point);
}

void	add_line_map(char **arr, t_map *map)
{
	t_point		**point;
	t_point		*new_line;
	int			i;
	int			k;

	i = -1;
	k = -1;
	point = (t_point **)ft_memalloc(sizeof(t_point *) * map->y_th);
	while (++i != map->y_th - 1)
		point[i] = map->map[i];
	free(map->map);
	map->map = NULL;
	new_line = (t_point *)malloc(sizeof(t_point) * map->x_th);
	while (arr[++k])
	{
		new_line[k].x = k;
		new_line[k].y = i;
		new_line[k].z = (float)ft_atoi(arr[k]);
		map->z_th = (map->z_th < new_line[k].z ? new_line[k].z : map->z_th);
		new_line[k].color = (ft_strchr(arr[k], ',') ?
		get_color(ft_strchr(arr[k], ',') + 3) : (get_color("FFFFFF")));
	}
	point[i] = new_line;
	map->map = point;
}

t_map	*validation_map(char *file, char *line, char **arr)
{
	int		fd;
	t_map	*map;
	int		ret;

	if ((fd = open(file, O_RDONLY)) < 0)
		print_error("File is not opening");
	map = map_init();
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		arr = check_line(line, map, NULL);
		add_line_map(arr, map);
		ft_freestrarr(arr);
	}
	ret == -1 ? print_error("File is not reading") : 0;
	close(fd);
	ft_strdel(&line);
	return (map);
}
