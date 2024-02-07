/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:00:53 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/02/07 17:25:08 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include <stdlib.h>

void	free_exit(t_vars *vars, int err_code)
{
	if (vars->data.img)
		mlx_destroy_image(vars->mlx, vars->data.img);
	if (vars->mlx)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit(err_code);
}

uint32_t	calculate_color(int x, int y, char *name)
{
	t_color	color;
	int		nb_iteration;

	nb_iteration = calculate_limit(name, x , y);
	if (nb_iteration == MAX_ITERATION)
		color.color = 0xFF000000;
	else
		color.color = 0xFF000000;
	return (color.color);
}
