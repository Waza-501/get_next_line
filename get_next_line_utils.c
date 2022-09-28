/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 10:56:55 by ohearn        #+#    #+#                 */
/*   Updated: 2022/09/28 17:40:22 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>

char	*read_file(int fd, char *stash, char *buffer)
{
	int		safeguard;
	int		cntr;
	char	*ret;

	safeguard = 1;
	while (safeguard > 0)
	{
		safeguard = read(fd, buffer, BUFFER_SIZE);
		if (safeguard == -1)
		{
			free_strings(&buffer, &stash, 0);
			return (NULL);
		}
		buffer[safeguard] = '\0';
		stash = strcat(stash, buffer);
		cntr = nl_checker(stash);
		if (cntr != '\0')
		{
			ret = return_line(cntr, stash);
			save_leftovers(cntr, stash);
			return (ret);
		}
	}
	ret = return_line(cntr, stash);
	return (ret);
}

char	*return_line(int cntr, char *stash)
{
	char	*test;
	int		tally;

	test = malloc(cntr);
	if (!test)
		return (NULL);
	tally = 0;
	while (tally < cntr)
	{
		test[tally] = stash[tally];
		tally++;
	}
	return (test);
}

void	save_leftovers(int cntr, char *stash)
{
	int		tally;
	int		new;
	char	*temp;

	tally = strlen(stash);
	temp = malloc(tally);
	if (!temp)
		return ;
	new = 0;
	while (cntr != tally)
	{
		temp[new] = stash[cntr];
		cntr++;
		new++;
	}
	strcpy(stash, temp);
	free_strings(&temp, 0, 0);
}

int	nl_checker(const char *s)
{
	int	tally;

	tally = 0;
	while (s[tally] != '\0')
	{
		if (s[tally] == '\n')
			return (tally + 1);
		tally++;
	}
	return ('\0');
}
