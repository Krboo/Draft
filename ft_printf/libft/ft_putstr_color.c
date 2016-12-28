/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 05:31:19 by pmartine          #+#    #+#             */
/*   Updated: 2016/06/04 05:31:01 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_color(char *s_color, char *s_print, char *s_stop)
{
	if (ft_strncmp(s_color, "\x1b[38;5;", 7) == 0)
		ft_putstr(s_color);
	else
		return (ft_putstr(s_print));
	ft_putstr(s_print);
	return (ft_putstr(s_stop));
}
