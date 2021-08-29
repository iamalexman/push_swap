/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 11:59:56 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/08/27 11:59:57 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_read(int fd, char *buf, int *ret)
{
	return (*ret = (int) read(fd, buf, BUFFER_SIZE));
}

void	ft_freeshka(char **string)
{
	if (string != NULL && *string != NULL)
	{
		free(*string);
		*string = NULL;
	}
}

static int	ft_make_line(char **ost, char **line)
{
	char	*ptr_n;
	char	*tmp;

	ptr_n = NULL;
	tmp = NULL;
	ptr_n = ft_strchr(*ost, '\n');
	if (ptr_n)
	{
		ptr_n++;
		*ptr_n = '\0';
		tmp = *ost;
		*line = ft_strdup(tmp);
		*ost = ft_strdup(ptr_n);
		ft_freeshka(&tmp);
	}
	else
	{
		tmp = *line;
		*line = ft_strdup(*ost);
		ft_freeshka(ost);
		return (0);
	}
	return (1);
}

static int	ft_out(char **ost, char **line, int fd, int ret)
{
	if (ret == 0)
	{
		if (ost[fd])
			return (ft_make_line(&ost[fd], line));
		else
			*line = NULL;
		return (0);
	}
	else
		return (ft_make_line(&ost[fd], line));
}

int	get_next_line(int fd, char **line)
{
	static char		*ost[FD_BUFFER];
	char			*buf;
	char			*tmp;
	int				ret;

	if ((read(fd, 0, 0) < 0) || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while ((ft_read(fd, buf, &ret)) > 0)
	{
		buf[ret] = '\0';
		if (ost[fd] == NULL)
			ost[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(ost[fd], buf);
			ft_freeshka(&ost[fd]);
			ost[fd] = tmp;
			tmp = NULL;
		}
		if (ft_strchr(ost[fd], '\n'))
			break ;
	}
	ft_freeshka(&buf);
	return (ft_out(ost, line, fd, ret));
}
