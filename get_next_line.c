/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 10:56:57 by ohearn        #+#    #+#                 */
/*   Updated: 2022/09/07 14:17:22 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

char	*get_next_line(int fd)
{
	static char	stash = NULL;
	char		buffer;
	char		line;
	char		*ret;

	if (fd < 0 || fd > 1024)
		return (NULL);
	if (!stash)
	{
		stash = (char*)malloc(sizeof(char));
		if (!stash)
			return (NULL);
		stash = "\0";
	}
}
