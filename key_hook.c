/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 21:07:05 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/22 21:07:09 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		exit_fdf(void)
{
	exit(0);
}

void	keys_move(int key, t_graf *t, t_point **m)
{
	int i;
	int j;

	j = -1;
	while (++j < t->m->y_th)
	{
		i = -1;
		while (++i < t->m->x_th)
		{
			key == MDOWN ? m[j][i].y += 10 : 0;
			key == MUP ? m[j][i].y -= 10 : 0;
			key == MLTH ? m[j][i].x -= 10 : 0;
			key == MRTH ? m[j][i].x += 10 : 0;
		}
	}
	key == MUP ? t->c[0] += 10 : 0;
	key == MDOWN ? t->c[0] -= 10 : 0;
	key == MLTH ? t->c[1] -= 10 : 0;
	key == MRTH ? t->c[1] += 10 : 0;
	key == MUP ? t->y += 10 : 0;
	key == MDOWN ? t->y -= 10 : 0;
	key == MLTH ? t->x -= 10 : 0;
	key == MRTH ? t->x += 10 : 0;
}

void	keys_zum(int key, t_graf *t, t_point **m)
{
	int i;
	int j;

	j = -1;
	while (++j < t->m->y_th)
	{
		i = -1;
		while (++i < t->m->x_th)
		{
			key == ZOUT ? m[j][i].x = (m[j][i].x - W / 2) * 1.3 + W / 2 : 0;
			key == ZOUT ? m[j][i].y = (m[j][i].y - H / 2) * 1.3 + H / 2 : 0;
			key == ZOUT ? m[j][i].z = m[j][i].z * 1.3 : 0;
			key == ZINN ? m[j][i].x = (m[j][i].x - W / 2) / 1.3 + W / 2 : 0;
			key == ZINN ? m[j][i].y = (m[j][i].y - H / 2) / 1.3 + H / 2 : 0;
			key == ZINN ? m[j][i].z = m[j][i].z / 1.3 : 0;
		}
	}
	t->zoom = (key == ZOUT ? t->zoom + 1 : t->zoom - 1);
}
