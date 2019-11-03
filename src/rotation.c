/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 00:06:58 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/11/02 22:58:23 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	iso(int *x, int *y, int z)
{
	int			previous_x;
	int			previous_y;
	double		angel;
	
	previous_x = *x;
	previous_y = *y;
	angel = 0.523599;
	*x = (previous_x - previous_y) * cos(angel);
	*y = ((previous_x + previous_y) * sin(angel)) - z;
}

void			rotate(t_data *data)
{
	int			i;
	int			j;

	i = -1;
	while (++i <= data->hight - 1)
	{
		j = -1;
		while (++j < data->width)
			iso(&data->p[i][j].x, &data->p[i][j].y, data->p[i][j].value);
	}
}

void			ft_zoom(t_data *data, char **tab)
{
	int x;

	x = ft_count_tab(tab);
	if (x > 200)
		data->zoom = 2;
	else if (x <= 200 && x > 50)
		data->zoom = 4;
	else if (x >= 27 && x <= 50)
		data->zoom = 8;
	else
		data->zoom = 35;
}
