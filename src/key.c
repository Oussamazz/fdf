
#include "fdf.h"

int		key_press(int key, void *param)
{
	t_data *data;

	data = (t_data *)param;
	if (key == 126)
		down(param);
	else if (key == 125)
		up(param);
	else if (key == 123 || key == 124)
		right_left(key, param);
	else if (key == 53)
		exit(0);
	else if (key == 24)
		increment_value(param);
	else if (key == 8)
		change_color(param);
	else if (key == 46)
		menu_(param);
	else if (key == 15 || key == 17)
		bonus_rotation(key, param);
	return (0);
}

void	up(t_data *data)
{
	int i;
	int j;

	i = -1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	while (++i < data->hight)
	{
		j = -1;
		while (++j < data->width)
			data->p[i][j].y = data->p[i][j].y + 10;
	}
	ft_draw(data);
}

void	down(t_data *data)
{
	int i;
	int j;

	i = -1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	while (++i < data->hight)
	{
		j = -1;
		while (++j < data->width)
			data->p[i][j].y = data->p[i][j].y - 10;
	}
	ft_draw(data);
}

void	right_left(int key, t_data *data)
{
	int j;
	int i;

	i = -1;
	if (key == 124)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		while (++i <= data->hight - 1)
		{
			j = -1;
			while (++j < data->width)
				data->p[i][j].x = data->p[i][j].x + 10;
		}
	}
	if (key == 123)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		while (++i <= data->hight - 1)
		{
			j = -1;
			while (++j < data->width)
				data->p[i][j].x = data->p[i][j].x - 10;
		}
	}
	ft_draw(data);
}

void	bonus_rotation(int key, t_data *data)
{
	t_data *tmp;

	tmp = data;
	if (key == 15)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		rotate(data);
		ft_draw(data);
	}
	if (key == 17)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		ft_check(data->v, tmp);
		ft_draw(tmp);
	}
}
