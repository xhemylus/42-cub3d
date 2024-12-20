/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invlerp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:37:02 by vpericat          #+#    #+#             */
/*   Updated: 2022/01/20 16:54:33 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	invlerp(float a, float b, float v)
{
	return ((v - a) / (b - a));
}
