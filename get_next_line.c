/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 10:56:57 by ohearn        #+#    #+#                 */
/*   Updated: 2022/09/27 17:58:34 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*buffer;
	char		*ret;

	buffer = malloc(sizeof * buffer * (BUFFER_SIZE + 1));
	if (fd < 0 || fd > 1024 || !buffer)
		return (NULL);
	stash[fd] = malloc(sizeof(char));
	if (!stash[fd])
	{
		return (NULL);
		stash[fd] = "\0";
	}
	ret = read_file(fd, stash[fd], buffer);
	free_strings (&buffer);
	free_strings (&stash[fd]);
	return (ret);
}
