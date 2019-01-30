/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 12:47:53 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 16:42:01 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void		itoa_isnegative(int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

char			*ft_itoa(int n)
{
	int		neg;
	int		len;
	int		tmp;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp = n;
	neg = 0;
	len = 2;
	itoa_isnegative(&n, &neg);
	while (tmp /= 10)
		len++;
	len += neg;
	if (!(str = (char *)malloc((sizeof(char) * len))))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = ((n % 10) + '0');
		n /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
