/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/01 09:57:19 by owen          #+#    #+#                 */
/*   Updated: 2024/12/04 13:33:34 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	tally;

	tally = 0;
	while (*s && s[tally])
		tally++;
	return (tally);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*combine;

	size = 0;
	combine = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) +1);
	if (!combine)
		return (NULL);
	while (s1 != NULL && *s1)
	{
		combine[size] = *s1;
		s1++;
		size++;
	}
	while (s2 != NULL && *s2)
	{
		combine[size] = *s2;
		s2++;
		size++;
	}
	combine[size] = '\0';
	return (combine);
}

int		nl_checker(const char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)s + i);
	return (NULL);
}

void	*ft_bzero(void *s, size_t n)
{
	char	*temp;
	size_t	tally;

	temp = (char *)s;
	tally = 0;
	while (tally < n)
	{
		temp[tally] = '\0';
		tally++;
	}
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*new;
	size_t	check;

	if (nmemb != 0 && size != 0)
	{
		check = nmemb * size;
		if (nmemb != check / size)
			return (NULL);
	}
	new = (char *)malloc(nmemb * size);
	if (!new)
		return (NULL);
	ft_bzero(new, nmemb * size);
	return (new);
}
