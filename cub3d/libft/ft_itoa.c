/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:16:50 by galtange          #+#    #+#             */
/*   Updated: 2022/01/04 20:49:18 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * (-1);
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	int			l;
	char		*s;
	long int	n;

	n = nb;
	l = len(nb);
	s = malloc ((l + 1) * sizeof(char));
	if (!s)
		return (NULL);
	if (n == 0)
		s[0] = 0 + '0';
	s[l--] = '\0';
	if (n < 0)
	{
		n = -n;
		s[0] = '-';
	}
	while (n > 0)
	{
		s[l--] = (n % 10) + '0';
		n = n / 10;
	}
	return (s);
}
