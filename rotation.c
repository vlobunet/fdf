/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 21:07:58 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/22 21:08:00 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	rotation_x(float n, t_map *m, t_graf *t)
{
	int		x;
	int		y;
	double	tmp;

	y = -1;
	while (++y < m->y_th)
	{
		x = -1;
		while (++x < m->x_th)
		{
			tmp = m->map[y][x].y - (H / 2);
			m->map[y][x].y =
				tmp * cos(n) + m->map[y][x].z * sin(n) + (H / 2);
			m->map[y][x].z = -(tmp * sin(n)) + m->map[y][x].z * cos(n);
		}
	}
	t->rad_x = t->rad_x + n;
}

void	rotation_y(float n, t_map *m, t_graf *t)
{
	int		i;
	int		j;
	double	tmp;

	j = -1;
	while (++j < m->y_th)
	{
		i = -1;
		while (++i < m->x_th)
		{
			tmp = m->map[j][i].x - (W / 2);
			m->map[j][i].x =
				tmp * cos(n) - m->map[j][i].z * sin(n) + (W / 2);
			m->map[j][i].z = tmp * sin(n) + m->map[j][i].z * cos(n);
		}
	}
	t->rad_y = t->rad_y + n;
}

void	rotation_z(float n, t_map *m, t_graf *t)
{
	int		i;
	int		j;
	double	tmp_x;
	double	tmp_y;

	j = -1;
	while (++j < m->y_th)
	{
		i = -1;
		while (++i < m->x_th)
		{
			tmp_x = m->map[j][i].x - (W / 2);
			tmp_y = m->map[j][i].y - (H / 2);
			m->map[j][i].x = tmp_x * cos(n) + tmp_y * sin(n) + (W / 2);
			m->map[j][i].y = -(tmp_x * sin(n)) + tmp_y * cos(n) + (H / 2);
		}
	}
	t->rad_z = t->rad_z + n;
}

void	keys_rotate(int key, t_graf *t)
{
	if (key == D)
		rotation_x(0.1, t->m, t);
	else if (key == U)
		rotation_x(-0.1, t->m, t);
	if (key == LTH)
		rotation_y(0.1, t->m, t);
	else if (key == RTH)
		rotation_y(-0.1, t->m, t);
	if (key == ULTH)
		rotation_z(0.1, t->m, t);
	else if (key == URTH)
		rotation_z(-0.1, t->m, t);
}
