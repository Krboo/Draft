/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 05:36:55 by pmartine          #+#    #+#             */
/*   Updated: 2016/06/04 05:36:58 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		find_nl(char *s, int i)
{
	if (s && s[i] == '\0')
		return (-1);
	else if (s && s[i] == '\n')
		return (i);
	return (find_nl(s, i + 1));
}

static void		final_cut(char **s, char **line)
{
	char	*tmp;
	int		nl;

	ft_string_swap(&*s, &tmp);
	nl = (find_nl(tmp, 0) == -1) ? (int)ft_strlen(tmp) : find_nl(tmp, 0);
	*line = ft_strsub(tmp, 0, nl);
	*s = ft_strsub(tmp, nl + 1, ft_strlen(tmp));
	free(tmp);
}

static int		read_fn(int const fd, char **s)
{
	int		ret;
	char	*tmp;
	char	buff[BUFF_SIZE + 1];

	while (!(ft_strchr(*s, '\n')) && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!(tmp = ft_strjoin(*s, buff)))
			return (0);
		free(*s);
		*s = NULL;
		ft_string_swap(&*s, &tmp);
	}
	return (ret);
}

static t_mfd	*multi_fd(int fd, t_mfd *lst)
{
	t_mfd	*tmp;
	t_mfd	*new;

	lst = lst->bgn_lst;
	tmp = lst;
	while (lst->fd != fd && lst->next)
		lst = lst->next;
	if (fd == lst->fd)
		return (lst);
	if (!(new = malloc(sizeof(t_mfd))))
		return (NULL);
	new->fd = fd;
	new->s = ft_strdup("");
	new->next = NULL;
	new->bgn_lst = tmp;
	lst->next = new;
	return (new);
}

int				get_next_line(int const fd, char **line)
{
	static t_mfd	*lst = NULL;
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	if (!lst)
	{
		if (!(lst = (t_mfd*)malloc(sizeof(t_mfd))))
			return (-1);
		lst->fd = fd;
		lst->s = ft_strdup("");
		lst->next = NULL;
		lst->bgn_lst = lst;
	}
	lst = multi_fd(fd, lst);
	if ((ret = read_fn(fd, &lst->s)) < 0)
		return (-1);
	ret = (lst->s[0] != '\0') ? 1 : 0;
	final_cut(&lst->s, &*line);
	return (ret);
}
