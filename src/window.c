
#include "fdf.h"

void	ft_line(int color, t_point p0, t_point p1, t_data *data)
{
	int err[2];
	int tab[4];

	tab[0] = abs(p1.x - p0.x);
	tab[2] = p0.x < p1.x ? 1 : -1;
	tab[1] = abs(p1.y - p0.y);
	tab[3] = p0.y < p1.y ? 1 : -1;
	err[0] = (tab[0] > tab[1] ? tab[0] : -tab[1]) / 2;
	while (1)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, p0.x, p0.y + 10, color);
		if (p0.x == p1.x && p0.y == p1.y)
			break ;
		err[1] = err[0];
		if (err[1] > -tab[0])
		{
			err[0] -= tab[1];
			p0.x += tab[2];
		}
		if (err[1] < tab[1])
		{
			err[0] += tab[0];
			p0.y += tab[3];
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
