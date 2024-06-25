/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-ghd <hael-ghd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:34:33 by hael-ghd          #+#    #+#             */
/*   Updated: 2024/03/06 20:54:54 by hael-ghd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	check_herdoc_or_not(char **argv, int argc, int *out_file)
{
	int		i;
	int		in_file;

	if (argc >= 6 && ft_strncmp(argv[1], "here_doc", leng(argv[1])) == 0)
	{
		i = 3;
		*out_file = open(argv[argc - 1], O_CREAT | O_RDWR | O_APPEND, 0644);
		if (*out_file == -1)
			free_write_error_exit(NULL, NULL, NULL);
		check_here_doc(argv);
	}
	else
	{
		i = 2;
		*out_file = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
		in_file = open(argv[i - 1], O_RDONLY);
		if (*out_file == -1 || in_file == -1)
			free_write_error_exit(NULL, NULL, NULL);
		dup2(in_file, 0);
		close(in_file);
	}
	return (i);
}

void	cmd_line(char *argv, char **env)
{
	int	pid;
	int	pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		free_write_error_exit(NULL, NULL, NULL);
	pid = fork();
	if (pid < 0)
		free_write_error_exit(NULL, NULL, NULL);
	if (pid == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], 1);
		close(pipe_fd[1]);
		fir_cmd(argv, env);
	}
	else
	{
		close(pipe_fd[1]);
		waitpid(pid, NULL, 0);
		dup2(pipe_fd[0], 0);
		close(pipe_fd[0]);
	}
}

int	check_lim(char **str)
{
	int		i;
	char	c;
	char	s;
	char	*buffer;

	s = -1;
	i = read(0, &c, 1);
	buffer = malloc(sizeof(char) * 65536);
	if (buffer == NULL)
		free_write_error_exit(NULL, NULL, NULL);
	while (i != 0 && c != 10 && c != 0)
	{
		buffer[s + i] = c;
		i = read(0, &c, 1);
		s += i;
	}
	buffer[s + 1] = 10;
	buffer[s + 2] = 0;
	*str = buffer;
	return (s + 2);
}

void	check_here_doc(char **argv)
{
	int		pipe_fd[2];
	int		pid;
	char	*buffer;

	if (pipe(pipe_fd) == -1)
		free_write_error_exit(NULL, NULL, NULL);
	pid = fork();
	if (pid < 0)
		free_write_error_exit(NULL, NULL, NULL);
	if (pid == 0)
	{
		close(pipe_fd[0]);
		while (check_lim(&buffer) != 0)
		{
			if (ft_strncmp(argv[2], buffer, leng(argv[2])) != 0)
				write(pipe_fd[1], buffer, leng(buffer));
			else
				exit(EXIT_SUCCESS);
			free(buffer);
		}
	}
	close(pipe_fd[1]);
	wait(NULL);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
}

int	main(int ac, char **av, char **envp)
{
	int	i;
	int	out_file;

	if (ac < 5)
		ft_putendl_fd("Number of arguments are not correct", 2);
	i = check_herdoc_or_not(av, ac, &out_file);
	while (i < ac - 2)
		cmd_line(av[i++], envp);
	dup2(out_file, 1);
	close(out_file);
	fir_cmd(av[i], envp);
}
