/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:13:53 by galtange          #+#    #+#             */
/*   Updated: 2021/12/20 21:40:31 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*temp;

	if (!str)
		return (0);
	temp = (char *) str;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == (c % 256))
			return (temp + i);
		i++;
	}
	if ((c % 256) == 0)
		return (temp + i);
	return (0);
}
