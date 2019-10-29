#include "includes/fdf.h"
#include "libft/includes/libft.h"

void	dispay(char **board)
{
	int c;

	c = 0;
	while (board[c])
	{
		ft_printf("%s\n", board[c]);
		c++;
	}
}

void	clean_board(t_map *map)
{
	int c;

	c = 0;
	while (map->board[c] != NULL)
	{
		free(map->board[c]);
		c++;
	}
	free(map->board);
}

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

int		read_to_list(int fd, t_map *map)
{
	int		ret;
	char	*tmp;
	int		c;
	t_list	*begin;
	t_list	*head;
	t_list	*ptr;

	if ((begin = ft_lstnew(NULL, 0)) == NULL)
		return (-1);
	head = begin;
	c = 0;
	while ((ret = get_next_line(fd, &tmp)) > 0)
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
	//dispay(map->board);
	return (0);
}
