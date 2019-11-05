/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 21:57:02 by oelazzou          #+#    #+#             */
/*   Updated: 2019/11/05 23:00:42 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	show_menu(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20,10,0x31A0BF, "---------------------------------MENU---------------------------------");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20,50,0x138D57, "-> To Change Colors Press [C] Key.");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20,100,0x138D57, "-> To Start/Change Projection Press [R] or [T] Key.");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20,150,0x138D57, "-> To Move The Graphic Representation Press [Up-Down-Right-Left] Keys.");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20,200,0x138D57, "-> To increase altitude Press [+] Key.");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20,250,0x138D57, "-> Press [M] Key To return To Menu Page.");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20,300,0x138D57, "-> Press [ESC] Key To Quit.");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20,350,0x31A0BF, "----------------------------------------------------------------------");
}

void	menu_(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	show_menu(data);
}
