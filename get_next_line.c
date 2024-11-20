/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/01 09:57:15 by owen          #+#    #+#                 */
/*   Updated: 2024/11/20 14:29:39 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>

void	free_mem(char **mem)
{
	if (mem != NULL)
		free(*mem);
	*mem = NULL;
}

static char	*find_leftovers(char *remain, char *temp, size_t size)
{
	int		i;

	if (remain[size] == '\0')
	{
		free_mem(&remain);
		return (NULL);
	}
	temp = ft_calloc(ft_strlen(remain) - size + 1, sizeof(char));
	if (!temp)
		return (NULL);
	i = 0;
	while (remain[size] != '\0')
	{
		temp[i] = remain[size];
		i++;
		size++;
	}
	free_mem(&remain);
	remain = ft_strjoin("", temp);
	free_mem(&temp);
	return (remain);
}

static char	*find_line(char *remain)
{
	char	*line;
	int		i;

	i = 0;
	while (remain[i] != '\n' && remain[i] != '\0')
		i++;
	if (remain[i] == '\n' || remain[i] != '\0')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (remain[i] != '\n' && remain[i] != '\0')
	{
		line[i] = remain[i];
		i++;
	}
	if (remain[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	return (line);
}

static char	*read_file(char *remain, char *temp, int fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_mem(&buffer), NULL);
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(remain, buffer);
		if (!temp)
			return (free_mem(&remain), NULL);
		free_mem(&remain);
		remain = ft_strjoin("", temp);
		free_mem(&temp);
		if (ft_strchr(remain, '\n'))
			break ;
	}
	free_mem(&buffer);
	return (remain);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char		*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!remain)
		remain = ft_calloc(1, sizeof(char));
	if (!remain)
		return (NULL);
	temp = NULL;
	if (!ft_strchr(remain, '\n'))
		remain = read_file(remain, temp, fd);
	if (remain == NULL || remain[0] == '\0')
		return (free_mem(&remain), NULL);
	line = find_line(remain);
	if (!line)
		return (free_mem(&remain), NULL);
	remain = find_leftovers(remain, temp, ft_strlen(line));
	return (line);
}

// int main(void)
// {
// 	int	fd;
// 	int	count;
// 	char *gnl;

// 	fd = open("dracula.txt", O_RDONLY);
// 	count = 0;
// 	while (true)
// 	{
// 		gnl = get_next_line(42);
// 		if (gnl == NULL)
// 			break;
// 		count++;
// 		printf("[%d]%s", count, gnl);
// 		free(gnl);
// 		gnl = NULL;
// 	}
// 	close (fd);
// 	return (0);
// }