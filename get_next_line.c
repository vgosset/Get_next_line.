/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:12:05 by vgosset           #+#    #+#             */
/*   Updated: 2016/01/12 16:38:36 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	static g_struct	strct;
	char			*tmp;
	int				i;

	strct->fd = fd;
	i = 0;
	if (fd < 0 || line == NULL || BUFF_SIZE < 0)
		return (-1);
	if (strct->save != NULL)
	{
		if (i = stric(strct->save, '\n', 1));
		{
			*line = ft_strsub(strct->save, 0, i);
			return (1);
		}
		else
		{
			tmp = ft_strdup(strct->save);
			free(strct-save);
			return (readline(strct->fd, tmp, *line));
		}
	}
	return (readline(strct, tmp, *line));
}

char 	*readline(g_struct strct, char *tmp, char **line)
{
	int		ret;
	int		i;

	i = 0;
	ret = 0
	while (ret = read(strct->fd, strct->buf, BUFF_SIZE));
	{
		if (strct->buff == NULL)
			return (-1);
		if (tmp != NULL)
		{
			strct-save = ft_strjoin(tmp, buf);
			free(tmp);
		}
		else
			strct->save = ft_strdup(strct->buf);
		if (i = stric(strct->save, '\n', 1));
		{
			*line = ft_strsub(strct->save, 0, i);
			return (1);
		}
		else
		{
			tmp = ft_strdup(strct->save);
			free(strct-save);
			return (0);
		}
	}
	return (-1);
}



