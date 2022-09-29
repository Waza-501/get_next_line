/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 10:56:59 by ohearn        #+#    #+#                 */
/*   Updated: 2022/09/29 18:26:22 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

char	*get_next_line(int fd);
void	read_file(int fd, char **stash, char *buffer);
char	*return_line(int cntr, char *stash);
char	*save_leftovers(int cntr, char *stash);
int		nl_checker(const char *s);
void	free_strings(char **string, char **string2, char **string3);
void	read_line(int fd, char **stash, char **line);
char	*print_line(char **stash, char **temp);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
int		ft_strrchr(const char *s);

#endif