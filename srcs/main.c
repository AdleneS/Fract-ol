/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 12:10:44 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/02/11 09:55:04 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	select_fractal(t_file *file)
{
	if (!(ft_strcmp(file->name, "julia")))
	{
		session_julia(file);
		file->frunctal = &(julia);
	}
	else if (!(ft_strcmp(file->name, "mandelbrot")))
	{
		session_mandelbrot(file);
		file->frunctal = &(mandelbrot);
	}
	else if (!(ft_strcmp(file->name, "burningship")))
	{
		session_bruningship(file);
		file->frunctal = &(burningship);
	}
}

int		multithreads(t_file *file)
{
	int			i;
	pthread_t	tid[THREADS];
	t_file		th_file[THREADS];

	i = 0;
	while (i < THREADS)
	{
		th_file[i] = *file;
		th_file[i].th_i = TWIDTH * i;
		th_file[i].th_imax = TWIDTH * (i + 1);
		pthread_create(&tid[i], NULL, start_fractol, &th_file[i]);
		i++;
	}
	while (i--)
		pthread_join(tid[i], NULL);
	return (1);
}

int		main(int argc, char **argv)
{
	t_file	*file;

	if (argc < 2)
	{
		ft_putstr("usage:\t./fractol <julia>\n\t./fractol <mandelbrot>\n");
		return (error("\t./fractol <burningship>"));
	}
	if ((ft_strcmp("julia", argv[1]) && ft_strcmp("mandelbrot", argv[1])
	&& ft_strcmp("burningship", argv[1])) || argc > 2)
		return (error("Wrong Fractal"));
	if (!(file = malloc(sizeof(t_file))))
		return (error("Malloc Error"));
	file->name = argv[1];
	ft_init(file);
	if (!(new_image(file)))
		return (error("Image Error"));
	select_fractal(file);
	display(file);
	mlx_hook(WIN, 3, (1L << 0), get_key, (void *)file);
	mlx_hook(WIN, 4, (1L << 0), mouse_press, (void *)file);
	mlx_hook(WIN, 6, 0, get_mouse, (void *)file);
	mlx_hook(WIN, 17, 0, wasted, NULL);
	mlx_loop(MLX);
	return (1);
}
