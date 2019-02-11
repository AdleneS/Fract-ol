/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   session.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/04 12:17:27 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/02/11 09:56:11 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int		session_julia(t_file *file)
{
	file->fractal.cre = -0.7;
	file->fractal.cim = 0.27016;
	file->fractal.newre = 0;
	file->fractal.newim = 0;
	file->fractal.oldim = 0;
	file->fractal.oldre = 0;
	file->fractal.movex = -1.6;
	file->fractal.movey = -0.9;
	file->fractal.maxiterations = 100;
	file->tx = 0;
	file->ty = 0;
	file->fractal.zoom = 400;
	return (1);
}

int		session_mandelbrot(t_file *file)
{
	file->fractal.cre = -0.7;
	file->fractal.cim = 0.27016;
	file->fractal.newre = 0;
	file->fractal.newim = 0;
	file->fractal.oldim = 0;
	file->fractal.oldre = 0;
	file->fractal.movex = -2.5;
	file->fractal.movey = -1.1;
	file->fractal.maxiterations = 100;
	file->tx = 0;
	file->ty = 0;
	file->fractal.zoom = 330;
	return (1);
}

int		session_bruningship(t_file *file)
{
	file->fractal.cre = -0.7;
	file->fractal.cim = 0.27016;
	file->fractal.newre = 0;
	file->fractal.newim = 0;
	file->fractal.oldim = 0;
	file->fractal.oldre = 0;
	file->fractal.movex = -2.3;
	file->fractal.movey = -1.9;
	file->fractal.maxiterations = 100;
	file->tx = 0;
	file->ty = 0;
	file->fractal.zoom = 300;
	return (1);
}
