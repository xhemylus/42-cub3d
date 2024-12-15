/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:57:13 by vpericat          #+#    #+#             */
/*   Updated: 2022/01/20 15:33:27 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *newlst)
{
	t_list	*node;

	if (!newlst || !alst)
		return ;
	else if ((*alst) == NULL)
		(*alst) = newlst;
	else
	{
		node = (*alst);
		while (node->next)
			node = node->next;
		node->next = newlst;
	}
}
