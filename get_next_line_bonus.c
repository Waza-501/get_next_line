/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 10:56:57 by ohearn        #+#    #+#                 */
/*   Updated: 2022/10/14 14:14:42 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>

void	free_strings(char **string, char **string2, char **string3)
{
	if (string != NULL)
	{
		free(*string);
		*string = NULL;
	}
	if (string2 != NULL)
	{
		free(*string2);
		*string2 = NULL;
	}
	if (string3 != NULL)
	{
		free(*string3);
		*string3 = NULL;
	}
}

int	nl_checker(const char *s)
{
	int	tally;

	tally = 0;
	if (!s)
		return (1);
	while (s[tally])
	{
		if (s[tally] == '\n')
			return (1);
		tally++;
	}
	return (0);
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
		free_strings(stash, NULL, NULL);
		*stash = ft_strjoin(*temp, buffer);
		free_strings(temp, NULL, NULL);
		if (nl_checker(*stash))
			break ;
	}
	free_strings(&buffer, NULL, NULL);
}

char	*print_line(char **stash, char **temp)
{
	int		cntr;
	char	*save;

	cntr = 0;
	*temp = ft_strdup(*stash);
	free_strings(stash, NULL, NULL);
	*stash = save_leftovers(cntr, *temp);
	save = return_line(cntr, *temp);
	free_strings(temp, NULL, NULL);
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
		stash[fd][0] = '\0';
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
