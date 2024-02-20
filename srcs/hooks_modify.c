/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_modify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:21:28 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/02/20 16:32:35 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <X11/keysym.h>
#include "fractol.h"

void	modify_x(t_vars *vars, int keycode)
{
	if (keycode == XK_Right)
		vars->params.move_x += PGCD;
	else
		vars->params.move_x -= PGCD;
}

void	modify_y(t_vars *vars, int keycode)
{
	if (keycode == XK_Down)
		vars->params.move_y += PGCD;
	else
		vars->params.move_y -= PGCD;
}

void	modify_zoom(t_vars *vars, int keycode)
{
	if (keycode == XK_i || keycode == 5)
		vars->params.zoom *= 1.01;
	else if (keycode == XK_o || keycode == 4)
		vars->params.zoom /= 1.01;
}

void	modify_colors(t_vars *vars, int keycode)
{
	if (keycode == XK_r)
		vars->params.move_color.r += 5;
	if (keycode == XK_g)
		vars->params.move_color.g += 5;
	if (keycode == XK_b)
		vars->params.move_color.b += 5;
}

void	modify_iteration(t_vars *vars, int keycode)
{
	if (keycode == XK_equal)
		vars->params.max_iteration += 1;
	else if (vars->params.max_iteration > 1)
		vars->params.max_iteration -= 1;
}
