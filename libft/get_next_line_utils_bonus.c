/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:41:01 by dgalactu          #+#    #+#             */
/*   Updated: 2021/12/02 15:41:13 by dgalactu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*new_list(void)
{
	t_list	*nlist;

	nlist = (t_list *)malloc(sizeof(t_list));
	if (!nlist)
		return (NULL);
	nlist->len = 0;
	nlist->next = NULL;
	return (nlist);
}

t_list	*list_next(t_list *last)
{
	if (!last)
		return (NULL);
	last->next = new_list();
	return (last->next);
}

void	free_list_elem(t_list *elem)
{
	if (elem)
		free(elem);
}

void	free_list(t_list **list)
{
	t_list	*a;
	t_list	*b;

	if (*list)
	{
		a = *list;
		while (a->next != NULL)
		{
			b = a;
			a = a->next;
			free_list_elem(b);
		}
		free_list_elem(a);
		*list = NULL;
	}
}
