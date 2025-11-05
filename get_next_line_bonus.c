/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:59:04 by jpaim-so          #+#    #+#             */
/*   Updated: 2025/11/05 14:33:41 by jpaim-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*append_text(char *text, char *tmp)
{
	char	*append;

	if (text)
		append = ft_strjoin(text, tmp);
	else
		append = ft_strdup(tmp);
	if (!append)
		return (NULL);
	free(text);
	return (append);
}

static char	*read_and_add(int fd, char *text)
{
	char	*tmp;
	ssize_t	size;

	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	while (1)
	{
		if (text && ft_linelen(text) < ft_strlen(text))
			break ;
		size = read(fd, tmp, BUFFER_SIZE);
		if (size <= 0)
			break ;
		tmp[size] = '\0';
		text = append_text(text, tmp);
		if (!text)
			break ;
	}
	free(tmp);
	if (!text || text[0] == '\0')
	{
		free(text);
		return (NULL);
	}
	return (text);
}

static char	*take_line(char **text)
{
	size_t	len;
	char	*line;
	char	*new_text;

	if (!*text || !**text)
		return (NULL);
	len = ft_linelen(*text);
	line = ft_substr(*text, 0, len);
	if (!line)
		return (NULL);
	if (len == ft_strlen(*text))
	{
		free(*text);
		*text = NULL;
		return (line);
	}
	new_text = ft_substr(*text, len, ft_strlen(*text) - len);
	if (!new_text)
	{
		free(line);
		return (NULL);
	}
	free(*text);
	*text = new_text;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &text, 0) < 0)
		return (NULL);
	text = read_and_add(fd, text);
	if (!text || text[0] == '\0')
	{
		if (text)
		{
			free(text);
			text = NULL;
		}
		return (NULL);
	}
	line = take_line(&text);
	if (!line && text)
	{
		free(text);
		text = NULL;
	}
	return (line);
}
