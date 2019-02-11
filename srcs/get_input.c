/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_input.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/04 16:36:05 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/02/04 16:38:04 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

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
