/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelfirst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:53:01 by vpericat          #+#    #+#             */
/*   Updated: 2022/03/24 17:11:46 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelfirst(t_list **lst, void (*del)(void*))
{
	t_list	*node;

	node = (*lst)->next;
	del((*lst)->content);
	del(*lst);
	*lst = node;
}
