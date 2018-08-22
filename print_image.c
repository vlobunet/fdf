/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 21:08:11 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/22 21:08:13 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	line(t_point d0, t_point d1, t_graf *tg)
{
	float	x;
	float	y;

	x = d0.x;
	y = d0.y;
	if (fabs(d1.y - d0.y) > fabs(d1.x - d0.x))
		while ((d0.y < d1.y) ? (y <= d1.y) : (y >= d1.y))
		{
			x = (((y - d0.y) / (d1.y - d0.y)) * (d1.x - d0.x) + d0.x);
			mlx_pixel_put(tg->mlx, tg->win, x, y, d0.color);
			(d0.y < d1.y) ? y++ : y--;
		}
	else
		while ((d0.x < d1.x) ? (x <= d1.x) : (x >= d1.x))
		{
			y = (((x - d0.x) / (d1.x - d0.x)) * (d1.y - d0.y) + d0.y);
			mlx_pixel_put(tg->mlx, tg->win, x, y, d0.color);
			(d0.x < d1.x) ? x++ : x--;
		}
}

void	print_param(t_graf *t)
{
	char *tmp;

	tmp = ft_itoa((int)t->x);
	mlx_string_put(t->mlx, t->win, 80, (H - 120), 0x62E200, tmp);
	ft_strdel(&tmp);
	tmp = ft_itoa((int)t->y);
	mlx_string_put(t->mlx, t->win, 80, (H - 100), 0x62E200, tmp);
	ft_strdel(&tmp);
	tmp = ft_itoa((int)t->zoom);
	mlx_string_put(t->mlx, t->win, 80, (H - 80), 0x62E200, tmp);
	ft_strdel(&tmp);
	tmp = ft_itoa((int)(t->rad_x * 57));
	mlx_string_put(t->mlx, t->win, 80, H - 60, 0x62E200, tmp);
	ft_strdel(&tmp);
	tmp = ft_itoa((int)(t->rad_y * 57));
	mlx_string_put(t->mlx, t->win, 80, H - 40, 0x62E200, tmp);
	ft_strdel(&tmp);
	tmp = ft_itoa((int)(t->rad_z * 57));
	mlx_string_put(t->mlx, t->win, 80, H - 20, 0x62E200, tmp);
	ft_strdel(&tmp);
}

void	print_info(t_graf *t)
{
	mlx_string_put(t->mlx, t->win, 5, 10, 0x62E200, "MOVE UP : UP");
	mlx_string_put(t->mlx, t->win, 5, 30, 0x62E200, "MOVE DOWN : DOWN");
	mlx_string_put(t->mlx, t->win, 5, 50, 0x62E200, "MOVE LEFT : LEFT");
	mlx_string_put(t->mlx, t->win, 5, 70, 0x62E200, "MOVE RIGHT : RIGHT");
	mlx_string_put(t->mlx, t->win, 5, 100, 0x62E200, "ROTATE IN X+ : NUM(8)");
	mlx_string_put(t->mlx, t->win, 5, 120, 0x62E200, "ROTATE IN X- : NUM(2)");
	mlx_string_put(t->mlx, t->win, 5, 140, 0x62E200, "ROTATE IN Y+ : NUM(4)");
	mlx_string_put(t->mlx, t->win, 5, 160, 0x62E200, "ROTATE IN Y- : NUM(6)");
	mlx_string_put(t->mlx, t->win, 5, 180, 0x62E200, "ROTATE IN Z+ : NUM(7)");
	mlx_string_put(t->mlx, t->win, 5, 200, 0x62E200, "ROTATE IN Z- : NUM(9)");
	mlx_string_put(t->mlx, t->win, 5, (H - 120), 0x62E200, "X     : ");
	mlx_string_put(t->mlx, t->win, 5, H - 100, 0x62E200, "y     : ");
	mlx_string_put(t->mlx, t->win, 5, H - 80, 0x62E200, "zoom  : ");
	mlx_string_put(t->mlx, t->win, 5, H - 60, 0x62E200, "rot_x : ");
	mlx_string_put(t->mlx, t->win, 5, H - 40, 0x62E200, "rot_y : ");
	mlx_string_put(t->mlx, t->win, 5, H - 20, 0x62E200, "rot_z : ");
	print_param(t);
}

void	print_image(t_graf *t, int i, int j)
{
	while (++j < t->m->y_th)
	{
		i = -1;
		while (++i < t->m->x_th)
		{
			j + 1 < t->m->y_th ?
			line(t->m->map[j][i], t->m->map[j + 1][i], t) : 0;
			i + 1 < t->m->x_th ?
			line(t->m->map[j][i], t->m->map[j][i + 1], t) : 0;
		}
	}
	print_info(t);
}
