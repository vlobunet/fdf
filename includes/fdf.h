/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 19:57:44 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/08/15 19:57:46 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# define W			1280
# define H			720
# define BUFF_SIZE 	42

# define ULTH		89
# define U			91
# define URTH		92
# define LTH		86
# define RTH		88
# define RES		87
# define DLTH		83
# define D			84
# define DRTH		85

# define ZDFF		82
# define ZINN		78
# define ZOUT		69
# define MUP		126
# define MDOWN		125
# define MLTH		123
# define MRTH		124

# define ESC		53

# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"

typedef	struct		s_point
{
	double			x;
	double			y;
	double			z;
	long int		color;
}					t_point;

typedef	struct		s_map
{
	t_point			**map;
	int				x_th;
	int				y_th;
	int				z_th;
}					t_map;

typedef	struct		s_graf
{
	void			*mlx;
	void			*win;
	double			c[2];
	double			zoom;
	double			x;
	double			y;
	double			z;
	double			rad_x;
	double			rad_y;
	double			rad_z;
	t_map			*m;

}					t_graf;

char				**ft_freestrarr(char **arr);
int					get_next_line(const int fd, char **line);
t_map				*validation_map(char *file, char *line, char **arr);
unsigned int		get_color(char *str);
void				print_error(char *str);

int					key_hooks(int key, t_graf *tg);
void				keys_rotate(int key, t_graf *t);
void				keys_zum(int key, t_graf *t, t_point **m);
void				keys_move(int key, t_graf *t, t_point **m);
int					exit_fdf(void);

void				print_image(t_graf *t, int i, int j);
void				print_image(t_graf *t, int i, int j);
#endif
