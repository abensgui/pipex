/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:49:56 by abensgui          #+#    #+#             */
/*   Updated: 2021/12/21 20:49:58 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static	int	ft_lin(const char *s, char c)
{
	int	i;
	int	spl;

	i = 0;
	spl = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			spl++;
			while (s[i] != c && s[i])
				i++;
			i--;
		}
		i++;
	}
	return (spl);
}

static	int	ft_len(char const *s, int i, char c)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static char	*ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static	char	**ft_prsplit(int k, char **cpy, const char *s, char c)
{
	int	i;
	int	ii;
	int	l;
	int	j;

	i = 0;
	ii = 0;
	while (i < k && s[ii])
	{
		while (s[ii] == c && s[ii])
			ii++;
		l = ft_len(s, ii, c);
		cpy[i] = (char *)malloc(sizeof(char) * (l + 1));
		if (!cpy[i])
		{
			ft_free(cpy);
			return (NULL);
		}
		j = 0;
		while (s[ii] != c && s[ii])
			cpy[i][j++] = s[ii++];
		cpy[i++][j] = '\0';
	}
	cpy[i] = NULL;
	return (cpy);
}

char	**ft_split(const char *s, char c)
{
	int		k;
	char	**cpy;

	if (s)
	{
		k = ft_lin(s, c);
		cpy = (char **)malloc(sizeof(char *) * (k + 1));
		if (!cpy)
			return (NULL);
		return (ft_prsplit (k, cpy, s, c));
	}
	return (NULL);
}
