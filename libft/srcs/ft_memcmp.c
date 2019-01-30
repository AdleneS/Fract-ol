/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 15:13:58 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 13:14:51 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptrs1;
	unsigned char	*ptrs2;

	i = 0;
	ptrs1 = (unsigned char*)s1;
	ptrs2 = (unsigned char*)s2;
	while (i < n)
	{
		if (ptrs1[i] == ptrs2[i])
			i++;
		else if (ptrs1[i] != ptrs2[i])
			return (ptrs1[i] - ptrs2[i]);
	}
	return (0);
}
