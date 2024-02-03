/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:51:44 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/02/03 18:38:05 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdint.h>

# define TITLE "fractol"
# define WIDTH 1080
# define HEIGHT 1920
# define CENTER_X WIDTH / 2
# define CENTER_Y HEIGHT / 2

# define X_MAX 2
# define X_MIN -2
# define Y_MAX 2
# define Y_MIN -2
# define MAX_ITERATION 100

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	struct s_data	data;
}	t_vars;

typedef struct s_complex
{
	double	z_r;
	double	z_i;
}	t_complex;


typedef union u_color
{
	uint32_t	color;
	struct
	{
		unsigned char b;
		unsigned char g;
		unsigned char r;
		unsigned char a;
	};
}	t_color;

void	init_all(t_vars *vars, char *name);
void	init_vars(t_vars *vars);
void	free_exit(t_vars *vars, int err_code);
int		key_press(int keycode, t_vars *vars);
int		close_window(t_vars *vars);
int		calculate_limit(char *name, double fract_x, double fract_y);
void	color_pixel(t_vars *vars, t_color color, int x, int y);
t_color	get_color(int nb_iteration);

#endif