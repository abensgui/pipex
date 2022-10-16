/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:51:06 by abensgui          #+#    #+#             */
/*   Updated: 2021/12/21 20:51:14 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_pipex.h"

static void	free_ft(int i, char **envp)
{
	while (envp[i])
	{
		free(envp[i]);
		i++;
	}
	free(envp);
}

char	*get_path(char *s, char **envp)
{
	int		i;
	char	**str;

	i = 0;
	if (!s)
		return (0);
	str = ft_split(ft_strstr(envp, "PATH="), ':');
	while (str[i])
	{
		str[i] = ft_strjoin(str[i], "/");
		str[i] = ft_strjoin(str[i], s);
		if (access (str[i], F_OK) == 0)
		{
			free_ft(i + 1, str);
			return (str[i]);
		}
		free (str[i]);
		i++;
	}
	return (0);
}
