/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:12:51 by vgosset           #+#    #+#             */
/*   Updated: 2016/01/12 18:30:18 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <sys/uio.h>
# include "lib/libft.h"

# define BUFF_SIZE 32

typedef struct	g_struct
{
	char	buf[BUFF_SIZE + 1];
	char	*save;
	int		fd;
}			g_struct;

int		get_next_line(int const fd, char **line);
int		readline(g_struct **strct, char *tmp, char **line);

#endif
