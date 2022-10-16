/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:53:17 by abensgui          #+#    #+#             */
/*   Updated: 2021/12/21 20:54:08 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H
///////////////////////
# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<string.h>
# include<fcntl.h>
//////////////////////////////
char	**ft_split(const char *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_path(char *s, char **envp);
char	*ft_strstr(char **str, char *to_find);
#endif
