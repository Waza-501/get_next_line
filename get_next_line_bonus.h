/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:32:56 by ohearn        #+#    #+#                 */
/*   Updated: 2022/10/05 15:11:15 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>

char	*get_next_line(int fd);
void	read_file(int fd, char **stash, char *buffer);
char	*return_line(int cntr, char *stash);
char	*save_leftovers(int cntr, char *stash);
void	free_strings(char **string, char **string2, char **string3);
void	read_line(int fd, char **stash, char **line);
char	*print_line(char **stash, char **temp);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
int		ft_strchr(const char *s);
int		nl_checker(const char *s);

#endif