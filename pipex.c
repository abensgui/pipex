/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:51:29 by abensgui          #+#    #+#             */
/*   Updated: 2021/12/21 20:51:36 by abensgui         ###   ########.fr       */
/*                      	q                                                 */
/* ************************************************************************** */

#include "ft_pipex.h"

static void	ft_child1(char **argv, char **envp, int fd1)
{
	int		f;
	char	**res;

	f = open(argv[1], O_RDONLY);
	if (f < 0)
	{
		perror("pipex :");
		exit(1);
	}
	dup2(f, 0);
	dup2(fd1, 1);
	close(f);
	close(fd1);
	res = ft_split(argv[2], ' ');
	if (execve(get_path(res[0], envp), res, NULL) == -1)
	{
		perror("pipex :");
		exit(1);
	}
}

static void	ft_child2(char **argv, char **envp, int fd0, int fd1)
{
	int		f1;
	char	**res;

	f1 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (f1 < 0)
	{
		perror("pipex :");
		exit(1);
	}
	dup2(f1, 1);
	dup2(fd0, 0);
	close(fd0);
	close(fd1);
	close(f1);
	res = ft_split(argv[3], ' ');
	if (execve(get_path(res[0], envp), res, NULL) == -1)
	{
		perror("pipex :");
		exit(1);
	}
}

static void	ft_error(int k)
{
	if (k == -1)
	{
		perror("pipex :");
		exit(1);
	}
}

int	main(int ac, char **argv, char **envp)
{
	int		fd[2];
	int		id;
	int		id2;

	if (ac == 5)
	{
		pipe(fd);
		id = fork();
		ft_error(id);
		if (id == 0)
			ft_child1(argv, envp, fd[1]);
		id2 = fork();
		ft_error(id2);
		if (id2 == 0)
			ft_child2(argv, envp, fd[0], fd[1]);
		close(fd[0]);
		close(fd[1]);
		waitpid(id, NULL, 0);
		waitpid(id2, NULL, 0);
	}
}
