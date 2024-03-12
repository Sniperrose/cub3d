/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:01:34 by galtange          #+#    #+#             */
/*   Updated: 2021/12/16 16:04:21 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*temp;

	s = (char *)src;
	temp = (char *)dest;
	if (src == NULL || dest == NULL)
		return (0);
	if (dest < src)
	{
		while (n--)
			*temp++ = *s++;
	}
	else
	{
		temp = (char *) dest + (n - 1);
		s = (char *) src + (n - 1);
		while (n--)
			*temp-- = *s--;
	}
	return (dest);
}
