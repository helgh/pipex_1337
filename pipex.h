/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-ghd <hael-ghd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:04:21 by hael-ghd          #+#    #+#             */
/*   Updated: 2024/06/10 17:46:14 by hael-ghd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

void	first_cmd(char **argv, int *pipe_fd, char **env);
void	finish_cmd1(char **mult[], char **spl_cmd, char *path, int *pipe_fd);
void	second_cmd(char **argv, int *pipe_fd, char **env);
void	finish_cmd2(char **mult[], char **spl_cmd, char *path, int *pipe_fd);
char	**ft_split(char const *s, char c);
void	free_write_error_exit(char **spl_cmd, char **spl_env, char *sp);
char	*ft_strjoin(char const	*s1, char const *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putendl_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
void	free_env_first(char **s, char **spl_cmd);
char	*path_env(char **envp);
char	find_separator(char *str);
char	*ft_strdup(const char *s1);

#endif