/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:12:05 by vgosset           #+#    #+#             */
/*   Updated: 2016/01/14 14:22:14 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	static g_struct *strct = NULL;
	int				i;

	i = 0;
	if (fd < 0 || line == NULL || BUFF_SIZE < 0)
		return (-1);
	//Create_line bonus//
	if (strct->save != NULL && (i = ft_stric(strct->save, '\n', 1)) >= 0)
	{
		*line = ft_strsub(strct->save, 0, i);
		ft_strcpy(strct->buf, strct->save + i + 1);
		free (strct->save);
		if (strct->buf[0])
			strct->save = ft_strdup(strct->buf);
		else
			strct->save = NULL;
		return (1);
	}
	return (readline(&strct, line));
}

int		return_line(g_struct *strct, char **line)
{
	int		i;
	char	*tmp;
	i = 0;
	tmp = NULL;
	i = ft_stric(strct->buf, '\n', 1);
	if (i >= 0 && (!(strct->save)))
	{
		*line = ft_strsub(strct->buf, 0, i);
		if (strct->buf[i + 1])
			strct->save = ft_strdup(strct->buf + i + 1);
		else
			strct->save = NULL;
		return (1);
	}
	else if (i >= 0 && strct->save)
	{
		tmp = ft_strjoin(strct_save, ft_strsub(strct_buf, 0, i));
		*line = tmp;
		free(strct_save);
		if (strct->buf[i + 1])
			strct->save = ft_strsub(strct_buf, 0, i + 1);
		else
			strct_save = NULL;
		return (1);
	}
	return (0);
}

int		readline(g_struct **strct, char **line)
{
	int		ret;
	char	*tmp;

	ret = 0;
	tmp = NULL;
	ft_bzero((*strct)->buf, BUFF_SIZE + 1);
	while ((ret = read((*strct)->fd, (*strct)->buf, BUFF_SIZE)))
	{
		if (return_line(line, *strct) == 1)
			return (1);
		else
		{
			tmp = ft_strjoin((*strct)->save, (*strct)->buf);
			free((*strct)->save);
			(*strct)->save = tmp;
		}
	}
	if ((*strct)->save != NULL && ret == 0)
	{
		*line = (*strct)->save;
		(*strct)->save = NULL;
		return (1);
	}
	if (ret < 0)
		return (-1);
	return (0);
}
