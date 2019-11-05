/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 21:57:02 by oelazzou          #+#    #+#             */
/*   Updated: 2019/11/05 23:40:42 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	show_menu(t_data *data)
{
	print_pipes(data, 17, 345, 715);
	print_pipes(data, 17, 345, 10);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20,10,0xFF0000, "---------------------------------MENU---------------------------------");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20,50,0x7CD80F, "-> To Change Colors Press [C] Key.");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20,100,0x7CD80F, "-> To Start/Change Projection Press [R] or [T] Key.");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20,150,0x7CD80F, "-> To Move The Graphic Representation Press [Up-Down-Right-Left] Keys");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20,200,0x7CD80F, "-> To increase altitude Press [+] Key.");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20,250,0x7CD80F, "-> Press [M] Key To return To Menu Page.");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20,300,0x7CD80F, "-> Press [ESC] Key To Quit.");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20,350,0xFF0000, "----------------------------------------------------------------------");
}

void	menu_(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	show_menu(data);
}

void	print_pipes(t_data *data, int i, int j, int pos)
{
	while (i < j)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, pos,i,0x31A0BF, "|");
		i = i + 5;
	}
}
