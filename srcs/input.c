/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 11:09:46 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 18:09:16 by asaba       ###    #+. /#+    ###.fr     */
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
		file->zoom.zoom *= 1.3;
	}	
	if (key == 5)
	{
		file->fractal.movex = (x / ZOOM + MOVEX) - (x / (ZOOM / 1.3));
		file->fractal.movey = (y / ZOOM + MOVEY) - (y / (ZOOM / 1.3));
		file->zoom.zoom /= 1.3;
	}	
	if (key == 1)
	{
		file->color.r_random = rand();
		file->color.g_random = rand();
		file->color.b_random = rand();
	}
	file->tx = x;
	file->ty = y;
}

void	move(int key, t_file *file)
{
	if (key == 123 || key == 124)
		file->fractal.movey += (key == 123) ? 0.1 : -0.1;
	if (key == 125 || key == 126)
		file->fractal.movex += (key == 126) ? 0.1 : -0.1;
	if (key == 49)
		file->fractal.move = file->fractal.move ? 0 : 1;
	if (key == 116)
	{
		file->fractal.maxIterations += 5;
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

int		mouse_press(int key, int x, int y, void *file)
{
	t_file	*tmp;

	tmp = (t_file*)file;
	zoom(key, x, y, tmp);
	display(file);
	return (1);
}

int		get_mouse(int x, int y, void *file)
{
	t_file	*tmp;

	tmp = (t_file*)file;
	change(x, y, tmp);
	display(file);
	return (1);
}

int		get_key(int key, void *file)
{
	t_file	*tmp;

	tmp = (t_file*)file;
	move(key, file);
	display(file);
	exit_prog(key, tmp);
	return (1);
}
