/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-ghd <hael-ghd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:55:04 by hael-ghd          #+#    #+#             */
/*   Updated: 2024/03/04 18:57:03 by hael-ghd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dup;

	i = 0;
	while (s1[i] != 0 && s1[i] != 32)
		i++;
	dup = malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != 0 && s1[i] != 32)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

static void	coppy(char *all, char const *s)
{
	int	i;

	i = 0;
	while (s[i] != 0 && s[i] != 32)
	{
		all[i] = s[i];
		i++;
	}
	all[i] = 0;
}

char	*ft_strjoin(char const	*s1, char const *s2)
{
	size_t		i;
	size_t		s;
	char		*all;

	i = 0;
	s = 0;
	while (s2[i] != 0)
	{
		if (s2[i] == '/')
			return (ft_strdup(s2));
		i++;
	}
	if (s1 != NULL)
		i = ft_strlen(s1);
	if (s2 != NULL)
		s = ft_strlen(s2);
	all = malloc(sizeof(char) * (i + s + 1));
	if (all == NULL)
		return (NULL);
	if (s1 != NULL)
		coppy(all, s1);
	if (s2 != NULL)
		coppy((all + i), s2);
	return (all);
}

void	free_write_error_exit(char **spl_cmd, char **spl_env, char *sp)
{
	int		i;
	int		s;

	i = 0;
	s = 0;
	if (spl_cmd != NULL)
	{
		while (spl_cmd[i] != NULL)
		{
			i++;
			free(spl_cmd[i - 1]);
		}
	}
	if (spl_env != NULL)
	{
		while (spl_env[s] != NULL)
		{
			s++;
			free(spl_env[s - 1]);
		}
	}
	if (sp != NULL)
		free(sp);
	perror("Error");
	exit(EXIT_FAILURE);
}

char	*path_env(char **envp)
{
	char	*envir;

	while (ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	envir = ft_strnstr(*envp, "/", 6);
	return (envir);
}
