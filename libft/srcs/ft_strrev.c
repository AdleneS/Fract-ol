/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 14:43:09 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 14:55:32 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	int min;
	int max;
	int temp;

	min = 0;
	max = 0;
	temp = 0;
	while (str[max])
	{
		max++;
	}
	max--;
	while (min <= max)
	{
		temp = str[max];
		str[max] = str[min];
		str[min] = temp;
		min++;
		max--;
	}
	return (str);
}
