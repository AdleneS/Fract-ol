/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 11:09:46 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/02/11 10:05:35 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int		wasted(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

void	exit_prog(int key, t_file *file)
{
	if (key == 53)
	{
		mlx_destroy_window(file->mlx, file->win);
		free(file);
		exit(EXIT_SUCCESS);
	}
}

void	zoom(int key, int x, int y, t_file *file)
{
	if (!((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT)))
		return ;
	if (key == 4)
	{
		file->fractal.movex = (x / ZOOM + MOVEX) - (x / (ZOOM * 1.3));
		file->fractal.movey = (y / ZOOM + MOVEY) - (y / (ZOOM * 1.3));
		ZOOM *= 1.3;
	}
	if (key == 5)
	{
		file->fractal.movex = (x / ZOOM + MOVEX) - (x / (ZOOM / 1.3));
		file->fractal.movey = (y / ZOOM + MOVEY) - (y / (ZOOM / 1.3));
		ZOOM /= 1.3;
	}
	if (key == 1)
	{
		file->color.r_random = rand();
		file->color.g_random = rand();
		file->color.b_random = rand();
	}
}

void	move(int key, t_file *file)
{
	if (key == 123 || key == 124)
		file->fractal.movex += (key == 123) ? 0.01 : -0.01;
	if (key == 125 || key == 126)
		file->fractal.movey += (key == 126) ? 0.01 : -0.01;
	if (key == 49)
		file->fractal.move = file->fractal.move ? 0 : 1;
	if (key == 116)
	{
		file->fractal.maxiterations += 5;
	}
}

void	change(int x, int y, t_file *file)
{
	if (!((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT)))
		return ;
	if (file->fractal.move)
	{
		if (file->tx != x)
		{
			if (file->tx > x)
				file->fractal.cim += ((double)x / 100000);
			else
				file->fractal.cim -= ((double)x / 100000);
		}
		if (file->ty != y)
		{
			if (file->ty > y)
				file->fractal.cre += ((double)y / 100000);
			else
				file->fractal.cre -= ((double)y / 100000);
		}
		file->tx = x;
		file->ty = y;
	}
}
