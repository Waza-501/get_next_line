/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 10:56:59 by ohearn        #+#    #+#                 */
/*   Updated: 2022/09/18 12:57:33 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

char	*get_next_line(int fd);
char	read_file(int fd, char *stash, char buffer);
char	*nl_checker(const char *s);
int		return_line(int temp, char *stash);

#endif