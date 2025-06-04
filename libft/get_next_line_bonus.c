/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:56:11 by trupham           #+#    #+#             */
/*   Updated: 2025/04/30 16:50:12 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	get_line_length(const char *line);
static char	*build_line(int fd, char *line);
static char	*get_line(char *line, int *pos);
static char	*clean_line(char *line, int pos);

char	*get_next_line(int fd)
{
	static char	*line[MAX_FD];
	char		*newline;
	char		*leftover;
	int			pos;

	line[fd] = build_line(fd, line[fd]);
	if (!line[fd] || ft_strlen(line[fd]) == 0)
		return (free(line[fd]), line[fd] = NULL, NULL);
	pos = 0;
	newline = get_line(line[fd], &pos);
	if (!newline)
		return (free(line[fd]), line[fd] = NULL, NULL);
	leftover = clean_line(line[fd], pos);
	if (!leftover)
		return (free(line[fd]), free(newline), line[fd] = NULL, NULL);
	free(line[fd]);
	line[fd] = leftover;
	return (newline);
}

static char	*build_line(int fd, char *line)
{
	ssize_t	bytes;
	char	*buff;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && !has_nl(line))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buff), NULL);
		buff[bytes] = 0;
		line = gnl_strjoin(line, buff);
		if (!line)
			return (free(buff), NULL);
	}
	free(buff);
	return (line);
}

static int	get_line_length(const char *line)
{
	int	length;

	length = 0;
	while (*line)
	{
		length++;
		if (*line == '\n')
			break ;
		line++;
	}
	return (length);
}

static char	*get_line(char *line, int *pos)
{
	char	*newline;

	newline = malloc(get_line_length(line) + 1);
	if (!newline)
		return (NULL);
	while (line[*pos])
	{
		if (line[*pos] == '\n')
		{
			newline[(*pos)++] = '\n';
			break ;
		}
		else
			newline[*pos] = line[*pos];
		(*pos)++;
	}
	newline[*pos] = 0;
	return (newline);
}

static char	*clean_line(char *line, int pos)
{
	char	*leftover;
	int		k;
	int		j;

	k = pos;
	while (line[pos])
		pos++;
	leftover = malloc(pos - k + 1);
	if (!leftover)
		return (NULL);
	j = 0;
	while (line[k])
		leftover[j++] = line[k++];
	leftover[j] = 0;
	return (leftover);
}
