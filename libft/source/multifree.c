/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multifree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:21:50 by vpericat          #+#    #+#             */
/*   Updated: 2022/01/20 16:37:14 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*multifree(int count, ...)
{
	va_list	args;
	int		i;

	i = -1;
	va_start(args, count);
	while (++i < count)
		free(va_arg(args, char *));
	va_end(args);
	return (NULL);
}
