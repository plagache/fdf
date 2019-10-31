/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:06:53 by plagache          #+#    #+#             */
/*   Updated: 2019/10/31 12:06:55 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	clean_list(t_list *head)
{
	t_list	*ptr;

	if (head != NULL)
	{
		while (head != NULL)
		{
			ptr = head;
			if (head->content != NULL)
				free(head->content);
			head = head->next;
			free(ptr);
		}
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
