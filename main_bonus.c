/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:10:12 by jpaim-so          #+#    #+#             */
/*   Updated: 2025/11/03 17:21:24 by jpaim-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c -o gnl_bonus

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;
	int		i;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			printf("Cannot open file.");
			perror("perror says - ");
			return (0);
		}
		while ((line = get_next_line(fd)) != NULL)
		{
			printf("%s", line);
			free(line);
		}
		close(fd);
		printf("\n");
		i++;
	}
	return (0);
}
