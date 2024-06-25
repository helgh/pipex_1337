/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-ghd <hael-ghd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:08:14 by hael-ghd          #+#    #+#             */
/*   Updated: 2024/03/06 22:08:33 by hael-ghd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_env_first(char **s, char **spl_cmd)
{
	int		i;
	char	**str;

	i = 0;
	str = s;
	if (spl_cmd != NULL)
	{
		while (spl_cmd[i] != NULL)
		{
			i++;
			free(spl_cmd[i - 1]);
		}
	}
	i = 0;
	while (s[i] != NULL)
	{
		i++;
		free(*str);
		str = (s + i);
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0 && s[i] != 32)
		i++;
	return (i);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != 0)
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
	exit(EXIT_FAILURE);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s10;
	unsigned char	*s20;

	i = 0;
	s10 = (unsigned char *)s1;
	s20 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n && (s10[i] != 0 || s20[i] != 0))
	{
		if (s10[i] > s20[i])
			return (s10[i] - s20[i]);
		if (s10[i] < s20[i])
			return (s10[i] - s20[i]);
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*tofind;

	i = 0;
	str = (char *) haystack;
	tofind = (char *) needle;
	if (tofind[i] == 0)
		return (str);
	while (i < len && str[i] != 0)
	{
		j = 0;
		while (str[i + j] == tofind[j] && (i + j) < len)
		{
			if (tofind[j + 1] == 0)
				return (str + i);
			j++;
		}
		i++;
	}
	return (0);
}
