/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractal.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/24 17:52:25 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 17:43:28 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void		*start_fractol(void *fvoid)
{
	int x;
	int y;
	t_file *file;

	file = (t_file *)fvoid;
	y = file->th_i;
	while (y < file->th_imax)
	{
		x = 0;
		while (x < WIDTH)
		{
			file->frunctal(file, x, y);
			x++;
		}
		y++;
	}
	return (file);
}

void		mandelbrot(t_file *file, int x, int y)
{
	int i = 0;
	
	i = -1;
	CIM = y / file->zoom.zoom + file->fractal.movey;
	CRE = x / file->zoom.zoom + file->fractal.movex;
	file->fractal.newre = 0;
	file->fractal.newim = 0;
	file->fractal.oldim = 0;
	file->fractal.oldre = 0;
	while (++i < file->fractal.maxIterations) 
	{
		ORE = NRE;
		OIM = NIM;
		NRE = ORE * ORE - OIM * OIM + CRE;
		NIM = 2.0 * ORE * OIM + CIM;
		if((NRE * NRE + NIM * NIM) > 4)
			break;
	}
	RED = i * file->color.r_random;
	GREEN = i * file->color.g_random;
	BLUE = 2 * i * file->color.b_random;
	ft_pixel_put(file, x, y);
}

void		burningship(t_file *file, int x, int y)
{
	int i;

	i = -1;
	CIM = y / file->zoom.zoom + file->fractal.movey;
	CRE = x / file->zoom.zoom + file->fractal.movex;
	NRE = 0;
	NIM = 0;
	while (++i < file->fractal.maxIterations) 
	{
		ORE = NRE;
		OIM = NIM;
		NRE = fabs((ORE * ORE - OIM * OIM) + CRE);
		NIM = fabs(2 * ORE * OIM + CIM);
		if((NRE * NRE + NIM * NIM) > 4)
			break;
	}

		RED = i % 255;
		GREEN = i % 10;
		BLUE = 2 * i % file->fractal.maxIterations;
		ft_pixel_put(file, x, y);
}

void		julia(t_file *file, int x, int y)
{
		int i;
		
		i = -1;
		NIM = y / file->zoom.zoom + file->fractal.movey;
		NRE =  x / file->zoom.zoom + file->fractal.movex;
		while (++i < file->fractal.maxIterations)
		{
			ORE = NRE;
			OIM = NIM;
			NRE = ORE * ORE - OIM * OIM + CRE;
			NIM = 2 * ORE * OIM + CIM;
			if((NRE * NRE + NIM * NIM) > 4)
				break;
		}
		RED = i + file->color.r_random;
		GREEN = i * file->color.g_random;
		BLUE = 2 * i * file->color.b_random; 
		/*RED = i % 255;
		GREEN = i % 150;
		BLUE = 2 * i % file->fractal.maxIterations;*/
		ft_pixel_put(file, x, y);
}