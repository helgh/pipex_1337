/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-ghd <hael-ghd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:33:28 by hael-ghd          #+#    #+#             */
/*   Updated: 2024/03/06 22:09:00 by hael-ghd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	find_separator(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0 && str[i] != 32)
		i++;
	while (str[i] != 0)
	{
		while (str[i] == 32)
			i++;
		if (str[i] == 39)
			return (str[i]);
		i++;
	}
	return (32);
}

size_t	leng(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	fin_cmd(char **spl_cmd, char *path, char **env)
{
	if (execve(path, spl_cmd, env) == -1)
		free_write_error_exit(spl_cmd, NULL, path);
}

void	fir_cmd(char *argv, char **env)
{
	char	**spl_cmd;
	char	**spl_env;
	char	**s;
	char	*path;

	spl_cmd = ft_split(argv, find_separator(argv));
	spl_env = ft_split(path_env(env), ':');
	s = spl_env;
	while (*(spl_env++) != NULL)
	{
		path = ft_strjoin(*spl_env, *spl_cmd);
		if (access(path, F_OK | X_OK) == -1 && *(spl_env + 1) == NULL)
		{
			free_env_first(s, spl_cmd);
			ft_putendl_fd("Error: command not found", 2);
		}
		else if (access(path, F_OK | X_OK) == 0)
			break ;
		free(path);
	}
	free_env_first(s, NULL);
	fin_cmd(spl_cmd, path, env);
}
