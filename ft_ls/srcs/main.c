/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 13:08:32 by pmartine          #+#    #+#             */
/*   Updated: 2016/02/11 17:06:49 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	DIR				*directory;
	struct dirent	*files;
	
	(void)argc;
	if (!(argv[1]))
	{	
		if ((directory = opendir("./")) == NULL)
			perror("");
		while ((files = readdir(directory)) != NULL)
		{
			if (files->d_name[0] != '.')
			{
				ft_putstr(files->d_name);
				if (files->d_type == DT_DIR)
					ft_putstr(" (doss)");
				ft_putstr("\t");
			}
		}
		closedir(directory);
	}
	
	else if (ft_strcmp(argv[1], "-a") == 0 && !(argv[2]))
	{
		directory = opendir("./");
		while ((files = readdir(directory)) != NULL)
		{
			ft_putstr(files->d_name);
			ft_putstr("\t");
		}
		closedir(directory);
	}
	else 
		ft_putendl("nope");
	return (0);
}
