/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:41:31 by pmartine          #+#    #+#             */
/*   Updated: 2016/06/04 05:33:10 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	ft_memset(dst, '\0', n);
	i = 0;
	while (n > 0 && src[i])
	{
		dst[i] = src[i];
		i++;
		n--;
	}
	return (dst);
}
