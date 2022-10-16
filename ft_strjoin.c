/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:50:11 by abensgui          #+#    #+#             */
/*   Updated: 2021/12/21 20:50:13 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	s = malloc((strlen(s1) + strlen(s2) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[k])
	{
		s[i] = s2[k];
		k++;
		i++;
	}
	free((char *)s1);
	s[i] = '\0';
	return (s);
}
