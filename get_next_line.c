/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:12:05 by vgosset           #+#    #+#             */
/*   Updated: 2016/01/08 14:36:41 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	
}

char 	*readline(int const fd)
{
	char buf[1];
	char *str;
	int i;

	i = 0;
	read(fd, buf, 1);
	while (buf[0] != '\n')
	{
		read(fd, buf, 1);
		i++;
	}
	str = malloc(sizeof(char *) * i + 1);
	//ouverture a revoir//
	read(fd, str, i);
	//'\0' a voir//
	return (str);
}



