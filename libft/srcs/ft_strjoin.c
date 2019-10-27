/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:30:58 by alagache          #+#    #+#             */
/*   Updated: 2019/04/27 20:20:06 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(new_str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	new_str[len] = '\0';
	ft_strcpy(new_str, s1);
	ft_strcat(new_str, s2);
	return (new_str);
}
