/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:01:18 by galtange          #+#    #+#             */
/*   Updated: 2024/03/05 20:03:26 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;
	char	**tmp;

	if (argc == 1)
		return (ft_error("Please choose the mapfile!\n"));
	else if (argc != 2)
		return (ft_error("This project accept only 2args!\n"));
	else
	{
		tmp = ft_readmapfile(argv[1]);
		if (!tmp)
			return (ft_error("map error!\n"));
		if (ft_initdata(&cub3d, tmp))
		{
			ft_free(tmp);
			ft_freegame(&cub3d, "");
			return (ft_error("test here!\n"));
		}
		ft_free(tmp);
		ft_raycast(cub3d);
		ft_freegame(&cub3d, "");
	}
	return (0);
}
