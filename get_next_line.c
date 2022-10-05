/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 10:56:57 by ohearn        #+#    #+#                 */
/*   Updated: 2022/10/05 17:33:11 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

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

size_t	ft_strlen(const	char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

void	read_line(int fd, char **stash, char **temp)
{
	char	*buffer;
	int		err;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return ;
	err = 1;
	while (err > 0)
	{
		err = read(fd, buffer, BUFFER_SIZE);
		if (err == -1)
		{
			free_strings(&buffer, &stash[fd], 0);
			return ;
		}
		buffer[err] = '\0';
		*temp = ft_strdup(*stash);
		free_strings(stash, 0, 0);
		*stash = ft_strjoin(*temp, buffer);
		free_strings(temp, 0, 0);
		if (ft_strchr(*stash) == 0)
			break ;
	}
	free_strings(&buffer, 0, 0);
}

char	*print_line(char **stash, char **temp)
{
	int		cntr;
	char	*save;

	*temp = ft_strdup(*stash);
	free_strings(stash, 0, 0);
	cntr = ft_strchr(*temp);
	if (cntr == 0)
		return (NULL);
	*stash = save_leftovers(cntr, *temp);
	save = return_line(cntr, *temp);
	free_strings(temp, 0, 0);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;
	char		*temp;

	line = NULL;
	temp = NULL;
	if ((read(fd, temp, 0) == -1) || BUFFER_SIZE < 0)
		return (NULL);
	if (!stash[fd])
	{
		stash[fd] = malloc(sizeof(char));
		if (!stash[fd])
			return (NULL);
	}
	read_line(fd, &stash[fd], &temp);
	if (stash[fd] != NULL && *(stash[fd]) != '\0')
		line = print_line(&stash[fd], &temp);
	if (!line || *line == '\0')
	{
		free_strings(&stash[fd], &line, &temp);
		return (NULL);
	}
	return (line);
}
