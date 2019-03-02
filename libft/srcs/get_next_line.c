/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 20:56:40 by tduval            #+#    #+#             */
/*   Updated: 2018/12/12 13:37:02 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

static int	free_all(char *cpy, char *line)
{
	if (cpy && *cpy)
		free(cpy);
	if (line && *line)
		free(line);
	return (-1);
}

static int	ft_check(char *cpy, char **line, char **buf)
{
	char	*tmp;

	if (!(*buf = ft_strdup(ft_strchr(cpy, '\n') + 1)))
		return (free_all(cpy, *line));
	if (!(tmp = ft_strdup(*line)))
		return (free_all(cpy, *line));
	free(*line);
	if (!(*line = ft_strsub(tmp, 0, ft_strchr(tmp, '\n') - tmp)))
		return (free_all(cpy, *line));
	free(cpy);
	free(tmp);
	return (0);
}

static int	ft_read(int fd, char **line, char **buf, int *byt)
{
	char	*tmp;
	char	*cpy;

	if (!(cpy = ft_strnew(BUFF_SIZE)))
		return (free_all(cpy, *line));
	while ((*byt = read(fd, cpy, BUFF_SIZE)))
	{
		if (*byt == -1)
			return (free_all(cpy, *line));
		cpy[*byt] = '\0';
		if (!(tmp = ft_strdup(*line)))
			return (free_all(cpy, *line));
		free(*line);
		if (!(*line = ft_strjoin(tmp, cpy)))
			return (free_all(cpy, *line));
		free(tmp);
		if (ft_strchr(cpy, '\n'))
		{
			if ((ft_check(cpy, line, buf)))
				return (free_all(cpy, *line));
			break ;
		}
	}
	return (*byt);
}

static int	ft_splitfun(char **line, char **buf)
{
	if (!(*line = ft_strsub(*buf, 0, ft_strchr(*buf, '\n') \
			- *buf)))
		return (free_all(0, *line));
	*buf = ft_strchr(*buf, '\n') + 1;
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*buf[2147483648];
	int			byt;

	if (!line || fd < 0 || BUFF_SIZE < 1 || !(*line = ft_strnew(0)))
		return (-1);
	byt = 0;
	if (buf[fd] && ft_strchr(buf[fd], '\n'))
		return (ft_splitfun(line, &buf[fd]));
	if (buf[fd])
	{
		if (!(*line = ft_strdup(buf[fd])))
		{
			ft_strdel(line);
			return (-1);
		}
		buf[fd] = 0;
	}
	if (ft_read(fd, &(*line), &buf[fd], &byt) == -1)
		return (free_all(0, *line));
	if (byt < 1 && !ft_strlen(*line))
		return (byt);
	return (1);
}
