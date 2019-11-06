/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberrich <sberrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 00:06:58 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/11/07 00:27:52 by sberrich         ###   ########.fr       */
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
	angel = 0.5;
	*x = (previous_x - previous_y) * cos(angel);
	*y = ((previous_x + previous_y) * sin(angel)) - z;
		

}

void			rotate(t_data *data)
{
	int			i;
	int			j;

	i = -1;
	while (++i < data->hight)
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
	data->zoom = 500 / x;
}
