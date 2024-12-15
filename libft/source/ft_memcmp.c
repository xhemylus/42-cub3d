/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:06:23 by vpericat          #+#    #+#             */
/*   Updated: 2021/11/05 12:11:38 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*source1;
	const unsigned char	*source2;

	source1 = s1;
	source2 = s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && source1[i] == source2[i])
		i++;
	return (source1[i] - source2[i]);
}
