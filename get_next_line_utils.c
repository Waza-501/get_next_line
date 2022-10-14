/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 10:56:55 by ohearn        #+#    #+#                 */
/*   Updated: 2022/10/14 14:14:00 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*return_line(int cntr, char *temp)
{
	char	*line;

	while (temp[cntr] != '\n' && temp[cntr] != '\0')
			cntr++;
	if (temp[cntr] == '\n' && temp[cntr] != '\0')
			cntr++;
	line = malloc(cntr + 1);
	if (!line)
		return (NULL);
	cntr = 0;
	while (temp[cntr] != '\n' && temp[cntr] != '\0')
	{
		line[cntr] = temp[cntr];
		cntr++;
	}
	if (temp[cntr] == '\n')
	{
		line[cntr] = temp[cntr];
		cntr++;
	}
	line[cntr] = '\0';
	return (line);
}

char	*save_leftovers(int cntr, char *bulk)
{
	int		tally;
	int		new;
	char	*stash;

	while (bulk[cntr] != '\n' && bulk[cntr] != '\0')
			cntr++;
	if (bulk[cntr] == '\n' && bulk[cntr] != '\0')
			cntr++;
	tally = ft_strlen(bulk);
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
	// new_string = malloc(ft_strlen (s1) + ft_strlen (s2) + 1);
	new_string = NULL;
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

	copy = malloc(ft_strlen(s1) + 1);
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

size_t	ft_strlen(const	char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}
