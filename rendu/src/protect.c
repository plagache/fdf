/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:40:12 by plagache          #+#    #+#             */
/*   Updated: 2019/11/05 14:59:39 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
int		verification(int fd, t_map *map, t_list *head)
{

}
*/

int		is_correct(char *str)
{
	int c;

	c = 0;
	while (str[c])
	{
		if (ft_isdigit(str[c]) != 1 && str[c] != ' ' && str[c] != '-' && str[c] != '\n')
			return (0);
		c++;
	}
	return (1);
}

int		first_read(int fd)
{
	char	buff[101];
	int		ret;

	while ((ret = read(fd, buff, 100)) > 0)
	{
		buff[ret] = '\0';
		if (is_correct(&buff[0]) == 0)
			return (-1);
	}
	return (0);
}

int		protect(char *path)
{
	int		fd;
	char	buff[1];

	if (ft_strnstr(path, "/dev", 4))
		return (-1);
	if (ft_strstr(path + ft_strlen(path) - 4, ".fdf") == NULL)
		return (-1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (-1);
	}
	if (read(fd, buff, 1) < 0)
	{
		close(fd);
		return (-1);
	}
	if (first_read(fd) == -1)
	{
		close(fd);
		return (-1);
	}
	return (0);
}
