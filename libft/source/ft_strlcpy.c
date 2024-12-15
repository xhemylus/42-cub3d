/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:48:01 by vpericat          #+#    #+#             */
/*   Updated: 2022/03/19 14:29:16 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;

	i = -1;
	while (src[++i] && i < size - 1)
		dest[i] = src[i];
	dest[i] = '\0';
}
