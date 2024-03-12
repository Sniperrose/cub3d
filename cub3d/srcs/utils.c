/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:56:32 by galtange          #+#    #+#             */
/*   Updated: 2024/03/05 17:56:42 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(str, 1);
	return (1);
}

int	ft_iswhitespace(char c)
{
	if (c == ' ')
		return (1);
	else if (c == '\n')
		return (1);
	else if (c == '\t')
		return (1);
	else if (c == '\v')
		return (1);
	else if (c == '\f')
		return (1);
	else if (c == '\r')
		return (1);
	return (0);
}

size_t	ft_countsep(const char *all, char sep)
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

int	ft_str_is_printable(char *str)
{
	int		i;
	size_t	c;

	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (! (str[i] > 31 && str[i] < 127))
		{
			c++;
		}
		i++;
	}
	if (ft_strlen(str) == c)
		return (0);
	return (1);
}
