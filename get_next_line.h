/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 10:56:59 by ohearn        #+#    #+#                 */
/*   Updated: 2022/09/27 16:49:34 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

char	*get_next_line(int fd);
char	*read_file(int fd, char *stash, char *buffer);
char	*return_line(int cntr, char *stash);
void	save_leftovers(int cntr, char *stash);
int		nl_checker(const char *s);
void	free_strings(char **string);

#endif