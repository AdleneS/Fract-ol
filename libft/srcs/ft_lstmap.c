/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 11:18:03 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 12:14:49 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmplst;
	t_list	*new;
	t_list	*start;

	if (lst == NULL)
		return (NULL);
	tmplst = (*f)(lst);
	if (!(new = ft_lstnew(tmplst->content, tmplst->content_size)))
		return (NULL);
	start = new;
	lst = lst->next;
	while (lst)
	{
		tmplst = (*f)(lst);
		if (!(new->next = ft_lstnew(tmplst->content, tmplst->content_size)))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (start);
}
