/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 10:56:55 by ohearn        #+#    #+#                 */
/*   Updated: 2022/10/04 01:01:51 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>

char	*return_line(int cntr, char *temp)
{
	char	*line;
	int		tally;

	line = malloc(cntr + 1);
	if (!line)
		return (NULL);
	tally = 0;
	while (temp[tally] != '\n' && temp[tally] != '\0')
	{
		line[tally] = temp[tally];
		tally++;
	}
	line[tally] = temp[tally];
	tally++;
	line[tally] = '\0';
	return (line);
}

char	*save_leftovers(int cntr, char *bulk)
{
	int		tally;
	int		new;
	char	*stash;

	tally = strlen(bulk);
	stash = malloc(sizeof(char) * ((tally - cntr) + 1));
	if (!stash)
		return (NULL);
	new = 0;
	while (bulk[new + cntr])
	{
		stash[new] = bulk[new + cntr];
		new++;
	}
	stash[new] = '\0';
	return (stash);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	int		tally;	

	if (!s1 || !s2)
		return (NULL);
	new_string = malloc(strlen (s1) + strlen (s2) + 1);
	tally = 0;
	if (!new_string)
		return (NULL);
	while (*s1)
	{
		new_string[tally] = *s1;
		tally++;
		s1++;
	}
	while (*s2)
	{
		new_string[tally] = *s2;
		tally++;
		s2++;
	}
	new_string[tally] = '\0';
	return (new_string);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		tally;

	copy = malloc(strlen(s1) + 1);
	if (!copy)
		return (NULL);
	tally = 0;
	while (s1[tally] != '\0')
	{
		copy[tally] = s1[tally];
		++tally;
	}
	copy[tally] = '\0';
	return (copy);
}

int	ft_strchr(const char *s)
{
	int		tally;

	tally = 0;
	while (s[tally])
	{
		while (s[tally] != '\n' && s[tally] != '\0')
			tally++;
		if (s[tally] == '\n' && s[tally] != '\0')
			return (tally + 1);
		return (tally);
	}
	return (0);
}
