/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 10:36:51 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 10:58:37 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;

	if (!alst || !*alst || !del)
		return ;
	lst = *alst;
	while (lst)
	{
		del((lst)->content, (lst)->content_size);
		free(lst);
		lst = lst->next;
	}
	*alst = NULL;
}
