/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 16:38:24 by ohearn        #+#    #+#                 */
/*   Updated: 2022/10/05 17:43:35 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void checkleaks(void){
	system("leaks -q a.out");
}


int	main(int argc, char **argv)
{
	atexit(checkleaks);
	int		fd;
	char	*line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		if (line != NULL)
		 	free(line);
	}
	fd = close(fd);
	printf("\n");
	return (0);
}
