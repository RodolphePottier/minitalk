/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:55:01 by rpottier          #+#    #+#             */
/*   Updated: 2021/11/26 16:57:26 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*iter_content;
	t_list	*new_elem;
	t_list	*new_list;

	if (!lst || !f)
		return (NULL);
	new_list = ft_lstnew((f)(lst->content));
	lst = lst->next;
	while (lst)
	{
		iter_content = (f)(lst->content);
		new_elem = ft_lstnew(iter_content);
		if (!new_elem)
		{
			if (del)
				ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_elem);
		lst = lst->next;
	}
	return (new_list);
}
