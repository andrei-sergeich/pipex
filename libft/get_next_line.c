/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:12:04 by cmero             #+#    #+#             */
/*   Updated: 2021/08/19 11:44:03 by cmero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_new_line_checker(char *s)
{
	int		x;

	x = 0;
	if (!s)
		return (0);
	while (s[x])
	{
		if (s[x] == '\n')
			return ((char *)s + x);
		x++;
	}
	return (NULL);
}

static int	ft_checker_mallocer(int fd, char **line, char **buf)
{
	if ((read(fd, NULL, 0) < 0) || !line || BUFFER_SIZE <= 0)
		return (-1);
	*buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	return (0);
}

static void	ft_connector_liberator(char **mem_liber, char **line, char *buf)
{
	*mem_liber = *line;
	*line = ft_strjoin(*line, buf);
	free(*mem_liber);
}

static char	*ft_sump_checker(char **sump, char **line)
{
	char	*p_nline;

	p_nline = NULL;
	if (*sump)
	{
		p_nline = ft_new_line_checker(*sump);
		if (p_nline)
		{
			*p_nline = '\0';
			*line = ft_strdup(*sump);
			ft_strcpy(*sump, ++p_nline);
		}
		else
		{
			*line = ft_strdup(*sump);
			free(*sump);
			*sump = NULL;
		}
	}
	else
		*line = ft_calloc(sizeof(char), 1);
	return (p_nline);
}

int	get_next_line(int fd, char **line)
{
	static char	*sump;
	char		*buf;
	char		*p_nline;
	char		*mem_liber;
	int			qbr;

	p_nline = NULL;
	qbr = 1;
	if (ft_checker_mallocer(fd, line, &buf) < 0)
		return (-1);
	p_nline = ft_sump_checker(&sump, line);
	while (!p_nline && qbr > 0)
	{
		qbr = read(fd, buf, BUFFER_SIZE);
		buf[qbr] = '\0';
		p_nline = ft_new_line_checker(buf);
		if (p_nline)
		{
			*p_nline = '\0';
			sump = ft_strdup(++p_nline);
		}
		ft_connector_liberator(&mem_liber, line, buf);
	}
	free(buf);
	return (qbr && sump);
}
