/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 11:49:45 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 15:13:11 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*ptrdst;
	const char	*ptrsrc;

	i = -1;
	ptrdst = dst;
	ptrsrc = src;
	if (ptrsrc < ptrdst)
		while ((int)(--len) >= 0)
			*(ptrdst + len) = *(ptrsrc + len);
	else
		while (++i < len)
			*(ptrdst + i) = *(ptrsrc + i);
	return (dst);
}
