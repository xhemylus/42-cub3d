/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:55:58 by vpericat          #+#    #+#             */
/*   Updated: 2022/01/26 15:08:09 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	long	anum;
	long	factor;
	int		i;

	anum = 0;
	factor = 1;
	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		factor = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		anum = anum * 10;
		anum += str[i] - '0';
		i++;
	}
	return (anum * factor);
}
