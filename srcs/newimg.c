/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   newimg.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 10:49:22 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 17:01:16 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int		session(t_file *file)
{
	file->fractal.cre = -0.7;
	file->fractal.cim = 0.27016;
	file->fractal.newre = 0;
	file->fractal.newim = 0;
	file->fractal.oldim = 0;
	file->fractal.oldre = 0;
	file->fractal.movex = -5;
	file->fractal.movey = -5;
	file->fractal.maxIterations = 100;
	file->tx = 0;
	file->ty = 0;
	file->zoom.zoom = 100;
	file->zoom.top = 1;
	file->zoom.left = 1;
	file->zoom.dx = 0;
	file->zoom.dy = 0;
	file->zoom.px = 0;
	file->zoom.py = 0;
	return (1);
}

void	ft_init(t_file *file)
{
	if (!file->color.color)
	{
		RED = 255;
		GREEN = 255;
		BLUE = 255;
		file->color.r_random = 10;
		file->color.g_random = 40;
		file->color.b_random = 255;
	}
}

int		new_image(t_file *file)
{
	if ((MLX = mlx_init()))
		if ((WIN = mlx_new_window(MLX, WIDTH, HEIGHT, "ORAGE")))
			return (1);
	return (0);
}

void	ft_pixel_put(t_file *file, int x, int y)
{
	int i;

	i = (x * 4) + (y * file->sl);
	if ((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT))
	{
		file->imgdata[i] = (char)file->color.blue;
		file->imgdata[i + 1] = (char)file->color.green;
		file->imgdata[i + 2] = (char)file->color.red;
	}
}
