/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-ghd <hael-ghd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:35:10 by hael-ghd          #+#    #+#             */
/*   Updated: 2024/06/10 17:47:00 by hael-ghd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

void	fir_cmd(char *argv, char **env);
void	fin_cmd(char **spl_cmd, char *path, char **env);
char	**ft_split(char const *s, char c);
void	free_write_error_exit(char **spl_cmd, char **spl_env, char *sp);
char	*ft_strjoin(char const	*s1, char const *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putendl_fd(char *s, int fd);
size_t	leng(const char *s);
size_t	ft_strlen(const char *s);
void	free_env_first(char **s, char **spl_cmd);
char	*path_env(char **envp);
char	find_separator(char *str);
char	*ft_strdup(const char *s1);
void	check_here_doc(char **argv);
int		check_lim(char **str);
void	cmd_line(char *argv, char **env);
int		check_herdoc_or_not(char **argv, int argc, int *out_file);

#endif