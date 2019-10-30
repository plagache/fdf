#include "includes/fdf.h"
#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"

int		is_map(char *str)
{
	int c;

	c = 0;
	while (str[c])
	{
		if (ft_isdigit(str[c]) != 1 || str[c] != ' ' || str[c] != '-')
			return (0);
		c++;
	}
	return (1);
}

int		list_to_array(t_map *map, t_list *head, int c)
{
	int 	ret;
	t_list	*ptr;

	if (!(map->board = (char**)malloc(sizeof(char*) * (c + 1))))
		return (-1);
	c = 0;
	ret = 0;
	while (head != NULL)
	{
		ptr = head;
		map->board[c] = (char*)head->content;
		head = head->next;
		free(ptr);
		if (map->board[c] != NULL && is_map(map->board[c]) == 1)
			ret = -1;
		c++;
	}
	return (ret);
}

int		read_to_list(int fd, t_map *map, t_list *head)
{
	char	*tmp;
	int		c;
	t_list	*begin;
	t_list	*ptr;

	if ((begin = ft_lstnew(NULL, 0)) == NULL)
		return (-1);
	head = begin;
	c = 0;
	while (get_next_line(fd, &tmp) > 0)
	{
		begin->content = tmp;
		if ((ptr = ft_lstnew(NULL, 0)) == NULL)
			return (-1);
		begin->next = ptr;
		begin = begin->next;
		c++;
	}
	if (list_to_array(map, head, c) == -1)
		return (-1);
	return (0);
}

int		read_file(t_map *map)
{
	int	fd;
	t_list	*head;

	head == NULL;
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || (ret = read_to_list(fd, map, head)) == -1
	{
		clean_list(head);
		clean_board(map);
		close(fd);
		return (-1);
	}
	if (data_trans(map) == -1)
	{
		clean_board(map);
		close(fd);
		return (-1);
	}
	close(fd);
	clean_board(map);
	return (0);
}
