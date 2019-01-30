/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 14:39:49 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 12:05:03 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*ptrdst;
	unsigned char		*ptrsrc;

	i = 0;
	ptrdst = (unsigned char *)dst;
	ptrsrc = (unsigned char *)src;
	while (i < n)
	{
		ptrdst[i] = ptrsrc[i];
		if (ptrsrc[i] == (unsigned char)c)
			return ((unsigned char*)dst + i + 1);
		i++;
	}
	return (NULL);
}
