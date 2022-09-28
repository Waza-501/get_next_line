/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 10:56:57 by ohearn        #+#    #+#                 */
/*   Updated: 2022/09/28 17:36:57 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>

void	free_strings(char **string, char **string2, char **string3)
{
	if (string != NULL && *string != '\0')
	{
		free(*string);
		*string = NULL;
	}
		if (string2 != NULL && *string2 != '\0')
	{
		free(*string2);
		*string2 = NULL;
	}
		if (string3 != NULL && *string3 != '\0')
	{
		free(*string3);
		*string3 = NULL;
	}
}

void	read_line(int fd, char *stash, char *line)
{
	char *buffer;

	buffer = malloc(sizeof * buffer * (BUFFER_SIZE + 1));
	if (!buffer)
		return ;
	*line = *read_file(fd, stash, buffer);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	line = "";
	if (fd < 0 || fd > 1024 ||BUFFER_SIZE < 0)
		return (NULL);
	if (!stash[fd])
	{
		stash[fd] = malloc(sizeof(char));
		if (!stash[fd])
			return (NULL);
	}
	read_line(fd, stash[fd], line);
	if (line == NULL)
	{
		free_strings (&stash[fd], 0, 0);
		return (NULL);
	}
	return (line);
}
