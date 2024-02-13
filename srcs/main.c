/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:53:09 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/02/13 16:41:17 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include "libft.h"
#include <stdlib.h>
// #include <X11/keysym.h>
// #include <X11/X.h>

void	parse_args(int argc, char **argv, t_vars *vars)
{
	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "Mandelbrot", 11) || !ft_strncmp(argv[1], "1", 2))
			vars->params.name = "mandelbrot";
		else if (!ft_strncmp(argv[1], "Julia", 6) || !ft_strncmp(argv[1], "2", 2))
			vars->params.name = "julia";
		else if (!ft_strncmp(argv[1], "Ship", 5) || !ft_strncmp(argv[1], "3", 2))
			vars->params.name = "ship";
		else
		{
			ft_printf("Available fractals are : Mandelbrot, Julia and Ship. Or 1, 2 and 3\n");	
			exit(0);
		}
	}
	else
	{
		ft_printf("Available fractals are : Mandelbrot, Julia and Ship. Or 1, 2 and 3\n");	
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	parse_args(argc, argv, &vars);
	init_all(&vars);
	mlx_loop(vars.mlx);
}
