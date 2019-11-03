/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:51:47 by oelazzou          #+#    #+#             */
/*   Updated: 2019/11/02 23:23:23 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# define H		1900
# define V		1200

typedef struct	s_point
{
	int			x;
	int			y;
	int			value;
	int			color;
}				t_point;

typedef struct	s_data
{
	void		*win_ptr;
	void		*mlx_ptr;
	int			width;
	int			hight;
	int			zoom;
	char		*v;
	t_point		**p;
}				t_data;

void			bonus_rotation(int key, t_data *data);
void			ft_check(char *nom, t_data *data);
void			ft_draw(t_data	*data);
void			ft_line(int color, t_point p0, t_point p1, t_data *data);
void			ft_zoom(t_data *data, char **tab);
void			ft_check_line(char *line);
void			rotate(t_data *data);
int				key_press(int key, void *param);
void			right_left(int key, t_data *data);
void			up(t_data *data);
void			down(t_data *data);
void			free_twod(char  **arr);
void			ft_error(char *name);
#endif
