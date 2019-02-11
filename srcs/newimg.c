/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   newimg.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 10:49:22 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/02/11 10:04:21 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init(t_file *file)
{
	if (!file->color.color)
	{
		RED = 255;
		GREEN = 255;
		BLUE = 255;
		file->color.r_random = 100;
		file->color.g_random = 0;
		file->color.b_random = 40;
	}
}

int		new_image(t_file *file)
{
	if ((MLX = mlx_init()))
		if ((WIN = mlx_new_window(MLX, WIDTH, HEIGHT, file->name)))
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
