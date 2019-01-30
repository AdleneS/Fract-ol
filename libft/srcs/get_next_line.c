/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 11:02:24 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 14:52:47 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*fdreader(t_gnl **lstgnl, int fd)
{
	t_gnl *tmp;

	tmp = *lstgnl;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	tmp->schar = ft_strnew(BUFF_SIZE);
	tmp->fd = fd;
	tmp->next = *lstgnl;
	*lstgnl = tmp;
	return (tmp);
}

static char		*filereader(const int fd, char *buf, char **str)
{
	char	*tmp;
	int		size;

	size = 1;
	while (size && (!(ft_strchr(*str, '\n'))))
	{
		size = read(fd, buf, BUFF_SIZE);
		if (size)
		{
			buf[size] = '\0';
			tmp = *str;
			if (!(*str = ft_strjoin(*str, buf)))
				return (NULL);
			free(tmp);
		}
	}
	if (!size && ft_strlen(*str) > 0)
	{
		tmp = *str;
		*str = ft_strjoin(tmp, "\n");
		free(tmp);
	}
	free(buf);
	return (*str);
}

static char		*newline(char **str)
{
	char		*tmp;
	char		*buf;
	char		*myline;

	buf = ft_strchr(*str, '\n');
	tmp = NULL;
	if (buf)
	{
		if (!(myline = ft_strsub(*str, 0, buf - *str)))
			return (NULL);
		tmp = *str;
		if (!(*str = ft_strdup(buf + 1)))
			return (NULL);
		free(tmp);
	}
	else if (!(myline = ft_strdup(*str)))
		return (NULL);
	if (!(*str) || !tmp)
		ft_strdel(str);
	return (myline);
}

int				get_next_line(const int fd, char **line)
{
	char			*buf;
	static t_gnl	*lstgnl;
	t_gnl			*lst;

	if (!(lst = fdreader(&lstgnl, fd)))
		return (-1);
	if (fd < 0 || !line || BUFF_SIZE <= 0 || !(buf = ft_strnew(BUFF_SIZE + 1)) \
		|| read(fd, buf, 0) == -1 || (lst->schar == NULL \
		&& !(lst->schar = ft_strnew(0))))
		return (-1);
	if (!(filereader(fd, buf, &lst->schar)))
		return (-1);
	if (*lst->schar)
	{
		if (!(*line = newline(&lst->schar)))
			return (-1);
		return (1);
	}
	return (0);
}
