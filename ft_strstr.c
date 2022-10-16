/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:50:31 by abensgui          #+#    #+#             */
/*   Updated: 2021/12/21 20:50:33 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

static char	*ft_instr(char *str, char *to_find)
{
	size_t	j;
	size_t	k;
	size_t	h;

	h = 0;
	while (str[h])
	{
		j = 0;
		k = h;
		while (str[k] == to_find[j] && to_find[j] != '\0')
		{
			if (to_find[j + 1] == '\0')
				return (&str[h + ft_strlen(to_find)]);
			k++;
			j++;
		}
		h++;
	}
	return (0);
}

char	*ft_strstr(char **str, char *to_find)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (!ft_instr(str[i], to_find))
				i++;
			else
				return (ft_instr(str[i], to_find));
		}
	}
	return (0);
}
