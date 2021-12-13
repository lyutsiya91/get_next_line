/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalio <sgalio@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:54:10 by sgalio            #+#    #+#             */
/*   Updated: 2021/12/13 15:54:11 by sgalio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	create_line_and_remainder(char **line, char **remainder)
{
	char	*pointer;

	pointer = ft_strchr(*remainder, '\n');
	if (pointer)
	{
		*pointer = '\0';
		*line = ft_strdup(*remainder);
		if (*line == ((void *)0))
		{
			free(*remainder);
			return (-1);
		}
		ft_strcpy(*remainder, ++pointer);
		return (1);
	}
	else
	{
		*line = ft_strdup(*remainder);
		free(*remainder);
		*remainder = NULL;
		if (*line == ((void *)0))
			return (-1);
		return (0);
	}
}

int	get_next_line(int fd, char **line)
{
	int			read_size;
	char		*buf;
	static char	*remainder;

	read_size = 1;
	if (!line || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == ((void *)0))
		return (-1);
	while (read_size != 0 && ft_strchr(remainder, '\n') == NULL)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(buf);
			return (-1);
		}
		buf[read_size] = '\0';
		remainder = ft_strjoin(remainder, buf);
	}
	free(buf);
	return (create_line_and_remainder(line, &remainder));
}
