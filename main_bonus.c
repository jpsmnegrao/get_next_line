/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:10:12 by jpaim-so          #+#    #+#             */
/*   Updated: 2025/11/10 17:36:24 by jpaim-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c -o gnl_bonus*/

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		fd[3];
	char	*line[3];
	int		done[3] = {0, 0, 0};
	int		i;

	i = 0;
	if (argc < 4)
	{
		printf("Usage: %s file1 file2 file3\n", argv[0]);
		return (1);
	}

	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[2], O_RDONLY);
	fd[2] = open(argv[3], O_RDONLY);

	while (!(done[0] && done[1] && done[2]))
	{
		for (int i = 0; i < 3; i++)
		{
			if (!done[i])
			{
				line[i] = get_next_line(fd[i]);
				if (line[i])
				{
					printf("File %d: %s", i + 1, line[i]);
					free(line[i]);
				}
				else
					done[i] = 1;
			}
		}
	}
	while (i < 3) 
	{
		close(fd[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	*line;

// 	while (((line = get_next_line(0))))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	return (0);
// }
