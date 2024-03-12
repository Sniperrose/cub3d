/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:10:51 by galtange          #+#    #+#             */
/*   Updated: 2021/12/30 21:35:08 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((ft_strlen(little) == 0) || (big == little && ft_strlen(little) == len))
	{
		return ((char *) big);
	}
	while (len > 0 && big[i] != '\0')
	{
		j = 0;
		while (little[j] != '\0' && big[i + j] == little[j] && j < len)
			j++;
		if (ft_strlen(little) == j)
		{
			return ((char *)big + i);
		}
		i++;
		len--;
	}
	return (NULL);
}
