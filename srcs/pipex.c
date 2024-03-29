/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yude-oli <yude-oli@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:12:21 by yude-oli          #+#    #+#             */
/*   Updated: 2024/02/03 13:20:45 by yude-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	fork_child_process(char **argv, char **env, int *fd)
{
	int	filein;
        if (!argv[2][1])
                error();
	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(filein);
	execute_cmd(&argv[2], env);
}

void	fork_parent_process(char **argv, char **env, int *fd)
{
	int	fileout;
        if (!argv[3][1])
                error();
	fileout = open(argv[4], O_RDONLY | O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	close(fileout);
	execute_cmd(&argv[3], env);
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid1;

	if (!env || !env[0] || !env[2])
	{
		ft_printf("Error");
		return (-1);
	}
	if (argc == 5)
	{
                if (!argv[2][0] || !argv[3][0])
                        error();
		if (pipe(fd) == -1)
			error();
		pid1 = fork();
		if (pid1 == -1)
			error();
		if (pid1 == 0)
			fork_child_process(argv, env, fd);
		waitpid(pid1, NULL, 0);
		fork_parent_process(argv, env, fd);
	}
	else
		error();
	return (0);
}
