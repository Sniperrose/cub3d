/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:55:25 by galtange          #+#    #+#             */
/*   Updated: 2024/03/05 17:55:28 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sep_line(char **gstr)
{
	char	*newline;
	char	*temp;
	char	*line;

	newline = ft_strchr(*gstr, '\n');
	line = ft_substr(*gstr, 0, newline - *gstr + 1);
	temp = *gstr;
	*gstr = ft_strdup(newline + 1);
	free(temp);
	return (line);
}

char	*return_line(int rc, char **gstr)
{
	char	*line;

	if (rc <= 0 && !*gstr)
		line = 0;
	else if (rc <= 0 && ft_strlen(*gstr) == 0)
		line = 0;
	else if (*gstr && !ft_strchr(*gstr, '\n'))
	{	
		line = ft_strdup(*gstr);
		free(*gstr);
		*gstr = 0;
	}
	else
		line = ft_sep_line(gstr);
	return (line);
}

char	*ft_read(int fd, char **gstr)
{
	int		rc;
	char	*buff;
	char	*temp;

	rc = 1;
	temp = 0;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	buff[BUFFER_SIZE] = 0;
	while (rc > 0 && !ft_strchr(*gstr, '\n'))
	{
		rc = read(fd, buff, BUFFER_SIZE);
		if (rc > 0)
		{
			buff[rc] = 0;
			temp = *gstr;
			*gstr = ft_strjoin(*gstr, buff);
			if (!*gstr)
				return (NULL);
			free(temp);
		}
	}
	free(buff);
	return (return_line(rc, gstr));
}

char	*get_next_line(int fd)
{
	static char	*str_save = 0;
	char		*line;

	if (fd < 0)
		return (0);
	if (BUFFER_SIZE <= 0)
		return (0);
	line = 0;
	line = ft_read(fd, &str_save);
	if (!line && str_save != 0)
		free (str_save);
	return (line);
}
