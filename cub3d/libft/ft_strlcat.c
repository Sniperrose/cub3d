/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:58:29 by galtange          #+#    #+#             */
/*   Updated: 2021/11/30 17:59:08 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	len_d;

	len = 0;
	len_d = ft_strlen(dst);
	if (!src || !dst)
		return (0);
	if (len_d >= size)
		return (ft_strlen(src) + size);
	while ((*(src + len) != '\0') && len < (size - len_d - 1))
	{
		*(dst + len_d + len) = *(src + len);
		len++;
	}
	*(dst + len_d + len) = '\0';
	return (len_d + ft_strlen(src));
}
