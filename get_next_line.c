/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 10:56:57 by ohearn        #+#    #+#                 */
/*   Updated: 2022/09/18 14:02:47 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

char	read_file(int fd, char *stash,  char buffer)
{
	int		safeguard;
	char	BUFFER_SIZE;
	char	temp;
	
	while (safeguard != 0)
	{
		safeguard == read(fd, buffer, BUFFER_SIZE);
		if (safeguard == -1)
			{
				free(stash);
				return (NULL);
			}
		stash = strjoin(stash, buffer);
		if ((temp = nl_checker(stash)) != NULL)
			{
				return_line(temp, stash);
				
			}
	}
}

int	return_line(int temp, char *stash)
{
	char	test;

	test = (char*)malloc(temp);
	
}

int	save_leftovers(int temp)
{

}

char	*nl_checker(const char *s)
{
	int	tally;

	tally = 0;
	while (s[tally] != '\0')
	{
		if (s[tally] == '\n')
			return (tally + 1);
		tally++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	int			BUFFER_SIZE = 42;
	char		buffer[BUFFER_SIZE + 1];
	char		*ret;

	if (fd < 0 || fd > 1024 || buffer <= 0)
		return (NULL);
	if (!stash)
	{
		stash = (char*)malloc(sizeof(char));
		if (!stash)
			return (NULL);
		*stash = "\0";
	}
	read_file(fd, *stash, buffer);
}
