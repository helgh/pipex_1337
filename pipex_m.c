/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-ghd <hael-ghd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:55:01 by hael-ghd          #+#    #+#             */
/*   Updated: 2024/03/06 21:37:31 by hael-ghd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	finish_cmd2(char **mult[], char **spl_cmd, char *path, int *pipe_fd)
{
	int	file_out;

	file_out = open(mult[0][4], O_RDWR);
	if (file_out == -1)
		free_write_error_exit(spl_cmd, NULL, path);
	dup2(file_out, STDOUT_FILENO);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(file_out);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	if (execve(path, spl_cmd, mult[1]) == -1)
		free_write_error_exit(spl_cmd, NULL, path);
}

void	second_cmd(char **argv, int *pipe_fd, char **env)
{
	char	**mult[2];
	char	**spl_cmd;
	char	**spl_env;
	char	**s;
	char	*path;

	spl_cmd = ft_split(argv[3], find_separator(argv[3]));
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
	mult[0] = argv;
	mult[1] = env;
	finish_cmd2(mult, spl_cmd, path, pipe_fd);
}

void	finish_cmd1(char **mult[], char **spl_cmd, char *path, int *pipe_fd)
{
	int	file_inp;

	file_inp = open(mult[0][1], O_RDONLY);
	if (file_inp == -1)
		free_write_error_exit(spl_cmd, NULL, path);
	dup2(file_inp, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(file_inp);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (execve(path, spl_cmd, mult[1]) == -1)
		free_write_error_exit(spl_cmd, NULL, path);
}

void	first_cmd(char **argv, int *pipe_fd, char **env)
{
	char	**mult[2];
	char	**spl_cmd;
	char	**spl_env;
	char	**s;
	char	*path;

	spl_cmd = ft_split(argv[2], find_separator(argv[2]));
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
		if (access(path, F_OK | X_OK) == 0)
			break ;
		free(path);
	}
	free_env_first(s, NULL);
	mult[0] = argv;
	mult[1] = env;
	finish_cmd1(mult, spl_cmd, path, pipe_fd);
}

int	main(int ac, char **av, char **envp)
{
	int	pid;
	int	pid1;
	int	pipe_fd[2];

	if (ac != 5)
		ft_putendl_fd("Number of argument is wrong", 2);
	if (pipe(pipe_fd) == -1 || open(av[4], O_CREAT | O_TRUNC, 0644) == -1)
		free_write_error_exit(NULL, NULL, NULL);
	pid = fork();
	if (pid < 0)
		free_write_error_exit(NULL, NULL, NULL);
	if (pid == 0)
		first_cmd(av, pipe_fd, envp);
	pid1 = fork();
	if (pid1 < 0)
		free_write_error_exit(NULL, NULL, NULL);
	if (pid1 == 0)
		second_cmd(av, pipe_fd, envp);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	while (wait(NULL) != -1)
		;
}
