/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 15:58:52 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 12:04:46 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*ptr;
	const char	*ptrsrc;

	i = 0;
	ptr = dst;
	ptrsrc = src;
	while (i < n)
	{
		ptr[i] = ptrsrc[i];
		i++;
	}
	return (dst);
}
