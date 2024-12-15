/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:19:03 by vpericat          #+#    #+#             */
/*   Updated: 2021/11/05 12:11:27 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_revstring(char	*s, int len)
{
	int		i;
	char	temp;

	i = -1;
	while (++i < len / 2)
	{
		temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}
	return (s);
}

static int	ft_intlen(long int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	int				i;
	long int		temp;
	int				len;
	char			*dest;

	i = -1;
	temp = n;
	len = ft_intlen(temp);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	if (n == 0)
		dest[++i] = '0';
	if (temp < 0)
		temp = -temp;
	while (temp > 0)
	{
		dest[++i] = temp % 10 + '0';
		temp = temp / 10;
	}
	if (n < 0)
		dest[++i] = '-';
	dest[++i] = '\0';
	return (ft_revstring(dest, len));
}
