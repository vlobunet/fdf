/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 21:07:45 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/22 21:07:48 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	set_image(t_graf t, double s, int i, int j)
{
	if (t.m->x_th >= t.m->y_th)
		s = ((((W - 10) / t.m->x_th) * t.m->y_th) < H ?
			((W - 10) / t.m->x_th) : ((H - 10) / t.m->y_th));
	else
		s = ((((H - 10) / t.m->y_th) * t.m->x_th) < W ?
			((W - 10) / t.m->y_th) : ((W - 10) / t.m->x_th));
	t.c[0] = W / 2;
	t.c[1] = H / 2;
	while (++j < t.m->y_th)
	{
		i = -1;
		while (++i < t.m->x_th)
		{
			t.m->map[j][i].x = (t.m->map[j][i].x - (t.m->x_th - 1) / 2) * \
			s + t.c[0];
			t.m->map[j][i].y = (t.m->map[j][i].y - (t.m->y_th - 1) / 2) * \
			s + t.c[1];
			t.m->map[j][i].z = t.m->map[j][i].z * s;
		}
	}
}

void	reset_image(t_graf *t)
{
	while (t->x != 0)
		t->x > 0 ? keys_move(MLTH, t, t->m->map) : \
	keys_move(MRTH, t, t->m->map);
	while (t->y != 0)
		t->y > 0 ? keys_move(MDOWN, t, t->m->map) : \
	keys_move(MUP, t, t->m->map);
	while (t->zoom != 0)
		t->zoom > 0 ? keys_zum(ZINN, t, t->m->map) : \
	keys_zum(ZOUT, t, t->m->map);
	while (t->rad_x != 0)
		t->rad_x > 0 ? keys_rotate(U, t) : keys_rotate(D, t);
	while (t->rad_y != 0)
		t->rad_y > 0 ? keys_rotate(RTH, t) : keys_rotate(LTH, t);
	while (t->rad_z != 0)
		t->rad_z > 0 ? keys_rotate(URTH, t) : keys_rotate(ULTH, t);
}

int		key_hooks(int key, t_graf *tg)
{
	if (key == ESC)
		exit_fdf();
	else if (key == ULTH || key == U || key == URTH ||
		key == LTH || key == RTH ||
		key == DLTH || key == D || key == DRTH)
		keys_rotate(key, tg);
	else if (key == MUP || key == MDOWN || key == MLTH ||
		key == MRTH)
		keys_move(key, tg, tg->m->map);
	else if (key == ZDFF || key == ZINN || key == ZOUT)
		keys_zum(key, tg, tg->m->map);
	else if (key == RES)
		reset_image(tg);
	mlx_clear_window(tg->mlx, tg->win);
	print_image(tg, -1, -1);
	return (0);
}

void	init_variables(t_graf *t)
{
	t->rad_z = 0;
	t->rad_y = 0;
	t->rad_z = 0;
	t->x = 0;
	t->y = 0;
	t->z = 0;
	t->zoom = 0;
}

int		main(int argc, char **argv)
{
	t_graf	tg;

	argc != 2 ? print_error("Invalid number of attributes!") : 0;
	tg.m = validation_map(argv[1], NULL, NULL);
	tg.mlx = mlx_init();
	tg.win = mlx_new_window(tg.mlx, W, H, "FDF");
	init_variables(&tg);
	set_image(tg, 0, -1, -1);
	print_image(&tg, -1, -1);
	mlx_hook(tg.win, 2, 1L << 1, key_hooks, &tg);
	mlx_loop(tg.mlx);
	return (0);
}
