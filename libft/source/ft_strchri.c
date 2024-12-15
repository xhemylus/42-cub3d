/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:49:22 by vpericat          #+#    #+#             */
/*   Updated: 2022/04/02 18:01:12 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchri(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == (const char)c)
			return (i);
	if (s[i] == (const char) c)
		return (i);
	return (0);
}
