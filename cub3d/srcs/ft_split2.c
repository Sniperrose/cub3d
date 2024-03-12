/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:03:59 by galtange          #+#    #+#             */
/*   Updated: 2022/10/24 18:04:46 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_substr2(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (ft_strlen(s) < start)
		len = 0;
	else if (ft_strlen(s) < start + len)
		len = ft_strlen(s) - start;
	substr = malloc ((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (i < len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

size_t	ft_count(const char *all, char sep)
{
	int		i;
	size_t	line;

	if (!all)
		return (0);
	i = 0;
	line = 0;
	while (*all != '\0' && *all == sep)
		all++;
	while (*all != '\0')
	{
		if (*all != sep && i == 0)
		{
			line++;
			i = 1;
		}
		if (i == 1 && *all == sep)
			i = 0;
		all++;
	}
	return (line);
}

size_t	ft_end(const char *s, char c)
{
	size_t	end;

	end = 0;
	while (*s != c && *s != '\0')
	{
		end++;
		s++;
	}
	return (end);
}

void	ft_split2(char **result, char const *all, char sep, size_t size)
{
	int		i;
	size_t	line;

	if (!all || !size)
		return ;
	i = 0;
	line = 0;
	while (line < size && all[i] != '\0')
	{
		while (all[i] == sep)
			i++;
		result[line] = ft_substr2(all, i, ft_end(&all[i], sep));
		if (!result[line])
		{
			ft_freecharchar(result, line);
			return ;
		}
		i = i + ft_end(&all[i], sep);
		while (all[i] == sep)
			i++;
		line++;
	}
	result[line] = NULL;
}
