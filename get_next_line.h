/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:12:51 by vgosset           #+#    #+#             */
/*   Updated: 2016/01/20 15:27:52 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <sys/uio.h>
# include "lib/libft.h"
# include <stdio.h>

# define BUFF_SIZE 51

typedef struct	c_struct
{
	char		buf[BUFF_SIZE + 1];
	char		*save;
	int			fd;
	struct		c_struct *next;
}				g_struct;

int				return_line(g_struct *strct, char **line);
int				get_next_line(int const fd, char **line);
int				readline(g_struct **strct, char **line);
void			creat_line(int const fd, g_struct **strct);
g_struct		*new_strct(int const fd, g_struct *next);

#endif
