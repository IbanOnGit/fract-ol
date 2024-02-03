/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:03:44 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/02/03 18:36:03 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include "libft.h"

int	julia(void)
{
	return (0);
}

int	mandelbrot(void)
{
	return (0);
}

int	calculate_limit(char *name, double fract_x, double fract_y)
{
	int		i;

	i = 0;
	if (!ft_strncmp(name, "julia", 6))
		i = julia();
	else if (!ft_strncmp(name, "mandelbrot", 11))
		i = mandelbrot();
	return (i);
}

