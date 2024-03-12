/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:39:41 by galtange          #+#    #+#             */
/*   Updated: 2021/12/28 20:42:59 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	len;

	start = 0;
	len = ft_strlen(s1) - 1;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	if (start == ft_strlen(s1))
	{
		trim = ft_strdup("");
		if (!trim)
			return (NULL);
		else
			return (trim);
	}
	while (ft_strchr(set, s1[len]) != 0)
		len--;
	trim = ft_substr(s1, start, len - start + 1);
	return (trim);
}
