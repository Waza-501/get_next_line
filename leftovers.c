/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   leftovers.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 15:05:00 by ohearn        #+#    #+#                 */
/*   Updated: 2022/09/29 15:05:09 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// void	read_file(int fd, char *stash, char *buffer)
// {
// 	int		safeguard;
// 	int		cntr;
// 	char	*ret;

// 	safeguard = 1;
// 	while (safeguard > 0)
// 	{
// 		safeguard = read(fd, buffer, BUFFER_SIZE);
// 		if (safeguard == -1)
// 		{
// 			free_strings(&buffer, &stash, 0);
// 			return (NULL);
// 		}
// 		buffer[safeguard] = '\0';
// 		stash = strcat(stash, buffer);
// 		cntr = nl_checker(stash);
// 		if (cntr != '\0')
// 		{
// 			ret = return_line(cntr, stash);
// 			save_leftovers(cntr, stash);
// 			return (ret);
// 		}
// 	}
// 	ret = return_line(cntr, stash);
// 	return ;
// }
//	no longer needed, but keeping this here for future reference