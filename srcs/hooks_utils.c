/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:18:37 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/02/02 19:30:57 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <X11/keysym.h>
#include "fractol.h"

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		close_window(vars);
	return (0);
}

int	close_window(t_vars *vars)
{
	free_exit(vars, 0);
	return (0);
}
