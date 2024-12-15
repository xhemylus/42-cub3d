/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:22:20 by vpericat          #+#    #+#             */
/*   Updated: 2022/01/20 16:54:53 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisint(char *str)
{
	int	i;

	if (str[0] == '-')
		i = 1;
	else
		i = 0;
	if (ft_strisdigit(&str[i]))
		return (1);
	else
		return (0);
}
