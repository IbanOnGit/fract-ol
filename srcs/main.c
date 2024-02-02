/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:53:09 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/02/01 14:08:14 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "libft.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	void	*mlx_ptr;
	void	*window_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (0);
	window_ptr = mlx_new_window(mlx_ptr, 500, 500, "t'es le + bo");
	mlx_loop(mlx_ptr);
	mlx
	mlx_destroy_window(mlx_ptr, window_ptr);	
}