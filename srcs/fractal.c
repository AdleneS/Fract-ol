/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractal.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/24 17:52:25 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/02/11 10:01:22 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void			*start_fractol(void *fvoid)
{
	int		x;
	int		y;
	t_file	*file;

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

static void		getcolor(t_file *file, double mu)
{
	RED = mu * 3 * (file->color.r_random % 255);
	GREEN = mu * 3 * (file->color.g_random % 255);
	BLUE = mu * 3 * (file->color.b_random % 255);
}

void			mandelbrot(t_file *file, int x, int y)
{
	int		i;
	double	mu;

	i = -1;
	mu = 0;
	CIM = y / ZOOM + file->fractal.movey;
	CRE = x / ZOOM + file->fractal.movex;
	NRE = 0;
	NIM = 0;
	OIM = 0;
	ORE = 0;
	while (++i < file->fractal.maxiterations)
	{
		ORE = NRE;
		OIM = NIM;
		NRE = ORE * ORE - OIM * OIM + CRE;
		NIM = 2.0 * ORE * OIM + CIM;
		if ((NRE * NRE + NIM * NIM) > 4)
			break ;
	}
	mu = i + 1 - log(log((NRE * NRE + NIM * NIM))) / log(2);
	mu /= file->fractal.maxiterations;
	getcolor(file, mu);
	ft_pixel_put(file, x, y);
}

void			burningship(t_file *file, int x, int y)
{
	int		i;
	double	mu;

	i = -1;
	mu = 0;
	CIM = y / ZOOM + file->fractal.movey;
	CRE = x / ZOOM + file->fractal.movex;
	NRE = 0;
	NIM = 0;
	while (++i < file->fractal.maxiterations)
	{
		ORE = NRE;
		OIM = NIM;
		NRE = fabs((ORE * ORE - OIM * OIM) + CRE);
		NIM = fabs(2 * ORE * OIM + CIM);
		if ((NRE * NRE + NIM * NIM) > 4)
			break ;
	}
	mu = i + 1 - log(log(sqrt(NRE * NRE + NIM * NIM))) / log(2);
	mu /= file->fractal.maxiterations;
	getcolor(file, mu);
	ft_pixel_put(file, x, y);
}

void			julia(t_file *file, int x, int y)
{
	int		i;
	double	mu;

	i = -1;
	mu = 0;
	NIM = y / ZOOM + file->fractal.movey;
	NRE = x / ZOOM + file->fractal.movex;
	while (++i < file->fractal.maxiterations)
	{
		ORE = NRE;
		OIM = NIM;
		NRE = ORE * ORE - OIM * OIM + CRE;
		NIM = 2 * ORE * OIM + CIM;
		if ((NRE * NRE + NIM * NIM) > 4)
			break ;
	}
	mu = i + 1 - log(log(sqrt(NRE * NRE + NIM * NIM))) / log(2);
	mu /= file->fractal.maxiterations;
	getcolor(file, mu);
	ft_pixel_put(file, x, y);
}
