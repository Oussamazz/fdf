/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:09:51 by oelazzou          #+#    #+#             */
/*   Updated: 2019/11/05 13:28:34 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_line(int color, t_point p0, t_point p1, t_data *data)
{
	t_bres point;

	point.dx = abs(p1.x - p0.x);
	point.dy = -abs(p1.y - p0.y);
	point.sx = p0.x < p1.x ? 1 : -1;
	point.sy = p0.y < p1.y ? 1 : -1;
	point.err = point.dx + point.dy;
	while (1)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, p0.x, p0.y, color);
		if (p0.x == p1.x && p0.y == p1.y)
			break ;
		point.err2 = point.err * 2;
		if (point.err2 >= point.dy)
		{
			point.err = point.err + point.dy;
			p0.x += point.sx;
		}
		if (point.err2 <= point.dx)
		{
			point.err += point.dx;
			p0.y += point.sy;
		}
	} 
}

void	ft_draw(t_data *data)
{
	int	j;
	int	i;

	i = -1;
	while (++i < data->hight)
	{
		j = -1;
		while (++j < data->width)
		{
			if (j + 1 < data->width)
				ft_line(data->p[i][j].color, data->p[i][j],
						data->p[i][j + 1], data);
			if (i + 1 < data->hight)
				ft_line(data->p[i][j].color, data->p[i][j],
						data->p[i + 1][j], data);
		}
	}
}
