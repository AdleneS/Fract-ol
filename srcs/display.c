/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/24 19:23:31 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/01/28 15:45:36 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int		display(t_file *file)
{
	if (!(file->img = mlx_new_image(MLX, WIDTH, HEIGHT)))
		error("Image Error");
	if (!(file->imgdata = mlx_get_data_addr(file->img, &file->bpp, &file->sl,
		&file->end)))
		error("Image Error");
	multithreads(file);
	mlx_put_image_to_window(MLX, WIN, file->img, 0, 0);
	mlx_destroy_image(MLX, file->img);
	return (0);
}