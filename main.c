/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:34:25 by jpaim-so          #+#    #+#             */
/*   Updated: 2025/11/06 21:11:44 by jpaim-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	if (argc < 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Cannot open file.");
		return (0);
	}
	while (((line = get_next_line(fd))))
	{
		printf("%s", line);
		free(line);
	}
	get_next_line(fd);
	close(fd);
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