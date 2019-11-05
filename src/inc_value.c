/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:07:02 by oelazzou          #+#    #+#             */
/*   Updated: 2019/11/05 21:28:09 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

void		increment_value(t_data *data)
{
	int i;
	int j;

	i = -1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	while (++i < data->hight)
	{
		j = -1;
		while (++j < data->width)
			data->p[i][j].value *= 2;
	}
	bonus_rotation(15, data);
}

void		change_color(t_data *data)
{
	int i;
	int j;

	i = -1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	while (++i < data->hight)
	{
		j = -1;
		while (++j < data->width)
			data->p[i][j].color += 0x000050;
	}
	ft_draw(data);
}
