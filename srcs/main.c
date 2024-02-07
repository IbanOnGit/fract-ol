/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:53:09 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/02/07 17:45:54 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include "libft.h"
#include <stdlib.h>
// #include <X11/keysym.h>
// #include <X11/X.h>

char	*parse_args(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "Julia", 6))
			return ("julia");
		else if (!ft_strncmp(argv[1], "Mandelbrot", 11))
			return ("mandelbrot");
		else
		{
			ft_printf("Available fractals are : Julia and Mandelbrot");
			exit(0);
		}
	}
	else
	{
		ft_printf("Available fractals are : Julia and Mandelbrot");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	char	*fractal;

	fractal = parse_args(argc, argv);
	init_all(&vars, fractal);
	mlx_loop(vars.mlx);
}
