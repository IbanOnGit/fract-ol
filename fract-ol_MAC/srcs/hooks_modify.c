/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_modify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:21:28 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/05/01 08:02:55 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include "fractol.h"

void	modify_x(t_vars *vars, int keycode)
{
	if (keycode == 124)
		vars->params.move_x += PGCD;
	else
		vars->params.move_x -= PGCD;
}

void	modify_y(t_vars *vars, int keycode)
{
	if (keycode == 125)
		vars->params.move_y += PGCD;
	else
		vars->params.move_y -= PGCD;
}

void	modify_zoom(t_vars *vars, int keycode)
{
	if (keycode == 34 || keycode == 5)
		vars->params.zoom *= 1.01;
	else if (keycode == 31 || keycode == 4)
		vars->params.zoom /= 1.01;
}

void	modify_colors(t_vars *vars, int keycode)
{
	if (keycode == 15)
		vars->params.move_color.r += 5;
	if (keycode == 5)
		vars->params.move_color.g += 5;
	if (keycode == 11)
		vars->params.move_color.b += 5;
}

void	modify_iteration(t_vars *vars, int keycode)
{
	if (keycode == 12)
		vars->params.max_iteration += 1;
	else if (vars->params.max_iteration > 1)
		vars->params.max_iteration -= 1;
}
