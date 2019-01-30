/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 10:28:18 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 18:09:23 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include <math.h>
# include <mlx.h>
# include <pthread.h> 

# define HEIGHT		720
# define WIDTH		1280
# define THREADS 	16
# define TWIDTH		WIDTH / THREADS
# define MLX		file->mlx
# define WIN		file->win
# define RED		file->color.red
# define GREEN		file->color.green
# define BLUE		file->color.blue
# define SCOLOR		file->color.startcolor
# define ECOLOR		file->color.endcolor
# define CIM		file->fractal.cim
# define CRE		file->fractal.cre
# define NRE		file->fractal.newre
# define NIM		file->fractal.newim
# define ORE		file->fractal.oldre
# define OIM		file->fractal.oldim
# define MOVEX		file->fractal.movex
# define MOVEY		file->fractal.movey
# define ZOOM		file->zoom.zoom

typedef struct		s_color
{
	int				startcolor;
	int				endcolor;
	int				color;
	int				red;
	int				green;
	int				blue;
	int				r_random;
	int				g_random;
	int				b_random;
}					t_color;

typedef struct		s_fractal
{
	double			cre;
	double			cim;
	double			newre;
	double			newim;
	double			oldre;
	double			oldim;
	double			movex;
	double			movey;
	int				move;
	int				maxIterations;
}					t_fractal;

typedef struct		s_zoom
{
	double dx;
	double dy;
	double px;
	double py;
	double left;
	double top;
	double zoom;
}					t_zoom;

typedef struct		s_file
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*imgdata;
	char			*name;

	int				bpp;
	int				end;
	int				sl;

	int				th_i;
	int				th_imax;

	int				tx;
	int				ty;

	void			(*frunctal)(struct s_file *file, int x, int y);
	t_color			color;
	t_zoom			zoom;
	t_fractal		fractal;

}					t_file;

void			julia(t_file *file, int x, int y);
void			mandelbrot(t_file *file, int x, int y);
void			burningship(t_file *file, int x, int y);
void			*start_fractol(void *fvoid);
int				session(t_file *file);
int				error(char *issue);
void			ft_init(t_file *file);
int				new_image(t_file *file);
void			ft_pixel_put(t_file *file, int x, int y);
int				get_key(int key, void *file);
int				wasted(void);
int				display(t_file *file);
int				get_mouse(int x, int y, void *file);
int				mouse_press(int key, int x, int y, void *file);
int				multithreads(t_file *file);

#endif
